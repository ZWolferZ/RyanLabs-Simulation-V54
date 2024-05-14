// ----------------------------- INCLUDES ----------------------------- //
#pragma once
#ifndef _TEXTURE2D_H
#define TEXTURE2D_H
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL/freeglut.h"
#include "GLUTCallbacks.h"
#include "Structures.h"
// ----------------------------- INCLUDES ----------------------------- //

// ----------------------------- TEXTURE2D CLASS ----------------------------- //
class Texture2D
{
public:
	/// <summary>
	/// Initialise properties for the texture.
	/// </summary>
	Texture2D();

	/// <summary>
	/// Delete the bind-ed textures.
	/// </summary>
	~Texture2D();

	/// <summary>
	/// Load texture from raw file type to cube mesh by using a path and a width/height.
	/// </summary>
	bool Load(const char* path, int width, int height);

	/// <summary>
	/// Returns a unused and free ID for use in a texture load.
	/// </summary>
	GLuint GetID() const { return ID; }

	/// <summary>
	/// Returns the width of a texture.
	/// </summary>
	int GetWidth() const { return _width; }

	/// <summary>
	/// Returns the height of a texture.
	/// </summary>
	int GetHeight() const { return _height; }

private:
	GLuint ID; // Texture ID
	int _width, _height;
};

#endif // _TEXTURE2D_H
// ----------------------------- TEXTURE2D CLASS ----------------------------- //
