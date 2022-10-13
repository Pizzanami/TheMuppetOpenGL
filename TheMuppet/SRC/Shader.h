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

class Shader {
	private:
		GLuint id;
		
		std::string loadShaderSource(char* filename) {
			
			std::ifstream in_file;
			std::string temp = "";
			std::string src = "";

			in_file.open(filename);
			if (in_file.is_open()) {
				while (std::getline(in_file, temp)) {
					src += temp + "\n";
				}
			}
			else {
				std::cout << "ERROR:SHADER::COULD_NOT_OPEN_FILE: " << filename << "\n";
			}
			in_file.close();

			return src;
		}

		GLuint loadShader(GLenum type, char* filename) {
			GLuint success;
			char infoLog[512];
			GLuint shader = glCreateShader(GL_VERTEX_SHADER);
			const GLchar* src = this->loadShaderSource(filename).c_str();
			glShaderSource(shader, 1, &src, NULL);
			glCompileShader(shader);

			glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

			if (!success) {
				glGetShaderInfoLog(shader, 512, NULL, infoLog);
				std::cout << "ERROR::LOADSHADERS::COULD_NOT_COMPILE" << "\n";
				std::cout << infoLog << "\n";
			}
		}

		void linkProgram(GLuint vertexShader, GLuint geometryShader, GLuint fragmentShader) {

		}

	public:
		// Constructor y destructor
		Shader(char* vertexFile, char* fragmentFile, char* geometryFile = "") {

		}
		~Shader() {
			glDeleteProgram(this->id);
		}
		// Set Uniform funtions

};