#include "StaticObjects.h"
#include <fstream>
#include <iostream>
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL/freeglut.h"


StaticObjects::StaticObjects(Mesh* mesh, float x, float y, float z) : SceneObject(mesh,nullptr,nullptr)
{
	position.x = x;
	position.y = y;
	position.z = z;
}



StaticObjects::~StaticObjects() = default;

void StaticObjects::DrawPyramids() const
{
	if (_mesh->Vertices != nullptr && _mesh->Colors != nullptr && _mesh->Indices != nullptr)
	{
		glPushMatrix();
		glTranslatef(position.x, position.y, position.z);

		glVertexPointer(3, GL_FLOAT, 0, _mesh->Vertices);
		glColorPointer(3, GL_FLOAT, 0, _mesh->Colors);
		glDrawElements(GL_TRIANGLES, 18, GL_UNSIGNED_SHORT, _mesh->Indices);


		glPopMatrix();
	}
}

void StaticObjects::Update()
{
}
