//
//  Application.cpp
//  CLink
//
//  Created by Johan Solbakken on 22/01/2022.
//

#include "pch.hpp"
#include "Application.hpp"

#include "GUI/Button.hpp"

namespace Link {
	namespace Core
	{
		Application* Application::s_Instance = nullptr;
		
		Application::Application() {
			ASSERT(!s_Instance, "Application already exists!");
			s_Instance = this;
			
			m_Window = Scope<Window>(Window::Create());
			
		}
		
		Application::~Application() {
			
		}
		
		
		void Application::Run() {
			while (m_Running) {
				
				m_Window->OnUpdate();
			}
		}
		
		
	}
}
