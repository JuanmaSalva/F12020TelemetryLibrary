#pragma once
#include "PacketHeader.h"
#include "PacketLapData.h"
#include "PacketSessionData.h"
#include "PacketMotionData.h"
#include "PacketEventData.h"
#include "PacketParticipantsData.h"
#include "PacketCarSetupsData.h"
#include "PacketTelemetryData.h"


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
	PacketCarSetupData* car_setup_data() const { return carSetupsData_; }
	PacketCarTelemetryData* car_telemetry_data() const { return carTelemetryData_; }

private:
	PacketHeader pHeader;
	
	PacketLapData* lapData_;
	PacketSessionData* sessionData_;
	PacketMotionData* motionData_;
	PacketEventData* eventData_;
	PacketParticipantsData* participantsData_;
	PacketCarSetupData* carSetupsData_;
	PacketCarTelemetryData* carTelemetryData_;

	
	void procesPacket(char* buf) const;
};
