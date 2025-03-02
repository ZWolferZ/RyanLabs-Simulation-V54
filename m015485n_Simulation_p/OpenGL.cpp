// ----------------------------- INCLUDE ----------------------------- //
#include "OpenGL.h"
// ----------------------------- INCLUDE ----------------------------- //

// ----------------------------- VARIABLES ----------------------------- //

// GL Variables
GLfloat cameraX = 0.75f;
GLfloat cameraY = 0.0f;
GLfloat cameraZ = 4.0f;
GLfloat cameraYaw = 0.0f;
GLfloat cameraPitch = 0.0f;
GLfloat scale = 0;
GLfloat rotation = 0.0f;

// UI/Screen Variables
bool UpButton = false;
bool DownButton = false;
bool LeftButton = false;
bool RightButton = false;
bool fullScreen = true;
bool toggle = false;
bool mouseToggle = false;
bool mainMenu = true;
bool play = false;
bool playSelected = true;
bool lightingEnabled = false;
bool materialEnabled = false;
bool texChange = false;
bool cubeMovement = true;
bool fogEnabled = true;
bool scaleFlip = false;

//Linked List variables
int temp;
int count = objectCount;

// Random seed for object generation by using the current time and adding my birthday
const auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count() +
	14 + 07 + 2005;

// Cool unique pointer for the linked list which deletes itself automatically when out of scope
std::unique_ptr<LinkedLists> lists(new LinkedLists());

// UI colour variables
Color c = {0.0f, 1.0f, 0.0f};

Color c2 = {1.0f, 0.0f, 0.0f};

Color c3 = {0.0f, 0.0f, 1.0f};

Color c4 = {1.0f, 1.0f, 1.0f};

// ----------------------------- VARIABLES ----------------------------- //

// OpenGL Constructor to initialize the program
OpenGL::OpenGL(int argc, char* argv[])
{
	srand(seed);
	InitGL(argc, argv);
	InitObjects();
	InitLighting();
	glutMainLoop();
}

// Display function which renders the scene including the UI
void OpenGL::Display() const
{
	// Clear the screen and depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	// Enable the vertex and colour arrays
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	// Draw the UI for the main menu
	if (mainMenu)
	{
		DrawString("GRAPHICS SIMULATION BY RYAN MOAKES", &c4, -0.8f, 0.0f);
		DrawString("CHOOSE A OPTION TO START", &c4, -0.8f, -0.1f);
		DrawString("USE LEFT AND RIGHT ARROW KEYS & CONFIRM WITH ENTER:", &c4, -0.8f, -0.2f);
		if (playSelected)
		{
			DrawString("PLAY", &c, -0.8f, -0.35f);
			DrawString("QUIT", &c2, -0.6f, -0.35f);
		}
		else
		{
			DrawString("PLAY", &c2, -0.8f, -0.35f);
			DrawString("QUIT", &c, -0.6f, -0.35f);
		}

		// Render the teapots for the menu graphic
		glPushMatrix();
		glColor3f(1.0f, 0.0f, 0.0f);
		glRotatef(scale, 0.0f, 0.0f, 0.0f);
		glTranslatef(3.0f, 3.0f, 0.0);
		glutSolidTeapot(1);
		glPopMatrix();

		glPushMatrix();
		glColor3f(0.0f, 1.0f, 0.0f);
		glRotatef(scale, 0.0f, 0.0f, 0.0f);
		glTranslatef(3.0f, 0.0f, 0.0);
		glutSolidTeapot(1);
		glPopMatrix();

		glPushMatrix();
		glColor3f(0.0f, 0.0f, 1.0f);
		glRotatef(scale, 0.0f, 0.0f, 0.0f);
		glTranslatef(3.0f, -3.0f, 0.0);
		glutSolidTeapot(1);
		glPopMatrix();
	}
	// Draw the UI for the main scene
	else if (!mainMenu)
	{
		// I disable lighting here to make the text render without issue 
		glDisable(GL_LIGHTING);

		// The heads up display UI for the scene
		DrawString("Graphics Renderer Property of RyanLabs", &c, -1.0f, 0.95f);
		DrawString("RANDOM SEED:", &c, 0.0f, 0.85);
		DrawString(std::to_string(seed), &c, 0.19f, 0.85f);

		DrawString("Camera Position:", &c, 0.47f, 0.95f);
		DrawString(std::to_string(cameraX), &c, 0.66f, 0.95f);
		DrawString(std::to_string(cameraY), &c, 0.775f, 0.95f);
		DrawString(std::to_string(cameraZ), &c, 0.89f, 0.95f);
		DrawString("Camera Rotation:", &c, 0.47f, 0.9f);
		DrawString(std::to_string(cameraYaw), &c, 0.66f, 0.9f);
		DrawString(std::to_string(cameraPitch), &c, 0.775f, 0.9f);

		DrawString("CONTROLS:", &c, -1.0f, -0.05f);

		DrawString("Move mouse to rotate camera around the origin", &c, -1.0f, -0.15f);
		DrawString("Scroll mouse wheel to zoom in/out", &c, -1.0f, -0.2f);
		DrawString("WASD / ARROWS to move camera position", &c, -1.0f, -0.25f);
		DrawString("Press 'R' to reset camera", &c, -1.0f, -0.3f);
		DrawString("Press 'F' to toggle fullscreen", &c, -1.0f, -0.35f);
		DrawString("Press 'T' to toggle mouse lock", &c, -1.0f, -0.4f);
		DrawString("Press 'Q' to toggle lighting", &c, -1.0f, -0.45f);
		DrawString("Press 'E' to toggle material (NEEDS LIGHTING ENABLED)", &c, -1.0f, -0.5f);
		DrawString("Press 'Z' to toggle fog", &c, -1.0f, -0.55f);
		DrawString("Press 'SPACE' to toggle object movement", &c, -1.0f, -0.6f);
		DrawString("Press 'X' to change texture", &c, -1.0f, -0.65f);
		DrawString("Press 'C' to see the console for 5 seconds", &c, -1.0f, -0.7f);
		DrawString("Press 'L' to print linked object list", &c, -1.0f, -0.75f);
		DrawString("Press 'BACKSPACE' to delete a object from the list", &c, -1.0f, -0.80f);
		DrawString("Press 'P' to print camera position", &c, -1.0f, -0.85f);
		DrawString("Press 'O' to print camera rotation", &c, -1.0f, -0.9f);
		DrawString("Press 'ESC' to quit", &c, -1.0f, -0.95f);

		// If statements to control the UI changes on input
		if (!texChange)
		{
			DrawString("TEXTURE: STARS", &c, 0.0f, 0.8f);
		}
		else
		{
			DrawString("TEXTURE: PENGUINS", &c, 0.0f, 0.8f);
		}

		if (cubeMovement)
		{
			DrawString("OBJECT MOVEMENT ENABLED", &c, 0.0f, 0.75f);
		}
		else
		{
			DrawString("OBJECT MOVEMENT DISABLED", &c, 0.0f, 0.75f);
		}
		if (fogEnabled)
		{
			DrawString("FOG ENABLED", &c, 0.0f, 0.7f);
		}
		else
		{
			DrawString("FOG DISABLED", &c, 0.0f, 0.7f);
		}

		if (lightingEnabled)
		{
			DrawString("LIGHTING ENABLED", &c, 0.0f, 0.95f);
			if (materialEnabled)
			{
				DrawString("MATERIAL ENABLED", &c, 0.0f, 0.9f);
			}
			else
			{
				DrawString("MATERIAL DISABLED", &c, 0.0f, 0.9f);
			}
			glEnable(GL_LIGHTING);
			glEnable(GL_LIGHT0);
		}
		else
		{
			DrawString("LIGHTING DISABLED", &c, 0.0f, 0.95f);
			DrawString("MATERIAL DISABLED", &c, 0.0f, 0.9f);
			glDisable(GL_LIGHTING);
			glDisable(GL_LIGHT0);
		}


		// Main draw function for the scene objects
		for (const auto object : objects)
		{
			if (object != nullptr)
			{
				//  Only enable textures for the cubes/obj objects as the other objects do not support it
				glEnable(GL_TEXTURE_2D);

				object->DrawCubes();
				object->DrawOBJ();

				glDisable(GL_TEXTURE_2D);

				object->DrawWire();
				object->DrawPyramids();
			}
		}

		// Draw the Teapot timeline
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
	}

	// Disable the vertex and colour arrays
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);

	// Swap the buffers and flush the scene
	glFlush();
	glutSwapBuffers();
}

// Quick and dirty function to minimize and maximize the console window
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


// Main update function for the scene
void OpenGL::updateRefreshrate()
{
	// Update the display, only when called by the timer function, this is how I lock the frame rate
	glutPostRedisplay();


	// For all valid objects in the scene, update them
	for (const auto& object : objects)
	{
		if (object != nullptr)
		{
			object->Update();
		}
	}

	// Update the lighting data for all the objects, I think this is needed
	glLightfv(GL_LIGHT0,GL_AMBIENT, &(lightData->ambient.x));

	glLightfv(GL_LIGHT0, GL_DIFFUSE, &(lightData->diffuse.x));

	glLightfv(GL_LIGHT0, GL_SPECULAR, &(lightData->specular.x));

	glLightfv(GL_LIGHT0, GL_POSITION, &(lightPosition->x));

	// Boolean logic stored here for some moving objects

	rotation += 1;

	if (rotation == 360)
	{
		rotation = 0;
	}

	if (!scaleFlip)
	{
		scale += 1;
	}
	else
	{
		scale -= 1;
	}

	if (scale == 0)
	{
		scaleFlip = !scaleFlip;
	}

	if (scale == 75)
	{
		scaleFlip = !scaleFlip;
	}

	// Update the camera position
	GLUTCallbacks::updateCamera();
}


// Function parse for keyboard controls
void OpenGL::keyboardControls(const unsigned char key, int x, int y)
{
	// If the main menu is active, parse the input for the main menu
	if (mainMenu)
	{
		switch (key)
		{
		case 27: // 27 = esc key
			std::cout << "Quiting..." << '\n';
			maximizeConsoleWindow();
			OpenGL::~OpenGL();
			glutLeaveMainLoop();
			break;

		case 13: // 13 = enter key
			if (playSelected)
			{
				play = true;
			}
			else
			{
				std::cout << "Quiting..." << '\n';
				glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
				glutLeaveFullScreen();
				fullScreen = false;
				maximizeConsoleWindow();
				OpenGL::~OpenGL();
				glutLeaveMainLoop();
			}


			break;

		default:
			break;
		}

		if (play)
		{
			// If the play button is selected, start the scene and reset the camera position
			mainMenu = false;
			cameraX = 0.75f;
			cameraY = 0.0f;
			cameraZ = 4.0f;
			cameraYaw = 0.0f;
			cameraPitch = 0.0f;
		}
	}
	// If the main menu is not active, parse the input for the scene
	else
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

		case 'l': // Print the linked list of objects
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

		case 'f': // Fullscreen toggle
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

		case 'w': // Camera movement
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

		case 'x': // Texture change
		case 'X':

			// Delete all cube objects
			for (int i = 0; i < cubeNumber; i++)
			{
				if (objects[i] != nullptr)
				{
					delete objects[i];
					objects[i] = nullptr;
				}
			}

		// Call the main texture change function
			textureChange();

			break;

		case 8: // 8 = backspace key

			// Delete object from the linked list
			glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
			glutLeaveFullScreen();
			fullScreen = false;
			maximizeConsoleWindow();
			std::cout << "Enter the object index you want to delete: " << '\n';


		// Error handling for the input
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

		// Error handling for the input
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

		// Delete the object from the linked list
		// Stealing the delete after function and minus one to get the correct index
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
			// Error handling for the input
			else
			{
				std::cout << "Previous node cannot be null or the last node." << '\n';
				Sleep(2000);
				minimizeConsoleWindow();
				glutFullScreen();
				fullScreen = true;
			}
			break;

		case't': // Mouse toggle
		case 'T':
			if (mouseToggle)
			{
				// Lock the mouse to the window and hide the cursor
				mouseToggle = false;
			}
			else
			{
				// Unlock the mouse from the window and show the cursor
				mouseToggle = true;
				glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
			}

			break;

		case 'c': // Show console for 5 seconds
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

		case 'q': // Lighting toggle
		case 'Q':

			if (lightingEnabled)
			{
				// Disable lighting and material for all objects
				materialEnabled = false;

				for (auto& object : objects)
				{
					if (object != nullptr)
					{
						object->materialChange = false;
					}
				}
				lightingEnabled = false;
			}
			else
			{
				// Enable lighting for all objects
				lightingEnabled = true;
			}

			break;
		case'e': // Material toggle
		case'E':

			if (materialEnabled && lightingEnabled)
			{
				for (auto& object : objects)
				{
					if (object != nullptr)
					{
						object->materialChange = false;
					}
				}
				materialEnabled = false;
			}
			else if (!materialEnabled && lightingEnabled)
			{
				for (auto& object : objects)
				{
					if (object != nullptr)
					{
						object->materialChange = true;
					}
				}
				materialEnabled = true;
			}

			break;

		case 32: // 32 = space key

			// Toggle object movement
			if (cubeMovement)
			{
				for (auto& object : objects)
				{
					if (object != nullptr)
					{
						object->isMoving = false;
					}
					cubeMovement = false;
				}
			}
			else
			{
				for (auto& object : objects)
				{
					if (object != nullptr)
					{
						object->isMoving = true;
					}
				}
				cubeMovement = true;
			}


			break;

		case 'z': // Fog toggle
		case 'Z':

			if (fogEnabled)
			{
				glDisable(GL_FOG);
				fogEnabled = false;
			}
			else
			{
				glEnable(GL_FOG);
				fogEnabled = true;
			}

			break;

		default:
			break;
		}
	}
}

// Function to parse the keyboard input if the key is not pressed
void OpenGL::keyboardControlsUp(const unsigned char key, int x, int y)
{
	// If the WASD keys are not pressed, revert the booleans
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

// Function to parse the special keyboard input
void OpenGL::keyboardSpecial(int key, int x, int y)
{
	// If the main menu is active, parse the input for the main menu
	if (mainMenu)
	{
		switch (key)
		{
		// Menu button logic
		case GLUT_KEY_LEFT:

			if (!playSelected)
			{
				playSelected = true;
			}

			break;

		case GLUT_KEY_RIGHT:
			if (playSelected)
			{
				playSelected = false;
			}


			break;

		default:
			break;
		}

		if (play)
		{
			mainMenu = false;
			cameraX = 0.75f;
			cameraY = 0.0f;
			cameraZ = 4.0f;
			cameraYaw = 0.0f;
			cameraPitch = 0.0f;
		}
	}
	// If the main menu is not active, parse the input for the scene
	else
	{
		// Camera movement logic
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
}

// Function to parse the special keyboard input if the key is not pressed
void OpenGL::keyboardSpecialUp(int key, int x, int y)
{
	// If the Arrow keys are not pressed, revert the booleans
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

// Update the camera position called in the main update function
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
	// Update the camera position based on the camera variables
	glTranslatef(-cameraX, -cameraY, -cameraZ);
	glRotatef(-cameraPitch, 1.0f, 0.0f, 0.0f);
	glRotatef(-cameraYaw, 0.0f, 1.0f, 0.0f);
}

// Initialize the OpenGL functions and the window
void OpenGL::InitGL(int argc, char* argv[])
{
	// Initialize the GLUT functions
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);

	// Set the window size and create the window
	glutInitWindowSize(screenWidth, screenHeight);
	glutCreateWindow("GRAPHICS SIMULATION BY RYAN MOAKES");
	glutFullScreen();
	minimizeConsoleWindow();

	// Enable the depth buffer and the auto normal and normalize functions
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

	// 3D Transformation Pipeline
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, screenWidth, screenHeight);
	gluPerspective(fov, aspectRatio, zNear, zFar);
	glMatrixMode(GL_MODELVIEW);
}

// Create all of objects in the scene bar the glut objects
void OpenGL::InitObjects()
{
	/// Toggle to make sure the cubes are only instanced once.
	/// Pretty sure they are already, but it cant hurt.
	if (toggle == false)
	{
		// Load the cube mesh and texture
		auto* cubeMesh = MeshLoader::texLoad(("Objects/cube.txt"));

		auto* texture = new Texture2D();

		texture->Load(("Textures/stars.raw"), 512, 512);

		// Create the cube objects and add them to the linked list
		for (int i = 0; i < cubeNumber; i++)
		{
			lists->InsertNode(i);

			// Parse the random values for the cube objects
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

		// Load the pyramid mesh
		auto* pyramidMesh = MeshLoader::noTexLoad(("Objects/pyramid.txt"));

		// Create the pyramid objects and add them to the linked list
		for (int i = cubeNumber; i < objectCount; i++)
		{
			// Parse the random values for the pyramid objects
			objects[i] = new StaticObjects(pyramidMesh, ((rand() % 400) / 10.0f) - 20.0f,
			                               ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f);

			lists->InsertNode(i);
		}

		toggle = true;
	}
}

// Initialize the lighting data for the scene
void OpenGL::InitLighting()
{
	lightPosition = new Vector4();

	lightPosition->x = 0.0f;
	lightPosition->y = 0.0f;
	lightPosition->z = 0.0f;
	lightPosition->w = 1.0f;

	lightData = new Lighting();

	lightData->ambient.x = 0.2;
	lightData->ambient.y = 0.2;
	lightData->ambient.z = 0.2;
	lightData->ambient.w = 1.0;

	lightData->diffuse.x = 0.8;
	lightData->diffuse.y = 0.8;
	lightData->diffuse.z = 0.8;
	lightData->diffuse.w = 1.0;

	lightData->specular.x = 0.2;
	lightData->specular.y = 0.2;
	lightData->specular.z = 0.2;
	lightData->specular.w = 1.0;
}

// Function to draw the string text on the screen
void OpenGL::DrawString(const std::string& text, Color* color, float x, float y)
{
	// Text location variables
	const GLfloat textLocationX = x;
	const GLfloat textLocationY = y;

	// Pipeline setup for the text rendering, you need to do this or the text will not stay on the camera,
	// this is because the text will be rendered in 3D space
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glOrtho(-1, 1, -1, 1, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	// Set the color of the text according to the color variable it is called with
	glColor3f(color->r, color->g, color->b);

	glRasterPos2f(textLocationX, textLocationY);

	// Render each character in the string
	for (const char c : text)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
	}

	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}

// Parse in mouse rotation for the camera
void OpenGL::mouseRotation(int x, int y)
{
	// If the main menu is not active, parse the mouse input for the scene
	if (!mainMenu)
	{
		if (fullScreen)
		{
			if (!mouseToggle)
			{
				// Mouse rotation logic
				GLfloat prevMouseX = screenWidth / static_cast<GLfloat>(2);
				GLfloat prevMouseY = screenHeight / static_cast<GLfloat>(2);
				constexpr GLfloat sensitivity = 0.05f;

				const GLfloat deltaX = x - prevMouseX;
				const GLfloat deltaY = y - prevMouseY;

				cameraYaw -= deltaX * sensitivity;
				cameraPitch -= deltaY * sensitivity;

				// Clamp the camera pitch to prevent the camera from flipping
				if (cameraPitch > 89.0f)
				{
					cameraPitch = 89.0f;
				}
				if (cameraPitch < -89.0f)
				{
					cameraPitch = -89.0f;
				}

				// Hide the cursor and lock the mouse to the window
				glutSetCursor(GLUT_CURSOR_NONE);
				glutWarpPointer(screenWidth / 2, screenHeight / 2);
			}
		}
		else
		{
			// Free the cursor from its cage of torment
			glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
		}
	}
	else
	{
		// If the main menu is active, hide the cursor and lock the mouse to the window
		glutSetCursor(GLUT_CURSOR_NONE);
		glutWarpPointer(screenWidth / 2, screenHeight / 2);
	}
}

// Parse in mouse wheel input for the camera
void OpenGL::mouseWheel(int wheel, int direction, int x, int y)
{
	// Look... I don't like how this function looks either but it works
	if (!mainMenu)
	{
		if (fullScreen)
		{
			if (!mouseToggle)
			{
				if (wheel == 0)
				{
					// Zoom in and out logic
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
}

// Function to change the texture of the cubes
void OpenGL::textureChange()
{
	cubeMovement = true;

	// Boolean flip logic to change the texture of the cubes by re-initializing them
	if (!texChange)
	{
		auto* cubeMesh = MeshLoader::texLoad(("Objects/cube.txt"));

		auto* texture = new Texture2D();

		texture->Load(("Textures/Penguins.raw"), 512, 512);

		for (int i = 0; i < cubeNumber; i++)
		{
			objects[i] = new Cube(cubeMesh, texture, ((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f,
			                      -(rand() % 1000) / 10.0f);
		}

		texChange = true;
		materialEnabled = false;
	}
	else
	{
		auto* cubeMesh = MeshLoader::texLoad(("Objects/cube.txt"));

		auto* texture = new Texture2D();

		texture->Load(("Textures/stars.raw"), 512, 512);

		for (int i = 0; i < cubeNumber; i++)
		{
			objects[i] = new Cube(cubeMesh, texture, ((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f,
			                      -(rand() % 1000) / 10.0f);
		}

		texChange = false;
		materialEnabled = false;
	}
}

// Destructor for the OpenGL class, deletes all objects in the scene and the lighting data
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

	delete lightData;

	delete lightPosition;

	// Deletes the class itself
	GLUTCallbacks::Destroy();
}
