#pragma once
#include <glew.h>
#include <vector>
class Mesh
{
public:
	Mesh();

	void CreateMesh(std::vector<float>vector);
	void RenderMesh();
	void ClearMesh();
	~Mesh();
private:
	unsigned int VAO, VBO, IBO, EBO;
	int indexCount;
};


