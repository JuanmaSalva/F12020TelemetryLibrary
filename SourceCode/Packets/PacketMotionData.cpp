#include "pch.h"
#include "PacketMotionData.h"

void CarMotionData::fromBin(char*& data)
{
    memcpy(&m_worldPositionX, data, sizeof(float)); data += sizeof(float);
    memcpy(&m_worldPositionY, data, sizeof(float)); data += sizeof(float);
    memcpy(&m_worldPositionZ, data, sizeof(float)); data += sizeof(float);
    memcpy(&m_worldVelocityX, data, sizeof(float)); data += sizeof(float);
    memcpy(&m_worldVelocityY, data, sizeof(float)); data += sizeof(float);
    memcpy(&m_worldVelocityZ, data, sizeof(float)); data += sizeof(float);

    memcpy(&m_worldForwardDirX, data, sizeof(int16_t)); data += sizeof(int16_t);
    memcpy(&m_worldForwardDirY, data, sizeof(int16_t)); data += sizeof(int16_t);
    memcpy(&m_worldForwardDirZ, data, sizeof(int16_t)); data += sizeof(int16_t);
    memcpy(&m_worldRightDirX, data, sizeof(int16_t)); data += sizeof(int16_t);
    memcpy(&m_worldRightDirY, data, sizeof(int16_t)); data += sizeof(int16_t);
    memcpy(&m_worldRightDirZ, data, sizeof(int16_t)); data += sizeof(int16_t);

    memcpy(&m_gForceLateral, data, sizeof(float)); data += sizeof(float);
    memcpy(&m_gForceLongitudinal, data, sizeof(float)); data += sizeof(float);
    memcpy(&m_gForceVertical, data, sizeof(float)); data += sizeof(float);
    memcpy(&m_yaw, data, sizeof(float)); data += sizeof(float);
    memcpy(&m_pitch, data, sizeof(float)); data += sizeof(float);
    memcpy(&m_roll, data, sizeof(float)); data += sizeof(float);
}

void PacketMotionData::fromBin(char*& data)
{

    memcpy(&m_suspensionPosition, data, sizeof(float) * 4); data += sizeof(float) * 4;
    memcpy(&m_suspensionVelocity, data, sizeof(float) * 4); data += sizeof(float) * 4;
    memcpy(&m_suspensionAcceleration, data, sizeof(float) * 4); data += sizeof(float) * 4;
    memcpy(&m_wheelSpeed, data, sizeof(float) * 4); data += sizeof(float) * 4;
    memcpy(&m_wheelSlip, data, sizeof(float) * 4); data += sizeof(float) * 4;

    memcpy(&m_localVelocityX, data, sizeof(float)); data += sizeof(float);
    memcpy(&m_localVelocityY, data, sizeof(float)); data += sizeof(float);
    memcpy(&m_localVelocityZ, data, sizeof(float)); data += sizeof(float);
    memcpy(&m_angularVelocityX, data, sizeof(float)); data += sizeof(float);
    memcpy(&m_angularVelocityY, data, sizeof(float)); data += sizeof(float);
    memcpy(&m_angularVelocityZ, data, sizeof(float)); data += sizeof(float);
    memcpy(&m_angularAccelerationX, data, sizeof(float)); data += sizeof(float);
    memcpy(&m_angularAccelerationY, data, sizeof(float)); data += sizeof(float);
    memcpy(&m_angularAccelerationZ, data, sizeof(float)); data += sizeof(float);
    memcpy(&m_frontWheelsAngle, data, sizeof(float)); data += sizeof(float);
}

PacketMotionData::PacketMotionData()
{
    for (float& i : m_suspensionPosition)
	    i = 0.0;
    for (float& i : m_suspensionVelocity)
	    i = 0.0;
    for (float& i : m_suspensionAcceleration)
	    i = 0.0;
    for (float& i : m_wheelSpeed)
	    i = 0.0;
    for (float& i : m_wheelSlip)
	    i = 0.0;
	
    for (CarMotionData& i : m_carMotionData)
	    i = CarMotionData();
}

void PacketMotionData::update(char*& data)
{
    for (CarMotionData& i : m_carMotionData)
	    i.fromBin(data);

    fromBin(data);
}
