#define GLFW_INCLUDE_VULKAN
#include<vulkan\vulkan.h>

#include "Logger.h"
#include "Engine.h"
#include "Platform.h"
#include "Window.h"

namespace ZEROGE {
	Platform::Platform(Engine* engine, const char* applicationName) {
		Logger::Trace("Initializing platform engine layer");
		_engine = engine;
		_window = new Window(1280, 720, applicationName);
	}
	Platform::~Platform() { _window->~Window(); }

	const bool Platform::StartGameTime() {
		while (!_window->closed())
		{
			_window->clear();
			glfwPollEvents();
			_engine->OnTime(0);


		}
		return true;
	}
}