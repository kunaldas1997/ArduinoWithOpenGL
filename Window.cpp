#include "CustomFunctions/Window.h"

Window::Window()
{
	
	height = 800;
	width = 600;
	bufferHeight = getBufferHeight();
	bufferWidth = getBufferWidth();

}

Window::Window(int windowWidth, int windowHeight)
{

	width = windowWidth;
	height = windowHeight;
	bufferHeight;
	bufferWidth;



	

}

void error_callback(int error, const char* desc)
{
	std::cout << "Error: %s\n" << desc << std::endl;
}

int Window::initialize()
{
	if (!glfwInit())
	{
		std::cout << "GLFW Failed!" << std::endl;
		glfwTerminate();
		return 1;
	}
	/* Set OpenGL version to 4.6 */
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

	//	remove backward compatibility 
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);


	mainWindow = glfwCreateWindow(width, height, "Test Window", NULL, NULL);
	
	if (!mainWindow)
	{
		std::cout << "Failed!" << std::endl;
		glfwTerminate();
		return 1;
	}

	//	buffer dimension

	glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);


	//	 let glew know that this window is main
	glfwMakeContextCurrent(mainWindow);

	//	Allow Modern Ext
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK)
	{
		glfwSetErrorCallback(error_callback);
		std::cout << "GLEW FAiled" << std::endl;
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
		return 1;
	}

	//	enable depth
	glEnable(GL_DEPTH_TEST);

	//	set viewport size
	glViewport(0, 0, bufferWidth, bufferHeight);
	return 0;
}

Window::~Window()
{
	glfwDestroyWindow(mainWindow);
	glfwTerminate();
}