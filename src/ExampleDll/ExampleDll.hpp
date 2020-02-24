#ifndef EXAMPLE_DLL_HPP
#define EXAMPLE_DLL_HPP 1

#include <string>
#include <memory>

struct GLFWwindow;

namespace ExDLL
{	
	//µº≥ˆWindow¿‡
	class _declspec(dllexport) Window
	{
	public:
		Window(int width, int  height, const std::string& title);
		~Window();

		bool shouldClose() const noexcept;

		void pollEvents() const noexcept;

		void swapBuffers() const noexcept;

		std::pair<int, int> getWindowSize() const noexcept;
		
	private:
		GLFWwindow* wnd;
	};
}

#endif