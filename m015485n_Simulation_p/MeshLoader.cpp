// ----------------------------- INCLUDE ----------------------------- //
#include "MeshLoader.h"
// ----------------------------- INCLUDE ----------------------------- //

// ----------------------------- NAMESPACE ----------------------------- //
namespace MeshLoader
{
	//Switched from using namespace std to only what is needed
	using std::ifstream, std::cerr;

	// Function prototypes
	void LoadVertices(ifstream& inFile, Mesh& mesh);
	void LoadColours(ifstream& inFile, Mesh& mesh);
	void LoadTexCoords(ifstream& inFile, Mesh& mesh);
	void LoadIndices(ifstream& inFile, Mesh& mesh);

	// Load vertices from file
	void LoadVertices(ifstream& inFile, Mesh& mesh)
	{
		// Read the vertex count from the file
		inFile >> mesh.vertexCount;

		if (mesh.vertexCount > 0)
		{
			// Allocate memory for the vertices
			mesh.Vertices = new Vertex[mesh.vertexCount];

			// Read the vertex data from the file
			for (int i = 0; i < mesh.vertexCount; i++)
			{
				inFile >> mesh.Vertices[i].x;
				inFile >> mesh.Vertices[i].y;
				inFile >> mesh.Vertices[i].z;
			}
		}
	}

	// Load colours from file
	void LoadColours(ifstream& inFile, Mesh& mesh)
	{
		// Read the colour count from the file
		inFile >> mesh.colorCount;

		if (mesh.colorCount > 0)
		{
			// Allocate memory for the colours
			mesh.Colors = new Color[mesh.colorCount];

			// Read the colour data from the file
			for (int i = 0; i < mesh.colorCount; i++)
			{
				inFile >> mesh.Colors[i].r;
				inFile >> mesh.Colors[i].g;
				inFile >> mesh.Colors[i].b;
			}
		}
	}

	// Load texture coordinates from file
	void LoadTexCoords(ifstream& inFile, Mesh& mesh)
	{
		// Read the texture coordinate count from the file
		inFile >> mesh.texCoordCount;

		if (mesh.texCoordCount > 0)
		{
			// Allocate memory for the texture coordinates
			mesh.texCoords = new Texcoord[mesh.texCoordCount];

			// Read the texture coordinate data from the file
			for (int i = 0; i < mesh.texCoordCount; i++)
			{
				inFile >> mesh.texCoords[i].u;
				inFile >> mesh.texCoords[i].v;
			}
		}
	}

	// Load indices from file
	void LoadIndices(ifstream& inFile, Mesh& mesh)
	{
		// Read the index count from the file
		inFile >> mesh.indexCount;

		if (mesh.indexCount > 0)
		{
			// Allocate memory for the indices
			mesh.Indices = new GLushort[mesh.indexCount];

			// Read the index data from the file
			for (int i = 0; i < mesh.indexCount; i++)
			{
				inFile >> mesh.Indices[i];
			}
		}
	}

	// Load mesh function with texture function included
	Mesh* MeshLoader::texLoad(const char* path)
	{
		// Create a new mesh
		const auto mesh = new Mesh();

		// Open the file
		ifstream inFile;

		inFile.open(path);

		// Check if the file is open/good
		if (!inFile.good())
		{
			cerr << "Can't open mesh file " << path << '\n';
			return nullptr;
		}

		// Load the vertices, colours, texture coordinates and indices
		LoadVertices(inFile, *mesh);
		LoadColours(inFile, *mesh);
		LoadTexCoords(inFile, *mesh);
		LoadIndices(inFile, *mesh);

		// Close the file
		inFile.close();

		// Return the mesh
		return mesh;
	}

	// Load mesh function without texture function included
	Mesh* MeshLoader::noTexLoad(const char* path)
	{
		const auto mesh = new Mesh();

		ifstream inFile;

		inFile.open(path);

		if (!inFile.good())
		{
			cerr << "Can't open mesh file " << path << '\n';
			return nullptr;
		}

		LoadVertices(inFile, *mesh);
		LoadColours(inFile, *mesh);
		LoadIndices(inFile, *mesh);

		inFile.close();
		return mesh;
	}
}

// ----------------------------- NAMESPACE ----------------------------- //
