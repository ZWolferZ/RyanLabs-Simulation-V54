// ----------------------------- INCLUDES ----------------------------- //
#pragma once
#ifndef _OBJLOADER_H
#define OBJLOADER_H
#include <vector>
#include "Structures.h"
#include <iostream>
#include <fstream>
// ----------------------------- INCLUDES ----------------------------- //

// ----------------------------- NAMESPACE ----------------------------- //
//Non-functional Loader (Points for trying?)
namespace OBJLoader
{
	/// <summary>
	/// Loads a OBJ file and decompiles it into the data structure.
	///  (It doesn't do this I just think it would be cool if it did)
	/// </summary>
	OBJMesh* LoadOBJ(const char* path);
}
#endif // _OBJLOADER_H
// ----------------------------- NAMESPACE ----------------------------- //
