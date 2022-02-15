
#define GLEW_STATIC
#include <glew.h>
#include <glfw3.h>
#include <iostream>


class Window
{
public:
	Window();
	Window(int windowWidth, int windowHeigth);
	int initialize();

	int getBufferWidth() { return bufferWidth; }
	int getBufferHeight() { return bufferHeight; }
	bool getWindowClose() { return glfwWindowShouldClose(mainWindow); }
	void swapBuffers() { return glfwSwapBuffers(mainWindow); }


	~Window();


private:
	GLFWwindow* mainWindow{};
	int width, height;
	int bufferWidth{}, bufferHeight{};
};



