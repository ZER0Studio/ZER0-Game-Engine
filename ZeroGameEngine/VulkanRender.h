#pragma once

#include <vulkan\vulkan.h>

#include "Types.h"

namespace ZEROGE {

	class Platform

	class VulkanRender
	{
	public:
		VulkanRender(Platform* platform);
		~VulkanRender();

	private:
		Platform* _platform;
		VkInstance _instance;
		VkDebugUtilsMessengerEXT _debugMessager;
		VkPhysicalDevice _physicalDevice;
		VkDevice _device;


	};

	
}