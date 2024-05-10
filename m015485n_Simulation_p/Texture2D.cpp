#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL/freeglut.h"
#include "GLUTCallbacks.h"
#include "OpenGL.h"
#include <iostream>

#include "Texture2D.h"

#include <fstream>


Texture2D::Texture2D()
{
	_width = 0;
	_height = 0;
	ID = 0;
}


Texture2D::~Texture2D()
{
	glDeleteTextures(1, &ID);
}

bool Texture2D::Load(const char* path, int width, int height)
{
	// Switched from Namespace std to only what is needed, which saves time and memory
	using std::ios;

	std::ifstream inFile;
	_width = width;
	_height = height;

	inFile.open(path, ios::binary);

	if (!inFile.good())
	{
		std::cerr << "Can't open texture file: " << path << '\n';
		return false;
	}

	inFile.seekg(0, std::ios::end);
	const int fileSize = inFile.tellg();
	const auto tempTextureData = new char [fileSize];
	inFile.seekg(0, std::ios::beg);
	inFile.read(tempTextureData, fileSize);
	inFile.close();

	std::cout << "Loaded: " << path << '\n';

	glGenTextures(1, &ID);
	glBindTexture(GL_TEXTURE_2D, ID);
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, GL_RGB, GL_UNSIGNED_BYTE, tempTextureData);
	delete [] tempTextureData;
	return true;
}
