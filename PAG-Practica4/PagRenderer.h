#pragma once

#include "PagShaderProgram.h"
#include "Pag3DGroup.h"
#include "Structs.h"

#include <vector>
#include "PagTexture.h"

class PagRenderer{
	Pag3DGroup objects;
	
	std::vector<PagShaderProgram> shaders;
	std::vector<PagTexture> textures;
	Structs::Fichero *ficheros;

public:
	PagRenderer();
	void cargarEscena();
	void pintarEscena(glm::mat4 ViewMatrix , glm::mat4 ProjectionMatrix);
	~PagRenderer();
};

