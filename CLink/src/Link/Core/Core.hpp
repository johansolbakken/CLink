#ifndef Core_hpp
#define Core_hpp

#ifdef DEBUG
#define ENABLE_ASSERTS
#else
#undef ENABLE_ASSERTS
#endif

#ifdef ENABLE_ASSERTS
#define ASSERT(x, ...) {if (!(x)) {LOG_ERROR(__VA_ARGS__); throw "assertion";}}
#else
#define ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#include <memory>

#define BIND_FN(fn) std::bind(&fn, this, std::placeholders::_1)

namespace Link {
	template<typename T>
	using Scope = std::unique_ptr<T>;
	
	template<typename T>
	using Ref = std::shared_ptr<T>;	
}

#endif
