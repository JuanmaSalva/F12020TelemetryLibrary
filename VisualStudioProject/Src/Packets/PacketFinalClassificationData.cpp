#include "pch.h"
#include "PacketFinalClassificationData.h"

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
	for (uint8_t& i : m_tyreStintsActual) memcpy(&i, data, sizeof(uint8_t)); data += sizeof(uint8_t);
	for (uint8_t& i : m_tyreStintsVisual) memcpy(&i, data, sizeof(uint8_t)); data += sizeof(uint8_t);
}

void PacketFinalClassificationData::fromBin(char*& data)
{
	memcpy(&m_numCars, data, sizeof(uint8_t)); data += sizeof(uint8_t);
}

void PacketFinalClassificationData::update(char*& data)
{
	fromBin(data);
	
	for(FinalClassificationData final_classification: m_classificationData)
	{
		final_classification = FinalClassificationData();
		final_classification.fromBin(data);
	}
}
