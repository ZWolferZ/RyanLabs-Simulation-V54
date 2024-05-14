// ----------------------------- INCLUDES ----------------------------- //
#pragma once
#ifndef _MESHLOADER_H
#define MESHLOADER_H
#include "Structures.h"
#include <iostream>
#include <fstream>
// ----------------------------- INCLUDES ----------------------------- //

// ----------------------------- NAMESPACE ----------------------------- //
namespace MeshLoader
{
	/// <summary>
	/// Meshloader that includes the texture load function.
	/// </summary>
	Mesh* texLoad(const char* path);

	/// <summary>
	///  Meshloader that does not includes the texture load function.
	/// </summary>
	Mesh* noTexLoad(const char* path);
};

#endif // _MESHLOADER_H
// ----------------------------- NAMESPACE ----------------------------- //