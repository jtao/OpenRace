#pragma once

// TODO: actually impement logs
#define LOG_INTERNAL(level, ...)

#define LOG_TRACE(...) LOG_INTERNAL(spdlog::level::trace, __VA_ARGS__)
#define LOG_DEBUG(...) LOG_INTERNAL(spdlog::level::debug, __VA_ARGS__)
#define LOG_INFO(...) LOG_INTERNAL(spdlog::level::info, __VA_ARGS__)
#define LOG_WARN(...) LOG_INTERNAL(spdlog::level::warn, __VA_ARGS__)
#define LOG_ERROR(...) LOG_INTERNAL(spdlog::level::err, __VA_ARGS__)