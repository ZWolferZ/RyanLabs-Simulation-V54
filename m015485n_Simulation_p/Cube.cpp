#include "Cube.h"
#include <fstream>
#include <iostream>
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL/freeglut.h"


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


Cube::Cube(Mesh* mesh, Texture2D* texture, float x, float y, float z) : SceneObject(mesh, nullptr, texture)
{
	position.x = x;
	position.y = y;
	position.z = z;
	rotation = 0;
}


Cube::~Cube() = default;


void Cube::DrawCubes() 
{
	if (_mesh->Vertices != nullptr && _mesh->Colors != nullptr && _mesh->Indices != nullptr)
	{
		glBindTexture(GL_TEXTURE_2D, _texture->GetID());
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);


		glVertexPointer(3, GL_FLOAT, 0, _mesh->Vertices);
		glColorPointer(3, GL_FLOAT, 0, _mesh->Colors);
		glTexCoordPointer(2, GL_FLOAT, 0, _mesh->texCoords);

			SetMaterial();
		glMaterialfv(GL_FRONT, GL_AMBIENT, &(material->ambient.x));
		glMaterialfv(GL_FRONT, GL_DIFFUSE, &(material->diffuse.x));
		glMaterialfv(GL_FRONT, GL_SPECULAR, &(material->specular.x));
		glMaterialf(GL_FRONT, GL_SHININESS, material->shininess);


		glPushMatrix();
		glTranslatef(position.x, position.y, position.z);
		glRotatef(rotation, 1, 1, 1);
		glRotatef(rotation, 0, 0, 0);
		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, _mesh->Indices);


		glPopMatrix();

		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	}
}

void Cube::DrawWire() const
{
	glPushMatrix();
	glTranslatef(position.x, position.y, position.z);
	glRotatef(rotation, 1, 1, 1);
	glRotatef(rotation, 0, 0, 0);
	glBegin(GL_LINE_LOOP);
	{
		glColor3f(1, 1, 1);

		for (const unsigned short i : indicesLINE)
		{
			glVertex3fv(&indexedVerticesLINE[i].x);
		}
	}
	glEnd();
	glPopMatrix();
}


void Cube::Update()
{
	rotation += 0.5f;

	if (rotation > 360.0f)
	{
		rotation = 0.0f;
	}


	position.z += velocity;

	if (position.z >= 1)
	{
		position.z = -80;
	}
}

void Cube::SetMaterial()
{
	material = new Material();

	material->ambient.x = 0.8f; material->ambient.y = 0.05f; material->ambient.z = 0.05f;
	material->ambient.w = 1.0f;

	material->diffuse.x = 0.8f; material->diffuse.y = 0.05f; material->diffuse.z = 0.05f;
	material->diffuse.w = 1.0f;

	material->specular.x = 1.0f; material->specular.y = 1.0f; material->specular.z = 1.0f;
	material->specular.w = 1.0f;

	material->shininess = 100.0f;
}