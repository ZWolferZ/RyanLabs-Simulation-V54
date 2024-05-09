#pragma once
#ifndef _MESHLOADER_H
#define MESHLOADER_H
#include "Structures.h"
#include <iostream>
#include <fstream>

namespace MeshLoader
{
	Mesh* texLoad(char* path);
	Mesh* noTexLoad(char* path);
};

#endif // _MESHLOADER_H
