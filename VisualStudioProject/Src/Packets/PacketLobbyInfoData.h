#pragma once
#include "iostream"

struct LobbyInfoData
{
private:
    uint8_t     m_aiControlled;            // Whether the vehicle is AI (1) or Human (0) controlled
    uint8_t     m_teamId;                  // Team id - see appendix (255 if no team currently selected)
    uint8_t     m_nationality;             // Nationality of the driver
    char        m_name[48];                // Name of participant in UTF-8 format � null terminated
                                           // Will be truncated with ... (U+2026) if too long
    uint8_t     m_readyStatus;             // 0 = not ready, 1 = ready, 2 = spectating

public:
    void fromBin(char*& data);

    uint8_t aiControlled() const {return m_aiControlled;}
    uint8_t teamId() const {return m_teamId;}
    uint8_t nationality()const {return m_nationality;}
    void name(char* n) { n = m_name; }
    uint8_t readyStatus() const { return m_readyStatus; }
};

struct PacketLobbyInfoData
{
private:
    uint8_t             m_numPlayers;               // Number of players in the lobby data
    LobbyInfoData       m_lobbyPlayers[22];

    void fromBin(char*& data);

public:
    void update(char*& data);

    uint8_t lobbyNumPlayers() const { return m_numPlayers; }
    uint8_t lobbyAiControlled(int8_t playerIdx) const { return m_lobbyPlayers[playerIdx].aiControlled(); }
    uint8_t lobbyTeamId(int8_t playerIdx) const { return m_lobbyPlayers[playerIdx].teamId(); }
    uint8_t lobbyNationality(int8_t playerIdx) const { return m_lobbyPlayers[playerIdx].nationality(); }
    void lobbyName(int8_t playerIdx, char* n) { m_lobbyPlayers[playerIdx].name(n); }
    uint8_t lobbyReadyStatus(int8_t playerIdx) const { return m_lobbyPlayers[playerIdx].readyStatus(); }
};