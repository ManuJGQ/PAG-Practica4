#pragma once

#include <GL/glew.h> //glew SIEMPRE va antes del glfw
#include <GLFW/glfw3.h>
#include "gtc\matrix_transform.hpp"


class PagLight{
	char light; // P - Puntuales  D - Direccional  S - Spot

	glm::vec3 position;

	glm::vec3 direction;

	float Ia;
	float Id;
	float Is;

	glm::vec3 Ka;
	glm::vec3 Kd;
	glm::vec3 Ks;

	float shininess;

	float y;
	float s;
public:
	PagLight();
	PagLight(glm::vec3 _positionDirection, float _Ia, float _Id, float _Is,
		glm::vec3 _Ka, glm::vec3 _Kd, glm::vec3 _Ks, char _light, float _shininess);
	PagLight(glm::vec3 _position, glm::vec3 _direction, float _Ia, float _Id, float _Is,
		glm::vec3 _Ka, glm::vec3 _Kd, glm::vec3 _Ks, float _y, float _s, float _shininess);
	PagLight* getLight() { return this; }
	~PagLight();
};

