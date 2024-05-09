#pragma once
#include <vector>

#include "Structures.h"

#include <iostream>
#include <fstream>

namespace OBJLoader
{
	OBJMesh* LoadOBJ(const char* path);
}
