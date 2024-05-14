// ----------------------------- INCLUDES ----------------------------- //
#include "OBJObjects.h"
#include <fstream>
#include <iostream>
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL/freeglut.h"
// ----------------------------- INCLUDES ----------------------------- //

// OBJObjects constructor that initialises the position of the object.
OBJObjects::OBJObjects(OBJMesh* mesh, float x, float y, float z) : SceneObject(nullptr, mesh, nullptr)
{
	position.x = x;
	position.y = y;
	position.z = z;
	rotation = 0;
}

// OBJObjects deconstructor that does nothing.
OBJObjects::~OBJObjects() = default;

// Draw function for the OBJ object that loads the OBJ object and stores it in the appropriate structure.
void OBJObjects::DrawOBJ() const
{
	// Check if the mesh data is not null
	if (_objMesh->Vertices != nullptr && _objMesh->texCoords != nullptr && _objMesh->Normals != nullptr && _objMesh->
		Indices != nullptr)
	{
		// Bind the texture to the OBJ object
		glBindTexture(GL_TEXTURE_2D, _texture->GetID());

		// Enable the texture coordinates
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);

		// Set the pointers for the vertices, texture coordinates and normals
		glVertexPointer(3, GL_FLOAT, 0, _objMesh->Vertices);
		glTexCoordPointer(2, GL_FLOAT, 0, _objMesh->texCoords);
		glNormalPointer(GL_FLOAT, 0, _objMesh->Normals);

		// Push the matrix onto the stack and apply the position and rotation
		glPushMatrix();
		glTranslatef(position.x, position.y, position.z);
		glRotatef(rotation, 1, 1, 1);

		// Draw the elements of the OBJ object
		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, _objMesh->Indices);

		// Pop the matrix from the stack
		glPopMatrix();

		// Disable the texture coordinates
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	}
}

// Update function for the OBJ object, currently does nothing.
void OBJObjects::Update()
{
}
