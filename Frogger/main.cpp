// main.cpp
#include "Engine.h"
using namespace std;
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

