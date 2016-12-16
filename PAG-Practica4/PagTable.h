#pragma once
#include "PagRevolutionObject.h"
#include "Pag3DObject.h"

class PagTable : public Pag3DObject {
	glm::mat4 ModelMatrix;
	PagRevolutionObject table;
public:
	PagTable();
	void createObject() override;
	void draw(glm::mat4 ViewMatrix, glm::mat4 ProjectionMatrix, PagRenderer* renderer, PagLight* light) override;
	PagTable(const PagTable &orig);
	void operator = (const PagTable &orig);
	~PagTable();
};

