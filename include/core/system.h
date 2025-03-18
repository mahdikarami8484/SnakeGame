#pragma once

#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>
#include <memory>
#include <thread>
#include <cstdint>

namespace System {
    int64_t GenerateNumber(int64_t minimum, int64_t maximum);
    void Delay(uint64_t duration);
}