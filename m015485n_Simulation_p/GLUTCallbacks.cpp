#include "GLUTCallbacks.h"
#include "HelloGL.h"
#include <iostream>

#include "Cube.h"


namespace GLUTCallbacks
{
	bool fullScreen = true;

	namespace
	{
		HelloGL* helloGL = nullptr;
	}

	void Init(HelloGL* gl)
	{
		helloGL = gl;
	}

	void Destroy()
	{
		helloGL = nullptr;
		delete helloGL;
	}

	void Display(void)
	{
		if (helloGL != nullptr)
		{
			helloGL->Display();
		}
		else
		{
			glutLeaveMainLoop();
		}
	}


	void keyboardControls(const unsigned char key, int x, int y)
	{
		if (helloGL != nullptr)
		{
			helloGL->keyboardControls(key, x, y);
		}
		else
		{
			glutLeaveMainLoop();
		}
	}

	void keyboardSpecial(int key, int x, int y)
	{
		if (helloGL != nullptr)
		{
			helloGL->keyboardSpecial(key, x, y);
		}
		else
		{
			glutLeaveMainLoop();
		}
	}

	void keyboardSpecialUp(int key, int x, int y)
	{
		if (helloGL != nullptr)
		{
			helloGL->keyboardSpecialUp(key, x, y);
		}
		else
		{
			glutLeaveMainLoop();
		}
	}

	void updateCamera()
	{
		if (helloGL != nullptr)
		{
			helloGL->updateCamera();
		}
		else
		{
			glutLeaveMainLoop();
		}
	}

	void mouseRotation(int x, int y)
	{
		if (helloGL != nullptr)
		{
			helloGL->mouseRotation(x, y);
		}
		else
		{
			glutLeaveMainLoop();
		}
	}

	void mouseWheel(int wheel, int direction, int x, int y)
	{
		if (helloGL != nullptr)
		{
			helloGL->mouseWheel(wheel, direction, x, y);
		}
		else
		{
			glutLeaveMainLoop();
		}
	}

	void keyboardControlsUp (unsigned char key, int x, int y)
	{
				if (helloGL != nullptr)
				{
								helloGL->keyboardControlsUp(key, x, y);
		}
		else
		{
						glutLeaveMainLoop();
		}
	}


	void Timer(const int preferredRefresh)
	{
		if (helloGL != nullptr)
		{
			int updateTime = glutGet(GLUT_ELAPSED_TIME);
			helloGL->updateRefreshrate();
			updateTime = glutGet(GLUT_ELAPSED_TIME) - updateTime;
			glutTimerFunc(preferredRefresh - updateTime, Timer, preferredRefresh);
		}
		else
		{
			glutLeaveMainLoop();
		}
	}
}
