
#include "Engine2D.h"

int main(int argc, const char** argv) {

	ZEROGE::Engine2D* engine = new ZEROGE::Engine2D("Zero Game Engine 2D v1");
	engine->Run();
	delete engine;

	return 0;
}