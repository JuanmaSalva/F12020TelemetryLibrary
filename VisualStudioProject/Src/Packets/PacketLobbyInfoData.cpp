#include "pch.h"
#include "PacketLobbyInfoData.h"

void LobbyInfoData::fromBin(char*& data)
{
	memcpy(&m_aiControlled, data, sizeof(uint8_t)); data += sizeof(uint8_t);
	memcpy(&m_teamId, data, sizeof(uint8_t)); data += sizeof(uint8_t);
	memcpy(&m_nationality, data, sizeof(uint8_t)); data += sizeof(uint8_t);
	memcpy(&m_name, data, sizeof(char) * 48); data += sizeof(char) * 48;
	memcpy(&m_readyStatus, data, sizeof(uint8_t)); data += sizeof(uint8_t);
}

void PacketLobbyInfoData::fromBin(char*& data)
{
	memcpy(&m_numPlayers, data, sizeof(uint8_t)); data += sizeof(uint8_t);
}

void PacketLobbyInfoData::update(char*& data)
{
	fromBin(data);
	for(LobbyInfoData lobby_info: m_lobbyPlayers)
	{
		lobby_info = LobbyInfoData();
		lobby_info.fromBin(data);
	}
}
