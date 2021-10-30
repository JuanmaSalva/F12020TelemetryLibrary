#include "pch.h"
#include "PacketSessionData.h"

void MarshalZone::fromBin(char*& data)
{
    memcpy(&m_zoneStart, data, sizeof(float)); data += sizeof(float);
    memcpy(&m_zoneFlag, data, sizeof(int8_t)); data += sizeof(int8_t);
}

void WeatherForecastSample::fromBin(char*& data)
{
    memcpy(&m_sessionType, data, sizeof(uint8_t)); data += sizeof(uint8_t);
    memcpy(&m_timeOffset, data, sizeof(uint8_t)); data += sizeof(uint8_t);
    memcpy(&m_weather, data, sizeof(uint8_t)); data += sizeof(uint8_t);
    memcpy(&m_trackTemperature, data, sizeof(int8_t)); data += sizeof(int8_t);
    memcpy(&m_airTemperature, data, sizeof(int8_t)); data += sizeof(int8_t);
}

void PacketSessionData::fromBin(char*& data)
{
    memcpy(&m_weather, data, sizeof(uint8_t)); data += sizeof(uint8_t);
    memcpy(&m_trackTemperature, data, sizeof(int8_t)); data += sizeof(int8_t);
    memcpy(&m_airTemperature, data, sizeof(int8_t)); data += sizeof(int8_t);
    memcpy(&m_totalLaps, data, sizeof(uint8_t)); data += sizeof(uint8_t);
    memcpy(&m_trackLength, data, sizeof(uint16_t)); data += sizeof(uint16_t);
    memcpy(&m_sessionType, data, sizeof(uint8_t)); data += sizeof(uint8_t);
    memcpy(&m_trackId, data, sizeof(int8_t)); data += sizeof(int8_t);
    memcpy(&m_formula, data, sizeof(uint8_t)); data += sizeof(uint8_t);

    memcpy(&m_sessionTimeLeft, data, sizeof(uint16_t)); data += sizeof(uint16_t);
    memcpy(&m_sessionDuration, data, sizeof(uint16_t)); data += sizeof(uint16_t);

    memcpy(&m_pitSpeedLimit, data, sizeof(uint8_t)); data += sizeof(uint8_t);
    memcpy(&m_gamePaused, data, sizeof(uint8_t)); data += sizeof(uint8_t);
    memcpy(&m_isSpectating, data, sizeof(uint8_t)); data += sizeof(uint8_t);
    memcpy(&m_spectatorCarIndex, data, sizeof(uint8_t)); data += sizeof(uint8_t);
    memcpy(&m_sliProNativeSupport, data, sizeof(uint8_t)); data += sizeof(uint8_t);
    memcpy(&m_numMarshalZones, data, sizeof(uint8_t)); data += sizeof(uint8_t);


    for (MarshalZone& m_marshalZone : m_marshalZones)
    {
	    m_marshalZone.fromBin(data);
    }

    memcpy(&m_safetyCarStatus, data, sizeof(uint8_t)); data += sizeof(uint8_t);
    memcpy(&m_networkGame, data, sizeof(uint8_t)); data += sizeof(uint8_t);
    memcpy(&m_numWeatherForecastSamples, data, sizeof(uint8_t)); data += sizeof(uint8_t);


    for (WeatherForecastSample& m_weatherForecastSample : m_weatherForecastSamples)
	    m_weatherForecastSample.fromBin(data);
}

PacketSessionData::PacketSessionData()
{
    for (MarshalZone& m_marshalZone : m_marshalZones)
	    m_marshalZone = MarshalZone();

    for (WeatherForecastSample& m_weatherForecastSample : m_weatherForecastSamples)
	    m_weatherForecastSample = WeatherForecastSample();
}

void PacketSessionData::update(char*& data)
{
    fromBin(data);
}
