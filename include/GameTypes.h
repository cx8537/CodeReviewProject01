#pragma once
#include <cstdint>
#include <cstddef>

namespace GameConstants {
    constexpr size_t MAX_USER_ID_LEN = 256;
    constexpr size_t MAX_PAYLOAD_SIZE = 4096;
    constexpr int CONNECT_SUCCESS = 0;
    constexpr int CONNECT_FAILED = -1;
    constexpr int SEND_SUCCESS = 0;
    constexpr int SEND_FAILED = -1;
}

// SFR-9015 규격 준수 구조체
struct LogPayload {
    char userId[GameConstants::MAX_USER_ID_LEN];
    uint32_t payloadSize;
    uint8_t payload[GameConstants::MAX_PAYLOAD_SIZE];
    uint32_t crc32;
};
