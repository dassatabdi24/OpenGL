
#include <GL/glut.h>
#include <GL/glu.h>
#include<stdlib.h>
#include<math.h>
#include<stdio.h>
/*
p=p+2(dy-dx)
g>=0 --> inc y & add g=2dy-2dx
else g+=2y
*/

float x1=30.0,x2=300.0,y11=30.0,y2=300.0;
int rounded(int mm){
	int mi=floor(mm+0.5);
	return mi;
}
void displayMeDDA()
{	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(0.0,0.0,1.0);
	float dx=x2-x1;
	float dy=y2- y11;
	float g=2*dy-dx;
	float x=x1,y=y11;
	while(x!=x2+1 && y!=y2+1){

		glBegin(GL_POINTS);
       	glVertex2f(rounded(x),rounded(y));
		glEnd();
		if(g>=0){
			x++;
			y++;
		   g=2*dy-2*dx;
		}
		else{
			x++;
			g+=2*dy;
		}
	}
		glFlush();
		glutPostRedisplay();
}

int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA);
	glutInitWindowSize(600,500);
	glutInitWindowPosition(260,300);
	glutCreateWindow("Bresenham's Algorithm");
	glutDisplayFunc(displayMeDDA);
	gluOrtho2D (0.0,600.0,0.0,500.0);
	glutMainLoop();
	return 0;

}

//g++ Bresenham.cpp -o hmm -lglut -lGLU -lGL