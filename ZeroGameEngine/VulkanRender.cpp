
#include "VulkanRender.h"
#include "Platform.h"
#include "Logger.h"
#include "Defines.h"

namespace ZEROGE {

	VulkanRender::VulkanRender(Platform* platform) {
		_platform = platform;
		Logger::Trace("Initializing Vulkan render");

		VkApplicationInfo appInfo = { VK_STRUCTURE_TYPE_APPLICATION_INFO };
		appInfo.apiVersion = VK_API_VERSION_1_2;
		appInfo.pApplicationName = "ZEROGE";
		appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
		appInfo.pEngineName = "No Engine";
		appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);


		VkInstanceCreateInfo instanceCreateInfo = { VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO };
		instanceCreateInfo.pApplicationInfo = &appInfo;
	}
	VulkanRender::~VulkanRender() {

	}
}