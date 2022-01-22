//
//  Link.cpp
//  CLink
//
//  Created by Johan Solbakken on 22/01/2022.
//

#include <stdio.h>
#include "Core/Application.hpp"

namespace Link
{
	class LinkApp : public Core::Application {
	public:
		LinkApp() {
			
		}
		
		virtual ~LinkApp() {
			
		}
	};
	
	Core::Application* Core::CreateApplication()
	{
		return new LinkApp();
	}
	
}
