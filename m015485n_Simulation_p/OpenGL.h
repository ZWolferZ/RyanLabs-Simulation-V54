#pragma once
#ifndef _OPENGL_H
#define OPENGL_H
#include <Windows.h>
#include <chrono>
#include <thread>
#include <cmath>
#include <string>
#include <iostream>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL/freeglut.h"
#include "GLUTCallbacks.h"
#include "Structures.h"
#include "SceneObject.h"
#include "StaticObjects.h"
#include "Cube.h"
#include "OBJObjects.h"
#include "MeshLoader.h"
#include "OBJLoader.h"
#include "LinkedLists.h"


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

	void InitLighting();

	static void DrawString(const std::string& text, Color* color, float x, float y);

	static void mouseRotation(int x, int y);

	static void mouseWheel(int wheel, int direction, int x, int y);

	

	 void textureChange();

private:
	SceneObject* objects[objectLimit];


	Vector4* lightPosition;
	Lighting* lightData;
};
#endif // _OPENGL_H
