#pragma once
#include "PacketHeader.h"
#include "PacketLapData.h"
#include "PacketMotionData.h"


static class PacketManager
{
public:
	PacketManager();
	~PacketManager();

	void newPacket(char* buf);

	PacketLapData* lap_data() const { return lapData_; }
	PacketMotionData* motion_data() const { return motionData_; }

private:
	PacketHeader pHeader;
	
	PacketLapData* lapData_;
	PacketMotionData* motionData_;

	
	void procesPacket(char* buf) const;

};
