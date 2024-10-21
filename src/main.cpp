#include "../glad/include/glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include <cstdlib>

void glfwErrorCallback(int error, const char *desc) {
	std::cerr << "GLFW Error (" << error << "):" << desc << std::endl;
}

int main(void) {
	if (!glfwInit()) {
		std::cout << "Failed to init GLFW\n";
		return EXIT_FAILURE;
	}

	glfwSetErrorCallback(glfwErrorCallback);

	GLFWwindow *window = glfwCreateWindow(800, 600, "OpenGL Template", nullptr, nullptr);

	if (!window) {
		std::cerr << "Failed to create window\n";
		glfwTerminate();
		return EXIT_FAILURE;
	}

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cerr << "Failed to init glad\n";
		return EXIT_FAILURE;
	}

	while(!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);

		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();

	return EXIT_SUCCESS;
}
