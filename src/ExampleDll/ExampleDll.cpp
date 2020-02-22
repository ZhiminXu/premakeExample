#include "ExampleDll.hpp"

#include <GLFW/glfw3.h>

namespace ExDLL
{
	Window::Window(int width, int height, const std::string& title)
	{
		glfwInit();
		wnd = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(wnd);
	}
	
	Window::~Window()
	{
		glfwDestroyWindow(wnd);
		glfwTerminate();
	}

	bool Window::shouldClose() const noexcept
	{
		return glfwWindowShouldClose(wnd) != 0;
	}

	void Window::pollEvents() const noexcept
	{
		glfwPollEvents();
	}

	void Window::swapBuffers() const noexcept
	{
		glfwSwapBuffers(wnd);
	}

	std::pair<int, int> Window::getWindowSize() const noexcept
	{
		std::pair<int, int> sz{};
		glfwGetWindowSize(wnd, &sz.first, &sz.second);
		return sz;
	}
}