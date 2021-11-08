#pragma once
#include <iostream>

enum PacketID : uint16_t {
	PACKET_ID_MOTION = 0,
	PACKET_ID_SESSION = 1,
	PACKET_ID_LAP_DATA = 2,
	PACKET_ID_EVENT = 3,
	PACKET_ID_PARTICIPANTS = 4,
	PACKET_ID_CAR_SETUPS = 5,
	PACKET_ID_CAR_TELEMETRY = 6,
	PACKET_ID_CAR_STATUS = 7,
	PACKET_ID_FINAL_CLASSIFICATION = 8,
	PACKET_ID_LOBBY_INFO = 9

};

struct PacketHeader
{
private:
	uint16_t    m_packetFormat;             // 2020
	uint8_t     m_gameMajorVersion;         // Game major version - "X.00"
	uint8_t     m_gameMinorVersion;         // Game minor version - "1.XX"
	uint8_t     m_packetVersion;            // Version of this packet type, all start from 1
	uint8_t     m_packetId;                 // Identifier for the packet type, see below
	uint64_t    m_sessionUID;               // Unique identifier for the session
	float       m_sessionTime;              // Session timestamp
	uint32_t    m_frameIdentifier;          // Identifier for the frame the data was retrieved on
	uint8_t     m_playerCarIndex;           // Index of player's car in the array

   // ADDED IN BETA 2: 
	uint8_t     m_secondaryPlayerCarIndex;  // Index of secondary player's car in the array (splitscreen)
										  // 255 if no second player

public:
	PacketHeader() {};

	void fromBin(char*& data);

	uint16_t packetFormat() const { return m_packetFormat; }
	uint8_t gameMajorVersion() const { return m_gameMajorVersion; }
	uint8_t gameMinorVersion()const { return m_gameMinorVersion; }
	uint8_t packetVersion()const { return m_packetVersion; }
	uint8_t packetId() const { return m_packetId; }
	uint64_t sessionUID()const { return m_sessionUID; }
	float sessionTime()const { return m_sessionTime; }
	uint32_t frameIdentifier() const { return m_frameIdentifier; }
	uint8_t playerCarIndex()const { return m_playerCarIndex; }

	uint8_t secondaryPlayerCarIndex()const { return m_secondaryPlayerCarIndex; }
};

