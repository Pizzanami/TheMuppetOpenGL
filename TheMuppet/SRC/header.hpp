#pragma once
#include <glew.h>
#include <glfw3.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
// Math library use for transformations
#include <glm.hpp>
#pragma once
#include <vec2.hpp>
#include <vec3.hpp> 
#include <vec4.hpp> 
#include <mat4x4.hpp> 
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>


struct Vertex {
	glm::vec3 position;
	glm::vec3 color;
	glm::vec2 texcoord;
};

// Shaders
// bool loadShaders(GLuint& program);
