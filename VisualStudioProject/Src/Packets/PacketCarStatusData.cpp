#include "pch.h"
#include "PacketCarStatusData.h"

CarStatusData::CarStatusData()
{
	for (int i = 0; i < 4; i++)
		m_tyresWear[4] = uint8_t();
	
	for (int i = 0; i < 4; i++)
		m_tyresDamage[4] = uint8_t();
}

void CarStatusData::fromBin(char*& data)
{
	memcpy(&m_tractionControl, data, sizeof(uint8_t)); data += sizeof(uint8_t);
	memcpy(&m_antiLockBrakes, data, sizeof(uint8_t)); data += sizeof(uint8_t);
	memcpy(&m_fuelMix, data, sizeof(uint8_t)); data += sizeof(uint8_t);
	memcpy(&m_frontBrakeBias, data, sizeof(uint8_t)); data += sizeof(uint8_t);
	memcpy(&m_pitLimiterStatus, data, sizeof(uint8_t)); data += sizeof(uint8_t);
	memcpy(&m_fuelInTank, data, sizeof(float)); data += sizeof(float);
	memcpy(&m_fuelCapacity, data, sizeof(float)); data += sizeof(float);
	memcpy(&m_fuelRemainingLaps, data, sizeof(float)); data += sizeof(float);
	memcpy(&m_maxRPM, data, sizeof(uint16_t)); data += sizeof(uint16_t);
	memcpy(&m_idleRPM, data, sizeof(uint16_t)); data += sizeof(uint16_t);
	memcpy(&m_maxGears, data, sizeof(uint8_t)); data += sizeof(uint8_t);
	memcpy(&m_drsAllowed, data, sizeof(uint8_t)); data += sizeof(uint8_t);

	memcpy(&m_drsActivationDistance, data, sizeof(uint16_t)); data += sizeof(uint16_t);

	memcpy(&m_tyresWear, data, sizeof(uint8_t) * 4); data += sizeof(uint8_t) * 4;
	memcpy(&m_actualTyreCompound, data, sizeof(uint8_t)); data += sizeof(uint8_t);
	memcpy(&m_visualTyreCompound, data, sizeof(uint8_t)); data += sizeof(uint8_t);
	memcpy(&m_tyresAgeLaps, data, sizeof(uint8_t)); data += sizeof(uint8_t);
	memcpy(&m_tyresDamage, data, sizeof(uint8_t) * 4); data += sizeof(uint8_t) * 4;
	memcpy(&m_frontLeftWingDamage, data, sizeof(uint8_t)); data += sizeof(uint8_t);
	memcpy(&m_frontRightWingDamage, data, sizeof(uint8_t)); data += sizeof(uint8_t);
	memcpy(&m_rearWingDamage, data, sizeof(uint8_t)); data += sizeof(uint8_t);

	memcpy(&m_drsFault, data, sizeof(uint8_t)); data += sizeof(uint8_t);
	memcpy(&m_engineDamage, data, sizeof(uint8_t)); data += sizeof(uint8_t);
	memcpy(&m_gearBoxDamage, data, sizeof(uint8_t)); data += sizeof(uint8_t);
	memcpy(&m_vehicleFiaFlags, data, sizeof(int8_t)); data += sizeof(int8_t);
	memcpy(&m_ersStoreEnergy, data, sizeof(float)); data += sizeof(float);
	memcpy(&m_ersDeployMode, data, sizeof(uint8_t)); data += sizeof(uint8_t);
	memcpy(&m_ersHarvestedThisLapMGUK, data, sizeof(float)); data += sizeof(float);
	memcpy(&m_ersHarvestedThisLapMGUH, data, sizeof(float)); data += sizeof(float);
	memcpy(&m_ersDeployedThisLap, data, sizeof(float)); data += sizeof(float);
	
}

PacketCarStatusData::PacketCarStatusData()
{
	for (CarStatusData& i : m_carStatusData)
		i = CarStatusData();
}

void PacketCarStatusData::update(char*& data)
{
	for (CarStatusData& i : m_carStatusData)
		i.fromBin(data);
}
