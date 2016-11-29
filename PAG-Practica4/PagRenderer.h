#pragma once

#include "PagShaderProgram.h"
#include "PagCamera.h"
#include "Pag3DGroup.h"
#include "Structs.h"

#include <vector>

class PagRenderer{
	std::vector<PagShaderProgram> shaders;
public:
	PagRenderer();
	int renderer();
	~PagRenderer();
};

