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
}

PacketManager::~PacketManager()
{
    delete lapData_;
}

void PacketManager::newPacket(char* buf)
{
	//primero leemos el header del paquete para saber de que es
	pHeader.fromBin(buf);

    procesPacket(buf);
}

void PacketManager::procesPacket(char* buf) const
{
    switch (pHeader.m_packetId)
    {
    case 0:
        std::cout << "Motion data\n";
        motionData_->update(buf);
        break;
    case 1:
        std::cout << "Session data\n";
        sessionData_->update(buf);
        break;
    case 2:
    {
        std::cout << "Lap Data\n";
        lapData_->update(buf);
        break;
    }
    case 3:
        std::cout << "Event data\n";
        eventData_->update(buf);
        break;
    case 4:
        std::cout << "Participants data\n";
        participantsData_->update(buf);
        break;
    case 5:
        std::cout << "Car Setups data\n";
        carSetupsData_->update(buf);
        break;
    case 6:
        std::cout << "Car Telemetry data\n";
        carTelemetryData_->update(buf);
        break;
    case 7:
        std::cout << "Car Status data\n";
        break;
    case 8:
        std::cout << "Final Classification data\n";
        break;
    case 9:
        std::cout << "Lobby Info data\n";
        break;
    }
}
