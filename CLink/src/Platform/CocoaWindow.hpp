#ifndef CocoaWindow_hpp
#define CocoaWindow_hpp

#include "Link/Core/Window.hpp"

#include <AppKit/AppKit.h>

namespace Link {
	namespace Core {
		
		class CocoaWindow : public Window
		{
		public:
			CocoaWindow(const WindowProps& props);
			virtual ~CocoaWindow();
			
			void OnUpdate() override;
					
			inline unsigned int GetWidth() const override {return m_Data.Width; }
			inline unsigned int GetHeight() const override { return m_Data.Height; }
			
			virtual void AddView(Ref<GUI::View> view) override;
			
		private:
			virtual void Init(const WindowProps& props);
			virtual void Shutdown();
			
		private:
			NSWindow* m_Window;
			
			struct WindowData {
				std::string Title;
				unsigned int Width;
				unsigned int Height;
			};
			
			WindowData m_Data;
		};
	}
}

#endif
