#include "pch.h"
#include "PacketHeader.h"

void PacketHeader::fromBin(char*& data)
{
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
