// ----------------------------- INCLUDES ----------------------------- //
#include <iostream>
#include "OpenGL.h"
// ----------------------------- INCLUDES ----------------------------- //

// ----------------------------- MAIN FUNCTION ----------------------------- //
int main(int argc, char* argv[])
{
	// Changed to unique_ptr to avoid memory leaks and because it looks cooler
	std::unique_ptr<OpenGL> Simulation(new OpenGL(argc, argv));

	return 0;
}

// ----------------------------- MAIN FUNCTION ----------------------------- //
