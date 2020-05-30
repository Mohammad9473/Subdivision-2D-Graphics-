#include <GL/glut.h>
#include <bevgrafmath2017.h>
#include <math.h>
#include <vector>
using namespace std;

GLsizei winWidth = 800, winHeight = 800;
//int n = 5;

vector <vec2> points = { {550,450},
	{455,519},
	{491,631},
	{609,631},
	{645,519},
	};

//float scheme[4] = { -2.0 / 6, 5.0 / 6, 5.0 / 6, -2.0 / 6 };
float scheme[4] = { -0.5 / 6, 3.5 / 6, 3.5 / 6, -0.5 / 6 };
//vec2 points1[20] = { {} };
/*vec2 points1[10] = {
	{581,455},
{519,455 },
{469,491},
{450,550 },
{469,609 },
{519,645 },
{581,645 },
{631,609 },
{650,550 },
{ 631,491 }
};

vec2 points2[20] = {
	{566, 451},
{534, 451 },
{505, 461},
{479, 479},
{461, 505},
{451, 534},
{451, 566},
{461, 595},
{479, 621},
{505, 639},
{534, 649},
{566, 649},
{595, 639},
{621, 621},
{639, 595},
{649, 566},
{649, 534},
{639, 505},
{621, 479},
{595, 461}
};
*/
void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, winWidth, 0.0, winHeight);
	glShadeModel(GL_FLAT);
	glEnable(GL_POINT_SMOOTH);
	glClear(GL_COLOR_BUFFER_BIT);
	
	glPointSize(5);
	glLineWidth(1.0);
	glFlush();
}



void subdivide() {
	vector <vec2> newarray = points;

	int n = points.size();

	for (int t = 0;t < n;t++) {
		vec2 newpoint = points[t] * scheme[0] + points[(t + 1) % n] * scheme[1] + points[(t + 2) % n] * scheme[2] + points[(t + 3) % n] * scheme[3];
		int newIndex = (2 * t + 2) % newarray.size();
		if (newIndex == 0)
			newIndex = newarray.size();
		newarray.insert(newarray.begin() + newIndex, newpoint);

	}
	points = newarray;



}



void keyPressed(unsigned char key, int x, int y)
{
	if (key == 'i') {
		subdivide();
	}
	glutPostRedisplay();
}

void shape() {
	
	



	glColor3f(10, 0, 0);
	glBegin(GL_POINTS);
	for (int i = 0; i < points.size(); i++) {
		glColor3f(0, 0, 1);
		glVertex2f(points[i].x, points[i].y);
	
	
	}
	glEnd();

	

	
	
	
	
	
	/*glColor3f(1, 0, 0);
	glBegin(GL_POINTS);
	for (int i = 0; i < 10; i++) {
		glVertex2f(points1[i].x, points1[i].y);

	}
	glEnd();

	glColor3f(0, 1, 0);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 10; i++) {
		glVertex2f(points1[i].x, points1[i].y);


	}
	glEnd();


	glColor3f(1, 0, 0);
	glBegin(GL_POINTS);
	for (int i = 0; i < 20; i++) {
		glVertex2f(points2[i].x, points2[i].y);

	}
	glEnd();

	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 20; i++) {
		glVertex2f(points2[i].x, points2[i].y);


	}
	glEnd();
	*/


	glColor3f(2, 0, 5);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i <points.size() ; i++) {
		glVertex2f(points[i].x, points[i].y);
	

	}
	glEnd();
	

}





void display() {
	GLint i;
	glClear(GL_COLOR_BUFFER_BIT);
	shape();
	glutSwapBuffers();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(winWidth, winHeight);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Computer Graphics");
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyPressed);
	glutMainLoop();
	return 0;
}