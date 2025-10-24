#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/fmt/ostr.h>
#include <memory>

namespace Core {

  class Log
  {
  public:
    static void init();
    inline static std::shared_ptr<spdlog::logger>& logger() { return s_logger; }
  private:
    static std::shared_ptr<spdlog::logger> s_logger;
    static bool s_running;
  };

#define LOG_TRACE(...)   Log::logger()->trace(__VA_ARGS__)
#define LOG_INFO(...)    Log::logger()->info(__VA_ARGS__)
#define LOG_WARN(...)    Log::logger()->warn(__VA_ARGS__)
#define LOG_ERROR(...)   Log::logger()->error(__VA_ARGS__)

}