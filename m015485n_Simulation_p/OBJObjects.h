// ----------------------------- INCLUDES ----------------------------- //
#pragma once
#ifndef _OBJOBJECTS_H
#define OBJOBJECTS_H
#include "Structures.h"
#include "SceneObject.h"
// ----------------------------- INCLUDES ----------------------------- //

// ----------------------------- OBJOBJECTS CLASS ----------------------------- //
class OBJObjects : public SceneObject
{
public:
	/// <summary>
	/// Creates a new OBJ object with the mesh and position.
	/// </summary>
	OBJObjects(OBJMesh* mesh, float x, float y, float z);

	/// <summary>
	///Decunstructor for the OBJ object, does nothing.
	/// </summary>
	~OBJObjects() override;

	/// <summary>
	///Draw function called every frame that loads the OBJ object and stores it in the appropriate structure.
	/// </summary>
	void DrawOBJ() const override;

	/// <summary>
	/// Update function called every frame that updates the position of the OBJ object.
	/// </summary>
	void Update() override;

private:
	GLfloat rotation;
	Vector3 position;
};
#endif // _OBJOBJECTS_H
// ----------------------------- OBJOBJECTS CLASS ----------------------------- //
