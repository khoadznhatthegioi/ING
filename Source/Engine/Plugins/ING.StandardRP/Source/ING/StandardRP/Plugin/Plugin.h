#pragma once

#include <ING/StandardRP/EntryPoint/EntryPoint.h>
#include <ING/Utils/Utils.h>



/**
 *	Declare Classes
 */
namespace ING {

	class Engine;
	class IPlugin;

}



/**
 *	Plugin Info
 */
DECLARE_PLUGIN(ING_STANDARDRP);



/**
 *	Plugin Events
 */
DECLARE_PLUGIN_FUNCTION(ING_STANDARDRP, bool, Load)		(ING::Engine* engine, ING::IPlugin * plugin);
DECLARE_PLUGIN_FUNCTION(ING_STANDARDRP, bool, Unload)		();

DECLARE_PLUGIN_FUNCTION(ING_STANDARDRP, bool, LateCreate)	();

DECLARE_PLUGIN_FUNCTION(ING_STANDARDRP, bool, PreInit)	();
DECLARE_PLUGIN_FUNCTION(ING_STANDARDRP, bool, LateInit)	();

DECLARE_PLUGIN_FUNCTION(ING_STANDARDRP, bool, PreRun)		();

DECLARE_PLUGIN_FUNCTION(ING_STANDARDRP, bool, PreRelease)	();