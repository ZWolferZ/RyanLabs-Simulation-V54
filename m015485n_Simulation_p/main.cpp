#include <iostream>
#include "HelloGL.h"
#include "LinkedLists.h"


int main(int argc, char* argv[])
{
	const auto* game = new HelloGL(argc, argv);
	
	delete game;

	return 0;
}
