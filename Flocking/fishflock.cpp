#include "headers.h"

int c=0;

int main(int argc, char** argv)
{
	std::cout<<"No of fish : ";
	std::cin>>c;
	glutInit(&argc, argv);
	glutInitWindowSize(1000,700);
	glutInitWindowPosition(10,10);
	glutCreateWindow("Assignment1");
	glutDisplayFunc(display);
	glutKeyboardFunc(keyPressed);	
	glutTimerFunc( 0, timer, 0 );
	glutMainLoop(); 
}

