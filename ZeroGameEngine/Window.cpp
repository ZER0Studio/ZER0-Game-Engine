#include "Window.h"
#include "Logger.h"


namespace ZEROGE {
	void Window::setColorWindow() {
		glClearColor(0.03f, 0.03f, 0.09f, 0.12f);
	}

	void windowResize(GLFWwindow* window, int width, int height);
	
	bool Window::Init() {
		if (!glfwInit())
		{
			ZEROGE::Logger::Error("Faliled Initialize Window, GLFW problem ");
			return false;
		}
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		mWindow = glfwCreateWindow(mWidth, mHeight, mTitle, nullptr, nullptr);
		setColorWindow();
		if (!mWindow)
		{
			glfwTerminate();
			ZEROGE::Logger::Error("Failed create GFLW window");
			return false;
		}
		glfwSetWindowUserPointer(mWindow, this);
		glfwMakeContextCurrent(mWindow);
		glfwSetWindowSizeCallback(mWindow, windowResize);

	}

	Window::Window(int width, int height, const char* title) {
		mTitle = title;
		mWidth = width;
		mHeight = height;
		if (!Init()) glfwTerminate();
	}
	Window::~Window(){ 
		if (mWindow)
		{
			glfwDestroyWindow(mWindow);
		}
		glfwTerminate();
	}

	
	void Window::clear() const {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
	void Window::update(){
		glfwPollEvents();
		glfwSwapBuffers(mWindow);
	}

	bool Window::closed() const {
		return glfwWindowShouldClose(mWindow) == 1;
	}
	void windowResize(GLFWwindow* window, int width, int height){
		glViewport(0, 0, width, height);
	}
}