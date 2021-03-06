#include "Logger.h"
#include "Platform.h"
#include "Engine.h"
#include "VulkanRender.h"

namespace ZEROGE {
	Engine::Engine(const char* applicationName) {
		ZEROGE::Logger::Log("Initializing Zero Game Engine v%d", 1);
		_platform = new Platform(this, applicationName);
		_render = new VulkanRender(_platform);
	}
	Engine::~Engine() {

	}

	void Engine::Run() {
		_platform->StartGameTime();

	}

	void Engine::OnTime(const F32 deltaTime) {

	}
}