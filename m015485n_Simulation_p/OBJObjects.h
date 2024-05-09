#pragma once
#include "Structures.h"
#include "SceneObject.h"

class OBJObjects : public SceneObject
{
public:
	OBJObjects(OBJMesh* mesh,float x, float y, float z);
	~OBJObjects();

	virtual void DrawOBJ() const;
	void Update();


	
private:


	GLfloat rotation;
	Vector3 position;


};
