#pragma once
#ifndef _OBJLOADER_H
#define OBJLOADER_H
#include <vector>

#include "Structures.h"

#include <iostream>
#include <fstream>

namespace OBJLoader
{
	OBJMesh* LoadOBJ(const char* path);
}
#endif // _OBJLOADER_H
