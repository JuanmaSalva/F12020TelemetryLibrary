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
	
    if (code == "SSTA") {
        if (m_sessionStartedCallBack != nullptr) {
            std::cout << "Going to call callback\n";
            m_sessionStartedCallBack();
            std::cout << "Callback called\n";
        }
        m_lastEvent = 0;
    }
    else if (code == "SEND") {
        if (m_sessionEndedCallBack != nullptr)
        {
            std::cout << "Going to call callback\n";
            std::cout << m_sessionEndedCallBack << "\n";
            m_sessionEndedCallBack();
            std::cout << "Callback called\n";
            
        }

        m_lastEvent = 1;
    }
    else if (code == "FTLP")
    {
        m_eventDetails.FastestLap = {};
        memcpy(&m_eventDetails.FastestLap.vehicleIdx, data, sizeof(uint8_t)); data += sizeof(uint8_t);
        memcpy(&m_eventDetails.FastestLap.lapTime, data, sizeof(float)); data += sizeof(float);
        if(m_fastestLapCallBack != nullptr) m_fastestLapCallBack();
        m_lastEvent = 2;
    }
    else if (code == "RTMT")
    {
        m_eventDetails.Retirement = {};
        memcpy(&m_eventDetails.Retirement.vehicleIdx, data, sizeof(uint8_t)); data += sizeof(uint8_t);
        if(m_retirementCallBack != nullptr) m_retirementCallBack();
        m_lastEvent = 3;
    }
    else if (code == "DRSE") {
        if(m_DRSenabledCallBack != nullptr) m_DRSenabledCallBack();
        m_lastEvent = 4;
    }
    else if (code == "DRSD") {
        if(m_DRSdisabledCallBack != nullptr) m_DRSdisabledCallBack();
        m_lastEvent = 5;
    }
    else if (code == "TMPT")
    {
        m_eventDetails.TeamMateInPits = {};
        memcpy(&m_eventDetails.TeamMateInPits.vehicleIdx, data, sizeof(uint8_t)); data += sizeof(uint8_t);
        if(m_teamMateInPitsCallBack != nullptr) m_teamMateInPitsCallBack();
        m_lastEvent = 6;
    }
    else if (code == "CHQF") {
        if(m_chequeredFlagCallBack != nullptr) m_chequeredFlagCallBack();
        m_lastEvent = 7;
    }
    else if (code == "RCWN")
    {
        m_eventDetails.RaceWinner = {};
        memcpy(&m_eventDetails.RaceWinner.vehicleIdx, data, sizeof(uint8_t)); data += sizeof(uint8_t);
        if(m_raceWinnerCallBack != nullptr) m_raceWinnerCallBack();
        m_lastEvent = 8;
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
        if (m_penaltyIssuedCallBack != nullptr) m_penaltyIssuedCallBack();
        m_lastEvent = 9;
    }
    else if (code == "SPTP")
    {
        m_eventDetails.SpeedTrap = {};
        memcpy(&m_eventDetails.SpeedTrap.vehicleIdx, data, sizeof(uint8_t)); data += sizeof(uint8_t);
        memcpy(&m_eventDetails.SpeedTrap.speed, data, sizeof(float)); data += sizeof(float);
        if(m_speedTrapTriggeredCallBack != nullptr) m_speedTrapTriggeredCallBack();
        m_lastEvent = 10;
    }
    else {
        std::cout << "Event data packet received but not identified" << std::endl;
        m_lastEvent = -1;
    }
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
