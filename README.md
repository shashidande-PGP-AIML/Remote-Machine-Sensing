# Remote Machnine Sensing
The Challenge of detecting gas leaks with mobile robots.

### Introduction
In this body of work we describe the design, construction and validation of a mobile sensory platform for gas leak monitoring. The complete system consists of a sensory system on board a small quadrotor (i.e., a four rotor mini-UAV). The goals of this system include taking mesurements of gases, sensing and identifying their source. There are many challenges in building a mobile sensory platform. We have to pay special attention to the robot perception and decisión-making processes and develop the capabilities necessary for an effcient, autonomous robot. In order to achive that we need to tackle the following design challenges. 
- Gas sensing and development of olfactory capability
- Design of perception, decision and actuation system
- Quadrotor's limited payload
- The sensors layout and placement in order to have the least possible influence of the rotors.

### Gas Sensing
Olfaction is a valuable source of information about the environment that has not been sufficiently exploited in mobile robotics yet. We claim that data provided by e-noses may have an important added-value when combined with other sensing modalities (particularly, vision), and also when olfaction is integrated into the robot high-level processes.

Gas sensing is the task of detecting volatile substances and providing a conversion of that information into a signal or electrical magnitude readable by an operator or instrument. In the field of artificial olfaction, devices that fullfill this task are known as Electronic noses(e-nose). 

E-noses are devices conceived to detect and monitorize the concentration and composition of volatile substances by means of an array of non-selective gas sensors and some kind of pattern recognition algorithm. Their exploitation can be classified into two main categories according to the level of control over the measurement conditions: Closed Sampling Systems (CSS), where gas sensors are usually hosted in test chambers with controlled airflow, volatile exposure times, temperature and humidity, etc., and Open Sampling Systems (OSS), with no control over the sensing conditions. Our interest is in the latter, which are more flexible and practical for field applications, specially when accomplished with the help of a mobile robot carrying the e-nose on board, which makes the sensing task even more challenging. Particularly, we have to study and propose different approaches to overcome one of the main drawbacks of metal oxide gas transducers (MOX) when used on OSS, their slow recovery.

### Platform Analysis
The primary alternatives to the proposed mini-UAV sensory system are Wireless Sensor Networks (WSNs) and Unmanned Ground Vehicles (UGVs). Both of them are well-known solutions that have been applied in the context of greenhouse agriculture. Despite this fact, the WSNs and UGVs are hindered by limitations that UAVs can overcome.

The primary advantage of WSNs is simultaneous measurements at various points, which a UGV or UAV cannot perform and may be desirable for this application. WSNs are a robust solution due to their simplicity, which reduces the probability of failure, and their modularity, which allows working with damaged motes. Conversely, in contrast to UGVs and UAVs, WSNs are not able to move within the workspace to take measures at points of interest. In addition, the costs of WSNs strongly depend on the number of motes, which may reach hundreds in a medium size greenhouse. This multiplication of motes (e.g., sensors, controllers, batteries and communication modules) makes their costs higher than the costs of UGVs or UAVs.

UGVs tend to have lower costs than WSNs and are competitive against UAVs. The simplicity of their mechanic elements and control systems makes their costs lower than the costs of UAVs. In addition, UGVs can move to the points of interest; however, these movements are restricted to the ground, preventing them from reaching certain points of interest due to obstacles such as plants and covers. Conversely, UAVs can obtain measurements at nearly any point in a three dimensional space including at different altitudes. This fact is interesting not only for reducing the number of sensors and therefore the total cost of such a system but also for obtaining local data for production monitoring, problem detection (e.g., a break in a plastic cover) and local climate control. In summary, the characteristics of UAVs make them a competitive option for measuring the environmental variables of greenhouses and justify this research.

### Integration of Sensors
he sensors have been integrated to satisfy two needs: the collection and storage of measurements including space and time references; and the communication between the mini-UAV sensory system and the greenhouse management system. Several alternatives for the integration of sensors have been studied, and two prototypes have been developed: one with an Arduino UNO and another with a Raspberry Pi. Both prototypes have been compared with multiple criteria including size, weight, performance and connectivity. The Raspberry Pi has ultimately been chosen instead of the Arduino UNO due to its performance, connectivity and programming. The Raspberry Pi has better performance than the Arduino UNO, both in hardware (e.g., processor speed and memory) and software (i.e., operating system), which allows it to preprocess data while measuring. Additionally, the Raspberry Pi typically has better performance when connected to Wi-Fi networks and exchanging data with other devices. Finally, the Raspberry Pi provides additional programming capabilities including full integration with Robot Operating System (ROS).

### Location of Sensors
The location of sensors on the quadrotor is not a trivial issue and requires the study of some conditions. Both the air-flows produced by the rotors and the light and shadow conditions can affect the sensor measurements. Additionally, the weights of the sensors influence the weight and inertia of the quadrotor, which can in turn affect navigation.

Specifically, the temperature and humidity sensor can be affected by solar radiation and the airflows of the rotors, the luminosity sensor is obviously conditioned by solar radiation and the carbon dioxide sensor can be affected by the air-flows of the rotors.

Two previous studies have addressed quadrotor aerodynamics with similar results [cite here]. Their conclusions stated that when considering an isolated rotor, the airspeed is maximum at its perimeter and minimum in the center and the exterior of the quadrotor; moreover, considering all rotors, the airspeed is maximum near the rotors and minimum in the center and outside the quadrotor.

Based on the quadrotor aerodynamics and considering the effects of solar radiation, there are two possible sensor locations to consider: the center part of the top side of the quadrotor and outside the quadrotor at some distance. Considering both options, the first does not require a complex assembly that could modify the center of gravity of the quadrotor (e.g., an extension for the sensors) and therefore is selected for the location of the sensors. Unfortunately, the conclusions of both publications were focused on quadrotor design and modeling instead of sensor allocation. Therefore, a complementary exhaustive study of quadrotor aerodynamics oriented to sensor allocation was necessary.

Simulations of computational fluid dynamics (CFD) and real experiments for determining quadrotor airflows were performed to determine the relevant aerodynamics and validate the location of sensors.




