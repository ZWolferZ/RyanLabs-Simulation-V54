#pragma once
#ifndef _OPENGL_H
#define OPENGL_H
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include "Cube.h"
#include "GL/freeglut.h"
#include "GLUTCallbacks.h""
#include "Structures.h"


class OpenGL
{
public:
	OpenGL(int argc, char* argv[]);

	~OpenGL();

	void Display(void) const;

	void updateRefreshrate();

	void keyboardControls(unsigned char key, int x, int y);

	static void keyboardControlsUp(unsigned char key, int x, int y);

	static void keyboardSpecial(int key, int x, int y);

	static void keyboardSpecialUp(int key, int x, int y);

	static void updateCamera();

	void InitGL(int argc, char* argv[]);

	void InitObjects();

	static void DrawString(const char* text, Color* color, float x, float y);

	static void mouseRotation(int x, int y);

	static void mouseWheel(int wheel, int direction, int x, int y);

private:
	SceneObject* objects[objectLimit];
};
#endif // _OPENGL_H
