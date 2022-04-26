
# ING Lowlevel Overview #

  

## Board and Square ("Low Level Modules") ##

+ **Board** is 1 class, singleton and has it own squares, virtual methods:
	- **Init**() (bool)
	- **Run**() (bool)
	- **Release**() (bool)

+ **Square** is 1 class and have virtual methods:
	- **Init**() (bool)
	- **Run**() (bool)
	- **Release**() (bool)

+ [**ING::Engine**](CPPClasses/Engine/Engine.md) is 1 class which inherited **Board** class, include these squares:

	- System

	- Time

	- Profiler

	- ResourceManager

	- Rendering Engine

	- ...

+ When [**ING::Engine**](CPPClasses/Engine/Engine.md)::**Init** is called, it will call Init method of each Square (the same as Run and Release methods)

  

## How it works ##

+ [**ING::Engine**](CPPClasses/Engine/Engine.md) class manages all systems and managers ([**ING::Engine**](CPPClasses/Engine/Engine.md) is not application).

+ ING::Application is a class whose instance is the application, managed by ING::ApplicationManager (1 Square of [**ING::Engine**](CPPClasses/Engine/Engine.md)). ING Engine allow multiple applications in 1 program. When we use editor, ING create 2 application (editor application and game application).

+ We built a dynamic linking library (ING.dll). It will imported by runtime (runtime is an ".exe file"). When we start game or editor, the runtime (ING.Editor.Runtime(editor's runtime) or ING.Runtime(release game which not support Play In Editor)) will create [**ING::Engine**](CPPClasses/Engine/Engine.md), init [**ING::Engine**](CPPClasses/Engine/Engine.md), create applications and run [**ING::Engine**](CPPClasses/Engine/Engine.md).

## Projects ##

+ Engine has 3 main projects:

	- ING (create ING.dll)

	- ING.Runtime (create standalone game runtime)

	- ING.Scripting.CSharp (create c# engine library)

+ Editor is an application created with ING Engine. It has 2 main projects:

	- EngineBuilderCaller (call ING.Tools.EngineBuilder to build engine directory)

	- ING.Editor.Runtime (create editor runtime, support play in editor,...)