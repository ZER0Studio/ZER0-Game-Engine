#pragma once

#include "Types.h"

namespace ZEROGE {
	
	class Platform;
	class VulkanRender;

	class Engine
	{
	public:
		Engine(const char* applicationName);
		~Engine();

		void Run();

		void OnTime(const F32 deltaTime);

	private:
		Platform* _platform;
		VulkanRender* _render;
	};

}
