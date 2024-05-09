#pragma once
#ifndef _GLUTCALLBACKS_H
#define GLUTCALLBACKS_H
#include <string>

class OpenGL;

namespace GLUTCallbacks
{
	void Init(OpenGL* gl);

	void Display();

	void keyboardControls(unsigned char key, int x, int y);

	void keyboardControlsUp(unsigned char key, int x, int y);

	void keyboardSpecial(int key, int x, int y);

	void keyboardSpecialUp(int key, int x, int y);

	void updateCamera();

	void Timer(int preferredRefresh);

	void Destroy();

	void mouseRotation(int x, int y);

	void mouseWheel(int wheel, int direction, int x, int y);
}
#endif // _GLUTCALLBACKS_H
