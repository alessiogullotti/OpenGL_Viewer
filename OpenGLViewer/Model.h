#ifndef MODEL_CLASS_H
#define MODEL_CLASS_H


#include <glad/glad.h> 

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <stb_image.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "Mesh.h"
#include "shaderClass.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>


using namespace std;
unsigned int TextureFromFile(const char* path, const string& directory, bool gamma);

class Model
{
	// model data 
	vector<Texture> textures_loaded;	// stores all the textures loaded so far, optimization to make sure textures aren't loaded more than once.
	vector<Mesh>    meshes;
	string directory;
	bool gammaCorrection;
public:
	// Loads in a model from a file and stores tha information in 'data', 'JSON', and 'file'
	Model(string const& path, bool gamma);

	void Draw(Shader& shader);

private:

	void loadModel(string const& path);

	void processNode(aiNode* node, const aiScene* scene);

	Mesh processMesh(aiMesh* mesh, const aiScene* scene);

	vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type, string typeName);
};
#endif