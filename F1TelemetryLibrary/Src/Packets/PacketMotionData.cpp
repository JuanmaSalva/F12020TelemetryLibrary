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
    for (float& i : m_suspensionPosition) memcpy(&i, data, sizeof(float)); data += sizeof(float);
    for (float& i : m_suspensionVelocity) memcpy(&i, data, sizeof(float)); data += sizeof(float);
    for (float& i : m_suspensionAcceleration) memcpy(&i, data, sizeof(float)); data += sizeof(float);
    for (float& i : m_wheelSpeed) memcpy(&i, data, sizeof(float)); data += sizeof(float);
    for (float& i : m_wheelSlip) memcpy(&i, data, sizeof(float)); data += sizeof(float);

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

void PacketMotionData::update(char*& data)
{
    for (CarMotionData motion_data : m_carMotionData)
    {
        motion_data = CarMotionData();
        motion_data.fromBin(data);
    }

    fromBin(data);
}
