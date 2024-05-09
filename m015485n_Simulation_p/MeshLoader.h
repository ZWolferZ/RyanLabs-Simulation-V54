#pragma once

#include "Structures.h"
#include <iostream>
#include <fstream>

namespace MeshLoader
{
	Mesh* texLoad(char* path);
	Mesh* noTexLoad(char* path);
	
};

