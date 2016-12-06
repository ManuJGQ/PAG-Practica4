#include "PagRenderer.h"

#include <iostream>
#include <string>

#include <GL/glew.h> //glew SIEMPRE va antes del glfw
#include <GLFW/glfw3.h>
#include "gtc\matrix_transform.hpp"

PagRenderer::PagRenderer() {
	
	// Leemos los datos y txt del usuario
	int perfiles;
	std::cout << "Introduce el numero de perfiles" << std::endl;
	std::cin >> perfiles;

	ficheros = new Structs::Fichero[perfiles];

	int j = perfiles;
	while (j != 0) {
		char* docdir = getenv("userprofile");
		std::string path = docdir;
		std::string archivo;
		path += "/Desktop/";
		std::cout << "Escriba el nombre del fichero " << perfiles - j + 1 << " (con .txt)" << std::endl;
		std::cin >> archivo;
		path += archivo;

		Structs::Fichero _fichero;
		_fichero.nombreAlumno = archivo;
		_fichero.archivoIN = path;
		ficheros[perfiles - j] = _fichero;
		j--;
	}

	int slices;
	std::cout << "Escriba el numero de slices" << std::endl;
	std::cin >> slices;

	for (int i = 0; i < perfiles; i++) {
		ficheros[i].numSlices = slices;
	}

	//Creamos la jerarquia de objetos
	objects = Pag3DGroup(ficheros, perfiles);
}

void PagRenderer::cargarEscena() {
	//Creamos las Geometrias y Topologias de los diferentes objetos
	objects.createObject();

	//Cargamos Texturas
	textures.push_back(PagTexture("Textures/pic.png", (GLuint)textures.size()));
}

void PagRenderer::pintarEscena(glm::mat4 ViewMatrix, glm::mat4 ProjectionMatrix) {
	objects.drawSolid(ViewMatrix, ProjectionMatrix, textures[textures.size() - 1].getTexture());
}

PagRenderer::~PagRenderer(){
	delete[] ficheros;
}
