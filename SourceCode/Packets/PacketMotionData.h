#pragma once
#include "iostream"

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
    
    void fromBin(char*& data);
};



struct PacketMotionData
{
private:
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

    void fromBin(char*& data);

public:
    PacketMotionData();
	
    void update(char*& data);
        	
    //GETTERS
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

    float suspensionPosition(int8_t tyre) const { return  m_suspensionPosition[tyre]; }
    float suspensionVelocity(int8_t tyre) const { return m_suspensionVelocity[tyre]; }
    float suspensionAcceleration(int8_t tyre) const { return m_suspensionAcceleration[tyre]; }
    float wheelSpeed(int8_t tyre) const { return m_wheelSpeed[tyre]; }
    float wheelSlip(int8_t tyre) const { return m_wheelSlip[tyre]; }
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