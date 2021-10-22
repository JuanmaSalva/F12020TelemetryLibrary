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
	
    uint8_t frontWing() const {return m_frontWing;}
    uint8_t rearWing() const {return m_rearWing;}
    uint8_t onThrottle() const {return m_onThrottle;}
    uint8_t offThrottle() const {return m_offThrottle;}
    float frontCamber() const {return m_frontCamber;}
    float rearCamber() const {return m_rearCamber;}
    float frontToe() const {return m_frontToe;}
    float rearToe() const {return m_rearToe;}
    uint8_t frontSuspension() const {return m_frontSuspension;}
    uint8_t rearSuspension() const {return m_rearSuspension;}
    uint8_t frontAntiRollBar() const {return m_frontAntiRollBar;}
    uint8_t rearAntiRollBar() const {return m_rearAntiRollBar;}
    uint8_t frontSuspensionHeight() const {return m_frontSuspensionHeight;}
    uint8_t rearSuspensionHeight() const {return m_rearSuspensionHeight;}
    uint8_t brakePressure() const {return m_brakePressure;}
    uint8_t brakeBias() const {return m_brakeBias;}
    float rearLeftTyrePressure() const {return m_rearLeftTyrePressure;}
    float rearRightTyrePressure() const {return m_rearRightTyrePressure;}
    float frontLeftTyrePressure() const {return m_frontLeftTyrePressure;}
    float frontRightTyrePressure() const {return m_frontRightTyrePressure;}
    uint8_t ballast() const {return m_ballast;}
    float fuelLoad() const { return m_fuelLoad; }
};

struct PacketCarSetupData
{
private:
    CarSetupData    m_carSetups[22];

public:
    void update(char*& data);

    uint8_t frontWing(int8_t carIdx) const { return m_carSetups[carIdx].frontWing(); }
    uint8_t rearWing(int8_t carIdx) const { return m_carSetups[carIdx].rearWing(); }
    uint8_t onThrottle(int8_t carIdx) const { return m_carSetups[carIdx].onThrottle(); }
    uint8_t offThrottle(int8_t carIdx) const { return m_carSetups[carIdx].offThrottle(); }
    float frontCamber(int8_t carIdx) const { return m_carSetups[carIdx].frontCamber(); }
    float rearCamber(int8_t carIdx) const { return m_carSetups[carIdx].rearCamber(); }
    float frontToe(int8_t carIdx) const { return m_carSetups[carIdx].frontToe(); }
    float rearToe(int8_t carIdx) const { return m_carSetups[carIdx].rearToe(); }
    uint8_t frontSuspension(int8_t carIdx) const { return m_carSetups[carIdx].frontSuspension(); }
    uint8_t rearSuspension(int8_t carIdx) const { return m_carSetups[carIdx].rearSuspension(); }
    uint8_t frontAntiRollBar(int8_t carIdx) const { return m_carSetups[carIdx].frontAntiRollBar(); }
    uint8_t rearAntiRollBar(int8_t carIdx) const { return m_carSetups[carIdx].rearAntiRollBar(); }
    uint8_t frontSuspensionHeight(int8_t carIdx) const { return m_carSetups[carIdx].frontSuspensionHeight(); }
    uint8_t rearSuspensionHeight(int8_t carIdx) const { return m_carSetups[carIdx].rearSuspensionHeight(); }
    uint8_t brakePressure(int8_t carIdx) const { return m_carSetups[carIdx].brakePressure(); }
    uint8_t brakeBias(int8_t carIdx) const { return m_carSetups[carIdx].brakeBias(); }
    float rearLeftTyrePressure(int8_t carIdx) const { return m_carSetups[carIdx].rearLeftTyrePressure(); }
    float rearRightTyrePressure(int8_t carIdx) const { return m_carSetups[carIdx].rearRightTyrePressure(); }
    float frontLeftTyrePressure(int8_t carIdx) const { return m_carSetups[carIdx].frontLeftTyrePressure(); }
    float frontRightTyrePressure(int8_t carIdx) const { return m_carSetups[carIdx].frontRightTyrePressure(); }
    uint8_t ballast(int8_t carIdx) const { return m_carSetups[carIdx].ballast(); }
    float fuelLoad(int8_t carIdx) const { return m_carSetups[carIdx].fuelLoad(); }
};