#ifndef PLUME_TRACKING
#define PLUME_TRACKING
#include <boost/format.hpp>

#include <vector>
#include <list>
#include <fstream>      // std::ofstream
#include <iostream>

#include <visualization_msgs/Marker.h>
#include <visualization_msgs/MarkerArray.h>

#include <gsl_algorithm.h>


typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;
enum class PT_state {WAITING_FOR_MAP, EXPLORATION, STOP_AND_MEASURE, INSPECTION, UPWIND_SURGE, CROSSWIND_CAST};

class PlumeTracking:public GSLAlgorithm
{

public:
    PlumeTracking(ros::NodeHandle *nh);
    ~PlumeTracking();

    PT_state get_state();              //Returns current Search-State
    void getGasWindObservations();      //Get Wind and Gas observations while standing
    float get_gas_concentration();      //Returns the averaged gas concentration
    virtual void checkState() = 0;                  //Check gas/wind to see if a state transition is necessary

    void setExplorationGoal();          //Set target according to GDM
    void setRandomGoal();               //Set target random (within the map)
    virtual void setSurgeGoal() = 0;                //Set target upwind
    virtual void setCastGoal() = 0;                 //Set target crosswind
    void setInspectionGoal();           // Set target arround current location

    void cancel_navigation();
protected:
    ros::NodeHandle *nh_;                                                 //! Node handler.
    ros::Time movingTimestamp;
    ros::Time recoveryTimestamp;

    //GSL variables
    bool gasFound;
    PT_state current_state, previous_state;
    double th_gas_present;
    double th_wind_present;
    double step, current_step;                                          //!distance (m) to move upwind during Surge search
    unsigned int cast_movement;                                          //! initial movement direction for crossWind (cast phase)    
    int inspection_iter;
    double inspection_radius;
    //For gas hit detection
    std::vector<float> gasConcentration_v;
    std::vector<float> windSpeed_v;
    std::vector<float> windDirection_v;
    std::vector<float>::iterator gas_it;
    std::vector<float>::iterator windS_it;
    std::vector<float>::iterator windD_it;
    //Stop_and_measure
    ros::Time time_stopped;                                             //! Used to measure wind while robot is stopped

    double average_concentration, average_wind_direction, average_wind_spped;
    std::vector<float> stop_and_measure_gas_v;
    std::vector<float> stop_and_measure_windS_v;
    std::vector<float> stop_and_measure_windD_v;

    double timeout_cast;                                                //! (seconds) Max time to do Cast (crosswind search) before returning to the EXPLORATION state.
    double stop_and_measure_time;                                       //! (seconds) time the robot is stopped while measuring the wind direction
    bool gasHit;

    //CallBacks
    void gasCallback(const olfaction_msgs::gas_sensorPtr& msg) override;
    void windCallback(const olfaction_msgs::anemometerPtr& msg) override;
    void mapCallback(const nav_msgs::OccupancyGrid::ConstPtr& msg) override;

    //Methods
    geometry_msgs::PoseStamped get_random_pose_environment();
    double fRand(double fMin, double fMax);
    float get_average_wind_direction(std::vector<float> const &v);
    
    //Actionlib callbacks (move_base)
    void goalDoneCallback(const actionlib::SimpleClientGoalState &state, const move_base_msgs::MoveBaseResultConstPtr &result) override;
};

#endif