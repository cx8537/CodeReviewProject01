#pragma once
#include <string>
#include "GameTypes.h"

class NetworkManager {
public:
    static NetworkManager& getInstance();

    bool connect(const std::string& serverKey);
    int sendPayload(const LogPayload& payload);
    void disconnect();
    bool isConnected() const;

private:
    NetworkManager();
    ~NetworkManager();
    NetworkManager(const NetworkManager&) = delete;
    NetworkManager& operator=(const NetworkManager&) = delete;

    bool m_connected;
    std::string m_serverAddress;
    int m_socketHandle;
};
