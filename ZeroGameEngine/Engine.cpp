#include "Logger.h"
#include "Platform.h"
#include "Engine.h"

namespace ZEROGE {
	Engine::Engine(const char* applicationName) {
		ZEROGE::Logger::Log("Initializing Zero Game Engine v%d", 1);
		_platform = new Platform(this, applicationName);
	}
	Engine::~Engine() {

	}

	void Engine::Run() {
		_platform->StartGameTime();

	}

	void Engine::OnTime(const F32 deltaTime) {

	}
}