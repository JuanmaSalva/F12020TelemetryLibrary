#include "pch.h"
#include "PacketParticipantsData.h"

void ParticipantData::fromBin(char*& data)
{
	memcpy(&m_aiControlled, data, sizeof(uint8_t)); data += sizeof(uint8_t);
	memcpy(&m_driverId, data, sizeof(uint8_t)); data += sizeof(uint8_t);
	memcpy(&m_teamId, data, sizeof(uint8_t)); data += sizeof(uint8_t);
	memcpy(&m_raceNumber, data, sizeof(uint8_t)); data += sizeof(uint8_t);
	memcpy(&m_nationality, data, sizeof(uint8_t)); data += sizeof(uint8_t);
	memcpy(&m_name, data, sizeof(char) * 48); data += sizeof(char) * 48;
	memcpy(&m_yourTelemetry, data, sizeof(uint8_t)); data += sizeof(uint8_t);
}

void PacketParticipantsData::fromBin(char*& data)
{
	memcpy(&m_numActiveCars, data, sizeof(uint8_t)); data += sizeof(uint8_t);
}

void PacketParticipantsData::update(char*& data)
{
	fromBin(data);

	for(ParticipantData participant_data: m_participants)
	{
		participant_data = ParticipantData();
		participant_data.fromBin(data);
	}
}
