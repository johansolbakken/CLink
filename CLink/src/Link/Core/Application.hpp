//
//  Application.hpp
//  CLink
//
//  Created by Johan Solbakken on 22/01/2022.
//

#ifndef Application_hpp
#define Application_hpp

namespace Link {
	namespace Core
	{
		class Application {
		public:
			virtual ~Application();
			void Run();
			
			inline static Application& Instance() { return *s_Instance; }
		protected:
			Application();
		private:
			static Application* s_Instance;
		};
		
		Application* CreateApplication();
	}
}

#endif /* Application_hpp */
