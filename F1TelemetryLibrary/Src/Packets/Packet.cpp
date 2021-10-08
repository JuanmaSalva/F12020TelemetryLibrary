#include "pch.h"
#include "Packet.h"
#include "PacketLapData.h"

Packet::Packet(char* buf)
{
	//system("cls"); //clear console

    //gets the hradear
	pHeader.FromBin(buf);
	//pHeader.Print();

    ProcessPacket(buf);
}

/// <summary>
/// Depending on the type of packet, it sends it to other parts of the program
/// </summary>
/// <param name="buf">Bytes read from de socket</param>
void Packet::ProcessPacket(char* &buf)
{
    switch (pHeader.m_packetId)
    {
    case 0:
        std::cout << "Motion\n";
        break;
    case 1:
        std::cout << "Session\n";
        break;
    case 2:
    {
        std::cout << "Lap Data\n";
        PacketLapData lapData = PacketLapData(buf);
        break; 
    }
    case 3:
        std::cout << "Event\n";
        break;
    case 4:
        std::cout << "Participants\n";
        break;
    case 5:
        std::cout << "Car Setups\n";
        break;
    case 6:
        std::cout << "Car Telemetry\n";
        break;
    case 7:
        std::cout << "Car Status\n";
        break;
    case 8:
        std::cout << "Final Classification\n";
        break;
    case 9:
        std::cout << "Lobby Info\n";
        break;
    }
}


