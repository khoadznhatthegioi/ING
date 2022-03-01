
/**
 *	Include Header
 */
#include "Context.h"



/**
 *	Include API Manager
 */
#include <ING/Rendering/API/Manager/Manager.h>



/**
 *	Include DirectX11 DeviceContext
 */
#include <ING/Rendering/API/DirectX11/Device/Context/Context.h>



namespace ING {

	namespace Rendering {

		/**
		 *	Constructors And Destructor
		 */
		DeviceContext::DeviceContext(Device* device) {

			this->device = device;

		}

		DeviceContext::~DeviceContext() {



		}



		/**
		 *	Create, Release Methods
		 */
		DeviceContext* DeviceContext::Create(Device* device) {

			switch (APIManager::GetInstance()->GetAPIFlag())
			{

			case NONE_API_FLAG:

				break;

			case DIRECTX11_API_FLAG:

				return new DirectX11::DeviceContext(device);

				break;

			case DIRECTX12_API_FLAG:

				break;

			case VULKAN_API_FLAG:

				break;

			case OPENGL_API_FLAG:

				break;

			default:
				break;
			}

			return nullptr;

		}

		void DeviceContext::Release() {

			delete this;

		}

	}

}