#pragma once

#include "Pag3DElement.h"
#include "PagShaderProgram.h"

class Pag3DObject : public Pag3DElement {
	glm::mat4 ModelMatrix;
	PagShaderProgram shader;
public:
	void drawPointsCloud(glm::mat4 ViewMatrix, glm::mat4 ProjectionMatrix) override = 0;
	void drawSolid(glm::mat4 ViewMatrix, glm::mat4 ProjectionMatrix, GLuint texture) override = 0;
	void createObject() override = 0;
	Pag3DObject();
	~Pag3DObject();
};

