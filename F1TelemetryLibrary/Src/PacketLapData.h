#pragma once
#include "PacketHeader.h"


struct LapData
{
    float    m_lastLapTime;               // Last lap time in seconds
    float    m_currentLapTime;            // Current time around the lap in seconds

    //UPDATED in Beta 3:
    uint16_t   m_sector1TimeInMS;           // Sector 1 time in milliseconds
    uint16_t   m_sector2TimeInMS;           // Sector 2 time in milliseconds
    float      m_bestLapTime;               // Best lap time of the session in seconds
    uint8_t    m_bestLapNum;                // Lap number best time achieved on
    uint16_t   m_bestLapSector1TimeInMS;    // Sector 1 time of best lap in the session in milliseconds
    uint16_t   m_bestLapSector2TimeInMS;    // Sector 2 time of best lap in the session in milliseconds
    uint16_t   m_bestLapSector3TimeInMS;    // Sector 3 time of best lap in the session in milliseconds
    uint16_t   m_bestOverallSector1TimeInMS;// Best overall sector 1 time of the session in milliseconds
    uint8_t    m_bestOverallSector1LapNum;  // Lap number best overall sector 1 time achieved on
    uint16_t   m_bestOverallSector2TimeInMS;// Best overall sector 2 time of the session in milliseconds
    uint8_t    m_bestOverallSector2LapNum;  // Lap number best overall sector 2 time achieved on
    uint16_t   m_bestOverallSector3TimeInMS;// Best overall sector 3 time of the session in milliseconds
    uint8_t    m_bestOverallSector3LapNum;  // Lap number best overall sector 3 time achieved on


    float      m_lapDistance;               // Distance vehicle is around current lap in metres – could
                                            // be negative if line hasn’t been crossed yet
    float      m_totalDistance;             // Total distance travelled in session in metres – could
                                            // be negative if line hasn’t been crossed yet
    float      m_safetyCarDelta;            // Delta in seconds for safety car
    uint8_t    m_carPosition;               // Car race position
    uint8_t    m_currentLapNum;             // Current lap number
    uint8_t    m_pitStatus;                 // 0 = none, 1 = pitting, 2 = in pit area
    uint8_t    m_sector;                    // 0 = sector1, 1 = sector2, 2 = sector3
    uint8_t    m_currentLapInvalid;         // Current lap invalid - 0 = valid, 1 = invalid
    uint8_t    m_penalties;                 // Accumulated time penalties in seconds to be added
    uint8_t    m_gridPosition;              // Grid position the vehicle started the race in
    uint8_t    m_driverStatus;              // Status of driver - 0 = in garage, 1 = flying lap
                                            // 2 = in lap, 3 = out lap, 4 = on track
    uint8_t    m_resultStatus;              // Result status - 0 = invalid, 1 = inactive, 2 = active
                                            // 3 = finished, 4 = disqualified, 5 = not classified
                                            // 6 = retired

    void FromBin(char* &data) {
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
};

struct PacketLapData
{
    PacketLapData() {};

    LapData m_lapData[22];        // Lap data for all cars on track

    PacketLapData(char* data) {

        for (int i = 0; i < 22; i++) {
            m_lapData[i] = LapData();
            m_lapData[i].FromBin(data);
        }
    }

    float currentLapTime() { return m_lapData[0].m_currentLapTime; }
    uint16_t sector1() { return m_lapData[0].m_sector1TimeInMS; }
    uint16_t sector2() { return m_lapData[0].m_sector2TimeInMS; }
    uint16_t sector3() { return m_lapData[0].m_sector2TimeInMS - m_lapData[0].m_currentLapTime; }
};