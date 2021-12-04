#include "pch.h"
#include "PacketEventData.h"

void PacketEventData::fromBin(char*& data)
{
    memcpy(&m_eventStringCode, data, sizeof(uint8_t) * 4); data += sizeof(uint8_t) * 4;

    std::string code = "0000";
    code[0] = m_eventStringCode[0];
    code[1] = m_eventStringCode[1];
    code[2] = m_eventStringCode[2];
    code[3] = m_eventStringCode[3];

    std::cout << "EventData Code: " << code << std::endl;
	
    if (code == "SSTA" && m_sessionStartedCallBack != nullptr) m_sessionStartedCallBack();
    else if (code == "SEND" && m_sessionEndedCallBack != nullptr) m_sessionEndedCallBack();
    else if (code == "FTLP" && m_fastestLapCallBack != nullptr)
    {
        m_eventDetails.FastestLap = {};
        memcpy(&m_eventDetails.FastestLap.vehicleIdx, data, sizeof(uint8_t)); data += sizeof(uint8_t);
        memcpy(&m_eventDetails.FastestLap.lapTime, data, sizeof(float)); data += sizeof(float);
        m_fastestLapCallBack();
    }
    else if (code == "RTMT" && m_retirementCallBack != nullptr)
    {
        m_eventDetails.Retirement = {};
        memcpy(&m_eventDetails.Retirement.vehicleIdx, data, sizeof(uint8_t)); data += sizeof(uint8_t);
        m_retirementCallBack();
    }
    else if (code == "DRSE" && m_DRSenabledCallBack != nullptr) m_DRSenabledCallBack();
    else if (code == "DRSD" && m_DRSdisabledCallBack != nullptr) m_DRSdisabledCallBack();
    else if (code == "TMPT" && m_teamMateInPitsCallBack != nullptr)
    {
        m_eventDetails.TeamMateInPits = {};
        memcpy(&m_eventDetails.TeamMateInPits.vehicleIdx, data, sizeof(uint8_t)); data += sizeof(uint8_t);
        m_teamMateInPitsCallBack();
    }
    else if (code == "CHQF" && m_chequeredFlagCallBack != nullptr) m_chequeredFlagCallBack();
    else if (code == "RCWN" && m_raceWinnerCallBack != nullptr)
    {
        m_eventDetails.RaceWinner = {};
        memcpy(&m_eventDetails.RaceWinner.vehicleIdx, data, sizeof(uint8_t)); data += sizeof(uint8_t);
        m_raceWinnerCallBack();
    }
    else if (code == "PENA" && m_penaltyIssuedCallBack != nullptr)
    {
        m_eventDetails.Penalty = {};
        memcpy(&m_eventDetails.Penalty.penaltyType, data, sizeof(uint8_t)); data += sizeof(uint8_t);
        memcpy(&m_eventDetails.Penalty.infringementType, data, sizeof(uint8_t)); data += sizeof(uint8_t);
        memcpy(&m_eventDetails.Penalty.vehicleIdx, data, sizeof(uint8_t)); data += sizeof(uint8_t);
        memcpy(&m_eventDetails.Penalty.otherVehicleIdx, data, sizeof(uint8_t)); data += sizeof(uint8_t);
        memcpy(&m_eventDetails.Penalty.time, data, sizeof(uint8_t)); data += sizeof(uint8_t);
        memcpy(&m_eventDetails.Penalty.lapNum, data, sizeof(uint8_t)); data += sizeof(uint8_t);
        memcpy(&m_eventDetails.Penalty.placesGained, data, sizeof(uint8_t)); data += sizeof(uint8_t);
        m_penaltyIssuedCallBack();
    }
    else if (code == "SPTP" && m_speedTrapTriggeredCallBack != nullptr)
    {
        m_eventDetails.SpeedTrap = {};
        memcpy(&m_eventDetails.SpeedTrap.vehicleIdx, data, sizeof(uint8_t)); data += sizeof(uint8_t);
        memcpy(&m_eventDetails.SpeedTrap.speed, data, sizeof(float)); data += sizeof(float);
        m_speedTrapTriggeredCallBack();
    }
    else std::cout << "Event data packet received but not identified" << std::endl;
}

PacketEventData::PacketEventData()
{
    for (uint8_t& i : m_eventStringCode)
	    i = 0;
}

void PacketEventData::update(char*& data)
{
    fromBin(data);
}
