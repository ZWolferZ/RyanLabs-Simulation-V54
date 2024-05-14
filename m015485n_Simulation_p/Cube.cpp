// ----------------------------- INCLUDES ----------------------------- //
#include "Cube.h"
#include <fstream>
#include <iostream>
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL/freeglut.h"
// ----------------------------- INCLUDES ----------------------------- //

// Line Arrays for the draw wire function
Vertex Cube::indexedVerticesLINE[] =
{
	{1, 1, 1}, {-1, 1, 1}, // v0-v1
	{-1, -1, 1}, {1, -1, 1}, // v2-v3
	{1, -1, -1}, {1, 1, -1}, // v4-v5
	{-1, 1, -1}, {-1, -1, -1} // v6-v7
};

GLushort Cube::indicesLINE[] =
{
	0, 1, 2, 2, 3, 0, // FRONT FACE
	0, 3, 4, 4, 5, 0, // RIGHT FACE
	0, 5, 6, 6, 1, 0, // TOP FACE
	1, 6, 7, 7, 2, 1, // LEFT FACE
	7, 4, 3, 3, 2, 7, // BOTTOM FACE
	4, 7, 6, 6, 5, 4 // BACK FACE
};

// Constructor for the Cube class
Cube::Cube(Mesh* mesh, Texture2D* texture, float x, float y, float z) : SceneObject(mesh, nullptr, texture)
{
	position.x = x;
	position.y = y;
	position.z = z;
	material = nullptr;
	rotation = 0;
}

// Deconstructor for the Cube class
Cube::~Cube() = default;

// Draw function for the cube class
void Cube::DrawCubes()
{
	// Check if the mesh data is not null
	if (_mesh->Vertices != nullptr && _mesh->Colors != nullptr && _mesh->Indices != nullptr)
	{
		// Bind the texture to the cube
		glBindTexture(GL_TEXTURE_2D, _texture->GetID());
		// Enable the texture coordinates
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);

		// Set the pointers for the vertices, colors and texture coordinates
		glVertexPointer(3, GL_FLOAT, 0, _mesh->Vertices);
		glColorPointer(3, GL_FLOAT, 0, _mesh->Colors);
		glTexCoordPointer(2, GL_FLOAT, 0, _mesh->texCoords);

		// Check if the material change is true
		// (Reading this back and it doesn't make any sense, but it works so I'm not going to fix it, just know that I am aware it makes no sense)
		if (materialChange == true)
		{
			SetMaterial();
			glMaterialfv(GL_FRONT, GL_AMBIENT, &(material->ambient.x));
			glMaterialfv(GL_FRONT, GL_DIFFUSE, &(material->diffuse.x));
			glMaterialfv(GL_FRONT, GL_SPECULAR, &(material->specular.x));
			glMaterialf(GL_FRONT, GL_SHININESS, material->shininess);
		}
		else
		{
			SetMaterial();
			glMaterialfv(GL_FRONT, GL_AMBIENT, &(material->ambient.x));
			glMaterialfv(GL_FRONT, GL_DIFFUSE, &(material->diffuse.x));
			glMaterialfv(GL_FRONT, GL_SPECULAR, &(material->specular.x));
			glMaterialf(GL_FRONT, GL_SHININESS, material->shininess);
		}

		// Push the matrix to the stack and apply world position and rotation
		glPushMatrix();
		glTranslatef(position.x, position.y, position.z);
		glRotatef(rotation, 1, 1, 1);
		glRotatef(rotation, 0, 0, 0);

		// Draw the elements of the cube
		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, _mesh->Indices);

		// Pop the matrix from the stack
		glPopMatrix();

		// Disable the texture coordinates
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	}
}

// Draw wire function for the cube class
void Cube::DrawWire() const
{
	// Push the matrix to the stack and apply world position and rotation
	glPushMatrix();
	glTranslatef(position.x, position.y, position.z);
	glRotatef(rotation, 1, 1, 1);
	glRotatef(rotation, 0, 0, 0);

	// Begin drawing the line loop
	glBegin(GL_LINE_LOOP);
	{
		// Set the color to white
		glColor3f(1, 1, 1);

		// Loop through the indices of the line array and draw the vertices
		for (const unsigned short i : indicesLINE)
		{
			glVertex3fv(&indexedVerticesLINE[i].x);
		}
	}
	// End the drawing
	glEnd();

	// Pop the matrix from the stack
	glPopMatrix();
}

// Update function for the cube class
void Cube::Update()
{
	// Increment the rotation of the cube and set it back to 0 if it goes over 360 degrees
	rotation += 0.5f;

	if (rotation > 360.0f)
	{
		rotation = 0.0f;
	}

	// Check if the cube is moving and increment the position of the cube
	if (isMoving)
	{
		position.z += velocity;

		// If the cube goes over the z axis of 1, set it back to -80
		if (position.z >= 1)
		{
			position.z = -80;
		}
	}
}

void Cube::SetMaterial()
{
	// Check if the material change is true
	if (materialChange)
	{
		// Set the material to new values
		material->ambient.x = 0.8f;
		material->ambient.y = 0.05f;
		material->ambient.z = 0.05f;
		material->ambient.w = 1.0f;

		material->diffuse.x = 0.8f;
		material->diffuse.y = 0.05f;
		material->diffuse.z = 0.05f;
		material->diffuse.w = 1.0f;

		material->specular.x = 1.0f;
		material->specular.y = 1.0f;
		material->specular.z = 1.0f;
		material->specular.w = 1.0f;

		material->shininess = 100.0f;
	}
	else
	{
		// Make a new material
		material = new Material();

		// Set the material to default values
		material->ambient.x = 1.0f;
		material->ambient.y = 1.00f;
		material->ambient.z = 1.00f;
		material->ambient.w = 1.0f;

		material->diffuse.x = 1.0f;
		material->diffuse.y = 1.0f;
		material->diffuse.z = 1.00f;
		material->diffuse.w = 1.0f;

		material->specular.x = 1.0f;
		material->specular.y = 1.0f;
		material->specular.z = 1.0f;
		material->specular.w = 1.0f;

		material->shininess = 100.0f;
	}
}
