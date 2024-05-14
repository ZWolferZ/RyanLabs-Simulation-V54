// ----------------------------- INCLUDES ----------------------------- //
#pragma once
#ifndef _STRUCTURES_H
#define STRUCTURES_H
#include <Windows.h>
#include <gl/GL.h>
#include "Texture2D.h"
// ----------------------------- INCLUDES ----------------------------- //

// ----------------------------- DATA STRUCTURES AND CONSTANTS ----------------------------- //
enum Constants
{
	refreshRate = 16,
	fogStart = 0,
	fogEnd = 50,
	lineWidth = 4,
	cubeNumber = 100,
	OBJNumber = 1,
	staticObjectNumber = 100,

	objectCount = staticObjectNumber + cubeNumber,
	objectLimit = objectCount,
};


struct Color
{
	GLfloat r, g, b;
};

struct Vertex
{
	GLfloat x, y, z;
};


struct Vector2
{
	GLfloat x, y;
};

struct Vector3
{
	GLfloat x, y, z;
};

struct Vector4
{
	GLfloat x, y, z, w;
};

struct Texcoord
{
	GLfloat u, v;
};

struct ListNode
{
	int data;

	ListNode* next;
};

struct Lighting
{
	Vector4 ambient;
	Vector4 diffuse;
	Vector4 specular;
};

struct Material
{
	Vector4 ambient;
	Vector4 diffuse;
	Vector4 specular;
	GLfloat shininess;
};

struct Mesh
{
	Vertex* Vertices;
	Color* Colors;
	GLushort* Indices;
	GLint vertexCount, colorCount, indexCount, texCoordCount;

	Texcoord* texCoords;
};

struct OBJMesh
{
	Vertex* Vertices;
	GLushort* Indices;
	Vector4* Normals;
	Texcoord* texCoords;

	GLint vertexCount, indexCount, normalCount, texCoordCount;
};

// ----------------------------- DATA STRUCTURES AND CONSTANTS ----------------------------- //

// ----------------------------- GLOBAL VARIABLES ----------------------------- //
// Screen Metrics
const GLint screenWidth = GetSystemMetrics(SM_CXSCREEN);
const GLint screenHeight = GetSystemMetrics(SM_CYSCREEN);

// Perspective Varibles
constexpr GLfloat fov = 90;
const GLfloat aspectRatio = static_cast<GLfloat>(screenWidth) / static_cast<GLfloat>(screenHeight);
constexpr GLint zNear = 1;
constexpr GLint zFar = 50;

// Fog Varibles
constexpr GLfloat fogColor[] = {0, 0, 0, 0};
constexpr GLfloat fogDensity = 0.4f;
#endif // !_STRUCTURES_H
// ----------------------------- GLOBAL VARIABLES ----------------------------- //
