#pragma once
#include <winsock2.h>
#include <WS2tcpip.h>
#include <iostream>
#pragma comment (lib, "Ws2_32.lib")
#include "Packets/PacketManager.h"


class TelemetryF1
{
public:
	TelemetryF1();
	~TelemetryF1();
	bool open_socket();
	void start();
	void end();
	bool close_socket();

	PacketManager* packet_manager();

	int b = 12;

private:

	int packetsRecv = 0;
	bool cycle = true;

	SOCKET sock;
	sockaddr_in client;
	int clientLength;

	PacketManager* packet_manager_;
};