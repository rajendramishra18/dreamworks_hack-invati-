#include "headers.h"
#include "fish.cpp"
#include "object.cpp"

extern int c;
int count=0;
int f=0,s=0;
fish cb;
object ob;

void display()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT); 
	int i;

	
	glPushMatrix();
	//if(s==0)
		glRotatef(cb.getAngle(), 0, 0, 1);	
		ob.drawObj(cb.getRotMat());
	for(i=0;i<c;i++)
		cb.drawfish();
	glPopMatrix();

	glFlush();
}

void move()
{
	cb.setCoord(0.005);
}

void timer( int value )
{
	if(s==1 && count<100)
	{
		move();
		f=1;
		count++;
		glutPostRedisplay();
	}
	glutTimerFunc( 100, timer, 0 );
}

void keyPressed (unsigned char key, int x, int y) 
{
	if(key=='s')
		s=1;
	glutPostRedisplay();
} 

