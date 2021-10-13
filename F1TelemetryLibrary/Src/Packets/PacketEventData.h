#pragma once
#include <iostream>

//TODO do not make this info public, it does not make sense. Instead use a FMS with this data

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
        uint8_t penaltyType;          // Penalty type – see info.md
        uint8_t infringementType;     // Infringement type – see info.md
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

struct PacketEventData
{
private:
    uint8_t           	m_eventStringCode[4]; // Event string code, see in info.md
    EventDataDetails	m_eventDetails;       // Event details - should be interpreted differently
                                              // for each type

	void FromBin(char*& data)
	{
		for(uint8_t sc : m_eventStringCode)
		{
            sc = uint8_t();
            memcpy(&sc, data, sizeof(uint8_t)); data += sizeof(uint8_t);			
		}
        std::string code = "0000";
        code[0] = m_eventStringCode[0];
        code[1] = m_eventStringCode[1];
        code[2] = m_eventStringCode[2];
        code[3] = m_eventStringCode[3];

        if (code == "SSTA");
        else if (code == "SEND");
        else if (code == "FTLP")
        {
            m_eventDetails.FastestLap = {};
            memcpy(&m_eventDetails.FastestLap.vehicleIdx, data, sizeof(uint8_t)); data += sizeof(uint8_t);
            memcpy(&m_eventDetails.FastestLap.lapTime, data, sizeof(float)); data += sizeof(float);
        }
        else if (code == "RTMT")
        {
            m_eventDetails.Retirement = {};
            memcpy(&m_eventDetails.Retirement.vehicleIdx, data, sizeof(uint8_t)); data += sizeof(uint8_t);
        }
        else if (code == "DRSE");
        else if (code == "DRSD");
        else if (code == "TMPT")
        {
            m_eventDetails.TeamMateInPits = {};
            memcpy(&m_eventDetails.TeamMateInPits.vehicleIdx, data, sizeof(uint8_t)); data += sizeof(uint8_t);
        }
        else if (code == "CHQF");
        else if (code == "RCWN")
        {
            m_eventDetails.RaceWinner = {};
            memcpy(&m_eventDetails.RaceWinner.vehicleIdx, data, sizeof(uint8_t)); data += sizeof(uint8_t);
        }
        else if (code == "PENA")
        {
            m_eventDetails.Penalty = {};
            memcpy(&m_eventDetails.Penalty.penaltyType, data, sizeof(uint8_t)); data += sizeof(uint8_t);
            memcpy(&m_eventDetails.Penalty.infringementType, data, sizeof(uint8_t)); data += sizeof(uint8_t);
            memcpy(&m_eventDetails.Penalty.vehicleIdx, data, sizeof(uint8_t)); data += sizeof(uint8_t);
            memcpy(&m_eventDetails.Penalty.otherVehicleIdx, data, sizeof(uint8_t)); data += sizeof(uint8_t);
            memcpy(&m_eventDetails.Penalty.time, data, sizeof(uint8_t)); data += sizeof(uint8_t);
            memcpy(&m_eventDetails.Penalty.lapNum, data, sizeof(uint8_t)); data += sizeof(uint8_t);
            memcpy(&m_eventDetails.Penalty.placesGained, data, sizeof(uint8_t)); data += sizeof(uint8_t);

        }
        else if (code == "SPTP")
        {
            m_eventDetails.SpeedTrap = {};
            memcpy(&m_eventDetails.SpeedTrap.vehicleIdx, data, sizeof(uint8_t)); data += sizeof(uint8_t);
            memcpy(&m_eventDetails.SpeedTrap.speed, data, sizeof(float)); data += sizeof(float);
        }
        else std::cout << "Event data packet received but not identified" << std::endl;
	}

public:
	void update(char*& data)
	{
        FromBin(data);
	}
};
