#pragma once
#include "iostream"

struct CarTelemetryData
{
private:
	uint16_t    m_speed;                         // Speed of car in kilometres per hour
	float		m_throttle;                      // Amount of throttle applied (0.0 to 1.0)
	float		m_steer;                         // Steering (-1.0 (full lock left) to 1.0 (full lock right))
	float		m_brake;                         // Amount of brake applied (0.0 to 1.0)
	uint8_t     m_clutch;                        // Amount of clutch applied (0 to 100)
	int8_t      m_gear;                          // Gear selected (1-8, N=0, R=-1)
	uint16_t    m_engineRPM;                     // Engine RPM
	uint8_t     m_drs;                           // 0 = off, 1 = on
	uint8_t     m_revLightsPercent;              // Rev lights indicator (percentage)
	uint16_t    m_brakesTemperature[4];          // Brakes temperature (celsius)
	uint8_t     m_tyresSurfaceTemperature[4];    // Tyres surface temperature (celsius)
	uint8_t     m_tyresInnerTemperature[4];      // Tyres inner temperature (celsius)
	uint16_t    m_engineTemperature;             // Engine temperature (celsius)
	float		m_tyresPressure[4];              // Tyres pressure (PSI)
	uint8_t     m_surfaceType[4];                // Driving surface, see info.md

public:
	void fromBin(char*& data);

	uint16_t speed() const { return m_speed; }
	float throttle() const { return m_throttle; }
	float steer() const { return m_steer; }
	float brake() const { return m_brake; }
	uint8_t clutch() const { return m_clutch; }
	int8_t gear() const { return m_gear; }
	uint16_t engineRPM() const { return m_engineRPM; }
	uint8_t drs() const { return m_drs; }
	uint8_t revLightsPercent() const { return m_revLightsPercent; }
	uint16_t brakesTemperature(int8_t tyre) const { return m_brakesTemperature[tyre]; }
	uint8_t tyresSurfaceTemperature(int8_t tyre) const { return m_tyresSurfaceTemperature[tyre]; }
	uint8_t tyresInnerTemperature(int8_t tyre) const { return m_tyresInnerTemperature[tyre]; }
	uint16_t engineTemperature() const { return m_engineTemperature; }
	float tyresPressure(int8_t tyre) const { return m_tyresPressure[tyre]; }
	uint8_t surfaceType(int8_t tyre) const { return  m_surfaceType[tyre]; }
};

struct PacketCarTelemetryData
{
private:
	CarTelemetryData		m_carTelemetryData[22];
	
	uint32_t				m_buttonStatus;    // Bit flags specifying which buttons are being pressed
											   // currently - see info.md

	// Added in Beta 3:
	uint8_t					m_mfdPanelIndex;   // Index of MFD panel open - 255 = MFD closed
											   // Single player, race � 0 = Car setup, 1 = Pits
											   // 2 = Damage, 3 =  Engine, 4 = Temperatures
											   // May vary depending on game mode
	uint8_t					m_mfdPanelIndexSecondaryPlayer;   // See above
	int8_t					m_suggestedGear;       // Suggested gear for the player (1-8)
											   // 0 if no gear suggested

	void fromBin(char*& data);
public:
	void update(char*& data);

	uint16_t speed(int8_t carIdx) const {return m_carTelemetryData[carIdx].speed();}
	float throttle(int8_t carIdx) const {return m_carTelemetryData[carIdx].throttle();}
	float steer(int8_t carIdx) const {return m_carTelemetryData[carIdx].steer();}
	float brake(int8_t carIdx) const {return m_carTelemetryData[carIdx].brake();}
	uint8_t clutch(int8_t carIdx) const {return m_carTelemetryData[carIdx].clutch();}
	int8_t gear(int8_t carIdx) const {return m_carTelemetryData[carIdx].gear();}
	uint16_t engineRPM(int8_t carIdx) const {return m_carTelemetryData[carIdx].engineRPM();}
	uint8_t drs(int8_t carIdx) const {return m_carTelemetryData[carIdx].drs();}
	uint8_t revLightsPercent(int8_t carIdx) const {return m_carTelemetryData[carIdx].revLightsPercent();}
	uint16_t brakesTemperature(int8_t carIdx, int8_t tyre) const {return m_carTelemetryData[carIdx].brakesTemperature(tyre);}
	uint8_t tyresSurfaceTemperature(int8_t carIdx, int8_t tyre) const { return m_carTelemetryData[carIdx].tyresSurfaceTemperature(tyre);}
	uint8_t tyresInnerTemperature(int8_t carIdx, int8_t tyre)const { return m_carTelemetryData[carIdx].tyresInnerTemperature(tyre);}
	uint16_t engineTemperature(int8_t carIdx) const {return m_carTelemetryData[carIdx].engineTemperature();}
	float tyresPressure(int8_t carIdx, int8_t tyre) const { return m_carTelemetryData[carIdx].tyresPressure(tyre);}
	uint8_t surfaceType(int8_t carIdx, int8_t tyre) const  { return m_carTelemetryData[carIdx].surfaceType(tyre); }

	uint32_t buttonStatus() const { return m_buttonStatus; }
	uint8_t	mfdPanelIndex() const { return m_mfdPanelIndex; }
	uint8_t mfdPanelIndexSecondaryPlayer() const { return m_mfdPanelIndexSecondaryPlayer; }
	int8_t suggestedGear() const { return m_suggestedGear; }
};