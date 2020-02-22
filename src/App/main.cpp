#include <ExampleDll.hpp>

#if defined _WIN32
    // OpenGL on Windows needs Windows.h
	#include <Windows.h>
	#pragma comment(linker,"/subsystem:\"windows\" /entry:\"mainCRTStartup\"")
#endif

#include <gl/GL.h>

class _declspec(dllimport) ExDLL::Window;

int main()
{
	ExDLL::Window window{ 800, 600, "Hello World!" };

	while (!window.shouldClose())
	{
		window.pollEvents();
		
		// Please note: this is old, OpenGL 1.1 code. It's here for simplicity.
		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_TRIANGLES);
			glVertex2f(-0.5f, -0.5f);
			glVertex2f(0.5f, -0.5f);
			glVertex2f(0, 0.5f);
		glEnd();

		window.swapBuffers();
	}

	return 0;
}