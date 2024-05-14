// ----------------------------- INCLUDES ----------------------------- //
#include "StaticObjects.h"
#include <fstream>
#include <iostream>
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL/freeglut.h"
// ----------------------------- INCLUDES ----------------------------- //

// StaticObjects constructor that sets the mesh, position and rotation.
StaticObjects::StaticObjects(Mesh* mesh, float x, float y, float z) : SceneObject(mesh, nullptr, nullptr)
{
	position.x = x;
	position.y = y;
	position.z = z;
}

// StaticObjects deconstructor that does nothing.
StaticObjects::~StaticObjects() = default;

// Draw function for the static objects that draws the objects in world space.
void StaticObjects::DrawPyramids() const
{
	// Check if the mesh data is not null
	if (_mesh->Vertices != nullptr && _mesh->Colors != nullptr && _mesh->Indices != nullptr)
	{
		// Apply the position to the object
		glPushMatrix();
		glTranslatef(position.x, position.y, position.z);

		// Set the pointers for the vertices and colors
		glVertexPointer(3, GL_FLOAT, 0, _mesh->Vertices);
		glColorPointer(3, GL_FLOAT, 0, _mesh->Colors);

		// Draw the elements of the object
		glDrawElements(GL_TRIANGLES, _mesh->indexCount, GL_UNSIGNED_SHORT, _mesh->Indices);

		// Pop the matrix from the stack
		glPopMatrix();
	}
}

// Update function for the static objects, currently does nothing.
void StaticObjects::Update()
{
}
