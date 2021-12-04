#pragma once
#include "iostream"
#include <atomic>

struct MarshalZone
{
private:
	float	m_zoneStart;   // Fraction (0..1) of way through the lap the marshal zone starts
	int8_t	m_zoneFlag;    // -1 = invalid/unknown, 0 = none, 1 = green, 2 = blue, 3 = yellow, 4 = red

public:
    void fromBin(char*& data);

    float zoneStart() const { return m_zoneStart; }
	int8_t zoneFlag() const { return m_zoneFlag; }
};

struct WeatherForecastSample
{
private:
	uint8_t     m_sessionType;			// 0 = unknown, 1 = P1, 2 = P2, 3 = P3, 4 = Short P, 5 = Q1
										// 6 = Q2, 7 = Q3, 8 = Short Q, 9 = OSQ, 10 = R, 11 = R2
										// 12 = Time Trial
	uint8_t     m_timeOffset;           // Time in minutes the forecast is for
	uint8_t     m_weather;              // Weather: 0 = clear, 1 = light cloud, 2 = overcast
										// 3 = light rain, 4 = heavy rain, 5 = storm
	int8_t      m_trackTemperature;     // Track temp. in degrees celsius
	int8_t      m_airTemperature;       // Air temp. in degrees celsius

public:
    void fromBin(char*& data);

    uint8_t sessionType() const { return m_sessionType; }
    uint8_t timeOffset() const { return m_timeOffset; }
    uint8_t weather() const { return m_weather; }
    int8_t trackTemperature() const { return m_trackTemperature; }
    int8_t airTemperature() const { return m_airTemperature; }
};

struct PacketSessionData
{
private:

	
    uint8_t           m_weather;                        // Weather - 0 = clear, 1 = light cloud, 2 = overcast
														// 3 = light rain, 4 = heavy rain, 5 = storm
    int8_t	          m_trackTemperature;                     // Track temp. in degrees celsius
    int8_t	          m_airTemperature;                       // Air temp. in degrees celsius
    uint8_t           m_totalLaps;                      // Total number of laps in this race
    uint16_t          m_trackLength;                    // Track length in metres
    uint8_t           m_sessionType;                    // 0 = unknown, 1 = P1, 2 = P2, 3 = P3, 4 = Short P
														// 5 = Q1, 6 = Q2, 7 = Q3, 8 = Short Q, 9 = OSQ
														// 10 = R, 11 = R2, 12 = Time Trial
    int8_t            m_trackId;                        // -1 for unknown, 0-26 for tracks, check info.md
    uint8_t           m_formula;                        // Formula, 0 = F1 Modern, 1 = F1 Classic, 2 = F2,
														// 3 = F1 Generic
    uint16_t          m_sessionTimeLeft;                // Time left in session in seconds
    uint16_t          m_sessionDuration;                // Session duration in seconds
    uint8_t           m_pitSpeedLimit;                  // Pit speed limit in kilometres per hour
    uint8_t           m_gamePaused;                     // Whether the game is paused
    uint8_t           m_isSpectating;                   // Whether the player is spectating
    uint8_t           m_spectatorCarIndex;              // Index of the car being spectated
    uint8_t           m_sliProNativeSupport;	        // SLI Pro support, 0 = inactive, 1 = active
    uint8_t           m_numMarshalZones;                // Number of marshal zones to follow
    MarshalZone       m_marshalZones[21];                 // List of marshal zones � max 21
    uint8_t           m_safetyCarStatus;                // 0 = no safety car, 1 = full safety car
														// 2 = virtual safety car
    uint8_t           m_networkGame;                    // 0 = offline, 1 = online
    uint8_t           m_numWeatherForecastSamples;      // Number of weather samples to follow
    WeatherForecastSample m_weatherForecastSamples[20]; // Array of weather forecast samples


    void fromBin(char*& data);

public:
    PacketSessionData();
	
    void update(char*& data);

    uint8_t weather()  const { return m_weather; }
    int8_t trackTemperature()  const { return m_trackTemperature; }
    int8_t airTemperature()  const { return m_airTemperature; }
    uint8_t totalLaps()  const { return m_totalLaps; }
    uint16_t trackLength()  const { return m_trackLength; }
    uint8_t sessionType()  const { return m_sessionType; }
    int8_t trackId()  const { return m_trackId; }
    uint8_t formula()  const { return m_formula; }
    uint16_t sessionTimeLeft()  const { return m_sessionTimeLeft; }
    uint16_t sessionDuration()  const { return m_sessionDuration; }
    uint8_t pitSpeedLimit()  const { return m_pitSpeedLimit; }
    uint8_t gamePaused()  const { return m_gamePaused; }
    uint8_t isSpectating()  const { return m_isSpectating; }
    uint8_t spectatorCarIndex()  const { return m_spectatorCarIndex; }
    uint8_t sliProNativeSupport()  const { return m_sliProNativeSupport; }
    uint8_t numMarshalZones()  const { return m_numMarshalZones; }

    float marshalZoneStart(uint8_t marshalIndx) const { return m_marshalZones[marshalIndx].zoneStart(); }
    int8_t marshalZoneFlag(uint8_t marshalIndx) const { return m_marshalZones[marshalIndx].zoneFlag(); }

    uint8_t safetyCarStatus() const { return m_safetyCarStatus; }
    uint8_t networkGame() const { return m_networkGame; }
    uint8_t numWeatherForecastSamples() const { return m_numWeatherForecastSamples; }

    uint8_t weatherForecastSessionType(uint8_t forecastIndx) const { return m_weatherForecastSamples[forecastIndx].sessionType(); }
    uint8_t weatherForecastTimeOffset(uint8_t forecastIndx) const { return m_weatherForecastSamples[forecastIndx].timeOffset(); }
    uint8_t weatherForecastWeather(uint8_t forecastIndx) const { return m_weatherForecastSamples[forecastIndx].weather(); }
    int8_t weatherForecastTrackTemperature(uint8_t forecastIndx) const { return m_weatherForecastSamples[forecastIndx].trackTemperature(); }
    int8_t weatherForecastAirTemperature(uint8_t forecastIndx) const { return m_weatherForecastSamples[forecastIndx].airTemperature(); }
};