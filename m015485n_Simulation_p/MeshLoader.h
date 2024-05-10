#pragma once
#ifndef _MESHLOADER_H
#define MESHLOADER_H
#include "Structures.h"
#include <iostream>
#include <fstream>

namespace MeshLoader
{
	Mesh* texLoad(const char* path);
	Mesh* noTexLoad(const char* path);
};

#endif // _MESHLOADER_H
