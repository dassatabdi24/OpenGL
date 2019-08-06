
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
void displayMeDDA()
{	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(0.0,1.0,0.0);
	float dx=x2-x1;
	float dy=y2-y11;
	int i=0;
	float x,y,inc;
	if(abs(dx)>abs(dy)) inc=abs(dx);
	else inc=abs(dy);
	float xinc=dx/(float)inc;
	float yinc=dy/(float)inc;
	x=x1;
	y=y11;
		glBegin(GL_POINTS);
			for(i = 0;i<=inc;i++)
   			 {         
 				x+=xinc;
 				y+=yinc;
       			glVertex2f(rounded(x),rounded(y));
		
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
	glutDisplayFunc(displayMeDDA);
	gluOrtho2D (0.0,600.0,0.0,500.0);
	glutMainLoop();
	return 0;

}
//g++ DDA.cpp -o dda -lglut -lGLU -lGL
