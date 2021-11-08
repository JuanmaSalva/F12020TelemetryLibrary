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

PacketLobbyInfoData::PacketLobbyInfoData()
{
	for (LobbyInfoData& m_lobbyPlayer : m_lobbyPlayers)
		m_lobbyPlayer = LobbyInfoData();
}

void PacketLobbyInfoData::update(char*& data)
{
	fromBin(data);

	for (LobbyInfoData& m_lobbyPlayer : m_lobbyPlayers)
		m_lobbyPlayer.fromBin(data);
}
