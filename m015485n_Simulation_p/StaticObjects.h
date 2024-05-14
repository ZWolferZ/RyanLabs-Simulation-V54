// ----------------------------- INCLUDES ----------------------------- //
#pragma once
#ifndef _STATICOBJECTS_H
#define STATICOBJECTS_H
#include "Structures.h"
#include "SceneObject.h"
// ----------------------------- INCLUDES ----------------------------- //

// ----------------------------- STATICOBJECTS CLASS ----------------------------- //
class StaticObjects : public SceneObject
{
public:
	/// <summary>
	/// Initiates static objects by taking in the appropriate mesh data and world space coordinates.
	/// </summary>
	StaticObjects(Mesh* mesh, float x, float y, float z);

	/// <summary>
	/// Deconstructor does nothing, objects are deleted elsewhere.
	/// </summary>
	~StaticObjects() override;

	/// <summary>
	/// Draw function that takes in mesh data and draws the objects in world space.
	/// </summary>
	void DrawPyramids() const override;

	/// <summary>
	/// Updated function that is called every frame.
	/// </summary>
	void Update() override;

private:
	Vector3 position;
};

#endif // _STATICOBJECTS_H
// ----------------------------- STATICOBJECTS CLASS ----------------------------- //
