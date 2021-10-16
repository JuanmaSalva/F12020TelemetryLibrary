#pragma once
#include "iostream"

/// <summary>
/// Note: in multiplayer games, other player cars will appear as blank, you will only be able to see
/// your car setup and AI cars.
/// </summary>
struct CarSetupData
{
private:
    uint8_t   m_frontWing;                // Front wing aero
    uint8_t   m_rearWing;                 // Rear wing aero
    uint8_t   m_onThrottle;               // Differential adjustment on throttle (percentage)
    uint8_t   m_offThrottle;              // Differential adjustment off throttle (percentage)
    float     m_frontCamber;              // Front camber angle (suspension geometry)
    float     m_rearCamber;               // Rear camber angle (suspension geometry)
    float     m_frontToe;                 // Front toe angle (suspension geometry)
    float     m_rearToe;                  // Rear toe angle (suspension geometry)
    uint8_t   m_frontSuspension;          // Front suspension
    uint8_t   m_rearSuspension;           // Rear suspension
    uint8_t   m_frontAntiRollBar;         // Front anti-roll bar
    uint8_t   m_rearAntiRollBar;          // Front anti-roll bar
    uint8_t   m_frontSuspensionHeight;    // Front ride height
    uint8_t   m_rearSuspensionHeight;     // Rear ride height
    uint8_t   m_brakePressure;            // Brake pressure (percentage)
    uint8_t   m_brakeBias;                // Brake bias (percentage)
    float     m_rearLeftTyrePressure;     // Rear left tyre pressure (PSI)
    float     m_rearRightTyrePressure;    // Rear right tyre pressure (PSI)
    float     m_frontLeftTyrePressure;    // Front left tyre pressure (PSI)
    float     m_frontRightTyrePressure;   // Front right tyre pressure (PSI)
    uint8_t   m_ballast;                  // Ballast
    float     m_fuelLoad;                 // Fuel load

public:
    void fromBin(char*& data);
	
    uint8_t frontWing(){return m_frontWing;}
    uint8_t rearWing(){return m_rearWing;}
    uint8_t onThrottle(){return m_onThrottle;}
    uint8_t offThrottle(){return m_offThrottle;}
    float frontCamber(){return m_frontCamber;}
    float rearCamber(){return m_rearCamber;}
    float frontToe(){return m_frontToe;}
    float rearToe(){return m_rearToe;}
    uint8_t frontSuspension(){return m_frontSuspension;}
    uint8_t rearSuspension(){return m_rearSuspension;}
    uint8_t frontAntiRollBar(){return m_frontAntiRollBar;}
    uint8_t rearAntiRollBar(){return m_rearAntiRollBar;}
    uint8_t frontSuspensionHeight(){return m_frontSuspensionHeight;}
    uint8_t rearSuspensionHeight(){return m_rearSuspensionHeight;}
    uint8_t brakePressure(){return m_brakePressure;}
    uint8_t brakeBias(){return m_brakeBias;}
    float rearLeftTyrePressure(){return m_rearLeftTyrePressure;}
    float rearRightTyrePressure(){return m_rearRightTyrePressure;}
    float frontLeftTyrePressure(){return m_frontLeftTyrePressure;}
    float frontRightTyrePressure(){return m_frontRightTyrePressure;}
    uint8_t ballast(){return m_ballast;}
    float fuelLoad() { return m_fuelLoad; }
};

struct PacketCarSetupData
{
private:
    CarSetupData    m_carSetups[22];

public:
    void update(char*& data);

    uint8_t frontWing(int8_t carIdx) { return m_carSetups[carIdx].frontWing(); }
    uint8_t rearWing(int8_t carIdx) { return m_carSetups[carIdx].rearWing(); }
    uint8_t onThrottle(int8_t carIdx) { return m_carSetups[carIdx].onThrottle(); }
    uint8_t offThrottle(int8_t carIdx) { return m_carSetups[carIdx].offThrottle(); }
    float frontCamber(int8_t carIdx) { return m_carSetups[carIdx].frontCamber(); }
    float rearCamber(int8_t carIdx) { return m_carSetups[carIdx].rearCamber(); }
    float frontToe(int8_t carIdx) { return m_carSetups[carIdx].frontToe(); }
    float rearToe(int8_t carIdx) { return m_carSetups[carIdx].rearToe(); }
    uint8_t frontSuspension(int8_t carIdx) { return m_carSetups[carIdx].frontSuspension(); }
    uint8_t rearSuspension(int8_t carIdx) { return m_carSetups[carIdx].rearSuspension(); }
    uint8_t frontAntiRollBar(int8_t carIdx) { return m_carSetups[carIdx].frontAntiRollBar(); }
    uint8_t rearAntiRollBar(int8_t carIdx) { return m_carSetups[carIdx].rearAntiRollBar(); }
    uint8_t frontSuspensionHeight(int8_t carIdx) { return m_carSetups[carIdx].frontSuspensionHeight(); }
    uint8_t rearSuspensionHeight(int8_t carIdx) { return m_carSetups[carIdx].rearSuspensionHeight(); }
    uint8_t brakePressure(int8_t carIdx) { return m_carSetups[carIdx].brakePressure(); }
    uint8_t brakeBias(int8_t carIdx) { return m_carSetups[carIdx].brakeBias(); }
    float rearLeftTyrePressure(int8_t carIdx) { return m_carSetups[carIdx].rearLeftTyrePressure(); }
    float rearRightTyrePressure(int8_t carIdx) { return m_carSetups[carIdx].rearRightTyrePressure(); }
    float frontLeftTyrePressure(int8_t carIdx) { return m_carSetups[carIdx].frontLeftTyrePressure(); }
    float frontRightTyrePressure(int8_t carIdx) { return m_carSetups[carIdx].frontRightTyrePressure(); }
    uint8_t ballast(int8_t carIdx) { return m_carSetups[carIdx].ballast(); }
    float fuelLoad(int8_t carIdx) { return m_carSetups[carIdx].fuelLoad(); }
};