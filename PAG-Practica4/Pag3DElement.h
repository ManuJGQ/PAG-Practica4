#pragma once

#include "gtc\matrix_transform.hpp"

class Pag3DElement{
	glm::mat4 ModelMatrix;
public:
	virtual void drawPointsCloud(glm::mat4 ViewMatrix, glm::mat4 ProjectionMatrix) = 0;
	virtual void drawSolid(glm::mat4 ViewMatrix, glm::mat4 ProjectionMatrix) = 0;
	virtual void createObject() = 0;
	Pag3DElement();
	virtual ~Pag3DElement();
};

