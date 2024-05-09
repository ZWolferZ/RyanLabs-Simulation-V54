#include "OBJLoader.h"

void LoadVertices(std::ifstream& inFile, OBJMesh& mesh);

void LoadTexCoords(std::ifstream& inFile, OBJMesh& mesh);

void LoadNormals(std::ifstream& inFile, OBJMesh& mesh);

void LoadIndices(std::ifstream& inFile, OBJMesh& mesh);


void LoadVertices(std::ifstream& inFile, OBJMesh& mesh)
{
	inFile >> mesh.vertexCount;

	if (mesh.vertexCount > 0)
	{
		mesh.Vertices = new Vertex[mesh.vertexCount];

		for (int i = 0; i < mesh.vertexCount; i++)
		{
			inFile >> mesh.Vertices[i].x;
			inFile >> mesh.Vertices[i].y;
			inFile >> mesh.Vertices[i].z;
		}
	}
}

void LoadIndices(std::ifstream& inFile, OBJMesh& mesh)
{
	inFile >> mesh.indexCount;
	if (mesh.indexCount > 1)
	{
		mesh.Indices = new GLushort[mesh.indexCount];
		for (int i = 0; i < mesh.indexCount; i++)
		{
			inFile >> mesh.Indices[i];
		}
	}
}

void LoadTexCoords(std::ifstream& inFile, OBJMesh& mesh)
{
	inFile >> mesh.texCoordCount;
	if (mesh.texCoordCount > 0)
	{
		mesh.texCoords = new Texcoord[mesh.texCoordCount];
		for (int i = 0; i < mesh.texCoordCount; i++)
		{
			inFile >> mesh.texCoords[i].u;
			inFile >> mesh.texCoords[i].v;
		}
	}
}



void LoadNormals(std::ifstream& inFile, OBJMesh& mesh)
{
	inFile >> mesh.normalCount;
	if (mesh.normalCount > 0)
	{
		mesh.Normals = new Vector4[mesh.normalCount];
		for (int i = 0; i < mesh.normalCount; i++)
		{
			inFile >> mesh.Normals[i].x;
			inFile >> mesh.Normals[i].y;
			inFile >> mesh.Normals[i].z;
			mesh.Normals[i].w = 0.0f;
		}
	}
}

OBJMesh* OBJLoader::LoadOBJ(const char* path)
{
	auto mesh = new OBJMesh();

	std::ifstream inFile;

		inFile.open(path);

		if (!inFile.good())
		{
			std::cerr << "Can't open OBJ file " << path << std::endl;
			delete mesh;
			return nullptr;
		}

	    LoadVertices(inFile, *mesh);
		LoadTexCoords(inFile, *mesh);
		LoadNormals(inFile, *mesh);
		LoadIndices(inFile, *mesh);

	return mesh;
}
