#pragma once

#include "Log.h"

namespace Core {
#define LOG_ASSERT(x, ...) { if(!x) { LOG_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
}