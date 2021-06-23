#pragma once
#include "spdlog/spdlog.h"
#include <memory>

namespace Manifold
{
    class Log
    {
        public:
        static void Init();
        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger() {return s_ClientLogger;}

        private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
}

// Core Logger
#define MF_CORE_TRACE(...)  ::Manifold::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define MF_CORE_INFO(...)  ::Manifold::Log::GetCoreLogger()->info(__VA_ARGS__)
#define MF_CORE_WARN(...)  ::Manifold::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define MF_CORE_ERROR(...) ::Manifold::Log::GetCoreLogger()->error(__VA_ARGS__)
#define MF_CORE_FATAL(...) ::Manifold::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client Logger
#define MF_TRACE(...) ::Manifold::Log::GetClientLogger()->trace(__VA_ARGS__)
#define MF_INFO(...) ::Manifold::Log::GetClientLogger()->info(__VA_ARGS__)
#define MF_WARN(...) ::Manifold::Log::GetClientLogger()->warn(__VA_ARGS__)
#define MF_ERROR(...) ::Manifold::Log::GetClientLogger()->error(__VA_ARGS__)
#define MF_FATAL(...) ::Manifold::Log::GetClientLogger()->fatal(__VA_ARGS__)