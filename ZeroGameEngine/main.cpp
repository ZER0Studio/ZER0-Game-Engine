
#include "Engine.h"



int main(int argc, const char** argv) {

	ZEROGE::Engine* engine = new ZEROGE::Engine("Zero Game Engine v1");
	engine->Run();

	delete engine;

	return 0;
}