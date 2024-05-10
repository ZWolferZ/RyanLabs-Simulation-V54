#include "OpenGL.h"

GLfloat cameraX = 0.75f;
GLfloat cameraY = 0.0f;
GLfloat cameraZ = 4.0f;
GLfloat cameraYaw = 0.0f;
GLfloat cameraPitch = 0.0f;
bool UpButton = false;
bool DownButton = false;
bool LeftButton = false;
bool RightButton = false;
bool fullScreen = true;
bool toggle = false;
bool mouseToggle = false;
GLfloat rotation = 0.0f;

std::unique_ptr<LinkedLists> lists(new LinkedLists());

Color c = {0.0f, 1.0f, 0.0f};

OpenGL::OpenGL(int argc, char* argv[])
{
	// Get a random seed by using the current time and the thread id
	const auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count() +
                std::hash<std::thread::id>{}(std::this_thread::get_id());
    srand(seed);
	InitGL(argc, argv);
	InitObjects();
	glutMainLoop();
}

void OpenGL::Display() const
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);


	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);


	DrawString("Graphics Renderer Property of RyanLabs", &c, -1.0f, 0.95f);

	DrawString("CONTROLS:", &c, -1.0f, -0.3f);

	DrawString("Move mouse to rotate camera around the origin", &c, -1.0f, -0.4f);
	DrawString("Scroll mouse wheel to zoom in/out", &c, -1.0f, -0.45f);
	DrawString("WASD / ARROWS to move camera position", &c, -1.0f, -0.5f);
	DrawString("Press 'R' to reset camera", &c, -1.0f, -0.55f);
	DrawString("Press 'F' to toggle fullscreen", &c, -1.0f, -0.60f);
	DrawString("Press 'T' to toggle mouse lock", &c, -1.0f, -0.65f);
	DrawString("Press 'C' to see the console for 5 seconds", &c, -1.0f, -0.7f);
	DrawString("Press 'L' to print linked object list", &c, -1.0f, -0.75f);
	DrawString("Press 'BACKSPACE' to delete a object from the list", &c, -1.0f, -0.80f);
	DrawString("Press 'P' to print camera position", &c, -1.0f, -0.85f);
	DrawString("Press 'O' to print camera rotation", &c, -1.0f, -0.9f);
	DrawString("Press 'ESC' to quit", &c, -1.0f, -0.95f);


	for (const auto object : objects)
	{
		if (object != nullptr)
		{
			glEnable(GL_TEXTURE_2D);
			object->DrawCubes();
			object->DrawOBJ();

			glDisable(GL_TEXTURE_2D);

			object->DrawWire();
			object->DrawPyramids();
		}
	}


	// TOTALLY OBJ OBJECTS, JUST DON'T LOOK TO HARD

	glPushMatrix();
	glTranslatef(8.0f, 0.0f, -3.0f);
	glRotatef(rotation, 0.0f, 1.0f, 0.0f);
	glColor3f(0.6f, 1.0f, 0.1f);
	glutWireTeapot(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(5.0f, 0.0f, -3.0f);
	glRotatef(rotation, 1.0f, 1.0f, 0.0f);
	glColor3f(0.6f, 1.0f, 0.1f);
	glutWireSphere(1.0f, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.0f, 0.0f, -3.0f);
	glRotatef(rotation, 1.0f, 1.0f, 0.0f);
	glColor3f(0.9f, 0.5f, 0.1f);
	glutWireIcosahedron();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.0f, 0.0f, -3.0f);
	glRotatef(rotation, 1.0f, 1.0f, 0.0f);
	glRotatef(60.0f, 0.0f, 0.0f, 0.0f);
	glColor3f(0.9f, 0.5f, 0.1f);
	glutWireDodecahedron();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-4.0f, 0.0f, -3.0f);
	glRotatef(rotation, 1.0f, 1.0f, 0.0f);
	glColor3f(1.0f, 0.0f, 0.0f);
	glutWireOctahedron();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-7.0f, 0.0f, -3.0f);
	glRotatef(rotation, 1.0f, 1.0f, 0.0f);
	glColor3f(1.0f, 0.0f, 0.0f);
	glutWireTetrahedron();
	glPopMatrix();


	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);

	glFlush();
	glutSwapBuffers();
}

void minimizeConsoleWindow()
{
	const HWND handle = GetConsoleWindow();
	ShowWindow(handle, SW_MINIMIZE);
}

void maximizeConsoleWindow()
{
	const HWND handle = GetConsoleWindow();
	ShowWindow(handle, SW_MAXIMIZE);
}

void OpenGL::updateRefreshrate()
{
	glutPostRedisplay();


	for (const auto& object : objects)
	{
		if (object != nullptr)
		{
			object->Update();
		}
	}
	rotation += 1;

	if (rotation == 360)
	{
		rotation = 0;
	}


	GLUTCallbacks::updateCamera();
}

int temp;
int count = objectCount;

void OpenGL::keyboardControls(const unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'r': // Reset camera
		case 'R': 
		cameraX = 0.75f;
		cameraY = 0.0f;
		cameraZ = 4.0f;
		cameraYaw = 0.0f;
		cameraPitch = 0.0f;

		break;

	case 'p': // Print camera position
		case 'P': 
		std::cout << "Camera Position: (" << cameraX << ", " << cameraY << ", " << cameraZ << ")" << '\n';
		glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
		glutLeaveFullScreen();
		fullScreen = false;
		maximizeConsoleWindow();
		Sleep(1000);
		minimizeConsoleWindow();
		glutFullScreen();
		fullScreen = true;
		break;

	case 'o': // Print camera rotation
		case 'O':
		std::cout << "Camera Rotation: (" << cameraYaw << ", " << cameraPitch << ")" << '\n';
		glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
		glutLeaveFullScreen();
		fullScreen = false;
		maximizeConsoleWindow();
		Sleep(1000);
		minimizeConsoleWindow();
		glutFullScreen();
		fullScreen = true;
		break;

	case 'l':
		case 'L':
		glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
		glutLeaveFullScreen();
		fullScreen = false;
		maximizeConsoleWindow();
		lists->PrintList();
		Sleep(1000);
		minimizeConsoleWindow();
		glutFullScreen();
		fullScreen = true;
		break;
	case 27: // 27 = esc key
		std::cout << "Quiting..." << '\n';
		glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
		glutLeaveFullScreen();
		fullScreen = false;
		maximizeConsoleWindow();
		OpenGL::~OpenGL();
		glutLeaveMainLoop();
		break;

	case 'f':
		case 'F':

		if (!fullScreen)
		{
			glutFullScreen();
			fullScreen = true;
		}
		else
		{
			glutLeaveFullScreen();
			fullScreen = false;
		}

		break;

	case 'w':
		case 'W':
		UpButton = true;
		break;

	case 's':
		case 'S':
		DownButton = true;
		break;

	case 'a':
		case 'A':
		LeftButton = true;
		break;

	case 'd':
		case 'D':
		RightButton = true;
		break;

	case 8:
		glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
		glutLeaveFullScreen();
		fullScreen = false;
		maximizeConsoleWindow();
		std::cout << "Enter the object index you want to delete: " << '\n';


		if (!(std::cin >> temp))
		{
			std::cerr << "Invalid input." << '\n';

			Sleep(2000);
			minimizeConsoleWindow();
			glutFullScreen();
			fullScreen = true;
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			break;
		}

		if (temp < 0 || temp > objectLimit - 1)
		{
			std::cerr << "Invalid index. Index must be between 0 and " << count - 1 << '\n';
			Sleep(2000);
			minimizeConsoleWindow();
			glutFullScreen();
			fullScreen = true;
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			break;
		}

		if (lists->DeleteAfter(lists->GetNode(temp - 1)))
		{
			delete objects[temp - 1];
			objects[temp - 1] = nullptr;
			count--;
			std::cout << "Object at index " << temp << " deleted." << '\n';
			Sleep(2000);
			minimizeConsoleWindow();
			glutFullScreen();
			fullScreen = true;
		}
		else
		{
			std::cout << "Previous node cannot be null or the last node." << '\n';
			Sleep(2000);
			minimizeConsoleWindow();
			glutFullScreen();
			fullScreen = true;
		}
		break;

	case't':
		case 'T':
		if (mouseToggle)
		{
			mouseToggle = false;
		}
		else
		{
			mouseToggle = true;
			glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
		}

		break;

		case 'c':
			case 'C':
			glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
		glutLeaveFullScreen();
		fullScreen = false;
		maximizeConsoleWindow();
		Sleep(5000);
		minimizeConsoleWindow();
		glutFullScreen();
		fullScreen = true;
			break;

	default: ;
	}
}

void OpenGL::keyboardControlsUp(const unsigned char key, int x, int y)
{
	if (UpButton || DownButton || LeftButton || RightButton)
	{
		switch (key)
		{
		case 'w':
			case 'W':
			UpButton = false;
			break;

		case 's':
			case 'S':
			DownButton = false;
			break;

		case 'a':
			case 'A':
			LeftButton = false;
			break;

		case 'd':
			case 'D':
			RightButton = false;
			break;

		default: ;
		}
	}
}

void OpenGL::keyboardSpecial(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		UpButton = true;
		break;

	case GLUT_KEY_DOWN:
		DownButton = true;
		break;

	case GLUT_KEY_LEFT:
		LeftButton = true;
		break;

	case GLUT_KEY_RIGHT:
		RightButton = true;
		break;

	default: ;
	}
}

void OpenGL::keyboardSpecialUp(int key, int x, int y)
{
	if (UpButton || DownButton || LeftButton || RightButton)
	{
		switch (key)
		{
		case GLUT_KEY_UP:
			UpButton = false;
			break;

		case GLUT_KEY_DOWN:
			DownButton = false;
			break;

		case GLUT_KEY_LEFT:
			LeftButton = false;
			break;

		case GLUT_KEY_RIGHT:
			RightButton = false;
			break;

		default: ;
		}
	}
}


void OpenGL::updateCamera()
{
	glLoadIdentity();

	if (UpButton)
	{
		cameraY += 0.25f;
	}

	if (DownButton)
	{
		cameraY -= 0.25f;
	}

	if (LeftButton)
	{
		cameraX -= 0.25f;
	}

	if (RightButton)
	{
		cameraX += 0.25f;
	}
	glTranslatef(-cameraX, -cameraY, -cameraZ);
	glRotatef(-cameraPitch, 1.0f, 0.0f, 0.0f);
	glRotatef(-cameraYaw, 0.0f, 1.0f, 0.0f);
}


void OpenGL::InitGL(int argc, char* argv[])
{
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(screenWidth, screenHeight);
	glutCreateWindow("3D Cubes Test");
	glutFullScreen();
	minimizeConsoleWindow();
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);

	/// FACE CULLING
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);


	/// FOG TESTING
	glEnable(GL_FOG);
	glFogf(GL_FOG_START, fogStart);
	glFogf(GL_FOG_END, fogEnd);
	glFogf(GL_FOG_MODE, GL_LINEAR);
	glFogf(GL_FOG_DENSITY, fogDensity);
	glFogfv(GL_FOG_COLOR, fogColor);


	/// GLUT FUNCTIONS
	glutDisplayFunc(GLUTCallbacks::Display);
	glutKeyboardFunc(GLUTCallbacks::keyboardControls);
	glutKeyboardUpFunc(GLUTCallbacks::keyboardControlsUp);
	glutSpecialFunc(GLUTCallbacks::keyboardSpecial);
	glutSpecialUpFunc(GLUTCallbacks::keyboardSpecialUp);
	glutPassiveMotionFunc(GLUTCallbacks::mouseRotation);
	glutMouseWheelFunc(GLUTCallbacks::mouseWheel);
	glutTimerFunc(refreshRate, GLUTCallbacks::Timer, refreshRate);


	/// LINE SMOOTHING

	glEnable(GL_LINE_SMOOTH);
	glLineWidth(lineWidth);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, screenWidth, screenHeight);
	gluPerspective(fov, aspectRatio, zNear, zFar);
	glMatrixMode(GL_MODELVIEW);
}

void OpenGL::InitObjects()
{
	/// Toggle to make sure the cubes are only instanced once.
	/// Pretty sure they are already, but it cant hurt.
	if (toggle == false)
	{
		auto* cubeMesh = MeshLoader::texLoad(("Objects/cube.txt"));

		auto* texture = new Texture2D();

		texture->Load(("Textures/stars.raw"), 512, 512);

		for (int i = 0; i < cubeNumber; i++)
		{
			lists->InsetNode(i);


			objects[i] = new Cube(cubeMesh, texture, ((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f,
			                      -(rand() % 1000) / 10.0f);
		}

		/*
	    //-------------------------------------TEST PROTOTYPE FOR OBJ LOADING (NON FUNCTIONAL)-------------------------------------//
	    |	                                                                                                                       |  
	    |	auto* OBJMesh = OBJLoader::LoadOBJ("Objects/teapot.obj");                                                              |
		|                                                                                                                          |
	    |	for (int i = cubeNumber; i < cubeNumber + OBJNumber; i++)                                                              |
		|    {                                                                                                                     |
		|	 objects[i] = new OBJObjects(OBJMesh, 0, 0, 0);                                                                        |
		|    }                                                                                                                     |
		|                                                                                                                          |
		//-------------------------------------------------------------------------------------------------------------------------//
		*/
		auto* pyramidMesh = MeshLoader::noTexLoad(("Objects/pyramid.txt"));


		for (int i = cubeNumber; i < objectCount; i++)
		{
			objects[i] = new StaticObjects(pyramidMesh, ((rand() % 400) / 10.0f) - 20.0f,
			                               ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f);

			lists->InsetNode(i);
		}

		toggle = true;
	}
}


void OpenGL::DrawString(const char* text, Color* color, float x, float y)
{
	const GLfloat textLocationX = x;
	const GLfloat textLocationY = y;

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glOrtho(-1, 1, -1, 1, -1, 1);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glColor3f(color->r, color->g, color->b);


	glRasterPos2f(textLocationX, textLocationY);


	for (const char* c = text; *c != '\0'; ++c)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
	}

	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}

void OpenGL::mouseRotation(int x, int y)
{
	if (fullScreen)
	{
		if (!mouseToggle)
		{
			GLint prevMouseX = screenWidth / 2;
			GLint prevMouseY = screenHeight / 2;
			constexpr GLfloat sensitivity = 0.05f;

			GLint deltaX = x - prevMouseX;
			GLint deltaY = y - prevMouseY;

			cameraYaw -= deltaX * sensitivity;
			cameraPitch -= deltaY * sensitivity;


			if (cameraPitch > 89.0f)
			{
				cameraPitch = 89.0f;
			}
			if (cameraPitch < -89.0f)
			{
				cameraPitch = -89.0f;
			}

			prevMouseX = x;
			prevMouseY = y;

			glutSetCursor(GLUT_CURSOR_NONE);
			glutWarpPointer(screenWidth / 2, screenHeight / 2);
		}
	}
	else
	{
		glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
	}
}

void OpenGL::mouseWheel(int wheel, int direction, int x, int y)
{
	if (fullScreen)
	{
		if (!mouseToggle)
		{
			if (wheel == 0)
			{
				cameraZ += direction * 0.5f;
			}

			if (direction == -1)
			{
				cameraZ += 1.0f;
			}
			else if (direction == 1)
			{
				cameraZ -= 1.0f;
			}
		}
	}
}


OpenGL::~OpenGL()
{
	for (auto& object : objects)
	{
		if (object != nullptr)
		{
			delete object;
			object = nullptr;
		}
	}


	GLUTCallbacks::Destroy();
}
