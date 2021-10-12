#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include "Externs.h"
#include <utility>
#include <limits.h>
#include "TelemetryF1.h"


void F1TS_startF1Telemetry()
{
	isReady_ = false;
	telemetry = new TelemetryF1();
	isReady_ = true;
	telemetry->open_socket();	
	telemetry->start();
}

void F1TS_closeF1Telemetry()
{
	telemetry->end();
	delete telemetry;
	t.join();
}

bool F1TS_isReady()
{
	return isReady_;
}

void F1Ts_startF1TelemetryThread()
{
	t = std::thread(F1TS_startF1Telemetry);
	while(!F1TS_isReady())
	{
		std::cout << "Waiting for the socket to open" << std::endl;
	}
	std::cout << "Socket opened" << std::endl;
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

float F1TS_suspensionPositionRL()
{
	return telemetry->packet_manager()->motion_data()->suspensionPositionRL();
}

float F1TS_suspensionPositionRR()
{
	return telemetry->packet_manager()->motion_data()->suspensionPositionRR();
}

float F1TS_suspensionPositionFL()
{
	return telemetry->packet_manager()->motion_data()->suspensionAccelerationFL();
}

float F1TS_suspensionPositionFR()
{
	return telemetry->packet_manager()->motion_data()->suspensionPositionFR();
}

float F1TS_suspensionVelocityRL()
{
	return telemetry->packet_manager()->motion_data()->suspensionVelocityRL();
}

float F1TS_suspensionVelocityRR()
{
	return telemetry->packet_manager()->motion_data()->suspensionVelocityRR();
}

float F1TS_suspensionVelocityFL()
{
	return telemetry->packet_manager()->motion_data()->suspensionVelocityFL();
}

float F1TS_suspensionVelocityFR()
{
	return telemetry->packet_manager()->motion_data()->suspensionVelocityFR();
}

float F1TS_suspensionAccelerationRL()
{
	return telemetry->packet_manager()->motion_data()->suspensionAccelerationRL();
}

float F1TS_suspensionAccelerationRR()
{
	return telemetry->packet_manager()->motion_data()->suspensionAccelerationRR();
}

float F1TS_suspensionAccelerationFL()
{
	return telemetry->packet_manager()->motion_data()->suspensionAccelerationFL();
}

float F1TS_suspensionAccelerationFR()
{
	return telemetry->packet_manager()->motion_data()->suspensionAccelerationFR();
}

float F1TS_wheelSpeedRL()
{
	return telemetry->packet_manager()->motion_data()->wheelSpeedRL();
}

float F1TS_wheelSpeedRR()
{
	return telemetry->packet_manager()->motion_data()->wheelSpeedRR();
}

float F1TS_wheelSpeedFL()
{
	return telemetry->packet_manager()->motion_data()->wheelSpeedFL();
}

float F1TS_wheelSpeedFR()
{
	return telemetry->packet_manager()->motion_data()->wheelSpeedFR();
}

float F1TS_wheelSlipRL()
{
	return telemetry->packet_manager()->motion_data()->wheelSlipRL();
}

float F1TS_wheelSlipRR()
{
	return telemetry->packet_manager()->motion_data()->wheelSlipRR();
}

float F1TS_wheelSlipFL()
{
	return telemetry->packet_manager()->motion_data()->wheelSlipFL();
}

float F1TS_wheelSlipFR()
{
	return telemetry->packet_manager()->motion_data()->wheelSlipFR();
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