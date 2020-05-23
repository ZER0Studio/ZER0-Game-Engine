
#include "Logger.h"
#include "Window2D.h"
#include "Engine2D.h"

namespace ZEROGE {
	Engine2D::Engine2D(const char* applicationName) {
		Logger::Log("Initializing Zero Game Engine 2D v%d", 1);
		_mainWindow = new Window2D(1280,720, applicationName);
	}
	Engine2D::~Engine2D() {

	}
	void Engine2D::Run() {
		_mainWindow->StartGameTime();
	}

	void Engine2D::OnTime(const F32 deltaTime) {

	}
}