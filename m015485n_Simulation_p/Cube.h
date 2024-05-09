#pragma once
#ifndef _CUBE_H
#define CUBE_H
#include "Structures.h"
#include "SceneObject.h"

class Cube final : public SceneObject
{
public:
	Cube(Mesh* mesh, Texture2D* texture, float x, float y, float z);
	~Cube() override;
	void DrawCubes() const override;
	void DrawWire() const override;
	void Update() override;

private:
	static Vertex indexedVerticesLINE[];
	static GLushort indicesLINE[];
	GLfloat rotation;
	Vector3 position;
	GLfloat velocity = 0.5f;
};
#endif // _CUBE_H
