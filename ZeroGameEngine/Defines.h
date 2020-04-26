#pragma once

#if _WIN32 || _WIN64
#define PLATFORM_WINDOWS
#else
#if __linux__
#define PLATFORM_LINUX
#elif __APPLE__
#define PLATFORM_MAC
#else
#error "Unable to determinate platform"
#endif
#endif

#ifdef PLATFORM_WINDOWS
#define FORCEINLINE __forceinline;
#define FORCENOINLINE _declspec(noinline)
#ifdef ZEROGE_BUILD_LTB
#define ZEROGE_API __declspec(dllexport)
#else
#define ZEROGE_API __declspec(dllinport)
#endif
#elif PLATFORM_LINUX || PLATFORM_MAC
#define FORCEINLINE inline
//TODO:Defines ZEROGE_API platforms
#endif 


// Assertions
#define ASSERTIONS_ENABLED
#include <iostream>

#ifndef ASSERTIONS_ENABLED

#if _MSC_VER
#include <intrin.h>
#define debugBreak() __debugBreak();
#else
#define debugBreak() __asm { int 3 }
#endif // ASSERTIONS_ENABLED



#define ASSERT(expr) {\
	if (expr) {\ 
	}
	else {\
		reportAssertionsFailure(#expr, "No message :)", __FILE__, __LINE__);\
		debugBreak();\
	}\

}
#define ASSERT_MSG(expr, message) {\
	if (expr) {\ 
	}
	else {\
		reportAssertionsFailure(#expr, message, __FILE__, __LINE__); \
		debugBreak(); \
	}\

}

#ifdef _DEBUG
#define ASSERT_DEBUG(expr) {\
	if (expr) {\ 
	}
	else {\
		reportAssertionsFailure(#expr, "No message :)", __FILE__, __LINE__); \
		debugBreak(); \
	}\

}
#else
#define ASSERT_DEBUG(expr)
#endif // _DEBUG

#else
#define ASSERT(expr)
#define ASSERT_MSG(expr, message)
#define ASSERT_DEBUG(expr)

#endif

FORCEINLINE void reportAssertionsFailure(const char* expression, const char* message, const char* file, int line) {
	std::cerr << "Assertions Failure : " << expression << "Log message :" << message << "File err : " << file << "In line :" << line << "\n";
}

