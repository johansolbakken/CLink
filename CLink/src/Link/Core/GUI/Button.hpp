//
//  Button.hpp
//  CLink
//
//  Created by Johan Solbakken on 23/01/2022.
//

#ifndef Button_h
#define Button_h

#include "View.hpp"

namespace Link {
	namespace GUI {
		
		class Button : public View {
		public:
			using CallbackFn = std::function<void()>;
			
			virtual ~Button() {}
			virtual void SetCallback(const CallbackFn& callback) = 0;
			virtual void* GetNativeButton() const = 0;
			
			static Button* Create(const std::string& message);
		};
	}
}

#endif /* Button_h */
