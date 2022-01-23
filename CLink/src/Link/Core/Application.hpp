//
//  Application.hpp
//  CLink
//
//  Created by Johan Solbakken on 22/01/2022.
//

#ifndef Application_hpp
#define Application_hpp

#include "Core.hpp"

#include "Window.hpp"

namespace Link {
	namespace Core
	{
		class Application {
		public:
			virtual ~Application();
			void Run();
			
			inline Window& GetWindow() { return *m_Window; }
			inline static Application& Instance() { return *s_Instance; }
		protected:
			Application();
			
		private:
			Scope<Window> m_Window;
			bool m_Running = true;
			
			static Application* s_Instance;
		};
		
		Application* CreateApplication();
	}
}

#endif /* Application_hpp */
