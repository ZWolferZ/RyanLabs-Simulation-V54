#pragma once
#ifndef _STATICOBJECTS_H
#define STATICOBJECTS_H
#include "Structures.h"
#include "SceneObject.h"

class StaticObjects : public SceneObject
{
public:
	StaticObjects(Mesh* mesh, float x, float y, float z);
	~StaticObjects() override;


	void DrawPyramids() const override;
	void Update() override;

private:
	Vector3 position;
};

#endif // _STATICOBJECTS_H
