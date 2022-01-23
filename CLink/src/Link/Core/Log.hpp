//
//  Log.hpp
//  CLink
//
//  Created by Johan Solbakken on 22/01/2022.
//

#ifndef Log_hpp
#define Log_hpp

#include "pch.hpp"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/fmt/ostr.h>

namespace Link {
	namespace Core {
		
		class Log
		{
		public:
			static void Init();
			
			inline static std::shared_ptr<spdlog::logger> GetLogger() { return s_Logger; }
		private:
			static std::shared_ptr<spdlog::logger> s_Logger;
		};
		
	}
}

#define LOG_INFO(...)  ::Link::Core::Log::GetLogger()->info(__VA_ARGS__)
#define LOG_ERROR(...) ::Link::Core::Log::GetLogger()->error(__VA_ARGS__)
#define LOG_WARN(...)  ::Link::Core::Log::GetLogger()->warn(__VA_ARGS__)
#define LOG_FATAL(...) ::Link::Core::Log::GetLogger()->fatal(__VA_ARGS__)
#define LOG_TRACE(...) ::Link::Core::Log::GetLogger()->trace(__VA_ARGS__)

#endif /* Log_hpp */
