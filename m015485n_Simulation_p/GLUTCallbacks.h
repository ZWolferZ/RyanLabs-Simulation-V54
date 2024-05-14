// ----------------------------- INCLUDES ----------------------------- //
#pragma once
#ifndef _GLUTCALLBACKS_H
#define GLUTCALLBACKS_H
#include <string>
// ----------------------------- INCLUDES ----------------------------- //

class OpenGL; // Foward Declaration for class

// ----------------------------- NAMESPACE ----------------------------- //
namespace GLUTCallbacks
{
	/// <summary>
	/// Initilise program by parsing in the opengl class.
	/// </summary>
	void Init(OpenGL* gl);

	/// <summary>
	/// Called in the glut main loop to render each new frame every time it is called.
	/// </summary>
	void Display();

	/// <summary>
	/// Keyboard function parsed into the glut main loop.
	/// </summary>
	void keyboardControls(unsigned char key, int x, int y);

	/// <summary>
	/// Keyboard function parsed into the glut main loop, if key is up.
	/// </summary>
	void keyboardControlsUp(unsigned char key, int x, int y);

	/// <summary>
	/// Special Keyboard function parsed into the glut main loop, for special keys.
	/// </summary>
	void keyboardSpecial(int key, int x, int y);

	/// <summary>
	/// Special Keyboard function parsed into the glut main loop, for special keys, if they are up.
	/// </summary>
	void keyboardSpecialUp(int key, int x, int y);

	/// <summary>
	/// Updates the position of the camera each time it is called, relative to the world origin
	/// </summary>
	void updateCamera();

	/// <summary>
	/// Sets the framerate to 60FPS by calling the glutPostRedisplay() function.
	/// </summary>
	void Timer(int preferredRefresh);

	/// <summary>
	/// Deletes the pointer to the opengl class
	/// </summary>
	void Destroy();

	/// <summary>
	/// Parses the mouse rotation into the mouse loop to update the camera position
	/// </summary>
	void mouseRotation(int x, int y);

	/// <summary>
	/// Parses the scroll wheel into the glut main loop to increase/decrease the Z position.
	/// </summary>
	void mouseWheel(int wheel, int direction, int x, int y);
}
#endif // _GLUTCALLBACKS_H
// ----------------------------- NAMESPACE ----------------------------- //
