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

    PacketHeader() {};

    void FromBin(char* &data) {
        memcpy(&m_packetFormat, data, sizeof(uint16_t)); data += sizeof(uint16_t);

        memcpy(&m_gameMajorVersion, data, sizeof(uint8_t)); data += sizeof(uint8_t);
        memcpy(&m_gameMinorVersion, data, sizeof(uint8_t)); data += sizeof(uint8_t);
        memcpy(&m_packetVersion, data, sizeof(uint8_t)); data += sizeof(uint8_t);
        memcpy(&m_packetId, data, sizeof(uint8_t)); data += sizeof(uint8_t);

        memcpy(&m_sessionUID, data, sizeof(uint64_t)); data += sizeof(uint64_t);

        memcpy(&m_sessionTime, data, sizeof(float)); data += sizeof(float);

        memcpy(&m_frameIdentifier, data, sizeof(uint32_t)); data += sizeof(uint32_t);

        memcpy(&m_playerCarIndex, data, sizeof(uint8_t)); data += sizeof(uint8_t);
        memcpy(&m_secondaryPlayerCarIndex, data, sizeof(uint8_t)); data += sizeof(uint8_t);
    }

    void Print()
    {
        std::cout << "PacketFormat: " << m_packetFormat << "\n";
        //std::cout << "Game major version: " << m_gameMajorVersion << "\n";
        //std::cout << "Game minor version: " << m_gameMinorVersion<< "\n";
        //std::cout << "Packet version: " << m_packetVersion << "\n";
        std::cout << "Packet id: " << m_packetId << "\n";
        //std::cout << "Session id: " << m_sessionUID << "\n";
        std::cout << "Session time: " << m_sessionTime << "\n";
        //std::cout << "Frame identifier: " << m_frameIdentifier << "\n";
        //std::cout << "Player car index: " << m_playerCarIndex << "\n";
        //std::cout << "Second player car index: " << m_secondaryPlayerCarIndex << "\n";
    }

};