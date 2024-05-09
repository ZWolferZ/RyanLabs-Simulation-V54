#include "MeshLoader.h"


using namespace std;

namespace MeshLoader
{
	void LoadVertices(ifstream& inFile, Mesh& mesh);
	void LoadColours(ifstream& inFile, Mesh& mesh);
	void LoadTexCoords(ifstream& inFile, Mesh& mesh);
	void LoadIndices(ifstream& inFile, Mesh& mesh);

	void LoadVertices(ifstream& inFile, Mesh& mesh)
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


	void LoadColours(ifstream& inFile, Mesh& mesh)
	{
		inFile >> mesh.colorCount;
		if (mesh.colorCount > 0)
		{
			mesh.Colors = new Color[mesh.colorCount];
			for (int i = 0; i < mesh.colorCount; i++)
			{
				inFile >> mesh.Colors[i].r;
				inFile >> mesh.Colors[i].g;
				inFile >> mesh.Colors[i].b;
			}
		}
	}


	void LoadTexCoords(ifstream& inFile, Mesh& mesh)
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


	void LoadIndices(ifstream& inFile, Mesh& mesh)
	{
		inFile >> mesh.indexCount;
		if (mesh.indexCount > 0)
		{
			mesh.Indices = new GLushort[mesh.indexCount];
			for (int i = 0; i < mesh.indexCount; i++)
			{
				inFile >> mesh.Indices[i];
			}
		}
	}


	Mesh* MeshLoader::texLoad(char* path)
	{
		auto mesh = new Mesh();

		ifstream inFile;

		inFile.open(path);

		if (!inFile.good())
		{
			cerr << "Can't open mesh file " << path << endl;
			return nullptr;
		}

		LoadVertices(inFile, *mesh);
		LoadColours(inFile, *mesh);
		LoadTexCoords(inFile, *mesh);
		LoadIndices(inFile, *mesh);

		inFile.close();
		return mesh;
	}

	Mesh* MeshLoader::noTexLoad(char* path)
	{
		auto mesh = new Mesh();

		ifstream inFile;

		inFile.open(path);

		if (!inFile.good())
		{
			cerr << "Can't open mesh file " << path << endl;
			return nullptr;
		}

		LoadVertices(inFile, *mesh);
		LoadColours(inFile, *mesh);
		LoadIndices(inFile, *mesh);

		inFile.close();
		return mesh;
	}
}
