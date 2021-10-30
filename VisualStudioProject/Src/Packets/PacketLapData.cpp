#include "pch.h"
#include "PacketLapData.h"

void LapData::fromBin(char*& data)
{
    memcpy(&m_lastLapTime, data, sizeof(float)); data += sizeof(float);
    memcpy(&m_currentLapTime, data, sizeof(float)); data += sizeof(float);

    memcpy(&m_sector1TimeInMS, data, sizeof(uint16_t)); data += sizeof(uint16_t);
    memcpy(&m_sector2TimeInMS, data, sizeof(uint16_t)); data += sizeof(uint16_t);
    memcpy(&m_bestLapTime, data, sizeof(float)); data += sizeof(float);
    memcpy(&m_bestLapNum, data, sizeof(uint8_t)); data += sizeof(uint8_t);

    memcpy(&m_bestLapSector1TimeInMS, data, sizeof(uint16_t)); data += sizeof(uint16_t);
    memcpy(&m_bestLapSector2TimeInMS, data, sizeof(uint16_t)); data += sizeof(uint16_t);
    memcpy(&m_bestLapSector3TimeInMS, data, sizeof(uint16_t)); data += sizeof(uint16_t);

    memcpy(&m_bestOverallSector1TimeInMS, data, sizeof(uint16_t)); data += sizeof(uint16_t);
    memcpy(&m_bestOverallSector1LapNum, data, sizeof(uint8_t)); data += sizeof(uint8_t);
    memcpy(&m_bestOverallSector2TimeInMS, data, sizeof(uint16_t)); data += sizeof(uint16_t);
    memcpy(&m_bestOverallSector2LapNum, data, sizeof(uint8_t)); data += sizeof(uint8_t);
    memcpy(&m_bestOverallSector3TimeInMS, data, sizeof(uint16_t)); data += sizeof(uint16_t);
    memcpy(&m_bestOverallSector3LapNum, data, sizeof(uint8_t)); data += sizeof(uint8_t);

    memcpy(&m_totalDistance, data, sizeof(float)); data += sizeof(float);
    memcpy(&m_lapDistance, data, sizeof(float)); data += sizeof(float);
    memcpy(&m_safetyCarDelta, data, sizeof(float)); data += sizeof(float);

    memcpy(&m_carPosition, data, sizeof(uint8_t)); data += sizeof(uint8_t);
    memcpy(&m_currentLapNum, data, sizeof(uint8_t)); data += sizeof(uint8_t);
    memcpy(&m_pitStatus, data, sizeof(uint8_t)); data += sizeof(uint8_t);
    memcpy(&m_sector, data, sizeof(uint8_t)); data += sizeof(uint8_t);
    memcpy(&m_currentLapInvalid, data, sizeof(uint8_t)); data += sizeof(uint8_t);
    memcpy(&m_penalties, data, sizeof(uint8_t)); data += sizeof(uint8_t);
    memcpy(&m_gridPosition, data, sizeof(uint8_t)); data += sizeof(uint8_t);
    memcpy(&m_driverStatus, data, sizeof(uint8_t)); data += sizeof(uint8_t);
    memcpy(&m_resultStatus, data, sizeof(uint8_t)); data += sizeof(uint8_t);
}

PacketLapData::PacketLapData()
{
	for (LapData& i : m_lapData)
		i = LapData();
}

void PacketLapData::update(char*& data)
{
    for (LapData& i : m_lapData)
    {
	    i.fromBin(data);
    }
}
