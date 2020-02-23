#include <ExampleDll.hpp>

#if defined _WIN32
    //Windows平台使用OpenGL需要包含Windows.h
	#include <Windows.h>
	//消除窗口程序的控制台界面
	#pragma comment(linker,"/subsystem:\"windows\" /entry:\"mainCRTStartup\"")
#endif
#include <gl/GL.h>

//导入ExampleDll中的Window类
class _declspec(dllimport) ExDLL::Window;

int main()
{
	ExDLL::Window window{ 800, 600, "Hello World!" };
	while (!window.shouldClose())
	{
		window.pollEvents();
		//为简单起见，使用了古老的固定管线
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