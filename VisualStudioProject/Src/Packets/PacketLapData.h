#pragma once
#include <iostream>

struct LapData
{
private:
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
public:
	void fromBin(char*& data);

	float    lastLapTime() const { return m_lastLapTime; }
	float    currentLapTime() const { return m_currentLapTime; }
	uint16_t   sector1TimeInMS() const { return m_sector1TimeInMS; }
	uint16_t   sector2TimeInMS() const { return m_sector2TimeInMS; }
	float      bestLapTime() const { return m_bestLapTime; }
	uint8_t    bestLapNum() const { return m_bestLapNum; }
	uint16_t   bestLapSector1TimeInMS() const { return m_bestLapSector1TimeInMS; }
	uint16_t   bestLapSector2TimeInMS() const { return m_bestLapSector2TimeInMS; }
	uint16_t   bestLapSector3TimeInMS() const { return m_bestLapSector3TimeInMS; }
	uint16_t   bestOverallSector1TimeInMS() const { return m_bestOverallSector1TimeInMS; }
	uint8_t    bestOverallSector1LapNum() const { return m_bestOverallSector1LapNum; }
	uint16_t   bestOverallSector2TimeInMS() const { return m_bestOverallSector2TimeInMS; }
	uint8_t    bestOverallSector2LapNum() const { return m_bestOverallSector2LapNum; }
	uint16_t   bestOverallSector3TimeInMS() const { return m_bestOverallSector3TimeInMS; }
	uint8_t    bestOverallSector3LapNum() const { return m_bestOverallSector3LapNum; }
	float      lapDistance() const { return m_lapDistance; }
	float      totalDistance() const { return m_totalDistance; }
	float      safetyCarDelta() const { return m_safetyCarDelta; }
	uint8_t    carPosition() const { return m_carPosition; }
	uint8_t    currentLapNum() const { return m_currentLapNum; }
	uint8_t    pitStatus() const { return m_pitStatus; }
	uint8_t    sector() const { return m_sector; }
	uint8_t    currentLapInvalid() const { return m_currentLapInvalid; }
	uint8_t    penalties() const { return m_penalties; }
	uint8_t    gridPosition() const { return m_gridPosition; }
	uint8_t    driverStatus() const { return m_driverStatus; }
	uint8_t    resultStatus() const { return m_resultStatus; }
};

struct PacketLapData
{
private:
	LapData m_lapData[22];        // Lap data for all cars on track

public:
	PacketLapData();
	
	void update(char*& data);

	float lastTimeLap(int8_t carId) const { return m_lapData[carId].lastLapTime(); }
	float currentLapTime(int8_t carId) const { return m_lapData[carId].currentLapTime(); }
	uint16_t sector1(int8_t carId) const { return m_lapData[carId].sector1TimeInMS(); }
	uint16_t sector2(int8_t carId) const { return m_lapData[carId].sector2TimeInMS(); }
	float bestLapTime(int8_t carId) const { return m_lapData[carId].bestLapTime(); }
	uint8_t bestLapNum(int8_t carId) const { return m_lapData[carId].bestLapNum(); }
	uint16_t bestLapSector1TimeInMS(int8_t carId) const { return m_lapData[carId].bestLapSector1TimeInMS(); }
	uint16_t bestLapSector2TimeInMS(int8_t carId) const { return m_lapData[carId].bestLapSector2TimeInMS(); }
	uint16_t bestLapSector3TimeInMS(int8_t carId) const { return m_lapData[carId].bestLapSector3TimeInMS(); }
	uint16_t bestOverallSector1TimeInMS(int8_t carId) const { return m_lapData[carId].bestOverallSector1TimeInMS(); }
	uint8_t bestOverallSector1LapNum(int8_t carId) const { return m_lapData[carId].bestOverallSector1LapNum(); }
	uint16_t bestOverallSector2TimeInMS(int8_t carId) const { return m_lapData[carId].bestOverallSector2TimeInMS(); }
	uint8_t bestOverallSector2LapNum(int8_t carId) const { return m_lapData[carId].bestOverallSector2LapNum(); }
	uint16_t bestOverallSector3TimeInMS(int8_t carId) const { return m_lapData[carId].bestOverallSector3TimeInMS(); }
	uint8_t bestOverallSector3LapNum(int8_t carId) const { return m_lapData[carId].bestOverallSector3LapNum(); }
	float lapDistance(int8_t carId) const { return m_lapData[carId].lapDistance(); }
	float totalDistance(int8_t carId) const { return m_lapData[carId].totalDistance(); }
	float safetyCarDelta(int8_t carId) const { return m_lapData[carId].safetyCarDelta(); }
	uint8_t carPosition(int8_t carId) const { return m_lapData[carId].carPosition(); }
	uint8_t currentLapNum(int8_t carId) const { return m_lapData[carId].currentLapNum(); }
	uint8_t pitStatus(int8_t carId) const { return m_lapData[carId].pitStatus(); }
	uint8_t sector(int8_t carId) const { return m_lapData[carId].sector(); }
	uint8_t currentLapInvalid(int8_t carId) const { return m_lapData[carId].currentLapInvalid(); }
	uint8_t penalties(int8_t carId) const { return m_lapData[carId].penalties(); }
	uint8_t gridPosition(int8_t carId) const { return m_lapData[carId].gridPosition(); }
	uint8_t driverStatus(int8_t carId) const { return m_lapData[carId].driverStatus(); }
	uint8_t resultStatus(int8_t carId) const { return m_lapData[carId].resultStatus(); }
};