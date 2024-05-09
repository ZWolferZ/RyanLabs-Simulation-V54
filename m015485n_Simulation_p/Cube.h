#pragma once

#include "Structures.h"
#include "SceneObject.h"

class Cube : public SceneObject
{
public:
	Cube(Mesh* mesh,Texture2D* texture,float x, float y, float z);
	~Cube();

	virtual void DrawCubes() const;
	virtual void DrawWire() const;
	void Update();

	
	
	
private:
	
	static Vertex indexedVerticesLINE[];
	static GLushort indicesLINE[];

	GLfloat rotation;
	Vector3 position;
	GLfloat velocity = 0.5f;

};
