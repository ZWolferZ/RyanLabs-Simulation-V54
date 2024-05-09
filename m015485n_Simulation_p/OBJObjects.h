#pragma once
#ifndef _OBJOBJECTS_H
#define OBJOBJECTS_H
#include "Structures.h"
#include "SceneObject.h"

class OBJObjects : public SceneObject
{
public:
	OBJObjects(OBJMesh* mesh, float x, float y, float z);
	~OBJObjects() override;

	void DrawOBJ() const override;
	void Update() override;

private:
	GLfloat rotation;
	Vector3 position;
};
#endif // _OBJOBJECTS_H
