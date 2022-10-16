#pragma once

#include<glew.h>
#include<glfw3.h>

#include<vector>
#include"Vertex.h"

#define colorCuerpo glm::vec3(0.703125f, 0.09375f, 0.11328125f)

class Primitive{
private:
	std::vector<Vertex> vertices;
	std::vector<GLuint> indices;

public:
	Primitive() {}
	virtual ~Primitive() {}

	//Functions
	void set(const Vertex* vertices, const unsigned nrOfVertices, const GLuint* indices, const unsigned nrOfIndices) {
		for (size_t i = 0; i < nrOfVertices; i++){
			this->vertices.push_back(vertices[i]);
		}

		for (size_t i = 0; i < nrOfIndices; i++){
			this->indices.push_back(indices[i]);
		}
	}

	inline Vertex* getVertices() { return this->vertices.data(); }
	inline GLuint* getIndices() { return this->indices.data(); }
	inline const unsigned getNrOfVertices() { return this->vertices.size(); }
	inline const unsigned getNrOfIndices() { return this->indices.size(); }
};

class Triangle : public Primitive{
public:
	Triangle() : Primitive(){
		Vertex vertices[] =
		{
			//Position								//Color							//Texcoords					//Normals
			glm::vec3(0.f, 0.5f, 0.f),				glm::vec3(1.f, 0.f, 0.f),		glm::vec2(0.5f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-0.5f, -0.5f, 0.f),			glm::vec3(0.f, 1.f, 0.f),		glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(0.5f, -0.5f, 0.f),			glm::vec3(0.f, 0.f, 1.f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
		};
		unsigned nrOfVertices = sizeof(vertices) / sizeof(Vertex);

		GLuint indices[] = {
			0, 1, 2	//Triangle 1
		};
		unsigned nrOfIndices = sizeof(indices) / sizeof(GLuint);

		this->set(vertices, nrOfVertices, indices, nrOfIndices);
	}
};

class Cabeza : public Primitive {
public:
	Cabeza() : Primitive() {
		Vertex vertices[] =
		{
			// Cara trasera
			//Position									//Color				//Texcoords					//Normals
			glm::vec3( 0.1125f,  0.375f , -0.1f),		colorCuerpo,		glm::vec2(0.5f, 1.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3( 0.175f ,  0.3f   , -0.1f),		colorCuerpo,		glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3( 0.175f ,  0.1875f, -0.1f),		colorCuerpo,		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3( 0.1125f,  0.15f  , -0.1f),		colorCuerpo,		glm::vec2(0.5f, 1.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(-0.1125f,  0.15f  , -0.1f),		colorCuerpo,		glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(-0.175f ,  0.1875f, -0.1f),		colorCuerpo,		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(-0.175f ,  0.3f   , -0.1f),		colorCuerpo,		glm::vec2(0.5f, 1.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(-0.1125f,  0.375f , -0.1f),		colorCuerpo,		glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, -1.f),
			
			//Cara delantera							//Color				//Texcoords					//Normals
			glm::vec3(-0.1f   ,  0.3625f , 0.1f),		colorCuerpo,		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-0.15f  ,  0.3f    , 0.1f),		colorCuerpo,		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-0.15f  ,  0.2f    , 0.1f),		colorCuerpo,		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-0.0875f,  0.15f   , 0.1f),		colorCuerpo,		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(0.0875f,  0.15f   , 0.1f),		colorCuerpo,		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(0.15f  ,  0.2f    , 0.1f),		colorCuerpo,		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(0.15f  ,  0.3f    , 0.1f),		colorCuerpo,		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(0.1f   ,  0.3625f , 0.1f),		colorCuerpo,		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f)
		};
		unsigned nrOfVertices = sizeof(vertices) / sizeof(Vertex);

		GLuint indices[] = {
			0, 1, 2,
			0, 2, 3,
			0, 3, 4,
			0, 4, 5,
			0, 5, 6,
			0, 6, 7,
			6, 9, 8,
			6, 8, 7,
			6, 10, 9,
			6, 5, 10,
			10, 5, 9,
			10, 9, 11,
			9, 3, 12,
			9, 12, 11,
			3, 2, 13,
			3, 13, 12,
			2, 14, 13,
			2, 1, 14,
			0, 15, 14,
			0, 14, 1,
			8, 15, 7,
			7, 15, 0
		};
		unsigned nrOfIndices = sizeof(indices) / sizeof(GLuint);

		this->set(vertices, nrOfVertices, indices, nrOfIndices);
	}
};
/*
0.5f, 0.5f,
0.5f, 0.0f,
0.0f, 0.25f,
0.0f, 0.75f,
0.5f, 0.0f,
1.0f, 0.75f,
1.0f, 0.25f
*/

class Cara : public Primitive {
public:
	Cara() : Primitive() {
		Vertex vertices[] =
		{
			//Position									//Color							//Texcoords						//Normals
			glm::vec3(-0.1f   ,  0.3625f , 0.1f),		glm::vec3(1.f, 0.f, 0.f),		glm::vec2(0.1666f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-0.15f  ,  0.3f    , 0.1f),		glm::vec3(1.f, 0.f, 0.f),		glm::vec2(0.f, 0.70580f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-0.15f  ,  0.2f    , 0.1f),		glm::vec3(1.f, 0.f, 0.f),		glm::vec2(0.f, 0.2352f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-0.0875f,  0.15f   , 0.1f),		glm::vec3(1.f, 0.f, 0.f),		glm::vec2(0.2083f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3( 0.0875f,  0.15f   , 0.1f),		glm::vec3(1.f, 0.f, 0.f),		glm::vec2(0.7916f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3( 0.15f  ,  0.2f    , 0.1f),		glm::vec3(1.f, 0.f, 0.f),		glm::vec2(1.0f, 0.2352f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3( 0.15f  ,  0.3f    , 0.1f),		glm::vec3(1.f, 0.f, 0.f),		glm::vec2(1.0f, 0.7058f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3( 0.1f   ,  0.3625f , 0.1f),		glm::vec3(1.f, 0.f, 0.f),		glm::vec2(0.8333f, 1.f),		glm::vec3(0.f, 0.f, 1.f)
		};
		unsigned nrOfVertices = sizeof(vertices) / sizeof(Vertex);

		GLuint indices[] = {
			0, 1, 2,
			0, 2, 3,
			0, 3, 4,
			0, 4, 5,
			0, 5, 6,
			0, 6, 7
		};
		unsigned nrOfIndices = sizeof(indices) / sizeof(GLuint);

		this->set(vertices, nrOfVertices, indices, nrOfIndices);
	}
};

class Quad : public Primitive {
public:
	Quad() : Primitive(){
		Vertex vertices[] = {
			//Position								//Color							//Texcoords					//Normals
			glm::vec3(-0.5f, 0.5f, 0.f),			glm::vec3(1.f, 0.f, 0.f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-0.5f, -0.5f, 0.f),			glm::vec3(0.f, 1.f, 0.f),		glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(0.5f, -0.5f, 0.f),			glm::vec3(0.f, 0.f, 1.f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(0.5f, 0.5f, 0.f),				glm::vec3(1.f, 1.f, 0.f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f)
		};
		unsigned nrOfVertices = sizeof(vertices) / sizeof(Vertex);

		GLuint indices[] = {
			0, 1, 2,	//Triangle 1
			0, 2, 3		//Triangle 2
		};
		unsigned nrOfIndices = sizeof(indices) / sizeof(GLuint);

		this->set(vertices, nrOfVertices, indices, nrOfIndices);
	}
};

class Pyramid : public Primitive {
public:
	Pyramid() : Primitive() {
		Vertex vertices[] = {
			//Position								//Color							//Texcoords					//Normals
			//Triangle front
			glm::vec3(0.f, 0.5f, 0.f),				glm::vec3(1.f, 0.f, 0.f),		glm::vec2(0.5f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-0.5f, -0.5f, 0.5f),			glm::vec3(0.f, 1.f, 0.f),		glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(0.5f, -0.5f, 0.5f),			glm::vec3(0.f, 0.f, 1.f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),

			//Triangle left
			glm::vec3(0.f, 0.5f, 0.f),				glm::vec3(1.f, 1.f, 0.f),		glm::vec2(0.5f, 1.f),		glm::vec3(-1.f, 0.f, 0.f),
			glm::vec3(-0.5f, -0.5f, -0.5f),			glm::vec3(0.f, 0.f, 1.f),		glm::vec2(0.f, 0.f),		glm::vec3(-1.f, 0.f, 0.f),
			glm::vec3(-0.5f, -0.5f, 0.5f),			glm::vec3(0.f, 0.f, 1.f),		glm::vec2(1.f, 0.f),		glm::vec3(-1.f, 0.f, 0.f),

			//Triangle back
			glm::vec3(0.f, 0.5f, 0.f),				glm::vec3(1.f, 1.f, 0.f),		glm::vec2(0.5f, 1.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(0.5f, -0.5f, -0.5f),			glm::vec3(0.f, 0.f, 1.f),		glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(-0.5f, -0.5f, -0.5f),			glm::vec3(0.f, 0.f, 1.f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, -1.f),

			//Triangles right
			glm::vec3(0.f, 0.5f, 0.f),				glm::vec3(1.f, 1.f, 0.f),		glm::vec2(0.5f, 1.f),		glm::vec3(1.f, 0.f, 0.f),
			glm::vec3(0.5f, -0.5f, 0.5f),			glm::vec3(0.f, 0.f, 1.f),		glm::vec2(0.f, 0.f),		glm::vec3(1.f, 0.f, 0.f),
			glm::vec3(0.5f, -0.5f, -0.5f),			glm::vec3(0.f, 0.f, 1.f),		glm::vec2(1.f, 0.f),		glm::vec3(1.f, 0.f, 0.f),
		};
		unsigned nrOfVertices = sizeof(vertices) / sizeof(Vertex);

		this->set(vertices, nrOfVertices, nullptr, 0);
	}
};

class Cube : public Primitive {
public:
	Cube() : Primitive() {
		Vertex vertices[] = {
			//Position								//Color							//Texcoords					//Normals
			glm::vec3(-0.5f, 0.5f, 0.5f),			glm::vec3(1.f, 0.f, 0.f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-0.5f, -0.5f, 0.5f),			glm::vec3(0.f, 1.f, 0.f),		glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(0.5f, -0.5f, 0.5f),			glm::vec3(0.f, 0.f, 1.f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(0.5f, 0.5f, 0.5f),			glm::vec3(1.f, 1.f, 0.f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),

			glm::vec3(0.5f, 0.5f, -0.5f),			glm::vec3(1.f, 0.f, 0.f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(0.5f, -0.5f, -0.5f),			glm::vec3(0.f, 1.f, 0.f),		glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(-0.5f, -0.5f, -0.5f),			glm::vec3(0.f, 0.f, 1.f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(-0.5f, 0.5f, -0.5f),			glm::vec3(1.f, 1.f, 0.f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, -1.f)
		};
		unsigned nrOfVertices = sizeof(vertices) / sizeof(Vertex);

		GLuint indices[] = {
			0, 1, 2,
			0, 2, 3,

			7, 6, 1,
			7, 1, 0,

			4, 5, 6,
			4, 6, 7,

			3, 2, 5,
			3, 5, 4
		};
		unsigned nrOfIndices = sizeof(indices) / sizeof(GLuint);

		this->set(vertices, nrOfVertices, indices, nrOfIndices);
	}
};

class PiramideHex : public Primitive {
	public:
		PiramideHex() : Primitive() {
			Vertex vertices[] = {
				//Position								//Color							//Texcoords					//Normals
				glm::vec3(-0.8f, 0.5f, 0.5f),			glm::vec3(1.f, 0.f, 0.f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
				glm::vec3(-0.5f, -0.5f, 0.5f),			glm::vec3(0.f, 1.f, 0.f),		glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
				glm::vec3(0.5f, -0.5f, 0.5f),			glm::vec3(0.f, 0.f, 1.f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
				glm::vec3(0.5f, 0.5f, 0.5f),			glm::vec3(1.f, 1.f, 0.f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),

				glm::vec3(0.5f, 0.5f, -0.5f),			glm::vec3(1.f, 0.f, 0.f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, -1.f),
				glm::vec3(0.5f, -0.5f, -0.5f),			glm::vec3(0.f, 1.f, 0.f),		glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, -1.f),
				glm::vec3(-0.5f, -0.5f, -0.5f),			glm::vec3(0.f, 0.f, 1.f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, -1.f),
				glm::vec3(-0.5f, 0.5f, -0.5f),			glm::vec3(1.f, 1.f, 0.f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, -1.f)
			};
			unsigned nrOfVertices = sizeof(vertices) / sizeof(Vertex);

			GLuint indices[] = {
				0, 1, 2,
				0, 2, 3,

				7, 6, 1,
				7, 1, 0,

				4, 5, 6,
				4, 6, 7,

				3, 2, 5,
				3, 5, 4
			};
			unsigned nrOfIndices = sizeof(indices) / sizeof(GLuint);

			this->set(vertices, nrOfVertices, indices, nrOfIndices);
		}
};