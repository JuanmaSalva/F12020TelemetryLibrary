#pragma once
#include "PacketHeader.h"

class Packet
{
public:
	Packet(char* buf);

private:
	PacketHeader pHeader;

	void ProcessPacket(char * &buf);
};

