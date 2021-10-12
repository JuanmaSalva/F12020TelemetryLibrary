#pragma once
#include "PacketHeader.h"
#include "PacketLapData.h"
#include "PacketSessionData.h"
#include "PacketMotionData.h"


static class PacketManager
{
public:
	PacketManager();
	~PacketManager();

	void newPacket(char* buf);

	PacketLapData* lap_data() const { return lapData_; }
	PacketSessionData* session_data() const { return sessionData_; }
	PacketMotionData* motion_data() const { return motionData_; }

private:
	PacketHeader pHeader;
	
	PacketLapData* lapData_;
	PacketSessionData* sessionData_;
	PacketMotionData* motionData_;

	
	void procesPacket(char* buf) const;

};
