#pragma once

#include "PagShaderProgram.h"
#include "PagCamera.h"
#include "Pag3DGroup.h"
#include "Structs.h"

#include <vector>
#include "PagTexture.h"

class PagRenderer{
	std::vector<PagShaderProgram> shaders;
	std::vector<PagTexture> textures;
public:
	PagRenderer();
	int renderer();
	~PagRenderer();
};

