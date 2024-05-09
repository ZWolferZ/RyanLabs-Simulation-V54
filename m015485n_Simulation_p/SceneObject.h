#pragma once
#include "Structures.h"


class SceneObject
{
protected:
	Mesh* _mesh;
	OBJMesh* _objMesh;
	Texture2D* _texture;

public:
	SceneObject(Mesh* mesh, OBJMesh* objMesh,Texture2D* texture);
	virtual ~SceneObject() {}

	virtual void Update() {}
	virtual void DrawCubes() const {}
	virtual void DrawOBJ() const {}
	virtual void DrawPyramids() const {}
	virtual void DrawWire() const {}

	 

};

