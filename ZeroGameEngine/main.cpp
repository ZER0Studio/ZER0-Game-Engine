#include <GLFW\glfw3.h>

#include "Logger.h"

int main(int argc, const char** argv) {
	ZEROGE::Logger::Log("Initializing Zero Game Engine v%d", 1);
	return 0;
}