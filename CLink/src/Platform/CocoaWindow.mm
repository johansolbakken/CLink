
#include "pch.hpp"
#include "CocoaWindow.hpp"

#include "WindowDelegate.hpp"

#include "GUI/CocoaButton.hpp"

namespace Link {
	namespace Core {
		Window* Window::Create(const WindowProps& props) {
			return new CocoaWindow(props);
		}
		
		CocoaWindow::CocoaWindow(const WindowProps& props)
		{
			Init(props);
		}
		
		CocoaWindow::~CocoaWindow()
		{
			Shutdown();
		}
		
		void CocoaWindow::Init(const WindowProps& props)
		{
			m_Data.Title = props.Title;
			m_Data.Width = props.Width;
			m_Data.Height = props.Height;
			
			LOG_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);
			
			// Initializing window
			WindowDelegate* delegate = [[WindowDelegate alloc] init];
			
			NSRect screen = [[NSScreen mainScreen] frame];
			uint32 x = (screen.size.width - m_Data.Width) * 0.5;
			uint32 y = (screen.size.height - m_Data.Height) * 0.5;
			
			NSRect frame = NSMakeRect((float)x, (float)y, (float)props.Width, (float)props.Height);
			m_Window = [[[NSWindow alloc] initWithContentRect:frame
													styleMask:NSWindowStyleMaskTitled | NSWindowStyleMaskClosable | NSWindowStyleMaskMiniaturizable | NSWindowStyleMaskResizable
													  backing:NSBackingStoreBuffered
														defer:YES
						 ] autorelease];
			
			NSString* title = [NSString stringWithUTF8String:m_Data.Title.c_str()];
			[m_Window setBackgroundColor:[NSColor blueColor]];
			[m_Window setTitle:title];
			[m_Window makeKeyAndOrderFront: nil];
			[m_Window setDelegate:delegate];
			m_Window.contentView.wantsLayer = true;
		}
		
		void CocoaWindow::OnUpdate()
		{
			// poll events
			NSEvent* event;
			do {
				event = [NSApp nextEventMatchingMask:NSEventMaskAny untilDate:nil inMode:NSDefaultRunLoopMode dequeue:true];
				switch ([event type]) {
					default:
						[NSApp sendEvent: event];
				}
			} while (event != nil);
			// Swap buffers
		}
		
		void CocoaWindow::AddView(Ref<GUI::View> view) {
			if (Ref<GUI::CocoaButton> button = std::static_pointer_cast<GUI::CocoaButton>(view)) {
				[m_Window.contentView addSubview:(NSButton*) button->GetNativeButton()];
			}
		}
		
		void CocoaWindow::Shutdown()
		{
			// Destroy window
			[m_Window release];
		}
	}
}
