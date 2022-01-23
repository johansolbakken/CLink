#include "pch.hpp"
#include "CocoaButton.hpp"

@interface ButtonPasser : NSObject
+ (IBAction)buttonPassthrough:(id)sender;
+ (void)setCallback:(Link::GUI::Button::CallbackFn) callback;
@end
@implementation ButtonPasser

Link::GUI::Button::CallbackFn m_Callback;

+ (IBAction)buttonPassthrough:(id)sender
{
	m_Callback();
}

+ (void)setCallback:(Link::GUI::Button::CallbackFn) callback
{
	m_Callback = callback;
}

@end

namespace Link {
	namespace GUI {
		CocoaButton::CocoaButton(const std::string& message)
		{
			NSString* string = [NSString stringWithUTF8String:message.c_str()];
			m_Button = [NSButton buttonWithTitle:string target:[ButtonPasser class] action:@selector(buttonPassthrough:)];
		}
		
		CocoaButton::~CocoaButton()
		{
			[m_Button release];
		}
		
		void CocoaButton::SetCallback(const CallbackFn &callback) {
			[ButtonPasser setCallback:callback];
		}
		
		Button* Button::Create(const std::string& message)
		{
			return new CocoaButton(message);
		}
	}
}
