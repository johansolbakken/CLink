//
//  main.cpp
//  CLink
//
//  Created by Johan Solbakken on 22/01/2022.
//

#include "Link/Core/Application.hpp"

extern Link::Core::Application* Link::Core::CreateApplication();

int main(int argc, const char * argv[]) {
	
	auto app = Link::Core::CreateApplication();
	app->Run();
	delete app;
	
	return 0;
}
