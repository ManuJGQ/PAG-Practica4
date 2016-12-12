#pragma once

#include "PagShaderProgram.h"
#include "Pag3DGroup.h"
#include "Structs.h"

#include <map>
#include <vector>
#include "PagTexture.h"
#include "PagLight.h"
#include <iterator>

class PagRenderer{
	Pag3DGroup objects;
	
	std::vector<PagShaderProgram*> shaders;
	std::map<std::string, PagTexture> textures;
	std::vector<PagLight> lights;
	Structs::Fichero *ficheros;

	std::string nombreShader;
	int s;

public:
	PagRenderer();
	void cargarEscena();
	void pintarEscena(glm::mat4 ViewMatrix , glm::mat4 ProjectionMatrix);
	PagShaderProgram* getShader() { return shaders[s]; }
	std::string getNombreShader() const { return nombreShader; }
	GLuint getTexture(std::string n) {
		std::map<std::string, PagTexture>::iterator it = textures.find(n);
		if(it != textures.end()) {
			return it->second.getTexture();
		}else return textures.find("default")->second.getTexture();
	}
	~PagRenderer();
};

