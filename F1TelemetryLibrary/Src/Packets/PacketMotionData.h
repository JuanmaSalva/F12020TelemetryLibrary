#pragma once
#include <iostream>

struct CarMotionData
{
    float         m_worldPositionX;           // World space X position
    float         m_worldPositionY;           // World space Y position
    float         m_worldPositionZ;           // World space Z position
    float         m_worldVelocityX;           // Velocity in world space X
    float         m_worldVelocityY;           // Velocity in world space Y
    float         m_worldVelocityZ;           // Velocity in world space Z
    int16_t       m_worldForwardDirX;         // World space forward X direction (normalised)
    int16_t       m_worldForwardDirY;         // World space forward Y direction (normalised)
    int16_t       m_worldForwardDirZ;         // World space forward Z direction (normalised)
    int16_t       m_worldRightDirX;           // World space right X direction (normalised)
    int16_t       m_worldRightDirY;           // World space right Y direction (normalised)
    int16_t       m_worldRightDirZ;           // World space right Z direction (normalised)
    float         m_gForceLateral;            // Lateral G-Force component
    float         m_gForceLongitudinal;       // Longitudinal G-Force component
    float         m_gForceVertical;           // Vertical G-Force component
    float         m_yaw;                      // Yaw angle in radians
    float         m_pitch;                    // Pitch angle in radians
    float         m_roll;                     // Roll angle in radians


    void FromBin(char* &data)
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
};



struct PacketMotionData
{
    CarMotionData   m_carMotionData[22];    	// Data for all cars on track

    // Extra player car ONLY data
    float         m_suspensionPosition[4];      // Note: All wheel arrays have the following order:
    float         m_suspensionVelocity[4];      // RL, RR, FL, FR
    float         m_suspensionAcceleration[4];	// RL, RR, FL, FR
    float         m_wheelSpeed[4];           	// Speed of each wheel
    float         m_wheelSlip[4];               // Slip ratio for each wheel
    float         m_localVelocityX;         	// Velocity in local space
    float         m_localVelocityY;         	// Velocity in local space
    float         m_localVelocityZ;         	// Velocity in local space
    float         m_angularVelocityX;           // Angular velocity x-component
    float         m_angularVelocityY;           // Angular velocity y-component
    float         m_angularVelocityZ;           // Angular velocity z-component
    float         m_angularAccelerationX;       // Angular velocity x-component
    float         m_angularAccelerationY;	    // Angular velocity y-component
    float         m_angularAccelerationZ;       // Angular velocity z-component
    float         m_frontWheelsAngle;           // Current front wheels angle in radians

    void FromBin(char* &data)
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

    PacketMotionData() {};
	
    void update(char* data)
	{
		for (CarMotionData motion_data : m_carMotionData)
		{
            motion_data = CarMotionData();
            motion_data.FromBin(data);
		}

        FromBin(data);		
	}

    float worldPositionX(int8_t carId) const { return m_carMotionData[carId].m_worldPositionX; }
    float worldPositionY(int8_t carId) const { return m_carMotionData[carId].m_worldPositionY; }
    float worldPositionZ(int8_t carId) const { return m_carMotionData[carId].m_worldPositionZ; }
    float worldVelocityX(int8_t carId) const { return m_carMotionData[carId].m_worldVelocityX; }
    float worldVelocityY(int8_t carId) const { return m_carMotionData[carId].m_worldVelocityY; }
    float worldVelocityZ(int8_t carId) const { return m_carMotionData[carId].m_worldVelocityZ; }
    int16_t worldForwardDirX(int8_t carId) const { return m_carMotionData[carId].m_worldForwardDirX; }
    int16_t worldForwardDirY(int8_t carId) const { return m_carMotionData[carId].m_worldForwardDirY; }
    int16_t worldForwardDirZ(int8_t carId) const { return m_carMotionData[carId].m_worldForwardDirZ; }
    int16_t worldRightDirX(int8_t carId) const { return m_carMotionData[carId].m_worldRightDirX; }
    int16_t worldRightDirY(int8_t carId) const { return m_carMotionData[carId].m_worldRightDirY; }
    int16_t worldRightDirZ(int8_t carId) const { return m_carMotionData[carId].m_worldRightDirZ; }
    float gForceLateral(int8_t carId) const { return m_carMotionData[carId].m_gForceLateral; }
    float gForceLongitudinal(int8_t carId) const { return m_carMotionData[carId].m_gForceLongitudinal; }
    float gForceVertical(int8_t carId) const { return m_carMotionData[carId].m_gForceVertical; }
    float yaw(int8_t carId) const { return m_carMotionData[carId].m_yaw; }
    float pitch(int8_t carId) const { return m_carMotionData[carId].m_pitch; }
    float roll(int8_t carId) const { return m_carMotionData[carId].m_roll; }

    float suspensionPositionRL() const { return m_suspensionPosition[0]; }
    float suspensionPositionRR() const { return m_suspensionPosition[1]; }
    float suspensionPositionFL() const { return m_suspensionPosition[2]; }
    float suspensionPositionFR() const { return m_suspensionPosition[3]; }
    float suspensionVelocityRL() const { return m_suspensionVelocity[0]; }
    float suspensionVelocityRR() const { return m_suspensionVelocity[1]; }
    float suspensionVelocityFL() const { return m_suspensionVelocity[2]; }
    float suspensionVelocityFR() const { return m_suspensionVelocity[3]; }
    float suspensionAccelerationRL() const { return m_suspensionAcceleration[0]; }
    float suspensionAccelerationRR() const { return m_suspensionAcceleration[1]; }
    float suspensionAccelerationFL() const { return m_suspensionAcceleration[2]; }
    float suspensionAccelerationFR() const { return m_suspensionAcceleration[3]; }
    float wheelSpeedRL() const { return m_wheelSpeed[0]; }
    float wheelSpeedRR() const { return m_wheelSpeed[1]; }
    float wheelSpeedFL() const { return m_wheelSpeed[2]; }
    float wheelSpeedFR() const { return m_wheelSpeed[3]; }
    float wheelSlipRL() const { return m_wheelSlip[0]; }
    float wheelSlipRR() const { return m_wheelSlip[1]; }
    float wheelSlipFL() const { return m_wheelSlip[2]; }
    float wheelSlipFR() const { return m_wheelSlip[3]; }
    float localVelocityX()const { return m_localVelocityX; }
    float localVelocityY()const { return m_localVelocityY; }
    float localVelocityZ()const { return m_localVelocityZ; }
    float angularVelocityX()const { return m_angularVelocityX; }
    float angularVelocityY()const { return m_angularVelocityY; }
    float angularVelocityZ()const { return m_angularVelocityZ; }
    float angularAccelerationX()const { return m_angularAccelerationX; }
    float angularAccelerationY()const { return m_angularAccelerationY; }
    float angularAccelerationZ()const { return m_angularAccelerationZ; }
    float frontWheelsAngle()const { return m_frontWheelsAngle; }
};