#include <ExampleDll.hpp>

#if defined _WIN32
    //Windowsƽ̨ʹ��OpenGL��Ҫ����Windows.h
	#include <Windows.h>
	//�������ڳ���Ŀ���̨����
	#pragma comment(linker,"/subsystem:\"windows\" /entry:\"mainCRTStartup\"")
#endif
#include <gl/GL.h>

//����ExampleDll�е�Window��
class _declspec(dllimport) ExDLL::Window;

int main()
{
	ExDLL::Window window{ 800, 600, "Hello World!" };
	while (!window.shouldClose())
	{
		window.pollEvents();
		//Ϊ�������ʹ���˹��ϵĹ̶�����
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