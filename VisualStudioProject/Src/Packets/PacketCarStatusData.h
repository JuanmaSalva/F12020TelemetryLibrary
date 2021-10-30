#pragma once
#include "iostream"

struct CarStatusData
{
private:
    uint8_t     m_tractionControl;          // 0 (off) - 2 (high)
    uint8_t     m_antiLockBrakes;           // 0 (off) - 1 (on)
    uint8_t     m_fuelMix;                  // Fuel mix - 0 = lean, 1 = standard, 2 = rich, 3 = max
    uint8_t     m_frontBrakeBias;           // Front brake bias (percentage)
    uint8_t     m_pitLimiterStatus;         // Pit limiter status - 0 = off, 1 = on
    float       m_fuelInTank;               // Current fuel mass
    float       m_fuelCapacity;             // Fuel capacity
    float       m_fuelRemainingLaps;        // Fuel remaining in terms of laps (value on MFD)
    uint16_t    m_maxRPM;                   // Cars max RPM, point of rev limiter
    uint16_t    m_idleRPM;                  // Cars idle RPM
    uint8_t     m_maxGears;                 // Maximum number of gears
    uint8_t     m_drsAllowed;               // 0 = not allowed, 1 = allowed, -1 = unknown


    // Added in Beta3:
    uint16_t    m_drsActivationDistance;    // 0 = DRS not available, non-zero - DRS will be available
                                            // in [X] metres

    uint8_t     m_tyresWear[4];             // Tyre wear percentage
    uint8_t     m_actualTyreCompound;	    // F1 Modern -- 16 = C5, 17 = C4, 18 = C3, 19 = C2, 20 = C1
					                        // 7 = inter, 8 = wet
					                        // F1 Classic - 9 = dry, 10 = wet
					                        // F2 � 11 = super soft, 12 = soft, 13 = medium, 14 = hard
					                        // 15 = wet
    uint8_t     m_visualTyreCompound;       // F1 visual (can be different from actual compound)
                                            // 16 = soft, 17 = medium, 18 = hard, 7 = inter, 8 = wet
                                            // F1 Classic � same as above
                                            // F2 � same as above
    uint8_t     m_tyresAgeLaps;             // Age in laps of the current set of tyres
    uint8_t     m_tyresDamage[4];           // Tyre damage (percentage)
    uint8_t     m_frontLeftWingDamage;      // Front left wing damage (percentage)
    uint8_t     m_frontRightWingDamage;     // Front right wing damage (percentage)
    uint8_t     m_rearWingDamage;           // Rear wing damage (percentage)

    // Added Beta 3:
    uint8_t     m_drsFault;                 // Indicator for DRS fault, 0 = OK, 1 = fault

    uint8_t     m_engineDamage;             // Engine damage (percentage)
    uint8_t     m_gearBoxDamage;            // Gear box damage (percentage)
    int8_t      m_vehicleFiaFlags;          // -1 = invalid/unknown, 0 = none, 1 = green
                                            // 2 = blue, 3 = yellow, 4 = red
    float       m_ersStoreEnergy;           // ERS energy store in Joules
    uint8_t     m_ersDeployMode;            // ERS deployment mode, 0 = none, 1 = medium
                                            // 2 = overtake, 3 = hotlap
    float       m_ersHarvestedThisLapMGUK;  // ERS energy harvested this lap by MGU-K
    float       m_ersHarvestedThisLapMGUH;  // ERS energy harvested this lap by MGU-H
    float       m_ersDeployedThisLap;       // ERS energy deployed this lap

public:
    CarStatusData();
	
    void fromBin(char*& data);

    uint8_t tractionControl() const {return m_tractionControl;}
    uint8_t antiLockBrakes() const {return m_antiLockBrakes;}
    uint8_t fuelMix() const {return m_fuelMix;}
    uint8_t frontBrakeBias() const {return m_frontBrakeBias;}
    uint8_t pitLimiterStatus() const {return m_pitLimiterStatus;}
    float fuelInTank() const {return m_fuelInTank;}
    float fuelCapacity() const {return m_fuelCapacity;}
    float fuelRemainingLaps() const {return m_fuelRemainingLaps;}
    uint16_t maxRPM() const {return m_maxRPM;}
    uint16_t idleRPM() const {return m_idleRPM;}
    uint8_t maxGears() const {return m_maxGears;}
    uint8_t drsAllowed() const {return m_drsAllowed;}
    uint16_t drsActivationDistance() const {return m_drsActivationDistance;}
    uint8_t tyresWear(int8_t  tyre) const {return m_tyresWear[tyre];}
    uint8_t actualTyreCompound() const {return m_actualTyreCompound;}
    uint8_t visualTyreCompound() const {return m_visualTyreCompound;}
    uint8_t tyresAgeLaps() const {return m_tyresAgeLaps;}
    uint8_t tyresDamage(int8_t tyre) const {return m_tyresDamage[tyre];}
    uint8_t frontLeftWingDamage() const {return m_frontLeftWingDamage;}
    uint8_t frontRightWingDamage() const {return m_frontRightWingDamage;}
    uint8_t rearWingDamage() const {return m_rearWingDamage;}
    uint8_t drsFault() const {return m_drsFault;}
    uint8_t gearBoxDamage() const {return m_gearBoxDamage;}
    float ersStoreEnergy() const {return m_ersStoreEnergy;}
    uint8_t ersDeployMode() const {return m_ersDeployMode;}
    float ersHarvestedThisLapMGUK() const {return m_ersHarvestedThisLapMGUK;}
    float ersHarvestedThisLapMGUH() const {return m_ersHarvestedThisLapMGUH;}
    float ersDeployedThisLap() const {return m_ersDeployedThisLap;}
};

struct PacketCarStatusData
{
private:
    CarStatusData	m_carStatusData[22];

public:
    PacketCarStatusData();
	
    void update(char*& data);

    uint8_t tractionControl(int8_t carIdx) const { return m_carStatusData[carIdx].tractionControl(); }
    uint8_t antiLockBrakes(int8_t carIdx) const { return m_carStatusData[carIdx].antiLockBrakes(); }
    uint8_t fuelMix(int8_t carIdx) const { return m_carStatusData[carIdx].fuelMix(); }
    uint8_t frontBrakeBias(int8_t carIdx) const { return m_carStatusData[carIdx].frontBrakeBias(); }
    uint8_t pitLimiterStatus(int8_t carIdx) const { return m_carStatusData[carIdx].pitLimiterStatus(); }
    float fuelInTank(int8_t carIdx) const { return m_carStatusData[carIdx].fuelInTank(); }
    float fuelCapacity(int8_t carIdx) const { return m_carStatusData[carIdx].fuelCapacity(); }
    float fuelRemainingLaps(int8_t carIdx) const { return m_carStatusData[carIdx].fuelRemainingLaps(); }
    uint16_t maxRPM(int8_t carIdx) const { return m_carStatusData[carIdx].maxRPM(); }
    uint16_t idleRPM(int8_t carIdx) const { return m_carStatusData[carIdx].idleRPM(); }
    uint8_t maxGears(int8_t carIdx) const { return m_carStatusData[carIdx].maxGears(); }
    uint8_t drsAllowed(int8_t carIdx) const { return m_carStatusData[carIdx].drsAllowed(); }
    uint16_t drsActivationDistance(int8_t carIdx) const { return m_carStatusData[carIdx].drsActivationDistance(); }
    uint8_t tyresWear(int8_t carIdx,  int8_t tyre) const { return m_carStatusData[carIdx].tyresWear(tyre); }
    uint8_t actualTyreCompound(int8_t carIdx) const { return m_carStatusData[carIdx].actualTyreCompound(); }
    uint8_t visualTyreCompound(int8_t carIdx) const { return m_carStatusData[carIdx].visualTyreCompound(); }
    uint8_t tyresAgeLaps(int8_t carIdx) const { return m_carStatusData[carIdx].tyresAgeLaps(); }
    uint8_t tyresDamage(int8_t carIdx,  int8_t tyre) const { return m_carStatusData[carIdx].tyresDamage(tyre); }
    uint8_t frontLeftWingDamage(int8_t carIdx) const { return m_carStatusData[carIdx].frontLeftWingDamage(); }
    uint8_t frontRightWingDamage(int8_t carIdx) const { return m_carStatusData[carIdx].frontRightWingDamage(); }
    uint8_t rearWingDamage(int8_t carIdx) const { return m_carStatusData[carIdx].rearWingDamage(); }
    uint8_t drsFault(int8_t carIdx) const { return m_carStatusData[carIdx].drsFault(); }
    uint8_t gearBoxDamage(int8_t carIdx) const { return m_carStatusData[carIdx].gearBoxDamage(); }
    float ersStoreEnergy(int8_t carIdx) const { return m_carStatusData[carIdx].ersStoreEnergy(); }
    uint8_t ersDeployMode(int8_t carIdx) const { return m_carStatusData[carIdx].ersDeployMode(); }
    float ersHarvestedThisLapMGUK(int8_t carIdx) const { return m_carStatusData[carIdx].ersHarvestedThisLapMGUK(); }
    float ersHarvestedThisLapMGUH(int8_t carIdx) const { return m_carStatusData[carIdx].ersHarvestedThisLapMGUH(); }
    float ersDeployedThisLap(int8_t carIdx) const { return m_carStatusData[carIdx].ersDeployedThisLap(); }
};