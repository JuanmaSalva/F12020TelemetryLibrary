#include "pch.h"
#include "TelemetryF1.h"
#include <thread>


TelemetryF1::TelemetryF1()
{
	packet_manager_ = new PacketManager();
	hasEnded_ = false;
}

TelemetryF1::~TelemetryF1()
{
	delete packet_manager_;
}


bool TelemetryF1::open_socket()
{
	WSADATA data;
	WORD version = MAKEWORD(2, 2);

	int wsOK = WSAStartup(version, &data);

	if (wsOK != 0) {
		std::cout << "Can't start winsock\n";
		return false;
	}

	sock = socket(AF_INET, SOCK_DGRAM, 0);
	sockaddr_in serverHint;
	serverHint.sin_family = AF_INET;
	serverHint.sin_port = htons(20777);
	inet_pton(AF_INET, "127.0.0.1", &serverHint.sin_addr);


	DWORD timeout = 1000;
	setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout, sizeof timeout);

	if (bind(sock, (sockaddr*)&serverHint, sizeof(serverHint)) == SOCKET_ERROR) {
		std::cout << "Can't bind\n";
		return false;
	}

	client;
	clientLength = sizeof(client);
	ZeroMemory(&client, sizeof(client));

	return true;
}

void TelemetryF1::start()
{
	char buf[4096];

	//main loop
	while (cycle)
	{
		int bytes = recvfrom(sock, buf, 4096, 0, (sockaddr*)&client, &clientLength);
		std::cout << "Mensaje recibido: " << bytes << "\n";
		packetsRecv++;

		if (bytes == SOCKET_ERROR) {
			std::cout << "Error on recv\n";
		}
		else
		{
			packet_manager_->newPacket(buf);
		}
	}
	
	close_socket();
	hasEnded_ = true;
}

void TelemetryF1::end()
{
	cycle = false;
}

bool TelemetryF1::close_socket()
{
	closesocket(sock);

	WSACleanup();

	return true;
}

bool TelemetryF1::hasEnded()
{
	return hasEnded_;
}

PacketManager* TelemetryF1::packet_manager()
{
	return packet_manager_;
}
