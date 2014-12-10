#include <stdlib.h>
#include <GL/glut.h>
#include <GL/GLAUX.h>
#include <Windows.h>
#include <GL/gl.h> 
#include <stdlib.h> 

#define GL_QUADS 0x0007
#define GL_COLOR_BUFFER_BIT 0x00004000
#define GL_DEPTH_BUFFER_BIT 0x00000100

BOOL    keys[256];
static float rquad2 ;          // ���� ��� ����������������

void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


  glBegin(GL_QUADS);                        // ������ ���  
		 glColor3f(0.0f,1.0f,0.0f);    
         glVertex2f( -1.0f, 1.0f);          // ����� ���� �������� (����)
         glVertex2f(1.0f, 1.0f);          // ���� ����
         glVertex2f(1.0f, -1.0f);          // ���� ���
         glVertex2f( -1.0f, -1.0f);          // ����� ���
   glEnd();                                // ��������� ��������

   glPopMatrix(); 
	glTranslatef(rquad2,0.0f,0.0f);           // ������� ������ �� 3 �������

   	glBegin(GL_QUADS);   
		  glColor3f(1.0f,1.0f,0.0f);              
         glVertex2f( -0.2f, 0.2f);          // ����� ���� �������� (����)
         glVertex2f(0.2f, 0.2f);          // ���� ����
         glVertex2f(0.2f, -0.2f);          // ���� ���
         glVertex2f( -0.2f, -0.2f);          // ����� ���
     glEnd();  
	 glPushMatrix();

   
   glutSwapBuffers();
    
}

void reshape (int w, int h)
{   
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (0x1701);
   glLoadIdentity();

   glEnable(GL_DEPTH_TEST);
   glClearDepth(1.0f);
   
   gluPerspective(45.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   gluLookAt (0.0, 0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}


void keyboard (unsigned char key, int x, int y)
{
   switch (key) {
      case 's':   
		  {rquad2=rquad2 + 0.2f; 
		  glutPostRedisplay();
		 //for(int i=0;i<-1;i++);
		  break;
		  }
      case 'a':
		  {rquad2=rquad2 - 0.2f;  
		  glutPostRedisplay();
			  break;}
      default:
         break;
   }
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize (500, 500);
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("OpenGL lesson 2");


   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutMainLoop();
   return 0;
}