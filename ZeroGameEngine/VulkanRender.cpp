#include <vector>

#include "VulkanRender.h"
#include "Platform.h"
#include "Logger.h"
#include "Defines.h"
#include "VulkanUtils.h"

namespace ZEROGE {

	static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
		VkDebugUtilsMessageSeverityFlagBitsEXT		messageSeverity,
		VkDebugUtilsMessageTypeFlagsEXT				messageTypes,
		const VkDebugUtilsMessengerCallbackDataEXT*	pCallbckData,
		void* pUserData) {

		switch (messageSeverity)
		{

		case VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT:
			Logger::Trace(pCallbckData->pMessage);
			break;
		case VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT:
			Logger::Log(pCallbckData->pMessage);
			break;
		case VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT:
			Logger::Warn(pCallbckData->pMessage);
			break;
		case VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT:
			Logger::Error(pCallbckData->pMessage);
			break;
		case VK_DEBUG_UTILS_MESSAGE_SEVERITY_FLAG_BITS_MAX_ENUM_EXT:
			Logger::Log(pCallbckData->pMessage);
			break;
		default:
			break;
		}

		return VK_FALSE;
	}

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
		for (U32 i = 0; i < (U32)requiredValidationLayers.size(); ++i)
		{
			bool found = false;
			for (U32 j = 0; j < availableLayerCount; ++j)
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
			else {
				Logger::Trace("Required Success layer : %s ( %d )", requiredValidationLayers[i], i);
			}

		}

		instanceCreateInfo.enabledLayerCount = (U32)requiredValidationLayers.size();
		instanceCreateInfo.ppEnabledLayerNames = requiredValidationLayers.data();

		VK_CHECK(vkCreateInstance(&instanceCreateInfo, nullptr, &_instance));

		VkDebugUtilsMessengerCreateInfoEXT debugCreateInfo = { VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT };
		debugCreateInfo.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT, VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT;
		debugCreateInfo.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT;
		debugCreateInfo.pfnUserCallback = debugCallback;
		debugCreateInfo.pUserData = this;
		PFN_vkCreateDebugUtilsMessengerEXT func = (PFN_vkCreateDebugUtilsMessengerEXT)vkGetInstanceProcAddr(_instance, "vkCreateDebugUtilsMessengerEXT");
		ASSERT_MSG(func, "Failed to create Debug Messager !");
		func(_instance, &debugCreateInfo, nullptr, &_debugMessager);


	}
	VulkanRender::~VulkanRender() {

		if (_debugMessager)
		{
			PFN_vkDestroyDebugUtilsMessengerEXT func = (PFN_vkDestroyDebugUtilsMessengerEXT)vkGetInstanceProcAddr(_instance, "vkDestroyDebugUtilsMessengerEXT");
			func(_instance, _debugMessager, nullptr);

		}

		vkDestroyInstance(_instance, nullptr);


	}
}