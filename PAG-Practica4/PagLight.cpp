#include "PagLight.h"

PagLight::PagLight(){}

PagLight::PagLight(glm::vec3 _positionDirection, float _Ia, float _Id, float _Is,
	glm::vec3 _Ka, glm::vec3 _Kd, glm::vec3 _Ks, char _light, float _shininess){

	if(_light == 'P') {

		light = 'P';

		position = _positionDirection;

		Ia = _Ia;
		Id = _Id;
		Is = _Is;
		Ka = _Ka;
		Kd = _Kd;
		Ks = _Ks;

	}else if(_light == 'D') {
		
		light = 'D';

		direction = _positionDirection;

		Ia = _Ia;
		Id = _Id;
		Is = _Is;
		Ka = _Ka;
		Kd = _Kd;
		Ks = _Ks;

		shininess = _shininess;

	}
}


PagLight::PagLight(glm::vec3 _position, glm::vec3 _direction, float _Ia, float _Id, float _Is,
	glm::vec3 _Ka, glm::vec3 _Kd, glm::vec3 _Ks, float _y, float _s, float _shininess){

	light = 'S';

	position = _position;
	direction = _direction;

	Ia = _Ia;
	Id = _Id;
	Is = _Is;
	Ka = _Ka;
	Kd = _Kd;
	Ks = _Ks;

	y = _y;
	s = _s;

	shininess = _shininess;

}


PagLight::~PagLight(){}
