#pragma once
#include <string>

class HelloGL;

namespace GLUTCallbacks
{

	void Init(HelloGL* gl);

	void Display(void);

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
