#pragma once

struct GLFWwindow;

namespace ZEROGE {

	class Engine;

	class Platform {
	public:
		Platform(Engine* engine, const char* applicationName);
		~Platform();
		GLFWwindow* GetWindow() { return _window; }

		const bool StartGameTime();
	private:
		Engine* _engine;
		GLFWwindow* _window;

	};
}
