#pragma once
#include "iostream"

struct FinalClassificationData
{
private:
	uint8_t     m_position;              // Finishing position
	uint8_t     m_numLaps;               // Number of laps completed
	uint8_t     m_gridPosition;          // Grid position of the car
	uint8_t     m_points;                // Number of points scored
	uint8_t     m_numPitStops;           // Number of pit stops made
	uint8_t     m_resultStatus;          // Result status - 0 = invalid, 1 = inactive, 2 = active
										 // 3 = finished, 4 = disqualified, 5 = not classified
										 // 6 = retired
	float       m_bestLapTime;           // Best lap time of the session in seconds
	double      m_totalRaceTime;         // Total race time in seconds without penalties
	uint8_t     m_penaltiesTime;         // Total penalties accumulated in seconds
	uint8_t     m_numPenalties;          // Number of penalties applied to this driver
	uint8_t     m_numTyreStints;         // Number of tyres stints up to maximum
	uint8_t     m_tyreStintsActual[8];   // Actual tyres used by this driver
	uint8_t     m_tyreStintsVisual[8];   // Visual tyres used by this driver

public:
	FinalClassificationData();
	
	void fromBin(char*& data);

	uint8_t position() const { return m_position; }
	uint8_t numLaps() const { return m_numLaps; }
	uint8_t gridPosition() const { return m_gridPosition; }
	uint8_t points() const { return m_points; }
	uint8_t numPitStops() const { return m_numPitStops; }
	uint8_t resultStatus() const { return m_resultStatus; }
	float  bestLapTime() const { return m_bestLapTime; }
	double totalRaceTime() const { return m_totalRaceTime; }
	uint8_t penaltiesTime() const { return m_penaltiesTime; }
	uint8_t numPenalties() const { return m_numPenalties; }
	uint8_t numTyreStints() const { return m_numTyreStints; }
	uint8_t tyreStintsActual(int8_t stintIdx) const { return m_tyreStintsActual[stintIdx]; }
	uint8_t tyreStintsVisual(int8_t stintIdx) const { return m_tyreStintsVisual[stintIdx]; }
};


struct PacketFinalClassificationData
{
private:
	uint8_t                    m_numCars;                 // Number of cars in the final classification
	FinalClassificationData    m_classificationData[22];

	void fromBin(char*& data);

public:
	PacketFinalClassificationData();
	
	void update(char*& data);

	uint8_t numCarsFinished() { return m_numCars; }

	uint8_t position(int8_t carIdx) const { return m_classificationData[carIdx].points(); }
	uint8_t numLaps(int8_t carIdx) const { return m_classificationData[carIdx].numLaps(); }
	uint8_t gridPosition(int8_t carIdx) const { return m_classificationData[carIdx].gridPosition(); }
	uint8_t points(int8_t carIdx) const { return m_classificationData[carIdx].points(); }
	uint8_t numPitStops(int8_t carIdx) const { return m_classificationData[carIdx].numPitStops(); }
	uint8_t resultStatus(int8_t carIdx) const { return m_classificationData[carIdx].resultStatus(); }
	float  bestLapTime(int8_t carIdx) const { return m_classificationData[carIdx].bestLapTime(); }
	double totalRaceTime(int8_t carIdx) const { return m_classificationData[carIdx].totalRaceTime(); }
	uint8_t penaltiesTime(int8_t carIdx) const { return m_classificationData[carIdx].penaltiesTime(); }
	uint8_t numPenalties(int8_t carIdx) const { return m_classificationData[carIdx].numPenalties(); }
	uint8_t numTyreStints(int8_t carIdx) const { return m_classificationData[carIdx].numTyreStints(); }
	uint8_t tyreStintsActual(int8_t carIdx, int8_t stintIdx) const { return m_classificationData[carIdx].tyreStintsActual(stintIdx); }
	uint8_t tyreStintsVisual(int8_t carIdx, int8_t stintIdx) const { return m_classificationData[carIdx].tyreStintsVisual(stintIdx); }
};