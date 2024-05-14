// ----------------------------- INCLUDES ----------------------------- //
#pragma once
#ifndef _CUBE_H
#define CUBE_H
#include "Structures.h"
#include "SceneObject.h"
// ----------------------------- INCLUDES ----------------------------- //

// ----------------------------- CUBE CLASS ----------------------------- //
class Cube : public SceneObject
{
public:
	/// <summary>
	/// Creates a cube by parsing the mesh data from a file, 
	/// parsing a texuture from a file and
	/// parsing the world postion of where it should spawn.
	/// </summary>
	Cube(Mesh* mesh, Texture2D* texture, float x, float y, float z);

	/// <summary>
	/// Cube Decontructor does nothing (Overrided)
	/// </summary>
	~Cube() override;

	/// <summary>
	/// Cube draw function that is called every frame to 
	/// render the postions of the cube from the mesh data stored.
	/// </summary>
	void DrawCubes() override;

	/// <summary>
	/// Draws a wire frame around the cube object.
	/// </summary>
	void DrawWire() const override;

	/// <summary>
	/// Update Function for each cube called every frame
	/// </summary>
	void Update() override;

	/// <summary>
	/// Sets the material of the cubes using material data
	/// </summary>
	void SetMaterial();

	// ----------------------------- PRIVATE VARIBLES ----------------------------- //
private:
	static Vertex indexedVerticesLINE[];
	static GLushort indicesLINE[];
	GLfloat rotation;
	Vector3 position;
	GLfloat velocity = 0.5f;


	Material* material;
	// ----------------------------- PRIVATE VARIBLES ----------------------------- //
};
#endif // _CUBE_H
// ----------------------------- CUBE CLASS ----------------------------- //
