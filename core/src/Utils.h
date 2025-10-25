#pragma once

#include "Log.h"

namespace Core {

  template<typename T, typename... Types>
  inline void LOG_ASSERT(bool condition, T message, Types... args)
  {
    if (!condition)
    {
      LOG_ERROR(message, args...);
      __debugbreak();
      assert(false);
    }
  };

}