#include "OBJObjects.h"

#include <fstream>
#include <iostream>
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL/freeglut.h"

OBJObjects::OBJObjects(OBJMesh* mesh, float x, float y, float z) : SceneObject(nullptr, mesh, nullptr)
{
	position.x = x;
	position.y = y;
	position.z = z;
	rotation = 0;
}

OBJObjects::~OBJObjects() = default;

void OBJObjects::DrawOBJ() const
{
	if (_objMesh->Vertices != nullptr && _objMesh->texCoords != nullptr && _objMesh->Normals != nullptr && _objMesh->
		Indices != nullptr)
	{
		glBindTexture(GL_TEXTURE_2D, _texture->GetID());
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		

		glVertexPointer(3, GL_FLOAT, 0, _objMesh->Vertices);
		glTexCoordPointer(2, GL_FLOAT, 0, _objMesh->texCoords);
		glNormalPointer(GL_FLOAT, 0, _objMesh->Normals);

	

		glPushMatrix();
		glTranslatef(position.x, position.y, position.z);
		glRotatef(rotation, 1, 1, 1);
	//	glRotatef(rotation, 0, 0, 0); //SCALE
		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, _objMesh->Indices);


		glPopMatrix();

		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	}
}

void OBJObjects::Update()
{
}
