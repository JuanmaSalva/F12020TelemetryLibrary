#pragma once
#include <cstdint>
#include <thread>

//Welcome to F1TS (F1 Telemetry System), the open source telemetry system for formula 1 games made by Codemasters
//In this .h you can see all accessible methods from this dll, if you want to edit some of the source code,
//yo can do so by downloading the visual studio solution [...], or simply the code from [...]. For a full experience,
//i made a program with unity that you can use straight away. This program will open a app that shows a bunch of
//telemetry of your game, take a look at [...] to se what the program can do. Yo can download this program from here[...]
//
//All data used in this library is taken out of the udp packets that the game sends through the localhost network.
//The data is divided in 10 types of packets, each of wich has the same header, for more information about the packets
//visit the official Codemasters post about if here https://forums.codemasters.com/topic/50942-f1-2020-udp-specification/
//
//In order to use the library, you will need to first go to yor game and enable telemetry on local host. At the moment
//the only port available is 20777 (default by the game)
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
bool isClosed_ = false;

//GENERAL.
F1LIBRARY_EXPORTS void F1TS_startF1Telemetry();
F1LIBRARY_EXPORTS void F1TS_closeF1Telemetry();
F1LIBRARY_EXPORTS bool F1TS_isReady();
F1LIBRARY_EXPORTS bool F1TS_isClosed();
F1LIBRARY_EXPORTS void F1TS_startF1TelemetryThread();
F1LIBRARY_EXPORTS uint8_t F1Ts_playerCarIndex();
F1LIBRARY_EXPORTS void F1TS_packetSizes();


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

//SESSION DATA
F1LIBRARY_EXPORTS uint8_t F1TS_weather();
F1LIBRARY_EXPORTS int8_t F1TS_trackTemperature();
F1LIBRARY_EXPORTS int8_t F1TS_airTemperature();
F1LIBRARY_EXPORTS uint8_t F1TS_totalLaps();
F1LIBRARY_EXPORTS uint16_t F1TS_trackLength();
F1LIBRARY_EXPORTS uint8_t F1TS_sessionType();
F1LIBRARY_EXPORTS int8_t F1TS_trackId();
F1LIBRARY_EXPORTS uint8_t F1TS_formula();
F1LIBRARY_EXPORTS uint16_t F1TS_sessionTimeLeft();
F1LIBRARY_EXPORTS uint16_t F1TS_sessionDuration();
F1LIBRARY_EXPORTS uint8_t F1TS_pitSpeedLimit();
F1LIBRARY_EXPORTS uint8_t F1TS_gamePaused();
F1LIBRARY_EXPORTS uint8_t F1TS_isSpectating();
F1LIBRARY_EXPORTS uint8_t F1TS_spectatorCarIndex();
F1LIBRARY_EXPORTS uint8_t F1TS_sliProNativeSupport();
F1LIBRARY_EXPORTS uint8_t F1TS_numMarshalZones();

F1LIBRARY_EXPORTS float F1TS_marshalZoneStart(int8_t zone);
F1LIBRARY_EXPORTS int8_t F1TS_marshalZoneFlag(int8_t zone);

F1LIBRARY_EXPORTS uint8_t F1TS_safetyCarStatus();
F1LIBRARY_EXPORTS uint8_t F1TS_networkGame();

F1LIBRARY_EXPORTS uint8_t F1TS_numWeatherForecastSamples();
F1LIBRARY_EXPORTS uint8_t F1TS_weatherForecastSampleSessionType(int8_t sample);
F1LIBRARY_EXPORTS uint8_t F1TS_weatherForecastSampleTimeOffset(int8_t sample);
F1LIBRARY_EXPORTS uint8_t F1TS_weatherForecastSampleWeather(int8_t sample);
F1LIBRARY_EXPORTS int8_t F1TS_weatherForecastSampleTrackTemperature(int8_t sample);
F1LIBRARY_EXPORTS int8_t F1TS_weatherForecastSampleAirTemperature(int8_t sample);


//MOTION DATA
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

F1LIBRARY_EXPORTS float F1TS_suspensionPosition(int8_t tyre);
F1LIBRARY_EXPORTS float F1TS_suspensionVelocity(int8_t tyre);
F1LIBRARY_EXPORTS float F1TS_suspensionAcceleration(int8_t tyre);
F1LIBRARY_EXPORTS float F1TS_wheelSpeed(int8_t tyre);
F1LIBRARY_EXPORTS float F1TS_wheelSlip(int8_t tyre);
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


//EVENT DATA
F1LIBRARY_EXPORTS void F1TS_sessionStartedCallBack(void (*f)());
F1LIBRARY_EXPORTS void F1TS_sessionEndedCallBack(void (*f)());
F1LIBRARY_EXPORTS void F1TS_fastestLapCallBack(void (*f)());
F1LIBRARY_EXPORTS void F1TS_retirementCallBack(void (*f)());
F1LIBRARY_EXPORTS void F1TS_DRSenabledCallBack(void (*f)());
F1LIBRARY_EXPORTS void F1TS_DRSdisabledCallBack(void (*f)());
F1LIBRARY_EXPORTS void F1TS_teamMateInPitsCallBack(void (*f)());
F1LIBRARY_EXPORTS void F1TS_chequeredFlagCallBack(void (*f)());
F1LIBRARY_EXPORTS void F1TS_raceWinnerCallBack(void (*f)());
F1LIBRARY_EXPORTS void F1TS_penaltyIssuedCallBack(void (*f)());
F1LIBRARY_EXPORTS void F1TS_speedTrapTriggeredCallBack(void (*f)());


F1LIBRARY_EXPORTS uint8_t F1TS_fastestLapVehicleIdx();
F1LIBRARY_EXPORTS float F1TS_fastestLaplapTime();	
F1LIBRARY_EXPORTS uint8_t F1TS_retirementVehicleIdx();	
F1LIBRARY_EXPORTS uint8_t F1TS_teamMateInPitsVehicleIdx();
F1LIBRARY_EXPORTS uint8_t F1TS_raceWinnerVehicleIdx();
F1LIBRARY_EXPORTS uint8_t F1TS_penaltyType();
F1LIBRARY_EXPORTS uint8_t F1TS_penaltyInfrigimentType();
F1LIBRARY_EXPORTS uint8_t F1TS_penaltyVehicleIdx();
F1LIBRARY_EXPORTS uint8_t F1TS_penaltyOtherVehicleIdx();
F1LIBRARY_EXPORTS uint8_t F1TS_penaltyTime();
F1LIBRARY_EXPORTS uint8_t F1TS_penaltyLapNum();
F1LIBRARY_EXPORTS uint8_t F1TS_penaltyPlacesGained();
F1LIBRARY_EXPORTS uint8_t F1TS_speedTrapVehicleIdx();
F1LIBRARY_EXPORTS float F1TS_speedTrapSpeed();


//PARTICIPANTS DATA
F1LIBRARY_EXPORTS uint8_t F1TS_numActiveCars();

F1LIBRARY_EXPORTS uint8_t F1TS_aiControlled(uint8_t idx);
F1LIBRARY_EXPORTS uint8_t F1TS_driverId(uint8_t idx);
F1LIBRARY_EXPORTS uint8_t F1TS_teamId(uint8_t idx);
F1LIBRARY_EXPORTS uint8_t F1TS_raceNumber(uint8_t idx);
F1LIBRARY_EXPORTS uint8_t F1TS_nationality(uint8_t idx);
F1LIBRARY_EXPORTS void F1TS_name(uint8_t idx, char* n);
F1LIBRARY_EXPORTS uint8_t F1TS_yourTelemetry(uint8_t idx);


//CAR SETUPS DATA (Note that in multiplayer games, other player cars will appear as blank, you will only be able to see your car setup and AI cars)
F1LIBRARY_EXPORTS uint8_t F1TS_frontWing(int8_t carIdx);
F1LIBRARY_EXPORTS uint8_t F1TS_rearWing(int8_t carIdx);
F1LIBRARY_EXPORTS uint8_t F1TS_onThrottle(int8_t carIdx);
F1LIBRARY_EXPORTS uint8_t F1TS_offThrottle(int8_t carIdx);
F1LIBRARY_EXPORTS float F1TS_frontCamber(int8_t carIdx);
F1LIBRARY_EXPORTS float F1TS_rearCamber(int8_t carIdx);
F1LIBRARY_EXPORTS float F1TS_frontToe(int8_t carIdx);
F1LIBRARY_EXPORTS float F1TS_rearToe(int8_t carIdx);
F1LIBRARY_EXPORTS uint8_t F1TS_frontSuspension(int8_t carIdx);
F1LIBRARY_EXPORTS uint8_t F1TS_rearSuspension(int8_t carIdx);
F1LIBRARY_EXPORTS uint8_t F1TS_frontAntiRollBar(int8_t carIdx);
F1LIBRARY_EXPORTS uint8_t F1TS_rearAntiRollBar(int8_t carIdx);
F1LIBRARY_EXPORTS uint8_t F1TS_frontSuspensionHeight(int8_t carIdx);
F1LIBRARY_EXPORTS uint8_t F1TS_rearSuspensionHeight(int8_t carIdx);
F1LIBRARY_EXPORTS uint8_t F1TS_brakePressure(int8_t carIdx);
F1LIBRARY_EXPORTS uint8_t F1TS_brakeBias(int8_t carIdx);
F1LIBRARY_EXPORTS float F1TS_tyrePressure(int8_t carIdx, int8_t tyre);
F1LIBRARY_EXPORTS uint8_t F1TS_ballast(int8_t carIdx);
F1LIBRARY_EXPORTS float F1TS_fuelLoad(int8_t carIdx);



//CAR TELEMETRY DATA
F1LIBRARY_EXPORTS uint16_t F1TS_speed(int8_t carIdx);
F1LIBRARY_EXPORTS float F1TS_throttle(int8_t carIdx);
F1LIBRARY_EXPORTS float F1TS_steer(int8_t carIdx);
F1LIBRARY_EXPORTS float F1TS_brake(int8_t carIdx);
F1LIBRARY_EXPORTS uint8_t F1TS_clutch(int8_t carIdx);
F1LIBRARY_EXPORTS int8_t F1TS_gear(int8_t carIdx);
F1LIBRARY_EXPORTS uint16_t F1TS_engineRPM(int8_t carIdx);
F1LIBRARY_EXPORTS uint8_t F1TS_drs(int8_t carIdx);
F1LIBRARY_EXPORTS uint8_t F1TS_revLightsPercent(int8_t carIdx);
F1LIBRARY_EXPORTS uint16_t F1TS_brakesTemperature(int8_t carIdx, int8_t tyre);
F1LIBRARY_EXPORTS uint8_t F1TS_tyresSurfaceTemperature(int8_t carIdx, int8_t tyre);
F1LIBRARY_EXPORTS uint8_t F1TS_tyresInnerTemperature(int8_t carIdx, int8_t tyre);
F1LIBRARY_EXPORTS uint16_t F1TS_engineTemperature(int8_t carIdx);
F1LIBRARY_EXPORTS float F1TS_tyresPressure(int8_t carIdx, int8_t tyre);
F1LIBRARY_EXPORTS uint8_t F1TS_surfaceType(int8_t carIdx, int8_t tyre);

F1LIBRARY_EXPORTS uint32_t F1TS_buttonStatus();
F1LIBRARY_EXPORTS uint8_t F1TS_mfdPanelIndex();
F1LIBRARY_EXPORTS uint8_t F1TS_mfdPanelIndexSecondaryPlayer();
F1LIBRARY_EXPORTS int8_t F1TS_suggestedGear();


//CAR STATUS DATA
F1LIBRARY_EXPORTS uint8_t F1TS_tractionControl(int8_t carIdx);
F1LIBRARY_EXPORTS uint8_t F1TS_antiLockBrakes(int8_t carIdx);
F1LIBRARY_EXPORTS uint8_t F1TS_fuelMix(int8_t carIdx) ;
F1LIBRARY_EXPORTS uint8_t F1TS_frontBrakeBias(int8_t carIdx) ;
F1LIBRARY_EXPORTS uint8_t F1TS_pitLimiterStatus(int8_t carIdx) ;
F1LIBRARY_EXPORTS float F1TS_fuelInTank(int8_t carIdx);
F1LIBRARY_EXPORTS float F1TS_fuelCapacity(int8_t carIdx);
F1LIBRARY_EXPORTS float F1TS_fuelRemainingLaps(int8_t carIdx) ;
F1LIBRARY_EXPORTS uint16_t F1TS_maxRPM(int8_t carIdx);
F1LIBRARY_EXPORTS uint16_t F1TS_idleRPM(int8_t carIdx) ;
F1LIBRARY_EXPORTS uint8_t F1TS_maxGears(int8_t carIdx) ;
F1LIBRARY_EXPORTS uint8_t F1TS_drsAllowed(int8_t carIdx) ;
F1LIBRARY_EXPORTS uint16_t F1TS_drsActivationDistance(int8_t carIdx) ;
F1LIBRARY_EXPORTS uint8_t F1TS_tyresWear(int8_t carIdx, int8_t tyre);
F1LIBRARY_EXPORTS uint8_t F1TS_actualTyreCompound(int8_t carIdx) ;
F1LIBRARY_EXPORTS uint8_t F1TS_visualTyreCompound(int8_t carIdx) ;
F1LIBRARY_EXPORTS uint8_t F1TS_tyresAgeLaps(int8_t carIdx);
F1LIBRARY_EXPORTS uint8_t F1TS_tyresDamage(int8_t carIdx, int8_t tyre);
F1LIBRARY_EXPORTS uint8_t F1TS_frontLeftWingDamage(int8_t carIdx);
F1LIBRARY_EXPORTS uint8_t F1TS_frontRightWingDamage(int8_t carIdx) ;
F1LIBRARY_EXPORTS uint8_t F1TS_rearWingDamage(int8_t carIdx);
F1LIBRARY_EXPORTS uint8_t F1TS_drsFault(int8_t carIdx);
F1LIBRARY_EXPORTS uint8_t F1TS_gearBoxDamage(int8_t carIdx);
F1LIBRARY_EXPORTS float F1TS_ersStoreEnergy(int8_t carIdx);
F1LIBRARY_EXPORTS uint8_t F1TS_ersDeployMode(int8_t carIdx) ;
F1LIBRARY_EXPORTS float F1TS_ersHarvestedThisLapMGUK(int8_t carIdx) ;
F1LIBRARY_EXPORTS float F1TS_ersHarvestedThisLapMGUH(int8_t carIdx);
F1LIBRARY_EXPORTS float F1TS_ersDeployedThisLap(int8_t carIdx);


//FINAL CLASSIFICATION DATA
F1LIBRARY_EXPORTS uint8_t F1TS_numCarsFinished();
F1LIBRARY_EXPORTS uint8_t F1TS_finalPosition(int8_t carIdx);
F1LIBRARY_EXPORTS uint8_t F1TS_finalNumLaps(int8_t carIdx);
F1LIBRARY_EXPORTS uint8_t F1TS_finalGridPosition(int8_t carIdx);
F1LIBRARY_EXPORTS uint8_t F1TS_finalPoints(int8_t carIdx);
F1LIBRARY_EXPORTS uint8_t F1TS_finalNumPitStops(int8_t carIdx);
F1LIBRARY_EXPORTS uint8_t F1TS_finalResultStatus(int8_t carIdx);
F1LIBRARY_EXPORTS float  F1TS_finalBestLapTime(int8_t carIdx);
F1LIBRARY_EXPORTS double F1TS_finalTotalRaceTime(int8_t carIdx);
F1LIBRARY_EXPORTS uint8_t F1TS_finalPenaltiesTime(int8_t carIdx);
F1LIBRARY_EXPORTS uint8_t F1TS_finalNumPenalties(int8_t carIdx);
F1LIBRARY_EXPORTS uint8_t F1TS_finalNumTyreStints(int8_t carIdx);
F1LIBRARY_EXPORTS uint8_t F1TS_finalTyreStintsActual(int8_t carIdx, int8_t stintIdx);
F1LIBRARY_EXPORTS uint8_t F1TS_finalTyreStintsVisual(int8_t carIdx, int8_t stintIdx);


//LOBBY INFO DATA
F1LIBRARY_EXPORTS uint8_t F1TS_lobbyNumPlayers();
F1LIBRARY_EXPORTS uint8_t F1TS_lobbyAiControlled(int8_t playerIdx);
F1LIBRARY_EXPORTS uint8_t F1TS_lobbyTeamId(int8_t playerIdx);
F1LIBRARY_EXPORTS uint8_t F1TS_lobbyNationality(int8_t playerIdx);
F1LIBRARY_EXPORTS void F1TS_lobbyName(int8_t playerIdx, char* n);
F1LIBRARY_EXPORTS uint8_t F1TS_lobbyReadyStatus(int8_t playerIdx);