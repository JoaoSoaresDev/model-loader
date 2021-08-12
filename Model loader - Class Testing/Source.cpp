#include <iostream>
#include <fstream>
#include <vector>

#include "GL/glut.h"
#include "Math/vector3.h"
#include "Model.h"

void myinit() {
	glClearColor(0.0, 0.0, 0.0, 0.0);

	glShadeModel(GL_FLAT);
}

void Display() {

	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0, 0.5, 0.6);
	glutSolidCube(1);

	glutSwapBuffers();
}

void reshape(int w, int h) {
	
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();
	gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);

	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();

	gluLookAt(-2.3, 2.5, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);


}

int main(int argc, char** argv)
{
	FILE* file = fopen("./Model/Glass/Glass OBJ.obj", "r");
	if (file == NULL)
	{
		std::cout << "Impossibel to open file!" << std::endl;
		return false;
	}

	//std::vector<Model> models;

	Model glassModel;

	glassModel.loadModel(*file);
	


	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 500);
	glutCreateWindow("Testing");

	myinit();

	//glutIgnoreKeyRepeat(1);
	//glutSpecialFunc(movementKeys);
	//glutSpecialUpFunc(releaseKey);
	//glutKeyboardUpFunc(releaseKeys);
	//glutKeyboardFunc(keys);

	glutDisplayFunc(Display);
	glutIdleFunc(Display);
	//glutMouseFunc(Mouse);

	// ONLY USE IF REQUIRE MOUSE MOVEMENT
	//glutPassiveMotionFunc(mouseMove);
	//ShowCursor(FALSE);

	glutReshapeFunc(reshape);
	glutMainLoop();
	return(0);
}