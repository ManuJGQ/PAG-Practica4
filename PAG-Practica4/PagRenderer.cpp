#include "PagRenderer.h"

#include <iostream>
#include <string>

#include <algorithm>
#include "dirent.h"

#include <GL/glew.h> //glew SIEMPRE va antes del glfw
#include <GLFW/glfw3.h>
#include "gtc\matrix_transform.hpp"

bool has_suffix(const std::string &str, const std::string &suffix){
	return str.size() >= suffix.size() &&
		str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
}

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

		std::string _nTextura;
		std::cout << "Escriba la textura para " << archivo << " (sin .png)" << std::endl;
		std::cin >> _nTextura;

		Structs::Fichero _fichero;
		_fichero.nombreAlumno = archivo;
		_fichero.archivoIN = path;
		_fichero.nTextura = _nTextura;
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
	//Creamos las Geometrias y Topologias de los diferentes objetos que componen la escena
	objects.createObject();

	//Cargamos todas las Texturas del directorio Textures
	DIR *dir = opendir("Textures/");

	dirent *entry;
	while ((entry = readdir(dir)) != nullptr){
		if (has_suffix(entry->d_name, ".png")){
		
			std::string name = std::string(entry->d_name);
			int ind = name.find_last_of(".");
			std::string nombreSinExt = name.substr(0, ind);
			std::string path = "Textures/" + name;

			textures.insert_or_assign(nombreSinExt, PagTexture(path, GLuint(textures.size())));
		}
	}
	closedir(dir);

	//Cargamos todos los shaders
	DIR *dirS = opendir("Textures/..");

	dirent *entryS;
	while ((entryS = readdir(dirS)) != nullptr) {
		if (has_suffix(entryS->d_name, ".frag")) {

			//std::cout << entryS->d_name << std::endl;

			entryS = readdir(dirS);

			if (has_suffix(entryS->d_name, ".vert")) {

				//std::cout << entryS->d_name << std::endl;

				std::string name = std::string(entryS->d_name);
				int ind = name.find_last_of(".");
				name = name.substr(0, ind);

				PagShaderProgram *shader = new PagShaderProgram();

				shader->createShaderProgram(name.c_str());

				shaders.push_back(shader);

				std::cout << "[" << shaders.size() - 1 << "] - " << name << std::endl;

			}

		}
	}
	closedir(dirS);

	std::cout << "Escoja el shader a usar: ";
	std::cin >> s;
}

void PagRenderer::pintarEscena(glm::mat4 ViewMatrix, glm::mat4 ProjectionMatrix) {
	//objects.drawSolid(ViewMatrix, ProjectionMatrix, textures[textures.size() - 1].getTexture());
}

PagRenderer::~PagRenderer(){
	delete[] ficheros;
}
