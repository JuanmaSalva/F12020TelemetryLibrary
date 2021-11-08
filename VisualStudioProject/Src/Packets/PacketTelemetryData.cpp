#include "pch.h"
#include "PacketTelemetryData.h"

CarTelemetryData::CarTelemetryData()
{
	for (int i = 0; i < 4; i++)
		m_brakesTemperature[i] = 0;
	for (int i = 0; i < 4; i++)
		m_tyresSurfaceTemperature[i] = 0;
	for (int i = 0; i < 4; i++)
		m_tyresInnerTemperature[i] = 0;
	for (int i = 0; i < 4; i++)
		m_tyresPressure[i] = 0.0;
	for (int i = 0; i < 4; i++)
		m_surfaceType[i] = 0;
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

	memcpy(&m_brakesTemperature, data, sizeof(uint16_t)*4); data += sizeof(uint16_t)*4;
	memcpy(&m_tyresSurfaceTemperature, data, sizeof(uint8_t) * 4); data += sizeof(uint8_t) * 4;
	memcpy(&m_tyresInnerTemperature, data, sizeof(uint8_t) * 4); data += sizeof(uint8_t) * 4;
	memcpy(&m_engineTemperature, data, sizeof(uint16_t)); data += sizeof(uint16_t);
	memcpy(&m_tyresPressure, data, sizeof(float) * 4); data += sizeof(float) * 4;
	memcpy(&m_surfaceType, data, sizeof(uint8_t) * 4); data += sizeof(uint8_t) * 4;
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
