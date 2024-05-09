#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include "Cube.h"
#include "GL/freeglut.h"
#include "GLUTCallbacks.h""
#include "Structures.h"


class HelloGL
{
public:
	HelloGL(int argc, char* argv[]);

	~HelloGL();

	void Display(void) const;

	void updateRefreshrate();

	void keyboardControls(const unsigned char key, int x, int y);

	static void keyboardControlsUp(const unsigned char key, int x, int y);

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
