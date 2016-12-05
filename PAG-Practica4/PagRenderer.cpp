#include "PagRenderer.h"

#include <iostream>
#include <string>

#include <GL/glew.h> //glew SIEMPRE va antes del glfw
#include <GLFW/glfw3.h>
#include "gtc\matrix_transform.hpp"

PagRenderer::PagRenderer() {}

int PagRenderer::renderer() {
	// Leemos los datos y txt del usuario
	int perfiles;
	std::cout << "Introduce el numero de perfiles" << std::endl;
	std::cin >> perfiles;

	Structs::Fichero *ficheros = new Structs::Fichero[perfiles];

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

	//Preparamos la ventana
	std::cout << "Starting application" << std::endl;

	if (!glfwInit()) {
		std::cout << "Failed to initialize GLFW" << std::endl;
		return -1;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_ANY_PROFILE);

	window = glfwCreateWindow(1024, 768, "PAG Practica 4 - TEXTURAS", NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to open GLFW window" << std::endl;
		glfwTerminate();
		return -2;
	}

	glfwMakeContextCurrent(window);

	glewExperimental = true;
	if (glewInit() != GLEW_OK) {
		std::cout << "Failed to initialize GLEW" << std::endl;
		glfwTerminate();
		return -3;
	}

	std::cout << glGetString(GL_RENDERER) << std::endl;
	std::cout << glGetString(GL_VENDOR) << std::endl;
	std::cout << glGetString(GL_VERSION) << std::endl;
	std::cout << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;

	//Inicializamos Camara
	double x, y;
	glfwGetCursorPos(window, &x, &y);
	camera = PagCamera(x, y);

	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glEnable(GL_PROGRAM_POINT_SIZE);
	glViewport(0, 0, 1024, 768);

	//Creamos las Geometrias y Topologias de los diferentes objetos
	objects.createObject();

	//Cargamos Texturas
	textures.push_back(PagTexture("pic.png", (GLuint)textures.size()));

	//glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);

	//Dibujamos los objetos
	do {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glm::mat4 ViewMatrix = camera.getViewMatrix();
		glm::mat4 ProjectionMatrix = camera.getProjectionMatrix();

		objects.drawSolid(ViewMatrix, ProjectionMatrix, textures[textures.size() - 1].getTexture());

		glfwSwapBuffers(window);
		glfwPollEvents();
	} while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);

	delete[] ficheros;
	return 0;
}

void PagRenderer::reDrawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::mat4 ViewMatrix = camera.getViewMatrix();
	glm::mat4 ProjectionMatrix = camera.getProjectionMatrix();

	objects.drawSolid(ViewMatrix, ProjectionMatrix, textures[textures.size() - 1].getTexture());

	glfwSwapBuffers(window);
	glfwPollEvents();
}


PagRenderer::~PagRenderer(){}
