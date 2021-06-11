//
// Created by matthiaso on 6/9/21.
//

#ifndef SCAYTHE_LOG_H
#define SCAYTHE_LOG_H

#include "Base.h"

#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#pragma warning(pop)

namespace Scaythe {
    class SCAYTHE_API Log {
    public:
        static void Init(const char* clientName);

        static Ref<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
        static Ref<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
    private:
        static Ref<spdlog::logger> s_CoreLogger;
        static Ref<spdlog::logger> s_ClientLogger;
    };
}

#define S_CORE_TRACE(...)    ::Scaythe::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define S_CORE_INFO(...)     ::Scaythe::Log::GetCoreLogger()->info(__VA_ARGS__)
#define S_CORE_WARN(...)     ::Scaythe::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define S_CORE_ERROR(...)    ::Scaythe::Log::GetCoreLogger()->error(__VA_ARGS__)
#define S_CORE_CRITICAL(...) ::Scaythe::Log::GetCoreLogger()->critical(__VA_ARGS__)

#define S_TRACE(...)    ::Scaythe::Log::GetClientLogger()->trace(__VA_ARGS__)
#define S_INFO(...)     ::Scaythe::Log::GetClientLogger()->info(__VA_ARGS__)
#define S_WARN(...)     ::Scaythe::Log::GetClientLogger()->warn(__VA_ARGS__)
#define S_ERROR(...)    ::Scaythe::Log::GetClientLogger()->error(__VA_ARGS__)
#define S_CRITICAL(...) ::Scaythe::Log::GetClientLogger()->critical(__VA_ARGS__)

#endif //SCAYTHE_LOG_H
