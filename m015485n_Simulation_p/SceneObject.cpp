// ----------------------------- INCLUDE ----------------------------- //
#include "SceneObject.h"
// ----------------------------- INCLUDE ----------------------------- //

// Virtual constructor for SceneObject
SceneObject::SceneObject(Mesh* mesh, OBJMesh* objMesh, Texture2D* texture)
{
	// Set the mesh, objMesh and texture
	_mesh = mesh;
	_objMesh = objMesh;
	_texture = texture;
}
