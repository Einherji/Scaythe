//
// Created by matthiaso on 6/9/21.
//

#ifndef SCAYTHE_LOG_H
#define SCAYTHE_LOG_H

#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#pragma warning(pop)

namespace Scaythe {
    class Log {
    public:
        static void Init();

        static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
    };
}

#define S_CORE_TRACE(...)    ::Scaythe::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define S_CORE_INFO(...)     ::Scaythe::Log::GetCoreLogger()->info(__VA_ARGS__)
#define S_CORE_WARN(...)     ::Scaythe::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define S_CORE_ERROR(...)    ::Scaythe::Log::GetCoreLogger()->error(__VA_ARGS__)
#define S_CORE_CRITICAL(...) ::Scaythe::Log::GetCoreLogger()->critical(__VA_ARGS__)



#endif //SCAYTHE_LOG_H
