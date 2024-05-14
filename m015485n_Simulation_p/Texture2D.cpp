// ----------------------------- INCLUDES ----------------------------- //
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL/freeglut.h"
#include "GLUTCallbacks.h"
#include "OpenGL.h"
#include <iostream>
#include "Texture2D.h"
#include <fstream>
// ----------------------------- INCLUDES ----------------------------- //

// Constructor for the Texture2D class, sets the width and height to 0 and the ID to 0.
Texture2D::Texture2D()
{
	_width = 0;
	_height = 0;
	ID = 0;
}

// Deconstructor for the Texture2D class, deletes the textures.
Texture2D::~Texture2D()
{
	glDeleteTextures(1, &ID);
}

// Load function for the Texture2D class, loads a texture from a raw file type to a cube mesh by using a path and a width/height.
bool Texture2D::Load(const char* path, int width, int height)
{
	// Switched from Namespace std to only what is needed, which saves time and memory
	using std::ios;

	std::ifstream inFile;

	// Set the width and height of the texture
	_width = width;
	_height = height;

	// Open the file in binary mode
	inFile.open(path, ios::binary);

	// Check if the file is good
	if (!inFile.good())
	{
		std::cerr << "Can't open texture file: " << path << '\n';
		return false;
	}

	// Seek to the end of the file
	inFile.seekg(0, std::ios::end);

	// Get the file size
	const int fileSize = inFile.tellg();

	// Create a temporary texture data array
	const auto tempTextureData = new char [fileSize];

	// Seek back to the beginning of the file
	inFile.seekg(0, std::ios::beg);

	// Read the texture data from the file
	inFile.read(tempTextureData, fileSize);
	inFile.close();

	// Print out that the texture has been loaded
	std::cout << "Loaded: " << path << '\n';

	// Generate a texture ID and binds it to the texture
	glGenTextures(1, &ID);
	glBindTexture(GL_TEXTURE_2D, ID);

	// Set the texture parameters by building the mipmaps
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, GL_RGB, GL_UNSIGNED_BYTE, tempTextureData);

	// Delete the temporary texture data
	delete [] tempTextureData;
	return true;
}
