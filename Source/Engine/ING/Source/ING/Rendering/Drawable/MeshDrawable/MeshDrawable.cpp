
/**
 * Include Header
 */
#include "MeshDrawable.h"



/**
 *	Include Camera
 */
#include <ING/Camera/Camera.h>



/**
 *	Include Renderer
 */
#include <ING/Rendering/Renderer/Renderer.h>



/**
 *	Include Rendering API
 */
#include <ING/Rendering/API/API.h>



/**
 *	Include Rendering Device Context
 */
#include <ING/Rendering/API/Device/Context/Context.h>



/**
 *	Include Rendering Device
 */
#include <ING/Rendering/API/Device/Device.h>



/**
 *	Include Rendering Buffer
 */
#include <ING/Rendering/API/Resource/Buffer/Buffer.h>



/**
 *	Include Rendering Primitive Topology
 */
#include <ING/Rendering/API/PrimitiveTopology/PrimitiveTopology.h>



/**
 *	Include Rendering Pass
 */
#include <ING/Rendering/Pass/Pass.h>



/**
 *	Include Rendering Drawable
 */
#include <ING/Rendering/Drawable/Filter/Filter.h>



/**
 *	Include Rendering Layer
 */
#include <ING/Rendering/Layer/Layer.h>



/**
 *	Include Rendering Layer Manager
 */
#include <ING/Rendering/Layer/Manager/Manager.h>



/**
 *	Include Rendering Mesh
 */
#include <ING/Rendering/Mesh/Mesh.h>



/**
 *	Include Rendering Material
 */
#include <ING/Rendering/Material/Material.h>



/**
 *	Include Rendering Drawable Material
 */
#include <ING/Rendering/Material/DrawableMaterial/DrawableMaterial.h>



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



/**
 *	Include Camera
 */
#include <ING/Camera/Camera.h>



/**
 *	Include Material Event
 */
#include <ING/Rendering/Material/Event/Event.h>



/**
 *	Include Shader
 */
#include <ING/Rendering/Shader/Shader.h>




namespace ING {

	namespace Rendering {

		/**
		 *	Constructors And Destructor
		 */
		MeshDrawable::MeshDrawable(LayerSystem* system) :
			IDrawable(system),
			mesh(0),
			material(0),
			nodeInMaterialUpdateFilterNameVectorEventListenerList(0)
		{



		}

		MeshDrawable::~MeshDrawable() {

				

		}



		/**
		 *	Release Methods
		 */
		void MeshDrawable::Release() {

			if (this->material != 0) {

				this->material->GetEvent("UPDATE_FILTER_NAME_VECTOR")->RemoveListener(nodeInMaterialUpdateFilterNameVectorEventListenerList);

			}

			delete this;

		}



		/**
		 *	Properties
		 */
		void MeshDrawable::SetMaterial(IMaterial* material) { 
			
			if (this->material != 0) {

				this->material->GetEvent("UPDATE_FILTER_NAME_VECTOR")->RemoveListener(nodeInMaterialUpdateFilterNameVectorEventListenerList);

			}

			this->material = material; 

			material->GetEvent("UPDATE_FILTER_NAME_VECTOR")->AddListener([](Event* e) {
			
				IMaterialEvent* materialEvent = (IMaterialEvent*)e;

				((MeshDrawable*)materialEvent->GetCurrentOwner())->SetFilterNameVector(
				
					materialEvent->GetMaterial()->GetShader()->GetFilterNameVector()
				
				);
				
			}, this);

		}



		/**
		 *	Methods
		 */
		void MeshDrawable::Draw(Camera* camera, const String& passName) {

			material->Apply(passName);

			material->As<DrawableMaterial>()->ApplyTransform(transformMatrices,false);
			material->As<DrawableMaterial>()->ApplyCamera(camera,false);

			material->UpdatePropertyBuffer();


			/* Bind Buffers */
			IBuffer* vertexBuffer = mesh->GetVertexBuffer();
			IBuffer* indexBuffer  = mesh->GetIndexBuffer();

			IDeviceContext* context = vertexBuffer->GetDevice()->GetImmediateContext();

			context->IASetPrimitiveTopology(TRIANGLE_LIST);

			context->IASetVertexBuffer(vertexBuffer, mesh->GetVertexBufferDesc().stride, 0);
			context->IASetIndexBuffer(indexBuffer, mesh->GetIndexBufferDesc().format, 0);


			context->DrawIndexed(mesh->GetIndexCount(),0,0);

		}

	}

}