#pragma once

#include <GL/glew.h> //glew SIEMPRE va antes del glfw
#include <GLFW/glfw3.h>
#include "gtc\matrix_transform.hpp"


class PagLight{
	char light; // P - Puntuales  D - Direccional  S - Spot
	glm::vec3 position;
	glm::vec3 direction;
	glm::vec3 Ia;
	glm::vec3 Id;
	glm::vec3 Is;
	glm::vec3 Ka;
	glm::vec3 Kd;
	glm::vec3 Ks;
	float y;
	float s;
public:
	PagLight();
	PagLight(glm::vec3 _positionDirection, glm::vec3 _Ia, glm::vec3 _Id, glm::vec3 _Is,
		glm::vec3 _Ka, glm::vec3 _Kd, glm::vec3 _Ks, char _light);
	PagLight(glm::vec3 _position, glm::vec3 _direction, glm::vec3 _Ia, glm::vec3 _Id, glm::vec3 _Is,
		glm::vec3 _Ka, glm::vec3 _Kd, glm::vec3 _Ks, float _y, float _s);
	PagLight* getLight() { return this; }
	~PagLight();
};

