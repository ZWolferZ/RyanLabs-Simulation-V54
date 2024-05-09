#include "SceneObject.h"

SceneObject::SceneObject(Mesh* mesh,OBJMesh* objMesh ,Texture2D* texture)
{
	_mesh = mesh;
	_objMesh = objMesh;
	_texture = texture;
}
