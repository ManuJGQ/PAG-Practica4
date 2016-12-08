#pragma once

#include <GL/glew.h> //glew SIEMPRE va antes del glfw
#include <GLFW/glfw3.h>
#include "gtc\matrix_transform.hpp"

class PagRenderer;

class Pag3DElement{
	glm::mat4 ModelMatrix;
public:
	//virtual void drawPointsCloud(glm::mat4 ViewMatrix, glm::mat4 ProjectionMatrix) = 0;
	virtual void draw(glm::mat4 ViewMatrix, glm::mat4 ProjectionMatrix, PagRenderer* renderer) = 0;
	virtual void createObject() = 0;
	Pag3DElement();
	virtual ~Pag3DElement();
};

