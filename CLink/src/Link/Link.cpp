//
//  Link.cpp
//  CLink
//
//  Created by Johan Solbakken on 22/01/2022.
//

#include "pch.hpp"
#include "Core/Application.hpp"
#include "Core/GUI/Button.hpp"

namespace Link
{
	class LinkApp : public Core::Application {
	public:
		LinkApp() {
			m_Button = Ref<GUI::Button>(GUI::Button::Create("Lasagna"));
			m_Button->SetCallback([this](){
				LOG_TRACE("Number: {0}", a);
				a++;
			});
			GetWindow().AddView(m_Button);
		}
		
		virtual ~LinkApp() {
			
		}
		
	private:
		Ref<GUI::Button> m_Button;
		int a = 1;
	};
	
	Core::Application* Core::CreateApplication()
	{
		return new LinkApp();
	}
	
}
