#ifndef MESH_CLASS_H
#define MESH_CLASS_H

#include <glad/glad.h> // holds all OpenGL type declarations

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "shaderClass.h"

#include <string>
#include <vector>
using namespace std;
#define MAX_BONE_INFLUENCE 4


struct Texture {
	unsigned int id;
	string type;
	string path;
};

struct Vertex {
	// position
	glm::vec3 Position;
	// normal
	glm::vec3 Normal;
	// texCoords
	glm::vec2 TexCoords;
	// tangent
	glm::vec3 Tangent;
	// bitangent
	glm::vec3 Bitangent;
	//bone indexes which will influence this vertex
	int m_BoneIDs[MAX_BONE_INFLUENCE];
	//weights from each bone
	float m_Weights[MAX_BONE_INFLUENCE];
};
class Mesh
{
public:
	std::vector <Vertex> vertices;
	std::vector <unsigned int> indices;
	std::vector <Texture> textures;
	// Store VAO in public so it can be used in the Draw function
	unsigned int VAO;

	// Initializes the mesh
	Mesh(std::vector <Vertex>& vertices, std::vector <unsigned>& indices, std::vector <Texture>& textures);

	// Draws the mesh
	void Draw
	(
		Shader& shader
	);

private:
	// render data 
	unsigned int VBO, EBO;
	void setupMesh();
};
#endif