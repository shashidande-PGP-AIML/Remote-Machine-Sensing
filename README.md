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

E-noses are devices conceived to detect and monitorize the concentration and composition of volatile substances by means of an array of non-selective gas sensors and some kind of pattern recognition algorithm. Their exploitation can be classified into two main categories according to the level of control over the measurement conditions: Closed Sampling Systems (CSS), where gas sensors are usually hosted in test chambers with controlled airflow, volatile exposure times, temperature and humidity, etc., and Open Sampling Systems (OSS), with no control over the sensing conditions. Our interest is in the latter, which are more flexible and practical for field applications, specially when accomplished with the help of a mobile robot carrying the e-nose on board, which makes the sensing task even more challenging. Particularly, we have to study and propose different approaches to overcome one of the main drawbacks of metal oxide gas transducers (MOX) when used on OSS, their slow recovery

The location of sensors on the quadrotor is not a trivial issue and requires the study of some conditions. Both the air-flows produced by the rotors and the light and shadow conditions can affect the sensor measurements. Additionally, the weights of the sensors influence the weight and inertia of the quadrotor, which can in turn affect navigation.

Specifically, the temperature and humidity sensor can be affected by solar radiation and the airflows of the rotors, the luminosity sensor is obviously conditioned by solar radiation and the carbon dioxide sensor can be affected by the air-flows of the rotors.

Two previous studies have addressed quadrotor aerodynamics with similar results [cite here]. Their conclusions stated that when considering an isolated rotor, the airspeed is maximum at its perimeter and minimum in the center and the exterior of the quadrotor; moreover, considering all rotors, the airspeed is maximum near the rotors and minimum in the center and outside the quadrotor.

Based on the quadrotor aerodynamics and considering the effects of solar radiation, there are two possible sensor locations to consider: the center part of the top side of the quadrotor and outside the quadrotor at some distance. Considering both options, the first does not require a complex assembly that could modify the center of gravity of the quadrotor (e.g., an extension for the sensors) and therefore is selected for the location of the sensors. Unfortunately, the conclusions of both publications were focused on quadrotor design and modeling instead of sensor allocation. Therefore, a complementary exhaustive study of quadrotor aerodynamics oriented to sensor allocation was necessary.

Simulations of computational fluid dynamics (CFD) and real experiments for determining quadrotor airflows were performed to determine the relevant aerodynamics and validate the location of sensors.




