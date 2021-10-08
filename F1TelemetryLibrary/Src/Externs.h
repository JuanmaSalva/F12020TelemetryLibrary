#pragma once
#include <cstdint>
#include <thread>

//Welcome to F1TS (F1 Telemetry System), the open source telemetry system for formula 1 games made by Codemasters
//In this dll you can see all accessible methods from this dll, if you want to edit some of the source code,
//yo can do so by downloading the visual studio solution [...], or simply the code from [...]. For a full experience,
//i made a program with unity that you can use straight away. This program will open a app that shows a bunch of
//telemetry of your game, take a look at [...] to se what the program can do. Yo can download this program from here[...]
//
//All data used in this library is taken out of the udp packets that the game sends through the localhost network.
//The data is divided in 10 types of packets, each of wich has the same header, for more information about the packets
//visit the official Codemaster post about if here https://forums.codemasters.com/topic/50942-f1-2020-udp-specification/
//
//In order to use the library, you will need to first go to yor game and enable telemetry on local host.
//
//If you find a bug o a possible improvement let me know and I will try to fix it or introduce it
//
//Disclaimer, this library will open a localhost port, it is VERRY important to call the close method,
//if this method is never called, the local port will remain open.
//I do not take any responsibilities for any side effects the library may have on your device.
//If the library is correctly used, there is no need to worry, only tons of telemetry information that you can extract
//from the game ^_^

class TelemetryF1;

#ifdef F1TELEMETRIAF1_EXPORTS
#define F1LIBRARY_EXPORTS extern "C"  __declspec(dllexport)
#else
#define F1LIBRARY_EXPORTS extern "C"  __declspec(dllimport)
#endif


std::thread t;
TelemetryF1* telemetry;
bool isReady_ = false;


//GENERAL.
F1LIBRARY_EXPORTS void F1TS_startF1Telemetry();
F1LIBRARY_EXPORTS void F1TS_closeF1Telemetry();
F1LIBRARY_EXPORTS bool F1TS_isReady();
F1LIBRARY_EXPORTS void F1Ts_startF1TelemetryThread();


//LAP DATA	
F1LIBRARY_EXPORTS float F1TS_lastTimeLap(int8_t carId);
F1LIBRARY_EXPORTS float F1TS_currentLapTime(int8_t id);
F1LIBRARY_EXPORTS uint16_t F1TS_sector1(int8_t carId);
F1LIBRARY_EXPORTS uint16_t F1TS_sector2(int8_t carId);
F1LIBRARY_EXPORTS float F1TS_bestLapTime(int8_t carId);
F1LIBRARY_EXPORTS uint8_t F1TS_bestLapNum(int8_t carId);
F1LIBRARY_EXPORTS uint16_t F1TS_bestLapSector1TimeInMS(int8_t carId);
F1LIBRARY_EXPORTS uint16_t F1TS_bestLapSector2TimeInMS(int8_t carId);
F1LIBRARY_EXPORTS uint16_t F1TS_bestLapSector3TimeInMS(int8_t carId);
F1LIBRARY_EXPORTS uint16_t F1TS_bestOverallSector1TimeInMS(int8_t carId);
F1LIBRARY_EXPORTS uint8_t F1TS_bestOverallSector1LapNum(int8_t carId);
F1LIBRARY_EXPORTS uint16_t F1TS_bestOverallSector2TimeInMS(int8_t carId);
F1LIBRARY_EXPORTS uint8_t F1TS_bestOverallSector2LapNum(int8_t carId);
F1LIBRARY_EXPORTS uint16_t F1TS_bestOverallSector3TimeInMS(int8_t carId);
F1LIBRARY_EXPORTS uint8_t F1TS_bestOverallSector3LapNum(int8_t carId);
F1LIBRARY_EXPORTS float F1TS_lapDistance(int8_t carId);
F1LIBRARY_EXPORTS float F1TS_totalDistance(int8_t carId);
F1LIBRARY_EXPORTS float F1TS_safetyCarDelta(int8_t carId);
F1LIBRARY_EXPORTS uint8_t F1TS_carPosition(int8_t carId);
F1LIBRARY_EXPORTS uint8_t F1TS_currentLapNum(int8_t carId);
F1LIBRARY_EXPORTS uint8_t F1TS_pitStatus(int8_t carId);
F1LIBRARY_EXPORTS uint8_t F1TS_sector(int8_t carId);
F1LIBRARY_EXPORTS uint8_t F1TS_currentLapInvalid(int8_t carId);
F1LIBRARY_EXPORTS uint8_t F1TS_penalties(int8_t carId);
F1LIBRARY_EXPORTS uint8_t F1TS_gridPosition(int8_t carId);
F1LIBRARY_EXPORTS uint8_t F1TS_driverStatus(int8_t carId);
F1LIBRARY_EXPORTS uint8_t F1TS_resultStatus(int8_t carId);


//MOTION PACKET DATA
F1LIBRARY_EXPORTS float F1TS_worldPositionX(int8_t carId);
F1LIBRARY_EXPORTS float F1TS_worldPositionY(int8_t carId);
F1LIBRARY_EXPORTS float F1TS_worldPositionZ(int8_t carId);
F1LIBRARY_EXPORTS float F1TS_worldVelocityX(int8_t carId);
F1LIBRARY_EXPORTS float F1TS_worldVelocityY(int8_t carId);
F1LIBRARY_EXPORTS float F1TS_worldVelocityZ(int8_t carId);
F1LIBRARY_EXPORTS int16_t F1TS_worldForwardDirX(int8_t carId);
F1LIBRARY_EXPORTS int16_t F1TS_worldForwardDirY(int8_t carId);
F1LIBRARY_EXPORTS int16_t F1TS_worldForwardDirZ(int8_t carId);
F1LIBRARY_EXPORTS int16_t F1TS_worldRightDirX(int8_t carId);
F1LIBRARY_EXPORTS int16_t F1TS_worldRightDirY(int8_t carId);
F1LIBRARY_EXPORTS int16_t F1TS_worldRightDirZ(int8_t carId);
F1LIBRARY_EXPORTS float F1TS_gForceLateral(int8_t carId);
F1LIBRARY_EXPORTS float F1TS_gForceLongitudinal(int8_t carId);
F1LIBRARY_EXPORTS float F1TS_gForceVertical(int8_t carId);
F1LIBRARY_EXPORTS float F1TS_yaw(int8_t carId);
F1LIBRARY_EXPORTS float F1TS_pitch(int8_t carId);
F1LIBRARY_EXPORTS float F1TS_roll(int8_t carId);

F1LIBRARY_EXPORTS float F1TS_suspensionPositionRL();
F1LIBRARY_EXPORTS float F1TS_suspensionPositionRR();
F1LIBRARY_EXPORTS float F1TS_suspensionPositionFL();
F1LIBRARY_EXPORTS float F1TS_suspensionPositionFR();
F1LIBRARY_EXPORTS float F1TS_suspensionVelocityRL();
F1LIBRARY_EXPORTS float F1TS_suspensionVelocityRR();
F1LIBRARY_EXPORTS float F1TS_suspensionVelocityFL();
F1LIBRARY_EXPORTS float F1TS_suspensionVelocityFR();
F1LIBRARY_EXPORTS float F1TS_suspensionAccelerationRL();
F1LIBRARY_EXPORTS float F1TS_suspensionAccelerationRR();
F1LIBRARY_EXPORTS float F1TS_suspensionAccelerationFL();
F1LIBRARY_EXPORTS float F1TS_suspensionAccelerationFR();
F1LIBRARY_EXPORTS float F1TS_wheelSpeedRL();
F1LIBRARY_EXPORTS float F1TS_wheelSpeedRR();
F1LIBRARY_EXPORTS float F1TS_wheelSpeedFL();
F1LIBRARY_EXPORTS float F1TS_wheelSpeedFR();
F1LIBRARY_EXPORTS float F1TS_wheelSlipRL();
F1LIBRARY_EXPORTS float F1TS_wheelSlipRR();
F1LIBRARY_EXPORTS float F1TS_wheelSlipFL();
F1LIBRARY_EXPORTS float F1TS_wheelSlipFR();
F1LIBRARY_EXPORTS float F1TS_localVelocityX();
F1LIBRARY_EXPORTS float F1TS_localVelocityY();
F1LIBRARY_EXPORTS float F1TS_localVelocityZ();
F1LIBRARY_EXPORTS float F1TS_angularVelocityX();
F1LIBRARY_EXPORTS float F1TS_angularVelocityY();
F1LIBRARY_EXPORTS float F1TS_angularVelocityZ();
F1LIBRARY_EXPORTS float F1TS_angularAccelerationX();
F1LIBRARY_EXPORTS float F1TS_angularAccelerationY();
F1LIBRARY_EXPORTS float F1TS_angularAccelerationZ();
F1LIBRARY_EXPORTS float F1TS_frontWheelsAngle();