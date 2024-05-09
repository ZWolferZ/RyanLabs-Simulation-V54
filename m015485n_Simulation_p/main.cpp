#include <iostream>
#include "OpenGL.h"
#include "LinkedLists.h"


int main(int argc, char* argv[])
{
	const auto* game = new OpenGL(argc, argv);

	delete game;

	return 0;
}
