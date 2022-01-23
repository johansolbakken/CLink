//
//  Log.cpp
//  CLink
//
//  Created by Johan Solbakken on 22/01/2022.
//

#include "pch.hpp"
#include "Log.hpp"

namespace Link
{
	namespace Core {
		
		std::shared_ptr<spdlog::logger> Log::s_Logger;
		
		void Log::Init()
		{
			spdlog::set_pattern("%^[%T] %n: %v%$");
			s_Logger = spdlog::stdout_color_mt("CLink");
			s_Logger->set_level(spdlog::level::trace);
		}
		
	}
}
