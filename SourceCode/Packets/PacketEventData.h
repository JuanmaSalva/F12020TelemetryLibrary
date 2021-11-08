#pragma once
#include <iostream>

/// <summary>
/// Union that depending on the event it stores diferent info
/// </summary>
union EventDataDetails
{
	struct
	{
		uint8_t	vehicleIdx; // Vehicle index of car achieving fastest lap
		float	lapTime;    // Lap time is in seconds
	} FastestLap;

	struct
	{
		uint8_t   vehicleIdx; // Vehicle index of car retiring
	} Retirement;

	struct
	{
		uint8_t   vehicleIdx; // Vehicle index of team mate
	} TeamMateInPits;

	struct
	{
		uint8_t   vehicleIdx; // Vehicle index of the race winner
	} RaceWinner;

	struct
	{
		uint8_t penaltyType;          // Penalty type � see info.md
		uint8_t infringementType;     // Infringement type � see info.md
		uint8_t vehicleIdx;           // Vehicle index of the car the penalty is applied to
		uint8_t otherVehicleIdx;      // Vehicle index of the other car involved
		uint8_t time;                 // Time gained, or time spent doing action in seconds
		uint8_t lapNum;               // Lap the penalty occurred on
		uint8_t placesGained;         // Number of places gained by this
	} Penalty;

	struct
	{
		uint8_t vehicleIdx; // Vehicle index of the vehicle triggering speed trap
		float speed;      // Top speed achieved in kilometres per hour
	} SpeedTrap;
};

/// <summary>
/// Packet that contains event data, this includes when a session started, ended, fastest lap... (check info.md)
/// In this case you need to pass a callback tfor each type of event data. This callback then will be called
/// after storing the information in this struct.
/// 
/// IMPORTANT: there is only one PacketEventData struct so if a event data message is received from the game,
/// the information on this struct will be overwritten with the new info. This is important because there is no
/// way to know what type actually contains the variable m_eventDetails. So if you want to do something with the
/// data stores, you might want to use it straight after the call back has been called.
/// As there is no way in know what type actually contains the variable m_eventDetails, there is no error
/// management, so be careful with that.
/// </summary>
struct PacketEventData
{
private:
	uint8_t           	m_eventStringCode[4]; // Event string code, see in info.md
	EventDataDetails	m_eventDetails;       // Event details - should be interpreted differently
											  // for each type

	void(*m_sessionStartedCallBack)() = nullptr;
	void(*m_sessionEndedCallBack)() = nullptr;
	void(*m_fastestLapCallBack)() = nullptr;
	void(*m_retirementCallBack)() = nullptr;
	void(*m_DRSenabledCallBack)() = nullptr;
	void(*m_DRSdisabledCallBack)() = nullptr;
	void(*m_teamMateInPitsCallBack)() = nullptr;
	void(*m_chequeredFlagCallBack)() = nullptr;
	void(*m_raceWinnerCallBack)() = nullptr;
	void(*m_penaltyIssuedCallBack)() = nullptr;
	void(*m_speedTrapTriggeredCallBack)() = nullptr;


	void fromBin(char*& data);

public:
	PacketEventData();
	
	void update(char*& data);

	void sessionStartedCallBack(void (*f)()) { m_sessionStartedCallBack = f; }
	void sessionEndedCallBack(void (*f)()) { m_sessionEndedCallBack = f; }
	void fastestLapCallBack(void (*f)()) { m_fastestLapCallBack = f; }
	void retirementCallBack(void (*f)()) { m_retirementCallBack = f; }
	void DRSenabledCallBack(void (*f)()) { m_DRSenabledCallBack = f; }
	void DRSdisabledCallBack(void (*f)()) { m_DRSdisabledCallBack = f; }
	void teamMateInPitsCallBack(void (*f)()) { m_teamMateInPitsCallBack = f; }
	void chequeredFlagCallBack(void (*f)()) { m_chequeredFlagCallBack = f; }
	void raceWinnerCallBack(void (*f)()) { m_raceWinnerCallBack = f; }
	void penaltyIssuedCallBack(void (*f)()) { m_penaltyIssuedCallBack = f; }
	void speedTrapTriggeredCallBack(void (*f)()) { m_speedTrapTriggeredCallBack = f; }

	
	uint8_t fastestLapVehicleIdx() const { return m_eventDetails.FastestLap.vehicleIdx; }
	float fastestLaplapTime() const { return m_eventDetails.FastestLap.lapTime; }
	
	uint8_t retirementVehicleIdx() const { return m_eventDetails.Retirement.vehicleIdx;  }
	
	uint8_t teamMateInPitsVehicleIdx() const { return m_eventDetails.TeamMateInPits.vehicleIdx; }

	uint8_t raceWinnerVehicleIdx() const { return m_eventDetails.RaceWinner.vehicleIdx; }

	uint8_t penaltyType() const { return m_eventDetails.Penalty.penaltyType; }
	uint8_t penaltyInfrigimentType() const { return m_eventDetails.Penalty.infringementType; }
	uint8_t penaltyVehicleIdx() const { return m_eventDetails.Penalty.vehicleIdx; }
	uint8_t penaltyOtherVehicleIdx() const { return m_eventDetails.Penalty.vehicleIdx; }
	uint8_t penaltyTime() const { return m_eventDetails.Penalty.otherVehicleIdx; }
	uint8_t penaltyLapNum() const { return m_eventDetails.Penalty.lapNum; }
	uint8_t penaltyPlacesGained() const { return m_eventDetails.Penalty.placesGained; }

	uint8_t speedTrapVehicleIdx() const { return m_eventDetails.SpeedTrap.vehicleIdx; }
	float speedTrapSpeed() const { return m_eventDetails.SpeedTrap.speed; }
};
