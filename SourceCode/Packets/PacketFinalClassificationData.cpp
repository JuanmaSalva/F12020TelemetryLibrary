#include "pch.h"
#include "PacketFinalClassificationData.h"

FinalClassificationData::FinalClassificationData()
{
	for (uint8_t& i : m_tyreStintsActual)
		i = 0;
	
	for (uint8_t& i : m_tyreStintsVisual)
		i = 0;
}

void FinalClassificationData::fromBin(char*& data)
{
	memcpy(&m_position, data, sizeof(uint8_t)); data += sizeof(uint8_t);
	memcpy(&m_numLaps, data, sizeof(uint8_t)); data += sizeof(uint8_t);
	memcpy(&m_gridPosition, data, sizeof(uint8_t)); data += sizeof(uint8_t);
	memcpy(&m_points, data, sizeof(uint8_t)); data += sizeof(uint8_t);
	memcpy(&m_numPitStops, data, sizeof(uint8_t)); data += sizeof(uint8_t);
	memcpy(&m_resultStatus, data, sizeof(uint8_t)); data += sizeof(uint8_t);

	memcpy(&m_bestLapTime, data, sizeof(float)); data += sizeof(float);
	memcpy(&m_totalRaceTime, data, sizeof(double)); data += sizeof(double);

	memcpy(&m_penaltiesTime, data, sizeof(uint8_t)); data += sizeof(uint8_t);
	memcpy(&m_numPenalties, data, sizeof(uint8_t)); data += sizeof(uint8_t);
	memcpy(&m_numTyreStints, data, sizeof(uint8_t)); data += sizeof(uint8_t);

	memcpy(&m_tyreStintsActual, data, sizeof(uint8_t) * 8); data += sizeof(uint8_t) * 8;
	memcpy(&m_tyreStintsVisual, data, sizeof(uint8_t) * 8); data += sizeof(uint8_t) * 8;
}

void PacketFinalClassificationData::fromBin(char*& data)
{
	memcpy(&m_numCars, data, sizeof(uint8_t)); data += sizeof(uint8_t);
}

PacketFinalClassificationData::PacketFinalClassificationData()
{
	for (FinalClassificationData& i : m_classificationData)
		i = FinalClassificationData();
}

void PacketFinalClassificationData::update(char*& data)
{
	fromBin(data);

	for (FinalClassificationData& i : m_classificationData)
		i.fromBin(data);
}
