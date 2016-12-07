#pragma once

#include "PagShaderProgram.h"
#include "Pag3DGroup.h"
#include "Structs.h"

#include <map>
#include <vector>
#include "PagTexture.h"

class PagRenderer{
	Pag3DGroup objects;
	
	std::vector<PagShaderProgram*> shaders;
	std::map<std::string, PagTexture> textures;
	Structs::Fichero *ficheros;

	int s;

public:
	PagRenderer();
	void cargarEscena();
	void pintarEscena(glm::mat4 ViewMatrix , glm::mat4 ProjectionMatrix);
	~PagRenderer();
};

