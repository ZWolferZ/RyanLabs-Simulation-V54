// ----------------------------- INCLUDES ----------------------------- //
#include "GLUTCallbacks.h"
#include "OpenGL.h"
#include <iostream>
#include "Cube.h"
// ----------------------------- INCLUDES ----------------------------- //

// ----------------------------- NAMESPACE ----------------------------- //
namespace GLUTCallbacks
{
	namespace
	{
		// Initialises the OpenGL class as a nullptr.
		OpenGL* GL_Class = nullptr;
	}

	// Initialises the OpenGL class using a pointer from main.
	void Init(OpenGL* gl)
	{
		GL_Class = gl;
	}

	// Deletes the OpenGL class.
	void Destroy()
	{
		GL_Class = nullptr;
		delete GL_Class;
	}

	// Display function that is called every frame, draws objects.
	void Display(void)
	{
		if (GL_Class != nullptr)
		{
			GL_Class->Display();
		}
		else
		{
			glutLeaveMainLoop();
		}
	}

	// Keyboard function parsed into the glut main loop.
	void keyboardControls(const unsigned char key, int x, int y)
	{
		if (GL_Class != nullptr)
		{
			GL_Class->keyboardControls(key, x, y);
		}
		else
		{
			glutLeaveMainLoop();
		}
	}

	// Keyboard function parsed into the glut main loop, if key is up.
	void keyboardSpecial(int key, int x, int y)
	{
		if (GL_Class != nullptr)
		{
			GL_Class->keyboardSpecial(key, x, y);
		}
		else
		{
			glutLeaveMainLoop();
		}
	}

	// Special Keyboard function parsed into the glut main loop, for special keys, if they are up.
	void keyboardSpecialUp(int key, int x, int y)
	{
		if (GL_Class != nullptr)
		{
			GL_Class->keyboardSpecialUp(key, x, y);
		}
		else
		{
			glutLeaveMainLoop();
		}
	}

	// Updates the position of the camera each time it is called, relative to the world origin
	void updateCamera()
	{
		if (GL_Class != nullptr)
		{
			GL_Class->updateCamera();
		}
		else
		{
			glutLeaveMainLoop();
		}
	}

	// Parses the mouse rotation into the mouse loop to update the camera position
	void mouseRotation(int x, int y)
	{
		if (GL_Class != nullptr)
		{
			GL_Class->mouseRotation(x, y);
		}
		else
		{
			glutLeaveMainLoop();
		}
	}

	// Sets the framerate to 60FPS by calling the glutPostRedisplay() function.
	void mouseWheel(int wheel, int direction, int x, int y)
	{
		if (GL_Class != nullptr)
		{
			GL_Class->mouseWheel(wheel, direction, x, y);
		}
		else
		{
			glutLeaveMainLoop();
		}
	}

	// Keyboard function parsed into the glut main loop, if key is up.
	void keyboardControlsUp(unsigned char key, int x, int y)
	{
		if (GL_Class != nullptr)
		{
			GL_Class->keyboardControlsUp(key, x, y);
		}
		else
		{
			glutLeaveMainLoop();
		}
	}

	// Sets the framerate to 60FPS by calling the glutPostRedisplay() function.
	void Timer(const int preferredRefresh)
	{
		if (GL_Class != nullptr)
		{
			// Get the time
			int updateTime = glutGet(GLUT_ELAPSED_TIME);
			// Update the refresh rate
			GL_Class->updateRefreshrate();
			// Calculate the time taken to update the frame
			updateTime = glutGet(GLUT_ELAPSED_TIME) - updateTime;
			// Set the timer function to the preferred refresh rate
			glutTimerFunc(preferredRefresh - updateTime, Timer, preferredRefresh);
		}
		else
		{
			glutLeaveMainLoop();
		}
	}
}

// ----------------------------- NAMESPACE ----------------------------- //
