// main.cpp
#include "Engine.h"

int main(int argc, char *argv[])
{
	Engine engine;
	if (engine.Initialize())
	{
		engine.Run();
	}
	engine.Cleanup();

	return 0;
}

