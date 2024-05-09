#pragma once
#include "Structures.h"
#include "SceneObject.h"

class StaticObjects : public SceneObject
{
public:
	StaticObjects(Mesh* mesh, float x, float y, float z);
	~StaticObjects();


	virtual void DrawPyramids() const;
	void Update();

private:
	Vector3 position;
};

