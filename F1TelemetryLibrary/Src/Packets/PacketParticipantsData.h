#pragma once
#include "iostream"

struct ParticipantData
{
private:
	uint8_t      m_aiControlled;           // Whether the vehicle is AI (1) or Human (0) controlled
	uint8_t      m_driverId;               // Driver id - see appendix
	uint8_t      m_teamId;                 // Team id - see appendix
	uint8_t      m_raceNumber;             // Race number of the car
	uint8_t      m_nationality;            // Nationality of the driver
	char		 m_name[48];               // Name of participant in UTF-8 format – null terminated
										   // Will be truncated with … (U+2026) if too long
	uint8_t      m_yourTelemetry;          // The player's UDP setting, 0 = restricted, 1 = public

public:
	void fromBin(char*& data);

	uint8_t aiControlled() { return m_aiControlled; }
	uint8_t driverId() { return m_driverId; }
	uint8_t teamId() { return m_teamId; }
	uint8_t raceNumber() { return m_raceNumber; }
	uint8_t nationality() { return m_nationality; }
	void name(char* n) { n = m_name; }
	uint8_t yourTelemetry() { return m_yourTelemetry; };
};

struct PacketParticipantsData
{
private:
	uint8_t         m_numActiveCars;	// Number of active cars in the data – should match number of
										// cars on HUD
	ParticipantData m_participants[22];

	void fromBin(char*& data);

public:
	void update(char*& data);
	
	uint8_t numActiveCars() { return m_numActiveCars; }

	uint8_t aiControlled(uint8_t idx) { return m_participants[idx].aiControlled(); }
	uint8_t driverId(uint8_t idx) { return m_participants[idx].driverId(); }
	uint8_t teamId(uint8_t idx) { return m_participants[idx].teamId(); }
	uint8_t raceNumber(uint8_t idx) { return m_participants[idx].raceNumber(); }
	uint8_t nationality(uint8_t idx) { return m_participants[idx].nationality(); }
	void name(uint8_t idx, char* n) { return m_participants[idx].name(n); }
	uint8_t yourTelemetry(uint8_t idx) { return m_participants[idx].yourTelemetry(); }
};