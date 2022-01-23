#ifndef CocoaButton_hpp
#define CocoaButton_hpp

#include "Link/Core/GUI/Button.hpp"

#include <Cocoa/Cocoa.h>



namespace Link {
	namespace GUI {
		class CocoaButton : public Button {
		public:
			CocoaButton(const std::string& message);
			virtual ~CocoaButton();
	
			virtual void SetCallback(const CallbackFn& callback) override;
			static Button* Create(const std::string& message);
			
			inline virtual void* GetNativeButton() const { return (void*) m_Button; }
			
		private:
			NSButton* m_Button;
		};
	}
}
#endif
