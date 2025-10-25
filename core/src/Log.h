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

  //// Format strings functions
  //template<typename... Args>
  //inline void LOG_TRACE(fmt::format_string<Args...> fmt, Args&&... args)
  //{
  //  Log::logger()->trace(fmt, std::forward<Args>(args)...);
  //};

  //template<typename... Args>
  //inline void LOG_INFO(fmt::format_string<Args...> fmt, Args&&... args)
  //{
  //  Log::logger()->info(fmt, std::forward<Args>(args)...);
  //};

  //template<typename... Args>
  //inline void LOG_WARN(fmt::format_string<Args...> fmt, Args&&... args)
  //{
  //  Log::logger()->warn(fmt, std::forward<Args>(args)...);
  //};

  //template<typename... Args>
  //inline void LOG_ERROR(fmt::format_string<Args...> fmt, Args&&... args)
  //{
  //  Log::logger()->error(fmt, std::forward<Args>(args)...);
  //};

  //// String view functions
  //template<typename... Args>
  //inline void LOG_TRACE(std::string_view fmt, Args&&... args)
  //{
  //  Log::logger()->trace(spdlog::fmt_lib::runtime(fmt), std::forward<Args>(args)...);
  //};

  //template<typename... Args>
  //inline void LOG_INFO(std::string_view fmt, Args&&... args)
  //{
  //  Log::logger()->info(spdlog::fmt_lib::runtime(fmt), std::forward<Args>(args)...);
  //};

  //template<typename... Args>
  //inline void LOG_WARN(std::string_view fmt, Args&&... args)
  //{
  //  Log::logger()->warn(spdlog::fmt_lib::runtime(fmt), std::forward<Args>(args)...);
  //};

  //template<typename... Args>
  //inline void LOG_ERROR(std::string_view fmt, Args&&... args)
  //{
  //  Log::logger()->error(spdlog::fmt_lib::runtime(fmt), std::forward<Args>(args)...);
  //};

  template<typename T, typename... Types>
  inline void LOG_TRACE(T message, Types... args)
  {
    Log::logger()->trace(spdlog::fmt_lib::runtime(message), args...);
  }

  template<typename T, typename... Types>
  inline void LOG_INFO(T message, Types... args)
  {
    Log::logger()->info(spdlog::fmt_lib::runtime(message), args...);
  }

  template<typename T, typename... Types>
  inline void LOG_WARN(T message, Types... args)
  {
    Log::logger()->warn(spdlog::fmt_lib::runtime(message), args...);
  }

  template<typename T, typename... Types>
  inline void LOG_ERROR(T message, Types... args)
  {
    Log::logger()->error(spdlog::fmt_lib::runtime(message), args...);
  }
}