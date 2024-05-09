#pragma once
#ifndef _SCENEOBJECT_H
#define SCENEOBJECT_H
#include "Structures.h"


class SceneObject
{
protected:
	Mesh* _mesh;
	OBJMesh* _objMesh;
	Texture2D* _texture;

public:
	SceneObject(Mesh* mesh, OBJMesh* objMesh, Texture2D* texture);
	virtual ~SceneObject() = default;

	virtual void Update()
	{
	}

	virtual void DrawCubes() const
	{
	}

	virtual void DrawOBJ() const
	{
	}

	virtual void DrawPyramids() const
	{
	}

	virtual void DrawWire() const
	{
	}
};

#endif // _SCENEOBJECT_H
