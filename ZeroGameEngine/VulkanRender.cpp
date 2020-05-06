#include <vector>

#include "VulkanRender.h"
#include "Platform.h"
#include "Logger.h"
#include "Defines.h"
#include "VulkanUtils.h"

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

		const char** pfe = nullptr;
		U32 count = 0;
		_platform->GetRequiredExtensions(&count, &pfe);
		std::vector<const char*> platformExtensions;
		for (U32 i = 0; i < count; i++)
		{
			platformExtensions.push_back(pfe[i]);
		}
		platformExtensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);

		instanceCreateInfo.enabledExtensionCount = (U32)platformExtensions.size();
		instanceCreateInfo.ppEnabledExtensionNames = platformExtensions.data();

		std::vector<const char*> requiredValidationLayers = {
			"VK_LAYER_KHRONOS_validation"
		};

		U32 availableLayerCount = 0;
		VK_CHECK(vkEnumerateInstanceLayerProperties(&availableLayerCount, nullptr));
		std::vector<VkLayerProperties> availableLayers(availableLayerCount);
		VK_CHECK(vkEnumerateInstanceLayerProperties(&availableLayerCount, availableLayers.data()));

		bool success = true;
		for (U32 i = 0; i < (U32)requiredValidationLayers.size(); i++)
		{
			bool found = false;
			for (U32 j = 0; j < availableLayerCount; j++)
			{
				if (strcmp(requiredValidationLayers[i], availableLayers[j].layerName) == 0)
				{
					found = true;
					break;
				}

			}
			if (!found)
			{
				success = false;
				Logger::Fatal("Required validation layer is missing : %s", requiredValidationLayers[i]);
				break;
			}

		}

		instanceCreateInfo.enabledLayerCount = (U32)requiredValidationLayers.size();
		instanceCreateInfo.ppEnabledLayerNames = requiredValidationLayers.data();

		VK_CHECK(vkCreateInstance(&instanceCreateInfo, nullptr, &_instance));
	}
	VulkanRender::~VulkanRender() {

	}
}