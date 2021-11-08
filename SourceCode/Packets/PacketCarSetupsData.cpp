#include "pch.h"
#include "PacketCarSetupsData.h"

void CarSetupData::fromBin(char*& data)
{
	memcpy(&m_frontWing, data, sizeof(uint8_t)); data += sizeof(uint8_t);
	memcpy(&m_rearWing, data, sizeof(uint8_t)); data += sizeof(uint8_t);
	memcpy(&m_onThrottle, data, sizeof(uint8_t)); data += sizeof(uint8_t);
	memcpy(&m_offThrottle, data, sizeof(uint8_t)); data += sizeof(uint8_t);

	memcpy(&m_frontCamber, data, sizeof(float)); data += sizeof(float);
	memcpy(&m_rearCamber, data, sizeof(float)); data += sizeof(float);
	memcpy(&m_frontToe, data, sizeof(float)); data += sizeof(float);
	memcpy(&m_rearToe, data, sizeof(float)); data += sizeof(float);

	memcpy(&m_frontSuspension, data, sizeof(uint8_t)); data += sizeof(uint8_t);
	memcpy(&m_rearSuspension, data, sizeof(uint8_t)); data += sizeof(uint8_t);
	memcpy(&m_frontAntiRollBar, data, sizeof(uint8_t)); data += sizeof(uint8_t);
	memcpy(&m_rearAntiRollBar, data, sizeof(uint8_t)); data += sizeof(uint8_t);
	memcpy(&m_frontSuspensionHeight, data, sizeof(uint8_t)); data += sizeof(uint8_t);
	memcpy(&m_rearSuspensionHeight, data, sizeof(uint8_t)); data += sizeof(uint8_t);
	memcpy(&m_brakePressure, data, sizeof(uint8_t)); data += sizeof(uint8_t);
	memcpy(&m_brakeBias, data, sizeof(uint8_t)); data += sizeof(uint8_t);

	memcpy(&m_rearLeftTyrePressure, data, sizeof(float)); data += sizeof(float);
	memcpy(&m_rearRightTyrePressure, data, sizeof(float)); data += sizeof(float);
	memcpy(&m_frontLeftTyrePressure, data, sizeof(float)); data += sizeof(float);
	memcpy(&m_frontRightTyrePressure, data, sizeof(float)); data += sizeof(float);

	memcpy(&m_ballast, data, sizeof(uint8_t)); data += sizeof(uint8_t);

	memcpy(&m_fuelLoad, data, sizeof(float)); data += sizeof(float);
}

PacketCarSetupData::PacketCarSetupData()
{
	for (CarSetupData& m_carSetup : m_carSetups)
		m_carSetup = CarSetupData();
}

void PacketCarSetupData::update(char*& data)
{
	for (CarSetupData& m_carSetup : m_carSetups)
		m_carSetup.fromBin(data);
}
