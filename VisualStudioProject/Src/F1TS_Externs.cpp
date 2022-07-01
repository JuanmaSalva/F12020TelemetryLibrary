#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include "F1TS_Externs.h"
#include "TelemetryF1.h"



void F1TS_startF1Telemetry()
{
	isReady_ = false;
	telemetry = new TelemetryF1();
	if (telemetry->open_socket() == false) {
		std::cout << "Sometihng went wrong\n";
		return;
	}
	isReady_ = true;
	telemetry->start();
}

void F1TS_closeF1Telemetry()
{
	telemetry->end();
	
	while (!telemetry->hasEnded())
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
		//std::cout << "Waiting for telemetry to end\n";
	
	if(t.joinable())
		t.join();
	delete telemetry;
	isClosed_ = true;
}

bool F1TS_isReady()
{
	return isReady_;
}

bool F1TS_isClosed()
{
	return isClosed_;
}

void F1TS_startF1TelemetryThread()
{
	t = std::thread(F1TS_startF1Telemetry);
	while (!F1TS_isReady())
	{
		std::cout << "Waiting for the socket to open" << std::endl;
	}
	std::cout << "Socket opened" << std::endl;
}

uint8_t F1TS_playerCarIndex()
{
	return telemetry->packet_manager()->playerCarIndex();
}

void F1TS_packetSizes()
{
	std::cout << (sizeof(uint16_t) + sizeof(uint8_t) * 6 + sizeof(uint64_t) + sizeof(float) + sizeof(uint32_t)) << std::endl;
	std::cout << "PacketHeader: " << sizeof(PacketHeader) << std::endl;
	std::cout << "PacketCarTelemetryData: " << sizeof(PacketCarTelemetryData) << std::endl;
	std::cout << "Header + PacketCarTelemetryData: " << (sizeof(PacketCarTelemetryData) + sizeof(PacketHeader)) << std::endl;
}

float F1TS_lastTimeLap(int8_t carId)
{
	return telemetry->packet_manager()->lap_data()->lastTimeLap(carId);
}


float F1TS_currentLapTime(int8_t id)
{
	return telemetry->packet_manager()->lap_data()->currentLapTime(id);
}

uint16_t F1TS_sector1(int8_t carId)
{
	return telemetry->packet_manager()->lap_data()->sector1(carId);
}

uint16_t F1TS_sector2(int8_t carId)
{
	return telemetry->packet_manager()->lap_data()->sector2(carId);
}

float F1TS_bestLapTime(int8_t carId)
{
	return telemetry->packet_manager()->lap_data()->bestLapTime(carId);
}

uint8_t F1TS_bestLapNum(int8_t carId)
{
	return telemetry->packet_manager()->lap_data()->bestLapNum(carId);
}

uint16_t F1TS_bestLapSector1TimeInMS(int8_t carId)
{
	return telemetry->packet_manager()->lap_data()->bestLapSector1TimeInMS(carId);
}

uint16_t F1TS_bestLapSector2TimeInMS(int8_t carId)
{
	return telemetry->packet_manager()->lap_data()->bestLapSector2TimeInMS(carId);
}

uint16_t F1TS_bestLapSector3TimeInMS(int8_t carId)
{
	return telemetry->packet_manager()->lap_data()->bestLapSector3TimeInMS(carId);
}

uint16_t F1TS_bestOverallSector1TimeInMS(int8_t carId)
{
	return telemetry->packet_manager()->lap_data()->bestOverallSector1TimeInMS(carId);
}

uint8_t F1TS_bestOverallSector1LapNum(int8_t carId)
{
	return telemetry->packet_manager()->lap_data()->bestOverallSector1LapNum(carId);
}

uint16_t F1TS_bestOverallSector2TimeInMS(int8_t carId)
{
	return telemetry->packet_manager()->lap_data()->bestOverallSector2TimeInMS(carId);
}

uint8_t F1TS_bestOverallSector2LapNum(int8_t carId)
{
	return telemetry->packet_manager()->lap_data()->bestOverallSector2LapNum(carId);
}

uint16_t F1TS_bestOverallSector3TimeInMS(int8_t carId)
{
	return telemetry->packet_manager()->lap_data()->bestOverallSector3TimeInMS(carId);
}

uint8_t F1TS_bestOverallSector3LapNum(int8_t carId)
{
	return telemetry->packet_manager()->lap_data()->bestOverallSector3LapNum(carId);
}

float F1TS_lapDistance(int8_t carId)
{
	return telemetry->packet_manager()->lap_data()->lapDistance(carId);
}

float F1TS_totalDistance(int8_t carId)
{
	return telemetry->packet_manager()->lap_data()->totalDistance(carId);
}

float F1TS_safetyCarDelta(int8_t carId)
{
	return telemetry->packet_manager()->lap_data()->safetyCarDelta(carId);
}

uint8_t F1TS_carPosition(int8_t carId)
{
	return telemetry->packet_manager()->lap_data()->carPosition(carId);
}

uint8_t F1TS_currentLapNum(int8_t carId)
{
	return telemetry->packet_manager()->lap_data()->currentLapNum(carId);
}

uint8_t F1TS_pitStatus(int8_t carId)
{
	return telemetry->packet_manager()->lap_data()->pitStatus(carId);
}

uint8_t F1TS_sector(int8_t carId)
{
	return telemetry->packet_manager()->lap_data()->sector(carId);
}

uint8_t F1TS_currentLapInvalid(int8_t carId)
{
	return telemetry->packet_manager()->lap_data()->currentLapInvalid(carId);
}

uint8_t F1TS_penalties(int8_t carId)
{
	return telemetry->packet_manager()->lap_data()->penalties(carId);
}

uint8_t F1TS_gridPosition(int8_t carId)
{
	return telemetry->packet_manager()->lap_data()->gridPosition(carId);
}

uint8_t F1TS_driverStatus(int8_t carId)
{
	return telemetry->packet_manager()->lap_data()->driverStatus(carId);
}

uint8_t F1TS_resultStatus(int8_t carId)
{
	return telemetry->packet_manager()->lap_data()->resultStatus(carId);
}

uint8_t F1TS_weather()
{
	return telemetry->packet_manager()->session_data()->weather();
}

int8_t F1TS_trackTemperature()
{
	return telemetry->packet_manager()->session_data()->trackTemperature();
}

int8_t F1TS_airTemperature()
{
	return telemetry->packet_manager()->session_data()->airTemperature();
}

uint8_t F1TS_totalLaps()
{
	return telemetry->packet_manager()->session_data()->totalLaps();
}

uint16_t F1TS_trackLength()
{
	return telemetry->packet_manager()->session_data()->trackLength();
}

uint8_t F1TS_sessionType()
{
	return telemetry->packet_manager()->session_data()->sessionType();
}

int8_t F1TS_trackId()
{
	return telemetry->packet_manager()->session_data()->trackId();
}

uint8_t F1TS_formula()
{
	return telemetry->packet_manager()->session_data()->formula();
}

uint16_t F1TS_sessionTimeLeft()
{
	return telemetry->packet_manager()->session_data()->sessionTimeLeft();
}

uint16_t F1TS_sessionDuration()
{
	return telemetry->packet_manager()->session_data()->sessionDuration();
}

uint8_t F1TS_pitSpeedLimit()
{
	return telemetry->packet_manager()->session_data()->pitSpeedLimit();
}

uint8_t F1TS_gamePaused()
{
	return telemetry->packet_manager()->session_data()->gamePaused();
}

uint8_t F1TS_isSpectating()
{
	return telemetry->packet_manager()->session_data()->isSpectating();
}

uint8_t F1TS_spectatorCarIndex()
{
	return telemetry->packet_manager()->session_data()->spectatorCarIndex();
}

uint8_t F1TS_sliProNativeSupport()
{
	return telemetry->packet_manager()->session_data()->sliProNativeSupport();
}

uint8_t F1TS_numMarshalZones()
{
	return telemetry->packet_manager()->session_data()->numMarshalZones();
}

float F1TS_marshalZoneStart(int8_t zone)
{
	return telemetry->packet_manager()->session_data()->marshalZoneStart(zone);
}

int8_t F1TS_marshalZoneFlag(int8_t zone)
{
	return telemetry->packet_manager()->session_data()->marshalZoneFlag(zone);
}

uint8_t F1TS_safetyCarStatus()
{
	return telemetry->packet_manager()->session_data()->safetyCarStatus();
}

uint8_t F1TS_networkGame()
{
	return telemetry->packet_manager()->session_data()->networkGame();
}

uint8_t F1TS_numWeatherForecastSamples()
{
	return telemetry->packet_manager()->session_data()->numWeatherForecastSamples();
}

uint8_t F1TS_weatherForecastSampleSessionType(int8_t sample)
{
	return telemetry->packet_manager()->session_data()->weatherForecastSessionType(sample);
}

uint8_t F1TS_weatherForecastSampleTimeOffset(int8_t sample)
{
	return telemetry->packet_manager()->session_data()->weatherForecastTimeOffset(sample);
}

uint8_t F1TS_weatherForecastSampleWeather(int8_t sample)
{
	return telemetry->packet_manager()->session_data()->weatherForecastWeather(sample);
}

int8_t F1TS_weatherForecastSampleTrackTemperature(int8_t sample)
{
	return telemetry->packet_manager()->session_data()->weatherForecastTrackTemperature(sample);
}

int8_t F1TS_weatherForecastSampleAirTemperature(int8_t sample)
{
	return telemetry->packet_manager()->session_data()->weatherForecastAirTemperature(sample);
}

float F1TS_worldPositionX(int8_t carId)
{
	return telemetry->packet_manager()->motion_data()->worldPositionX(carId);
}

float F1TS_worldPositionY(int8_t carId)
{
	return telemetry->packet_manager()->motion_data()->worldPositionY(carId);
}

float F1TS_worldPositionZ(int8_t carId)
{
	return telemetry->packet_manager()->motion_data()->worldPositionZ(carId);
}

float F1TS_worldVelocityX(int8_t carId)
{
	return telemetry->packet_manager()->motion_data()->worldVelocityX(carId);
}

float F1TS_worldVelocityY(int8_t carId)
{
	return telemetry->packet_manager()->motion_data()->worldVelocityX(carId);
}

float F1TS_worldVelocityZ(int8_t carId)
{
	return telemetry->packet_manager()->motion_data()->worldVelocityZ(carId);
}

int16_t F1TS_worldForwardDirX(int8_t carId)
{
	return telemetry->packet_manager()->motion_data()->worldForwardDirX(carId);
}

int16_t F1TS_worldForwardDirY(int8_t carId)
{
	return telemetry->packet_manager()->motion_data()->worldForwardDirY(carId);
}

int16_t F1TS_worldForwardDirZ(int8_t carId)
{
	return telemetry->packet_manager()->motion_data()->worldForwardDirZ(carId);
}

int16_t F1TS_worldRightDirX(int8_t carId)
{
	return telemetry->packet_manager()->motion_data()->worldRightDirX(carId);
}

int16_t F1TS_worldRightDirY(int8_t carId)
{
	return telemetry->packet_manager()->motion_data()->worldRightDirY(carId);
}

int16_t F1TS_worldRightDirZ(int8_t carId)
{
	return telemetry->packet_manager()->motion_data()->worldRightDirZ(carId);
}

float F1TS_gForceLateral(int8_t carId)
{
	return telemetry->packet_manager()->motion_data()->gForceLateral(carId);
}

float F1TS_gForceLongitudinal(int8_t carId)
{
	return telemetry->packet_manager()->motion_data()->gForceLongitudinal(carId);
}

float F1TS_gForceVertical(int8_t carId)
{
	return telemetry->packet_manager()->motion_data()->gForceVertical(carId);
}

float F1TS_yaw(int8_t carId)
{
	return telemetry->packet_manager()->motion_data()->yaw(carId);
}

float F1TS_pitch(int8_t carId)
{
	return telemetry->packet_manager()->motion_data()->pitch(carId);
}

float F1TS_roll(int8_t carId)
{
	return telemetry->packet_manager()->motion_data()->roll(carId);
}

float F1TS_suspensionPosition(int8_t tyre)
{
	return telemetry->packet_manager()->motion_data()->suspensionPosition(tyre);
}

float F1TS_suspensionVelocity(int8_t tyre)
{
	return telemetry->packet_manager()->motion_data()->suspensionVelocity(tyre);
}

float F1TS_suspensionAcceleration(int8_t tyre)
{
	return telemetry->packet_manager()->motion_data()->suspensionAcceleration(tyre);
}

float F1TS_wheelSpeed(int8_t tyre)
{
	return telemetry->packet_manager()->motion_data()->wheelSpeed(tyre);
}

float F1TS_wheelSlip(int8_t tyre)
{
	return telemetry->packet_manager()->motion_data()->wheelSlip(tyre);
}

float F1TS_localVelocityX()
{
	return telemetry->packet_manager()->motion_data()->localVelocityX();
}

float F1TS_localVelocityY()
{
	return telemetry->packet_manager()->motion_data()->localVelocityY();
}

float F1TS_localVelocityZ()
{
	return telemetry->packet_manager()->motion_data()->localVelocityZ();
}

float F1TS_angularVelocityX()
{
	return telemetry->packet_manager()->motion_data()->angularVelocityX();
}

float F1TS_angularVelocityY()
{
	return telemetry->packet_manager()->motion_data()->angularVelocityY();
}

float F1TS_angularVelocityZ()
{
	return telemetry->packet_manager()->motion_data()->angularVelocityZ();
}

float F1TS_angularAccelerationX()
{
	return telemetry->packet_manager()->motion_data()->angularAccelerationX();
}

float F1TS_angularAccelerationY()
{
	return telemetry->packet_manager()->motion_data()->angularAccelerationY();
}

float F1TS_angularAccelerationZ()
{
	return telemetry->packet_manager()->motion_data()->angularAccelerationZ();
}

float F1TS_frontWheelsAngle()
{
	return telemetry->packet_manager()->motion_data()->frontWheelsAngle();
}


void F1TS_sessionStartedCallBack(void(*f)())
{
	telemetry->packet_manager()->event_data()->sessionStartedCallBack(f);
}


void(*bro)();

void F1TS_sessionEndedCallBack(void(*f)())
{
	telemetry->packet_manager()->event_data()->sessionEndedCallBack(f);
}

void F1TS_fastestLapCallBack(void(*f)())
{
	telemetry->packet_manager()->event_data()->fastestLapCallBack(f);
}

void F1TS_retirementCallBack(void(*f)())
{
	telemetry->packet_manager()->event_data()->retirementCallBack(f);
}

void F1TS_DRSenabledCallBack(void(*f)())
{
	telemetry->packet_manager()->event_data()->DRSenabledCallBack(f);
}

void F1TS_DRSdisabledCallBack(void(*f)())
{
	telemetry->packet_manager()->event_data()->DRSdisabledCallBack(f);
}

void F1TS_teamMateInPitsCallBack(void(*f)())
{
	telemetry->packet_manager()->event_data()->teamMateInPitsCallBack(f);
}

void F1TS_chequeredFlagCallBack(void(*f)())
{
	telemetry->packet_manager()->event_data()->chequeredFlagCallBack(f);
}

void F1TS_raceWinnerCallBack(void(*f)())
{
	telemetry->packet_manager()->event_data()->raceWinnerCallBack(f);
}

void F1TS_penaltyIssuedCallBack(void(*f)())
{
	telemetry->packet_manager()->event_data()->penaltyIssuedCallBack(f);
}

void F1TS_speedTrapTriggeredCallBack(void(*f)())
{
	telemetry->packet_manager()->event_data()->speedTrapTriggeredCallBack(f);
}

int8_t F1TS_lastEventReceived()
{
	return telemetry->packet_manager()->event_data()->lastEventReceived();
}

uint8_t F1TS_fastestLapVehicleIdx()
{
	return telemetry->packet_manager()->event_data()->fastestLapVehicleIdx();
}

float F1TS_fastestLaplapTime()
{
	return telemetry->packet_manager()->event_data()->fastestLaplapTime();
}

uint8_t F1TS_retirementVehicleIdx()
{
	return telemetry->packet_manager()->event_data()->retirementVehicleIdx();
}

uint8_t F1TS_teamMateInPitsVehicleIdx()
{
	return telemetry->packet_manager()->event_data()->teamMateInPitsVehicleIdx();
}

uint8_t F1TS_raceWinnerVehicleIdx()
{
	return telemetry->packet_manager()->event_data()->raceWinnerVehicleIdx();
}

uint8_t F1TS_penaltyType()
{
	return telemetry->packet_manager()->event_data()->penaltyType();
}

uint8_t F1TS_penaltyInfrigimentType()
{
	return telemetry->packet_manager()->event_data()->penaltyInfrigimentType();
}

uint8_t F1TS_penaltyVehicleIdx()
{
	return telemetry->packet_manager()->event_data()->penaltyVehicleIdx();
}

uint8_t F1TS_penaltyOtherVehicleIdx()
{
	return telemetry->packet_manager()->event_data()->penaltyOtherVehicleIdx();
}

uint8_t F1TS_penaltyTime()
{
	return telemetry->packet_manager()->event_data()->penaltyTime();
}

uint8_t F1TS_penaltyLapNum()
{
	return telemetry->packet_manager()->event_data()->penaltyLapNum();
}

uint8_t F1TS_penaltyPlacesGained()
{
	return telemetry->packet_manager()->event_data()->penaltyPlacesGained();
}

uint8_t F1TS_speedTrapVehicleIdx()
{
	return telemetry->packet_manager()->event_data()->speedTrapVehicleIdx();
}

float F1TS_speedTrapSpeed()
{
	return telemetry->packet_manager()->event_data()->speedTrapSpeed();
}

uint8_t F1TS_numActiveCars()
{
	return telemetry->packet_manager()->participants_data()->numActiveCars();
}

uint8_t F1TS_aiControlled(uint8_t idx)
{
	return telemetry->packet_manager()->participants_data()->aiControlled(idx);
}

uint8_t F1TS_driverId(uint8_t idx)
{
	return telemetry->packet_manager()->participants_data()->driverId(idx);
}

uint8_t F1TS_teamId(uint8_t idx)
{
	return telemetry->packet_manager()->participants_data()->teamId(idx);
}

uint8_t F1TS_raceNumber(uint8_t idx)
{
	return telemetry->packet_manager()->participants_data()->raceNumber(idx);
}

uint8_t F1TS_nationality(uint8_t idx)
{
	return telemetry->packet_manager()->participants_data()->nationality(idx);
}

void F1TS_name(uint8_t idx, char n[])
{
	return telemetry->packet_manager()->participants_data()->name(idx, n);
}

uint8_t F1TS_yourTelemetry(uint8_t idx)
{
	return telemetry->packet_manager()->participants_data()->yourTelemetry(idx);
}

uint8_t F1TS_frontWing(int8_t carIdx)
{
	return telemetry->packet_manager()->car_setup_data()->frontWing(carIdx);
}

uint8_t F1TS_rearWing(int8_t carIdx)
{
	return telemetry->packet_manager()->car_setup_data()->rearWing(carIdx);
}

uint8_t F1TS_onThrottle(int8_t carIdx)
{
	return telemetry->packet_manager()->car_setup_data()->onThrottle(carIdx);
}

uint8_t F1TS_offThrottle(int8_t carIdx)
{
	return telemetry->packet_manager()->car_setup_data()->offThrottle(carIdx);
}

float F1TS_frontCamber(int8_t carIdx)
{
	return telemetry->packet_manager()->car_setup_data()->frontCamber(carIdx);
}

float F1TS_rearCamber(int8_t carIdx)
{
	return telemetry->packet_manager()->car_setup_data()->rearCamber(carIdx);
}

float F1TS_frontToe(int8_t carIdx)
{
	return telemetry->packet_manager()->car_setup_data()->frontToe(carIdx);
}

float F1TS_rearToe(int8_t carIdx)
{
	return telemetry->packet_manager()->car_setup_data()->rearToe(carIdx);
}

uint8_t F1TS_frontSuspension(int8_t carIdx)
{
	return telemetry->packet_manager()->car_setup_data()->frontSuspension(carIdx);
}

uint8_t F1TS_rearSuspension(int8_t carIdx)
{
	return telemetry->packet_manager()->car_setup_data()->rearSuspension(carIdx);
}

uint8_t F1TS_frontAntiRollBar(int8_t carIdx)
{
	return telemetry->packet_manager()->car_setup_data()->frontAntiRollBar(carIdx);
}

uint8_t F1TS_rearAntiRollBar(int8_t carIdx)
{
	return telemetry->packet_manager()->car_setup_data()->rearAntiRollBar(carIdx);
}

uint8_t F1TS_frontSuspensionHeight(int8_t carIdx)
{
	return telemetry->packet_manager()->car_setup_data()->frontSuspensionHeight(carIdx);
}

uint8_t F1TS_rearSuspensionHeight(int8_t carIdx)
{
	return telemetry->packet_manager()->car_setup_data()->rearSuspensionHeight(carIdx);
}

uint8_t F1TS_brakePressure(int8_t carIdx)
{
	return telemetry->packet_manager()->car_setup_data()->brakePressure(carIdx);
}

uint8_t F1TS_brakeBias(int8_t carIdx)
{
	return telemetry->packet_manager()->car_setup_data()->brakeBias(carIdx);
}

float F1TS_tyrePressure(int8_t carIdx, int8_t tyre)
{
	switch (tyre) {
	case 0:return telemetry->packet_manager()->car_setup_data()->rearLeftTyrePressure(carIdx);
	case 1:return telemetry->packet_manager()->car_setup_data()->rearRightTyrePressure(carIdx);
	case 2:return telemetry->packet_manager()->car_setup_data()->frontLeftTyrePressure(carIdx);
	case 3:return telemetry->packet_manager()->car_setup_data()->frontRightTyrePressure(carIdx);
	}
	return telemetry->packet_manager()->car_setup_data()->rearLeftTyrePressure(carIdx);
}

uint8_t F1TS_ballast(int8_t carIdx)
{
	return telemetry->packet_manager()->car_setup_data()->ballast(carIdx);
}

float F1TS_fuelLoad(int8_t carIdx)
{
	return telemetry->packet_manager()->car_setup_data()->fuelLoad(carIdx);
}

uint16_t F1TS_speed(int8_t carIdx)
{
	return telemetry->packet_manager()->car_telemetry_data()->speed(carIdx);
}

float F1TS_throttle(int8_t carIdx)
{
	return telemetry->packet_manager()->car_telemetry_data()->throttle(carIdx);
}

float F1TS_steer(int8_t carIdx)
{
	return telemetry->packet_manager()->car_telemetry_data()->steer(carIdx);
}

float F1TS_brake(int8_t carIdx)
{
	return telemetry->packet_manager()->car_telemetry_data()->brake(carIdx);
}

uint8_t F1TS_clutch(int8_t carIdx)
{
	return telemetry->packet_manager()->car_telemetry_data()->clutch(carIdx);
}

int8_t F1TS_gear(int8_t carIdx)
{
	return telemetry->packet_manager()->car_telemetry_data()->gear(carIdx);
}

uint16_t F1TS_engineRPM(int8_t carIdx)
{
	return telemetry->packet_manager()->car_telemetry_data()->engineRPM(carIdx);
}

uint8_t F1TS_drs(int8_t carIdx)
{
	return telemetry->packet_manager()->car_telemetry_data()->drs(carIdx);
}

uint8_t F1TS_revLightsPercent(int8_t carIdx)
{
	return telemetry->packet_manager()->car_telemetry_data()->revLightsPercent(carIdx);
}

uint16_t F1TS_brakesTemperature(int8_t carIdx, int8_t tyre)
{
	return telemetry->packet_manager()->car_telemetry_data()->brakesTemperature(carIdx, tyre);
}

uint8_t F1TS_tyresSurfaceTemperature(int8_t carIdx, int8_t tyre)
{
	return telemetry->packet_manager()->car_telemetry_data()->tyresSurfaceTemperature(carIdx, tyre);
}

uint8_t F1TS_tyresInnerTemperature(int8_t carIdx, int8_t tyre)
{
	return telemetry->packet_manager()->car_telemetry_data()->tyresInnerTemperature(carIdx, tyre);
}

uint16_t F1TS_engineTemperature(int8_t carIdx)
{
	return telemetry->packet_manager()->car_telemetry_data()->engineTemperature(carIdx);
}

float F1TS_tyresPressure(int8_t carIdx, int8_t tyre)
{
	return telemetry->packet_manager()->car_telemetry_data()->tyresPressure(carIdx, tyre);
}

uint8_t F1TS_surfaceType(int8_t carIdx, int8_t tyre)
{
	return telemetry->packet_manager()->car_telemetry_data()->surfaceType(carIdx, tyre);
}

uint32_t F1TS_buttonStatus()
{
	return telemetry->packet_manager()->car_telemetry_data()->buttonStatus();
}

uint8_t F1TS_mfdPanelIndex()
{
	return telemetry->packet_manager()->car_telemetry_data()->mfdPanelIndex();
}

uint8_t F1TS_mfdPanelIndexSecondaryPlayer()
{
	return telemetry->packet_manager()->car_telemetry_data()->mfdPanelIndexSecondaryPlayer();
}

int8_t F1TS_suggestedGear()
{
	return telemetry->packet_manager()->car_telemetry_data()->suggestedGear();
}

uint8_t F1TS_tractionControl(int8_t carIdx)
{
	return telemetry->packet_manager()->car_status_data()->tractionControl(carIdx);
}

uint8_t F1TS_antiLockBrakes(int8_t carIdx)
{
	return telemetry->packet_manager()->car_status_data()->antiLockBrakes(carIdx);
}

uint8_t F1TS_fuelMix(int8_t carIdx)
{
	return telemetry->packet_manager()->car_status_data()->fuelMix(carIdx);
}

uint8_t F1TS_frontBrakeBias(int8_t carIdx)
{
	return telemetry->packet_manager()->car_status_data()->frontBrakeBias(carIdx);
}

uint8_t F1TS_pitLimiterStatus(int8_t carIdx)
{
	return telemetry->packet_manager()->car_status_data()->pitLimiterStatus(carIdx);
}

float F1TS_fuelInTank(int8_t carIdx)
{
	return telemetry->packet_manager()->car_status_data()->fuelInTank(carIdx);
}

float F1TS_fuelCapacity(int8_t carIdx)
{
	return telemetry->packet_manager()->car_status_data()->fuelCapacity(carIdx);
}

float F1TS_fuelRemainingLaps(int8_t carIdx)
{
	return telemetry->packet_manager()->car_status_data()->fuelRemainingLaps(carIdx);
}

uint16_t F1TS_maxRPM(int8_t carIdx)
{
	return telemetry->packet_manager()->car_status_data()->maxRPM(carIdx);
}

uint16_t F1TS_idleRPM(int8_t carIdx)
{
	return telemetry->packet_manager()->car_status_data()->idleRPM(carIdx);
}

uint8_t F1TS_maxGears(int8_t carIdx)
{
	return telemetry->packet_manager()->car_status_data()->maxGears(carIdx);
}

uint8_t F1TS_drsAllowed(int8_t carIdx)
{
	return telemetry->packet_manager()->car_status_data()->drsAllowed(carIdx);
}

uint16_t F1TS_drsActivationDistance(int8_t carIdx)
{
	return telemetry->packet_manager()->car_status_data()->drsActivationDistance(carIdx);
}

uint8_t F1TS_tyresWear(int8_t carIdx, int8_t tyre)
{
	return telemetry->packet_manager()->car_status_data()->tyresWear(carIdx, tyre);
}

uint8_t F1TS_actualTyreCompound(int8_t carIdx)
{
	return telemetry->packet_manager()->car_status_data()->actualTyreCompound(carIdx);
}

uint8_t F1TS_visualTyreCompound(int8_t carIdx)
{
	return telemetry->packet_manager()->car_status_data()->visualTyreCompound(carIdx);
}

uint8_t F1TS_tyresAgeLaps(int8_t carIdx)
{
	return telemetry->packet_manager()->car_status_data()->tyresAgeLaps(carIdx);
}

uint8_t F1TS_tyresDamage(int8_t carIdx, int8_t tyre)
{
	return telemetry->packet_manager()->car_status_data()->tyresDamage(carIdx, tyre);
}

uint8_t F1TS_frontLeftWingDamage(int8_t carIdx)
{
	return telemetry->packet_manager()->car_status_data()->frontLeftWingDamage(carIdx);
}

uint8_t F1TS_frontRightWingDamage(int8_t carIdx)
{
	return telemetry->packet_manager()->car_status_data()->frontRightWingDamage(carIdx);
}

uint8_t F1TS_rearWingDamage(int8_t carIdx)
{
	return telemetry->packet_manager()->car_status_data()->rearWingDamage(carIdx);
}

uint8_t F1TS_drsFault(int8_t carIdx)
{
	return telemetry->packet_manager()->car_status_data()->drsFault(carIdx);
}

uint8_t F1TS_engineDamage(int8_t carIdx)
{
	return telemetry->packet_manager()->car_status_data()->engineDamage(carIdx);
}

uint8_t F1TS_gearBoxDamage(int8_t carIdx)
{
	return telemetry->packet_manager()->car_status_data()->gearBoxDamage(carIdx);
}

float F1TS_ersStoreEnergy(int8_t carIdx)
{
	return telemetry->packet_manager()->car_status_data()->ersStoreEnergy(carIdx);
}

uint8_t F1TS_ersDeployMode(int8_t carIdx)
{
	return telemetry->packet_manager()->car_status_data()->ersDeployMode(carIdx);
}

float F1TS_ersHarvestedThisLapMGUK(int8_t carIdx)
{
	return telemetry->packet_manager()->car_status_data()->ersHarvestedThisLapMGUK(carIdx);
}

float F1TS_ersHarvestedThisLapMGUH(int8_t carIdx)
{
	return telemetry->packet_manager()->car_status_data()->ersHarvestedThisLapMGUH(carIdx);
}

float F1TS_ersDeployedThisLap(int8_t carIdx)
{
	return telemetry->packet_manager()->car_status_data()->ersDeployedThisLap(carIdx);
}

uint8_t F1TS_numCarsFinished()
{
	return telemetry->packet_manager()->final_classification_data()->numCarsFinished();
}

uint8_t F1TS_finalPosition(int8_t carIdx)
{
	return telemetry->packet_manager()->final_classification_data()->position(carIdx);
}

uint8_t F1TS_finalNumLaps(int8_t carIdx)
{
	return telemetry->packet_manager()->final_classification_data()->numLaps(carIdx);
}

uint8_t F1TS_finalGridPosition(int8_t carIdx)
{
	return telemetry->packet_manager()->final_classification_data()->gridPosition(carIdx);
}

uint8_t F1TS_finalPoints(int8_t carIdx)
{
	return telemetry->packet_manager()->final_classification_data()->points(carIdx);
}

uint8_t F1TS_finalNumPitStops(int8_t carIdx)
{
	return telemetry->packet_manager()->final_classification_data()->numPitStops(carIdx);
}

uint8_t F1TS_finalResultStatus(int8_t carIdx)
{
	return telemetry->packet_manager()->final_classification_data()->resultStatus(carIdx);
}

float F1TS_finalBestLapTime(int8_t carIdx)
{
	return telemetry->packet_manager()->final_classification_data()->bestLapTime(carIdx);
}

double F1TS_finalTotalRaceTime(int8_t carIdx)
{
	return telemetry->packet_manager()->final_classification_data()->totalRaceTime(carIdx);
}

uint8_t F1TS_finalPenaltiesTime(int8_t carIdx)
{
	return telemetry->packet_manager()->final_classification_data()->penaltiesTime(carIdx);
}

uint8_t F1TS_finalNumPenalties(int8_t carIdx)
{
	return telemetry->packet_manager()->final_classification_data()->numPenalties(carIdx);
}

uint8_t F1TS_finalNumTyreStints(int8_t carIdx)
{
	return telemetry->packet_manager()->final_classification_data()->numTyreStints(carIdx);
}

uint8_t F1TS_finalTyreStintsActual(int8_t carIdx, int8_t stintIdx)
{
	return telemetry->packet_manager()->final_classification_data()->tyreStintsActual(carIdx, stintIdx);
}

uint8_t F1TS_finalTyreStintsVisual(int8_t carIdx, int8_t stintIdx)
{
	return telemetry->packet_manager()->final_classification_data()->tyreStintsVisual(carIdx, stintIdx);
}

uint8_t F1TS_lobbyNumPlayers()
{
	return telemetry->packet_manager()->lobby_info_data()->lobbyNumPlayers();
}

uint8_t F1TS_lobbyAiControlled(int8_t playerIdx)
{
	return telemetry->packet_manager()->lobby_info_data()->lobbyAiControlled(playerIdx);
}

uint8_t F1TS_lobbyTeamId(int8_t playerIdx)
{
	return telemetry->packet_manager()->lobby_info_data()->lobbyTeamId(playerIdx);
}

uint8_t F1TS_lobbyNationality(int8_t playerIdx)
{
	return telemetry->packet_manager()->lobby_info_data()->lobbyNationality(playerIdx);
}

void F1TS_lobbyName(int8_t playerIdx, char* n)
{
	telemetry->packet_manager()->lobby_info_data()->lobbyName(playerIdx, n);
}

uint8_t F1TS_lobbyReadyStatus(int8_t playerIdx)
{
	return telemetry->packet_manager()->lobby_info_data()->lobbyReadyStatus(playerIdx);
}
