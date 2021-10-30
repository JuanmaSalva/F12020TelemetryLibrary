#include "pch.h"
#include "PacketTelemetryData.h"

CarTelemetryData::CarTelemetryData()
{
	for (uint16_t& i : m_brakesTemperature)
		i = 0;
	for (uint8_t& i : m_tyresSurfaceTemperature)
		i = 0;
	for (uint8_t& i : m_tyresInnerTemperature)
		i = 0;
	for (float& i : m_tyresPressure)
		i = 0.0;
	for (uint8_t& i : m_surfaceType)
		i = 0;
}

void CarTelemetryData::fromBin(char*& data)
{
	memcpy(&m_speed, data, sizeof(uint16_t)); data += sizeof(uint16_t);
	memcpy(&m_throttle, data, sizeof(float)); data += sizeof(float);
	memcpy(&m_steer, data, sizeof(float)); data += sizeof(float);
	memcpy(&m_brake, data, sizeof(float)); data += sizeof(float);
	memcpy(&m_clutch, data, sizeof(uint8_t)); data += sizeof(uint8_t);
	memcpy(&m_gear, data, sizeof(int8_t)); data += sizeof(int8_t);
	memcpy(&m_engineRPM, data, sizeof(uint16_t)); data += sizeof(uint16_t);
	memcpy(&m_drs, data, sizeof(uint8_t)); data += sizeof(uint8_t);
	memcpy(&m_revLightsPercent, data, sizeof(uint8_t)); data += sizeof(uint8_t);
	for (uint16_t& i : m_brakesTemperature) memcpy(&i, data, sizeof(uint16_t)); data += sizeof(uint16_t);
	for (uint8_t& i : m_tyresSurfaceTemperature) memcpy(&i, data, sizeof(uint8_t)); data += sizeof(uint8_t);
	for (uint8_t& i : m_tyresInnerTemperature) memcpy(&i, data, sizeof(uint8_t)); data += sizeof(uint8_t);
	memcpy(&m_engineTemperature, data, sizeof(uint16_t)); data += sizeof(uint16_t);
	for (float& i : m_tyresPressure) memcpy(&i, data, sizeof(float)); data += sizeof(float);
	for (uint8_t& i : m_surfaceType) memcpy(&i, data, sizeof(uint8_t)); data += sizeof(uint8_t);

}

void PacketCarTelemetryData::fromBin(char*& data)
{
	memcpy(&m_buttonStatus, data, sizeof(uint32_t)); data += sizeof(uint32_t);
	memcpy(&m_mfdPanelIndex, data, sizeof(uint8_t)); data += sizeof(uint8_t);
	memcpy(&m_mfdPanelIndexSecondaryPlayer, data, sizeof(uint8_t)); data += sizeof(uint8_t);
	memcpy(&m_suggestedGear, data, sizeof(int8_t)); data += sizeof(int8_t);
}

PacketCarTelemetryData::PacketCarTelemetryData()
{
	for (CarTelemetryData& i : m_carTelemetryData)
		i = CarTelemetryData();
}

void PacketCarTelemetryData::update(char*& data)
{
	for (CarTelemetryData& i : m_carTelemetryData)
		i.fromBin(data);

	fromBin(data);
}
