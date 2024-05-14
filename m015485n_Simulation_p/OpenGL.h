// ----------------------------- INCLUDES ----------------------------- //
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
// ----------------------------- INCLUDES ----------------------------- //

// ----------------------------- OPENGL CLASS ----------------------------- //
class OpenGL
{
public:
	/// <summary>
	/// Initialise OpenGL by calling several other functions.
	/// </summary>
	OpenGL(int argc, char* argv[]);

	/// <summary>
	/// Deletes the OpenGL object and frees the window.
	/// </summary>
	~OpenGL();

	/// <summary>
	/// Display function that is called every frame, draws objects.
	/// </summary>
	void Display(void) const;

	/// <summary>
	/// Update function that is called every frame, controls refresh rate.
	/// </summary>
	void updateRefreshrate();

	/// <summary>
	/// Holds switch-case for keyboard controls.
	/// </summary>
	void keyboardControls(unsigned char key, int x, int y);

	/// <summary>
	/// Reverts switch-case booleans for keyboard controls.
	/// </summary>
	static void keyboardControlsUp(unsigned char key, int x, int y);

	/// <summary>
	/// Holds switch-case for special keyboard controls.
	/// </summary>
	static void keyboardSpecial(int key, int x, int y);

	/// <summary>
	/// Reverts switch-case booleans for special keyboard controls.
	/// </summary>
	static void keyboardSpecialUp(int key, int x, int y);

	/// <summary>
	/// Updates the camera position relative to the world origin.
	/// </summary>
	static void updateCamera();

	/// <summary>
	/// Initialise most of the OpenGL functions called in the constructor.
	/// </summary>
	void InitGL(int argc, char* argv[]);

	/// <summary>
	/// Initialise objects before the scene is rendered, called in the constructor.
	/// </summary>
	void InitObjects();

	/// <summary>
	/// Initialise the lighting data used in the scene, called in the constructor.
	/// </summary>
	void InitLighting();

	/// <summary>
	/// Draws text to the screen using a colour and screen coordinates.
	/// </summary>
	static void DrawString(const std::string& text, Color* color, float x, float y);

	/// <summary>
	/// Parse in mouse rotation through the user input.
	/// </summary>
	static void mouseRotation(int x, int y);

	/// <summary>
	/// Parse in mouse scrolling through the user input.
	/// </summary>
	static void mouseWheel(int wheel, int direction, int x, int y);

	/// <summary>
	/// Changes the texture of the cube objects by re-initialising the objects.
	/// </summary>
	void textureChange();

private:
	SceneObject* objects[objectLimit];

	Vector4* lightPosition;
	Lighting* lightData;
};
#endif // _OPENGL_H
// ----------------------------- OPENGL CLASS ----------------------------- //
