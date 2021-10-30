#include "pch.h"
#include "PacketManager.h"


PacketManager::PacketManager()
{
	pHeader = PacketHeader();
	motionData_ = new PacketMotionData();
	sessionData_ = new PacketSessionData();
	lapData_ = new PacketLapData();
	eventData_ = new PacketEventData();
	participantsData_ = new PacketParticipantsData();
	carSetupsData_ = new PacketCarSetupData();
	carTelemetryData_ = new PacketCarTelemetryData();
	carStatusData_ = new PacketCarStatusData();
	finalClassificationData_ = new PacketFinalClassificationData();
	lobbyData_ = new PacketLobbyInfoData();
}

PacketManager::~PacketManager()
{
	delete motionData_;
	delete sessionData_;
	delete lapData_;
	delete eventData_;
	delete participantsData_;
	delete carSetupsData_;
	delete carTelemetryData_;
	delete carStatusData_;
	delete finalClassificationData_;
	delete lobbyData_;
}

void PacketManager::newPacket(char* buf)
{
	//primero leemos el header del paquete para saber de que es
	pHeader.fromBin(buf);
	m_playerCarIndex = pHeader.playerCarIndex();
	
	procesPacket(buf);
}

void PacketManager::procesPacket(char*& buf)
{
	switch (pHeader.packetId())
	{
	case 0:
	{
		std::cout << "Motion data\n";
		motionData_->update(buf);
		break;
	}
	case 1:
	{
		std::cout << "Session data\n";
		sessionData_->update(buf);
		break;
	}
	case 2:
	{
		std::cout << "Lap Data\n";
		lapData_->update(buf);
		break;
	}
	case 3:
	{
		std::cout << "Event data\n";
		eventData_->update(buf);
		break;
	}
	case 4:
	{
		std::cout << "Participants data\n";
		participantsData_->update(buf);
		break;
	}
	case 5:
	{
		std::cout << "Car Setups data\n";
		carSetupsData_->update(buf);
		break;
	}
	case 6:
	{
		std::cout << "Car Telemetry data\n";
		carTelemetryData_->update(buf);
		break;
	}
	case 7:
		std::cout << "Car Status data\n";
		carStatusData_->update(buf);
		break;
	case 8:
	{
		std::cout << "Final Classification data\n";
		finalClassificationData_->update(buf);
		break;
	}
	case 9:
	{
		std::cout << "Lobby Info data\n";
		lobbyData_->update(buf);
		break;
	}
	}
}
