#include "pch.h"
#include "PacketCarStatusData.h"

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
	for (uint8_t& i : m_tyresWear) memcpy(&i, data, sizeof(uint8_t)); data += sizeof(uint8_t);
	memcpy(&m_actualTyreCompound, data, sizeof(uint8_t)); data += sizeof(uint8_t);
	memcpy(&m_visualTyreCompound, data, sizeof(uint8_t)); data += sizeof(uint8_t);
	memcpy(&m_tyresAgeLaps, data, sizeof(uint8_t)); data += sizeof(uint8_t);
	for (uint8_t& i : m_tyresDamage) memcpy(&i, data, sizeof(uint8_t)); data += sizeof(uint8_t);
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

void PacketCarStatusData::update(char*& data)
{
	for(CarStatusData status_data: m_carStatusData)
	{
		status_data = CarStatusData();
		status_data.fromBin(data);
	}
}
