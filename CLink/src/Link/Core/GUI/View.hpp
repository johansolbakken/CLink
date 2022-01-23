//
//  View.hpp
//  CLink
//
//  Created by Johan Solbakken on 23/01/2022.
//

#ifndef View_h
#define View_h

#include <vector>

#include "Link/Core/Core.hpp"

namespace Link {
	namespace GUI {
		class View {
		public:
			inline void Add(Ref<View> view) { m_Views.push_back(view); }
			inline std::vector<Ref<View>>::iterator begin() { return m_Views.begin(); }
			inline std::vector<Ref<View>>::iterator end() { return m_Views.end(); }
			
		private:
			std::vector<Ref<View>> m_Views;
		};
	}
}

#endif /* View_h */
