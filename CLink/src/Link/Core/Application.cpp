//
//  Application.cpp
//  CLink
//
//  Created by Johan Solbakken on 22/01/2022.
//

#include "Application.hpp"
#include "Log.hpp"

#include <iostream>

namespace Link {
	namespace Core
	{
		Application* Application::s_Instance = nullptr;
		
		Application::Application() {
			s_Instance = this;
			
			LOG_INFO("Application Created!");
		}
		
		Application::~Application() {
			
		}
		
		void Application::Run() {
			std::cout << "Hello, World!" << std::endl;
		}
		
	}
}
