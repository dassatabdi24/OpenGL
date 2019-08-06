
#include <GL/glut.h>
#include <GL/glu.h>
#include<stdlib.h>
#include<math.h>
#include<stdio.h>

float x1=30.0,x2=300.0,y11=30.0,y2=300.0;
int rounded(int mm){
	int mi=floor(mm+0.5);
	return mi;
}
void displayMe()
{	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0,0.0,0.0);
	float m,b,x,y;
	m = (y2 - y11)/(x2 - x1);
	b = y11 -m * x1;
	

		glBegin(GL_POINTS);
			for(x = x1;x<x2;x++)
   			 {         
 				y = m*x + b;
       			glVertex2f(rounded(x),rounded(y));
		//printf("%f %f\n",x,y );
       		}
		glEnd();
		glFlush();
		glutPostRedisplay();
}

int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA);
	glutInitWindowSize(600,500);
	glutInitWindowPosition(260,300);
	glutCreateWindow("Direct Equation Algorithm");
	glutDisplayFunc(displayMe);
	gluOrtho2D (0.0,600.0,0.0,500.0);
	glutMainLoop();
	return 0;

}

