#pragma once

#include<glew.h>
#include<glfw3.h>

#include<vector>
#include"Vertex.h"

#define colorCuerpo  glm::vec3(0.703125f, 0.09375f  , 0.11328125f)
#define colorCejas   glm::vec3(0.5546875, 0.125f    ,    0.15625f)
#define colorPiernas glm::vec3(0.984375f, 0.8515625f, 0.17578125f)
#define colorPico    glm::vec3(0.8828125f, 0.7421875f, 0.15234375f)
#define colorMono    glm::vec3(0.953125f, 0.4921875f,   0.640625f)

class Primitive {
private:
	std::vector<Vertex> vertices;
	std::vector<GLuint> indices;
	glm::vec3 Origen = glm::vec3(0.f);

public:
	Primitive() {}
	virtual ~Primitive() {}

	//Functions
	void set(const Vertex* vertices, const unsigned nrOfVertices, const GLuint* indices, const unsigned nrOfIndices) {
		for (size_t i = 0; i < nrOfVertices; i++) {
			this->vertices.push_back(vertices[i]);
		}

		for (size_t i = 0; i < nrOfIndices; i++) {
			this->indices.push_back(indices[i]);
		}
	}
	void giveOr(glm::vec3 orig) {
		this->Origen = orig;
	}
	glm::vec3 orig() {
		return this->Origen;
	}

	inline Vertex* getVertices() { return this->vertices.data(); }
	inline GLuint* getIndices() { return this->indices.data(); }
	inline const unsigned getNrOfVertices() { return this->vertices.size(); }
	inline const unsigned getNrOfIndices() { return this->indices.size(); }
};

// Cabeza

class Cabeza : public Primitive {
public:
	Cabeza() : Primitive() {
		Vertex vertices[] = {
			// Cara trasera
			//Position									//Color				//Texcoords					//Normals
			glm::vec3(0.1125f,  0.375f , -0.1f),		colorCuerpo,		glm::vec2(0.5f, 1.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(0.175f ,  0.3f   , -0.1f),		colorCuerpo,		glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(0.175f ,  0.1875f, -0.1f),		colorCuerpo,		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(0.1125f,  0.15f  , -0.1f),		colorCuerpo,		glm::vec2(0.5f, 1.f),		glm::vec3(0.f, 0.f, -1.f),
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
			glm::vec3(0.1f   ,  0.3625f , 0.1f),		colorCuerpo,		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),

			//Cejas											//Color				//Texcoords					//Normals
			glm::vec3(-0.1125f,  0.375f , 0.10001f),		colorCejas,		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-0.05f  ,  0.325f , 0.10001f),		colorCejas,		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3( 0.05f  ,  0.325f , 0.10001f),		colorCejas,		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3( 0.1125f,  0.375f , 0.10001f),		colorCejas,		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3( 0.15f  ,  0.3375f, 0.10001f),		colorCejas,		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3( 0.05f  ,  0.2875f, 0.10001f),		colorCejas,		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-0.05f  ,  0.2875f, 0.10001f),		colorCejas,		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-0.15f  ,  0.3375f, 0.10001f),		colorCejas,		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f)
		};
		unsigned nrOfVertices = sizeof(vertices) / sizeof(Vertex);

		GLuint indices[] = {
			0, 1, 2,
			0, 2, 3, 
			0, 3, 4,
			0, 4, 5,
			0, 5, 6,
			0, 6, 7,

			//Caras laterales
			7, 8, 15,
			7, 15, 0,
			0, 15, 14,
			0, 14, 1,
			1, 14, 13,
			1, 13, 2,
			2, 13, 12,
			2, 12, 3,
			3, 12, 11,
			3, 11, 4,
			4, 11, 10,
			4, 10, 5,
			5, 10, 9,
			5, 9, 6,
			6, 9, 8,
			6, 8, 7,

			// Cejas

			16, 23, 22,
			16, 22, 17,
			17, 22, 21,
			17, 21, 18,
			19, 18, 21,
			19, 21, 20
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
			glm::vec3(0.0875f,  0.15f   , 0.1f),		glm::vec3(1.f, 0.f, 0.f),		glm::vec2(0.7916f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(0.15f  ,  0.2f    , 0.1f),		glm::vec3(1.f, 0.f, 0.f),		glm::vec2(1.0f, 0.2352f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(0.15f  ,  0.3f    , 0.1f),		glm::vec3(1.f, 0.f, 0.f),		glm::vec2(1.0f, 0.7058f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(0.1f   ,  0.3625f , 0.1f),		glm::vec3(1.f, 0.f, 0.f),		glm::vec2(0.8333f, 1.f),		glm::vec3(0.f, 0.f, 1.f)
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

class Pico : public Primitive {
public:
	Pico() : Primitive() {
		Vertex vertices[] = {
			//Position									//Color							//Texcoords					//Normals
			glm::vec3(-0.025f, 0.2875f, 0.1f),			colorPiernas,		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(0.025f, 0.2875f, 0.1f),			colorPiernas,		glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(0.0375f, 0.25f, 0.1f),			colorPiernas,		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(0.025f, 0.2125f, 0.1f),			colorPiernas,		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-0.025f, 0.2125f, 0.1f),			colorPiernas,		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-0.0375f, .25f, 0.1f),			colorPiernas,		glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			//Punta										
			glm::vec3(0.f, 0.25f, 0.15f),				colorPico,			glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f)
		};
		unsigned nrOfVertices = sizeof(vertices) / sizeof(Vertex);

		GLuint indices[] = {
			0, 6, 1,
			1, 6, 2,
			2, 6, 3,
			3, 6, 4,
			4, 6, 5,
			5, 6, 0
		};
		unsigned nrOfIndices = sizeof(indices) / sizeof(GLuint);

		this->set(vertices, nrOfVertices, indices, nrOfIndices);
	}
};

class MonoR : public Primitive {
public:
	MonoR() : Primitive() {
		Vertex vertices[] = {
			//Position									//Color							//Texcoords					//Normals
			glm::vec3(0.05f,  0.45f, -0.1f),			colorMono,		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(0.15f,  0.45f ,  -0.1f),			colorMono,		glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(0.1625f, 0.35f, -0.1f),			colorMono,		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(0.0f   ,  0.35f, -0.1f),			colorMono,		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
															 
			glm::vec3(0.f,  0.35f, -0.1f),			    colorMono,		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(0.1625f, 0.35f, -0.15f),			colorMono,		glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(0.15f, 0.45f  , -0.15f),			colorMono,		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(0.05f, 0.45f, -0.15f),			colorMono,		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, -1.f),
		};
		unsigned nrOfVertices = sizeof(vertices) / sizeof(Vertex);

		GLuint indices[] = {
			0, 2, 1,
			0, 3, 2,

			6, 4, 7,
			6, 5, 4,

			1, 2, 5,
			1, 5, 6,

			7, 3, 0,
			7, 4, 3,

			7, 1, 6,
			7, 0, 1,

			3, 5, 2,
			3, 4, 5
		};
		unsigned nrOfIndices = sizeof(indices) / sizeof(GLuint);

		this->set(vertices, nrOfVertices, indices, nrOfIndices);
	}
};

class MonoL : public Primitive {
public:
	MonoL() : Primitive() {
		Vertex vertices[] = {
			//Position									//Color			//Texcoords					//Normals
			glm::vec3(-0.05f,  0.45f, -0.1f),			colorMono,		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-0.15f,  0.45f ,  -0.1f),			colorMono,		glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-0.1625f, 0.35f, -0.1f),			colorMono,		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-0.0f   ,  0.35f, -0.1f),			colorMono,		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),

			glm::vec3(-0.f,  0.35f, -0.1f),			colorMono,		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(-0.1625f, 0.35f, -0.15f),			colorMono,		glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(-0.15f, 0.45f  , -0.15f),			colorMono,		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(-0.05f, 0.45f, -0.15f),			colorMono,		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, -1.f),

		};
		unsigned nrOfVertices = sizeof(vertices) / sizeof(Vertex);

		GLuint indices[] = {
			1, 3, 0,
			1, 2, 3,

			7, 5, 6,
			7, 4, 5,

			0, 4, 7,
			0, 3, 4,

			6, 2, 1,
			6, 5, 2,

			6, 1, 0,
			6, 0, 7,

			2, 4, 3,
			2, 5, 4
		};
		unsigned nrOfIndices = sizeof(indices) / sizeof(GLuint);

		this->set(vertices, nrOfVertices, indices, nrOfIndices);
	}
};

// Cuerpo

class Cuerpo : public Primitive {
public:
	Cuerpo() : Primitive() {
		Vertex vertices[] = {
			// Cara trasera
			//Position									//Color				//Texcoords					//Normals
			glm::vec3(0.0875f ,  0.15f    , -0.1f),		colorCuerpo,		glm::vec2(0.5f, 1.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(0.125f  ,  0.125f   , -0.1f),		colorCuerpo,		glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(0.125f  , -0.125f   , -0.1f),		colorCuerpo,		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(0.1f    , -0.2125f  , -0.1f),		colorCuerpo,		glm::vec2(0.5f, 1.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(-0.1f   , -0.2125f  , -0.1f),		colorCuerpo,		glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(-0.125f , -0.125f   , -0.1f),		colorCuerpo,		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(-0.125f ,  0.125f   , -0.1f),		colorCuerpo,		glm::vec2(0.5f, 1.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(-0.0875f,  0.15f    , -0.1f),		colorCuerpo,		glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, -1.f),

			//Cara delantera							//Color				//Texcoords					//Normals
			glm::vec3(-0.0875f ,  0.15f   ,  0.1f),		colorCuerpo,		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-0.125f  ,  0.125f  ,  0.1f),		colorCuerpo,		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-0.125f  , -0.125f  ,  0.1f),		colorCuerpo,		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-0.1f    , -0.2125f ,  0.1f),		colorCuerpo,		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(0.1f   ,  -0.2125f ,  0.1f),		colorCuerpo,		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(0.125f ,  -0.125f  ,  0.1f),		colorCuerpo,		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(0.125f ,   0.125f  , 0.1f),		colorCuerpo,		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(0.0875f,   0.15f   , 0.1f),		colorCuerpo,		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f)
		};
		unsigned nrOfVertices = sizeof(vertices) / sizeof(Vertex);

		GLuint indices[] = {
			0, 1, 2,
			0, 2, 3,
			0, 3, 4,
			0, 4, 5,
			0, 5, 6,
			0, 6, 7,

			//Caras laterales
			7, 8, 15, 
			7, 15, 0,
			0, 15, 14,
			0, 14, 1,
			1, 14, 13,
			1, 13, 2,
			2, 13, 12,
			2, 12, 3,
			3, 12, 11,
			3, 11, 4,
			4, 11, 10,
			4, 10, 5,
			5, 10, 9,
			5, 9, 6,
			6, 9, 8, 
			6, 8, 7
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

class Torso : public Primitive {
public:
	Torso() : Primitive() {
		Vertex vertices[] =
		{
			//Cara delantera							//Color				//Texcoords						//Normals
			glm::vec3(-0.0875f , 0.15f  ,  0.1f),		colorCuerpo,		glm::vec2(0.15f, 1.f),			glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-0.125f  , 0.125f ,  0.1f),		colorCuerpo,		glm::vec2(0.f, 0.8928f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-0.125f  ,-0.125f ,  0.1f),		colorCuerpo,		glm::vec2(0.f, 0.2141f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-0.1f    ,-0.2125f,  0.1f),		colorCuerpo,		glm::vec2(0.1f, 0.f),			glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(0.1f    ,-0.2125f,  0.1f),		colorCuerpo,		glm::vec2(0.9f, 0.f),			glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(0.125f  ,-0.125f ,  0.1f),		colorCuerpo,		glm::vec2(1.f, 0.2142f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(0.125f  , 0.125f ,  0.1f),		colorCuerpo,		glm::vec2(1.f, 0.8928f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(0.0875f , 0.15f  ,  0.1f),		colorCuerpo,		glm::vec2(0.85f, 1.f),			glm::vec3(0.f, 0.f, 1.f)
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

// Brazos
class RUpArm : public Primitive {
public:
	RUpArm() : Primitive() {
		glm::vec3 Orig = glm::vec3(0.f);//glm::vec3(0.125f, 0.1125f, 0.5f);
		giveOr(Orig);
		Vertex vertices[] = {
			//Position										//Color				//Texcoords					//Normals
			glm::vec3(0.125f, 0.1125f, 0.1f) + Orig,		colorCuerpo,		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(0.175f, 0.1f , 0.1f) + Orig,			colorCuerpo,		glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(0.175f, 0.025f, 0.1f) + Orig,			colorCuerpo,		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(0.125f, 0.025f, 0.1f) + Orig,			colorCuerpo,		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
														
			glm::vec3(0.125f,  0.025f, -0.1f) + Orig,		colorCuerpo,		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(0.175f, 0.025f, -0.1f) + Orig,		colorCuerpo,		glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(0.175f, 0.1f  , -0.1f) + Orig,		colorCuerpo,		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(0.125f, 0.1125f, -0.1f) + Orig,		colorCuerpo,		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, -1.f)
		};
		unsigned nrOfVertices = sizeof(vertices) / sizeof(Vertex);

		GLuint indices[] = {
			0, 2, 1,
			0, 3, 2,

			6, 4, 7,
			6, 5, 4,

			1, 2, 5,
			1, 5, 6,

			7, 3, 0,
			7, 4, 3,

			7, 1, 6,
			7, 0, 1,

			3, 5, 2,
			3, 4, 5
		};
		unsigned nrOfIndices = sizeof(indices) / sizeof(GLuint);

		this->set(vertices, nrOfVertices, indices, nrOfIndices);
	}
};

class LUpArm : public Primitive {
public:
	LUpArm() : Primitive() {
		Vertex vertices[] = {
			//Position									//Color				//Texcoords					//Normals
			glm::vec3(-0.125f, 0.1125f, 0.1f),			colorCuerpo,		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-0.175f, 0.1f, 0.1f),			colorCuerpo,		glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-0.175f, 0.025f, 0.1f),			colorCuerpo,		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-0.125f, 0.025f, 0.1f),			colorCuerpo,		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),

			glm::vec3(-0.125f,  0.025f, -0.1f),			colorCuerpo,		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(-0.175f, 0.025f, -0.1f),			colorCuerpo,		glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(-0.175f, 0.1f  , -0.1f),			colorCuerpo,		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(-0.125f, 0.1125f, -0.1f),			colorCuerpo,		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, -1.f)

		};
		unsigned nrOfVertices = sizeof(vertices) / sizeof(Vertex);

		GLuint indices[] = {
			1, 3, 0,
			1, 2, 3,

			7, 5, 6,
			7, 4, 5,

			0, 4, 7,
			0, 3, 4,

			6, 2, 1,
			6, 5, 2,

			6, 1, 0,
			6, 0, 7,

			2, 4, 3,
			2, 5, 4
		};
		unsigned nrOfIndices = sizeof(indices) / sizeof(GLuint);

		this->set(vertices, nrOfVertices, indices, nrOfIndices);
	}
};

class RLowArm : public Primitive {
public:
	RLowArm() : Primitive() {
		Vertex vertices[] = {
			//Position									//Color							//Texcoords					//Normals
			glm::vec3(0.125f, 0.025f, 0.1f),			colorCuerpo,		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(0.175f, 0.025f, 0.1f),			colorCuerpo,		glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(0.175f, -0.1f, 0.1f),				colorCuerpo,		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(0.1375f, -0.1f, 0.1f),			colorCuerpo,		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
														
			glm::vec3(0.1375f, -0.1f, -0.1f),			colorCuerpo,		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(0.175f, -0.1f, -0.1f),			colorCuerpo,		glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(0.175f, 0.025f, -0.1f),			colorCuerpo,		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(0.125f, 0.025f, -0.1f),			colorCuerpo,		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, -1.f)
		};
		unsigned nrOfVertices = sizeof(vertices) / sizeof(Vertex);

		GLuint indices[] = {
			0, 2, 1,
			0, 3, 2,

			6, 4, 7,
			6, 5, 4,

			1, 2, 5,
			1, 5, 6,

			7, 3, 0,
			7, 4, 3,

			7, 1, 6,
			7, 0, 1,

			3, 5, 2,
			3, 4, 5
		};
		unsigned nrOfIndices = sizeof(indices) / sizeof(GLuint);

		this->set(vertices, nrOfVertices, indices, nrOfIndices);
	}
};

class LLowArm : public Primitive {
public:
	LLowArm() : Primitive() {
		Vertex vertices[] = {
			//Position									//Color				//Texcoords					//Normals
			glm::vec3(-0.125f, 0.025f, 0.1f),			colorCuerpo,		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-0.175f, 0.025f, 0.1f),			colorCuerpo,		glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-0.175f, -0.1f, 0.1f),			colorCuerpo,		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-0.1375f, -0.1f, 0.1f),			colorCuerpo,		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),

			glm::vec3(-0.1375f, -0.1f, -0.1f),			colorCuerpo,		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(-0.175f, -0.1f, -0.1f),			colorCuerpo,		glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(-0.175f, 0.025f, -0.1f),			colorCuerpo,		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(-0.125f, 0.025f, -0.1f),			colorCuerpo,		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, -1.f)
		};
		unsigned nrOfVertices = sizeof(vertices) / sizeof(Vertex);

		GLuint indices[] = {
			1, 3, 0,
			1, 2, 3,

			7, 5, 6,
			7, 4, 5,

			0, 4, 7,
			0, 3, 4,

			6, 2, 1,
			6, 5, 2,

			6, 1, 0,
			6, 0, 7,

			2, 4, 3,
			2, 5, 4
		};
		unsigned nrOfIndices = sizeof(indices) / sizeof(GLuint);

		this->set(vertices, nrOfVertices, indices, nrOfIndices);
	}
};

class RHand : public Primitive {
public:
	RHand() : Primitive() {
		Vertex vertices[] = {
			//Position								//Color							//Texcoords					//Normals
			glm::vec3(0.1375f, -0.1f, 0.1f),		glm::vec3(0.f, 0.f, 0.f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(0.175f, -0.1f, 0.1f),			glm::vec3(0.f, 0.f, 0.f),		glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(0.1625f, -0.15f, 0.1f),		glm::vec3(1.f, 1.f, 1.f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(0.1375f, -0.15f, 0.1f),		glm::vec3(1.f, 1.f, 1.f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),

			glm::vec3(0.1375f, -0.15f, -0.1f),		glm::vec3(1.f, 1.f, 1.f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(0.1625f, -0.15f, -0.1f),		glm::vec3(1.f, 1.f, 1.f),		glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(0.175f, -0.1f, -0.1f),		glm::vec3(0.f, 0.f, 0.f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(0.1375f, -0.1f, -0.1f),		glm::vec3(0.f, 0.f, 0.f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, -1.f)
		};
		unsigned nrOfVertices = sizeof(vertices) / sizeof(Vertex);

		GLuint indices[] = {
			0, 2, 1,
			0, 3, 2,

			6, 4, 7,
			6, 5, 4,

			1, 2, 5,
			1, 5, 6,

			7, 3, 0,
			7, 4, 3,

			7, 1, 6,
			7, 0, 1,

			3, 5, 2,
			3, 4, 5
		};
		unsigned nrOfIndices = sizeof(indices) / sizeof(GLuint);

		this->set(vertices, nrOfVertices, indices, nrOfIndices);
	}
};

class LHand : public Primitive {
public:
	LHand() : Primitive() {
		Vertex vertices[] = {
			//Position									//Color							//Texcoords					//Normals
			glm::vec3(-0.1375f, -0.1f, 0.1f),			glm::vec3(0.f, 0.f, 0.f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-0.175f, -0.1f, 0.1f),			glm::vec3(0.f, 0.f, 0.f),		glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-0.1625f, -0.15f, 0.1f),			glm::vec3(1.f, 1.f, 1.f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-0.1375f, -0.15f, 0.1f),			glm::vec3(1.f, 1.f, 1.f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),

			glm::vec3(-0.1375f, -0.15f, -0.1f),			glm::vec3(1.f, 1.f, 1.f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(-0.1625f, -0.15f, -0.1f),			glm::vec3(1.f, 1.f, 1.f),		glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(-0.175f, -0.1f, -0.1f),			glm::vec3(0.f, 0.f, 0.f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(-0.1375f, -0.1f, -0.1f),			glm::vec3(0.f, 0.f, 0.f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, -1.f)
		};
		unsigned nrOfVertices = sizeof(vertices) / sizeof(Vertex);

		GLuint indices[] = {
			1, 3, 0,
			1, 2, 3,

			7, 5, 6,
			7, 4, 5,

			0, 4, 7,
			0, 3, 4,

			6, 2, 1,
			6, 5, 2,

			6, 1, 0,
			6, 0, 7,

			2, 4, 3,
			2, 5, 4
		};
		unsigned nrOfIndices = sizeof(indices) / sizeof(GLuint);

		this->set(vertices, nrOfVertices, indices, nrOfIndices);
	}
};


// Piernas
class RUpLeg : public Primitive {
public:
	RUpLeg() : Primitive() {
		Vertex vertices[] = {
			//Position									//Color				//Texcoords					//Normals
			glm::vec3(0.025f, -0.2125f,   0.05f),		colorPiernas,		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(0.0625f, -0.2125f,  0.05f),		colorPiernas,		glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(0.0625f, -0.3125f,  0.05f),		colorPiernas,		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(0.025f, -0.3125f,   0.05f),		colorPiernas,		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
														
			glm::vec3(0.025f,  -0.3125f,  -0.05f),		colorPiernas,		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(0.0625f, -0.3125f,  -0.05f),		colorPiernas,		glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(0.0625f, -0.2125f , -0.05f),		colorPiernas,		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(0.025f,  -0.2125f,  -0.05f),		colorPiernas,		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, -1.f)
		};
		unsigned nrOfVertices = sizeof(vertices) / sizeof(Vertex);

		GLuint indices[] = {
			0, 2, 1,
			0, 3, 2,

			6, 4, 7,
			6, 5, 4,

			1, 2, 5,
			1, 5, 6,

			7, 3, 0,
			7, 4, 3,

			7, 1, 6,
			7, 0, 1,

			3, 5, 2,
			3, 4, 5
		};
		unsigned nrOfIndices = sizeof(indices) / sizeof(GLuint);

		this->set(vertices, nrOfVertices, indices, nrOfIndices);
	}
};

class LUpLeg : public Primitive {
public:
	LUpLeg() : Primitive() {
		Vertex vertices[] = {
			//Position									//Color				//Texcoords					//Normals
			glm::vec3(-0.025f, -0.2125f, 0.05f),		colorPiernas,		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-0.0625f, -0.2125f, 0.05f),		colorPiernas,		glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-0.0625f, -0.3125f,0.05f),		colorPiernas,		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-0.025f, -0.3125f, 0.05f),		colorPiernas,		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),

			glm::vec3(-0.025f,  -0.3125f,-0.05f),		colorPiernas,		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(-0.0625f, -0.3125f,-0.05f),		colorPiernas,		glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(-0.0625f, -0.2125f, -0.05f),		colorPiernas,		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(-0.025f,  -0.2125f,-0.05f),		colorPiernas,		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, -1.f)

		};
		unsigned nrOfVertices = sizeof(vertices) / sizeof(Vertex);

		GLuint indices[] = {
			1, 3, 0,
			1, 2, 3,

			7, 5, 6,
			7, 4, 5,

			0, 4, 7,
			0, 3, 4,

			6, 2, 1,
			6, 5, 2,

			6, 1, 0,
			6, 0, 7,

			2, 4, 3,
			2, 5, 4
		};
		unsigned nrOfIndices = sizeof(indices) / sizeof(GLuint);

		this->set(vertices, nrOfVertices, indices, nrOfIndices);
	}
};

class RLowLeg : public Primitive {
public:
	RLowLeg() : Primitive() {
		Vertex vertices[] = {
			//Position									//Color							//Texcoords					//Normals
			glm::vec3(0.025f, -0.3125f, 0.05f),			colorPiernas,		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(0.0625f, -0.3125f,0.05f),			colorPiernas,		glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(0.05f,  -0.4125f, 0.05f),			colorPiernas,		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(0.025f, -0.4125f, 0.05f),			colorPiernas,		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),

			glm::vec3(0.025f, -0.4125f, -0.05f),		colorPiernas,		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(0.05f, -0.4125f,  -0.05f),		colorPiernas,		glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(0.0625f, -0.3125f,-0.05f),		colorPiernas,		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(0.025f, -0.3125f, -0.05f),		colorPiernas,		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, -1.f)
		};
		unsigned nrOfVertices = sizeof(vertices) / sizeof(Vertex);

		GLuint indices[] = {
			0, 2, 1,
			0, 3, 2,

			6, 4, 7,
			6, 5, 4,

			1, 2, 5,
			1, 5, 6,

			7, 3, 0,
			7, 4, 3,

			7, 1, 6,
			7, 0, 1,

			3, 5, 2,
			3, 4, 5
		};
		unsigned nrOfIndices = sizeof(indices) / sizeof(GLuint);

		this->set(vertices, nrOfVertices, indices, nrOfIndices);
	}
};

class LLowLeg : public Primitive {
public:
	LLowLeg() : Primitive() {
		Vertex vertices[] = {
			//Position									//Color				//Texcoords					//Normals
			glm::vec3(-0.025f, -0.3125f, 0.05f),		colorPiernas,		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-0.0625f, -0.3125f,0.05f),		colorPiernas,		glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-0.05f,  -0.4125f, 0.05f),		colorPiernas,		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-0.025f, -0.4125f, 0.05f),		colorPiernas,		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),

			glm::vec3(-0.025f, -0.4125f, -0.05f),		colorPiernas,		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(-0.05f, -0.4125f,  -0.05f),		colorPiernas,		glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(-0.0625f, -0.3125f,-0.05f),		colorPiernas,		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(-0.025f, -0.3125f, -0.05f),		colorPiernas,		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, -1.f)
		};
		unsigned nrOfVertices = sizeof(vertices) / sizeof(Vertex);

		GLuint indices[] = {
			1, 3, 0,
			1, 2, 3,

			7, 5, 6,
			7, 4, 5,

			0, 4, 7,
			0, 3, 4,

			6, 2, 1,
			6, 5, 2,

			6, 1, 0,
			6, 0, 7,

			2, 4, 3,
			2, 5, 4
		};
		unsigned nrOfIndices = sizeof(indices) / sizeof(GLuint);

		this->set(vertices, nrOfVertices, indices, nrOfIndices);
	}
};

class RFoot : public Primitive {
public:
	RFoot() : Primitive() {
		Vertex vertices[] = {
			//Position									//Color							//Texcoords					//Normals
			glm::vec3(0.025f, -0.4f,    0.05f),			colorPiernas,					glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(0.1f, -0.425f,    0.05f),			glm::vec3(1.f, 1.f, 1.f),		glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(0.1f, -0.4375f,   0.05f),			glm::vec3(1.f, 1.f, 1.f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(0.025f, -0.4375f, 0.05f),			colorPiernas,					glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),

			glm::vec3(0.025f, -0.4375f, -0.05f),		colorPiernas,					glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(0.1f, -0.4375f,   -0.05f),		glm::vec3(1.f, 1.f, 1.f),		glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(0.1f, -0.425f,    -0.05f),		glm::vec3(1.f, 1.f, 1.f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(0.025f, -0.4f,    -0.05f),		colorPiernas,					glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, -1.f)
		};
		unsigned nrOfVertices = sizeof(vertices) / sizeof(Vertex);

		GLuint indices[] = {
			0, 2, 1,
			0, 3, 2,

			6, 4, 7,
			6, 5, 4,

			1, 2, 5,
			1, 5, 6,

			7, 3, 0,
			7, 4, 3,

			7, 1, 6,
			7, 0, 1,

			3, 5, 2,
			3, 4, 5
		};
		unsigned nrOfIndices = sizeof(indices) / sizeof(GLuint);

		this->set(vertices, nrOfVertices, indices, nrOfIndices);
	}
};

class LFoot : public Primitive {
public:
	LFoot() : Primitive() {
		Vertex vertices[] = {
			//Position									//Color							//Texcoords					//Normals
			glm::vec3(-0.025f, -0.4f,    0.05f),		colorPiernas,						glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-0.1f, -0.425f,    0.05f),		glm::vec3(1.f, 1.f, 1.f),			glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-0.1f, -0.4375f,   0.05f),		glm::vec3(1.f, 1.f, 1.f),			glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-0.025f, -0.4375f, 0.05f),		colorPiernas,						glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),

			glm::vec3(-0.025f, -0.4375f, -0.05f),		colorPiernas,						glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(-0.1f, -0.4375f,   -0.05f),		glm::vec3(1.f, 1.f, 1.f),			glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(-0.1f, -0.425f,    -0.05f),		glm::vec3(1.f, 1.f, 1.f),			glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(-0.025f, -0.4f,    -0.05f),		colorPiernas,						glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, -1.f)
		};
		unsigned nrOfVertices = sizeof(vertices) / sizeof(Vertex);

		GLuint indices[] = {
			1, 3, 0,
			1, 2, 3,

			7, 5, 6,
			7, 4, 5,

			0, 4, 7,
			0, 3, 4,

			6, 2, 1,
			6, 5, 2,

			6, 1, 0,
			6, 0, 7,

			2, 4, 3,
			2, 5, 4
		};
		unsigned nrOfIndices = sizeof(indices) / sizeof(GLuint);

		this->set(vertices, nrOfVertices, indices, nrOfIndices);
	}
};


