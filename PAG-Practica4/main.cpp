#include "PagRenderer.h"

PagRenderer escena;

static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
	std::cout << "Entro: " << xpos << " - " << ypos << std::endl;
	escena.getCamera()->mover(xpos, ypos);
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
		escena.getCamera()->setRotates(true);
		escena.getCamera()->setTruck(false);
	}
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE) escena.getCamera()->setRotates(false);
	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS) {
		escena.getCamera()->setTruck(true);
		escena.getCamera()->setRotates(false);
	}
	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE) escena.getCamera()->setTruck(false);
}

void scroll(GLFWwindow* window, double x, double y) {
	escena.getCamera()->zoom(y * -1);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_O && action == GLFW_REPEAT) {
		escena.getCamera()->setOrbit(true);
		escena.getCamera()->movOrbit();
		
		escena.reDrawScene();

	}
	if (key == GLFW_KEY_O && action == GLFW_RELEASE) {
		escena.getCamera()->setOrbit(false);
		escena.getCamera()->resetCamera();
	}
}

int main(int argc, char** argv) {
	GLFWwindow* window = escena.getWindow();

	//Callbacks Camara & Teclado
	glfwSetCursorPosCallback(window, cursor_position_callback);
	glfwSetMouseButtonCallback(window, mouse_button_callback);
	glfwSetScrollCallback(window, scroll);
	glfwSetKeyCallback(window, key_callback);
	
	int r = escena.renderer();

	return r;
}
