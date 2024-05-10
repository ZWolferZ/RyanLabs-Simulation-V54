#include "GLUTCallbacks.h"
#include "OpenGL.h"
#include <iostream>

#include "Cube.h"

namespace GLUTCallbacks
{
	namespace
	{
		OpenGL* GL_Class = nullptr;
	}

	void Init(OpenGL* gl)
	{
		GL_Class = gl;
	}

	void Destroy()
	{
		GL_Class = nullptr;
		delete GL_Class;
	}

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


	void Timer(const int preferredRefresh)
	{
		if (GL_Class != nullptr)
		{
			int updateTime = glutGet(GLUT_ELAPSED_TIME);
			GL_Class->updateRefreshrate();
			updateTime = glutGet(GLUT_ELAPSED_TIME) - updateTime;
			glutTimerFunc(preferredRefresh - updateTime, Timer, preferredRefresh);
		}
		else
		{
			glutLeaveMainLoop();
		}
	}
}
