#include "NetworkManager.h"
#include "Config.h"
#include "Logger.h"
#include <cstring>

/*
MR 생성을 위한 테스트 
*/

NetworkManager::NetworkManager()
    : m_connected(false)
    , m_serverAddress("")
    , m_socketHandle(-1)
{
}

NetworkManager::~NetworkManager()
{
    if (m_connected) {
        disconnect();
    }
}

NetworkManager& NetworkManager::getInstance()
{
    static NetworkManager instance;
    return instance;
}

bool NetworkManager::connect(const std::string& serverKey)
{
    if (m_connected) {
        AppLog::warning("NetworkManager", "Already connected. Disconnecting first.");
        disconnect();
    }

    m_serverAddress = Config::getServerIP(serverKey);
    if (m_serverAddress.empty()) {
        AppLog::error("NetworkManager", "Failed to get server IP from config.");
        return false;
    }

    // Simulate socket connection
    // In real implementation, this would create actual socket connection
    m_socketHandle = 1; // Simulated valid socket handle
    m_connected = true;

    AppLog::info("NetworkManager", "Successfully connected to server.");
    return true;
}

int NetworkManager::sendPayload(const LogPayload& payload)
{
    if (!m_connected) {
        AppLog::error("NetworkManager", "Cannot send payload: not connected.");
        return GameConstants::SEND_FAILED;
    }

    if (payload.payloadSize == 0 || payload.payloadSize > GameConstants::MAX_PAYLOAD_SIZE) {
        AppLog::error("NetworkManager", "Invalid payload size.");
        return GameConstants::SEND_FAILED;
    }

    // Simulate sending data
    // In real implementation, this would send data through socket
    AppLog::info("NetworkManager", "Payload sent successfully.");
    return GameConstants::SEND_SUCCESS;
}

void NetworkManager::disconnect()
{
    if (!m_connected) {
        return;
    }

    // Simulate socket close
    m_socketHandle = -1;
    m_connected = false;
    m_serverAddress.clear();

    AppLog::info("NetworkManager", "Disconnected from server.");
}

bool NetworkManager::isConnected() const
{
    return m_connected;
}
