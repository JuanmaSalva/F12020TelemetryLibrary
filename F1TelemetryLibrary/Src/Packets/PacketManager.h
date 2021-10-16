#pragma once
#include "PacketHeader.h"
#include "PacketLapData.h"
#include "PacketSessionData.h"
#include "PacketMotionData.h"
#include "PacketEventData.h"
#include "PacketParticipantsData.h"


static class PacketManager
{
public:
	PacketManager();
	~PacketManager();

	void newPacket(char* buf);

	PacketLapData* lap_data() const { return lapData_; }
	PacketSessionData* session_data() const { return sessionData_; }
	PacketMotionData* motion_data() const { return motionData_; }
	PacketEventData* event_data() const { return eventData_; }
	PacketParticipantsData* participants_data() const { return participantsData_; }

private:
	PacketHeader pHeader;
	
	PacketLapData* lapData_;
	PacketSessionData* sessionData_;
	PacketMotionData* motionData_;
	PacketEventData* eventData_;
	PacketParticipantsData* participantsData_;

	
	void procesPacket(char* buf) const;
};
