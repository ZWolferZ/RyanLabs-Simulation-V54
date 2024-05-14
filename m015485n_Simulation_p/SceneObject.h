// ----------------------------- INCLUDES ----------------------------- //
#pragma once
#ifndef _SCENEOBJECT_H
#define SCENEOBJECT_H
#include "Structures.h"
// ----------------------------- INCLUDES ----------------------------- //

// ----------------------------- SCENEOBJECT CLASS ----------------------------- //
class SceneObject
{
protected:
	Mesh* _mesh;
	OBJMesh* _objMesh;
	Texture2D* _texture;

public:
	/// <summary>
	/// Virtual constructor for objects in the scene.
	/// </summary>
	SceneObject(Mesh* mesh, OBJMesh* objMesh, Texture2D* texture);

	/// <summary>
	/// Virtual Deconstructor for scene objects.
	/// </summary>
	virtual ~SceneObject() = default;

	/// <summary>
	/// Virtual Update function for scene objects, called every frame.
	/// </summary>
	virtual void Update()
	{
	}

	/// <summary>
	/// Virtual draw cubes function to draw cubes, separated to get the both objects working.
	/// </summary>
	virtual void DrawCubes()
	{
	}

	/// <summary>
	/// Virtual draw obj function for scene objects. (NOT WORKING)
	/// </summary>
	virtual void DrawOBJ() const
	{
	}

	/// <summary>
	/// Virtual draw pyramid function to draw pyramids, separated to get the both objects working.
	/// </summary>
	virtual void DrawPyramids() const
	{
	}

	/// <summary>
	/// Virtual draw wire function to draw wires mesh around cubes.
	/// </summary>
	virtual void DrawWire() const
	{
	}


	bool materialChange = false;

	bool isMoving = true;
};

#endif // _SCENEOBJECT_H
// ----------------------------- SCENEOBJECT CLASS ----------------------------- //
