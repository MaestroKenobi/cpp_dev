#include "stl.h"
#include "cpp_dev/devlibs.h"
#include "glew/glew.h"
#include "freeglut/GL/freeglut.h"
#include "GLFW/glfw3.h"
#ifdef _WIN32
#include "Windows.h"
#endif

void render(void);

int height = GetSystemMetrics(SM_CXSCREEN);
int width = GetSystemMetrics(SM_CYSCREEN);

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(height, width);
	glutCreateWindow("Example");	
	glutDisplayFunc(render);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
#ifdef _WIN32
	HWND Console;
	AllocConsole();
	Console = FindWindowA("ConsoleWindowClass", NULL);
	ShowWindow(Console, 0);
#endif
	GLenum res = glewInit();
	if (res != GLEW_OK) {
		fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
		return 1;
	}
	glutMainLoop();

	return 0;
}

void render(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glutSwapBuffers();
}
