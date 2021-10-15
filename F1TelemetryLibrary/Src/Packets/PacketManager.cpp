#include "pch.h"
#include "PacketManager.h"


PacketManager::PacketManager()
{
    pHeader = PacketHeader();
    lapData_ = new PacketLapData();
    sessionData_ = new PacketSessionData();
    motionData_ = new PacketMotionData();
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
        break;
    case 5:
        std::cout << "Car Setups data\n";
        break;
    case 6:
        std::cout << "Car Telemetry data\n";
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
