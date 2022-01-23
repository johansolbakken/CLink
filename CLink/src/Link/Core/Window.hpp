#ifndef Window_hpp
#define Window_hpp

#include "pch.hpp"

#include "Core.hpp"
#include "GUI/View.hpp"

namespace Link {
	namespace Core {
		
		struct WindowProps {
			std::string Title;
			unsigned int Width;
			unsigned int Height;
			
			WindowProps(const std::string& title = "Window",
						unsigned int width = 1280,
						unsigned int height = 720) : Title(title), Width(width), Height(height) {}
		};
		
		class Window {
		public:
			virtual ~Window() {}
					
			virtual void OnUpdate() = 0;
			
			virtual unsigned int GetWidth() const = 0;
			virtual unsigned int GetHeight() const = 0;
			
			virtual void AddView(Ref<GUI::View> view) = 0;
			
			static Window* Create(const WindowProps& props = WindowProps());
		};
		
	}
}

#endif
