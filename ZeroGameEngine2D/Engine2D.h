#pragma once

#include "Types.h"

namespace ZEROGE {

	class Window2D;

	class Engine2D
	{
	public:
		Engine2D(const char* applicationName);
		~Engine2D();
		void Run();
		void OnTime(const F32 deltaTime);

	private:
		Window2D* _mainWindow;
	};

}