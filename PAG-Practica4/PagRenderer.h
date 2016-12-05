#pragma once

#include "PagShaderProgram.h"
#include "PagCamera.h"
#include "Pag3DGroup.h"
#include "Structs.h"

#include <vector>
#include "PagTexture.h"

class PagRenderer{
	PagCamera camera;
	Pag3DGroup objects;
	
	std::vector<PagShaderProgram> shaders;
	std::vector<PagTexture> textures;

	GLFWwindow* window;
public:
	PagRenderer();
	int renderer();
	void reDrawScene();
	GLFWwindow* getWindow() { return window; }
	PagCamera* getCamera() { return &camera; }
	~PagRenderer();
};

