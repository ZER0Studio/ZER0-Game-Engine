#pragma once

#include "Types.h"

struct GLFWwindow;

namespace ZEROGE {

	class Engine;

	class Platform {
	public:
		Platform(Engine* engine, const char* applicationName);
		~Platform();
		GLFWwindow* GetWindow() { return _window; }
		void GetRequiredExtensions(U32* extensionCount, const char*** extensionNames );

		const bool StartGameTime();
	private:
		Engine* _engine;
		GLFWwindow* _window;

	};
}
