#pragma once
#ifndef _TEXTURE2D_H
#define TEXTURE2D_H
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL/freeglut.h"
#include "GLUTCallbacks.h""

#include "Structures.h"

class Texture2D
{
public:
	Texture2D();

	~Texture2D();

	bool Load(char* path, int width, int height);

	GLuint GetID() const { return ID; }
	int GetWidth() const { return _width; }
	int GetHeight() const { return _height; }

private:
	GLuint ID; // Texture ID
	int _width, _height;
};

#endif // _TEXTURE2D_H
