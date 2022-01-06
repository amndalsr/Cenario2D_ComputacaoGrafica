#include <windows.h>  
#include <GL/glut.h>  
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define PI 3.1415926535

float porta1 = -10.0f;
float porta2 = -14.5f;
float porta3 = -2.0f;

float telhado1 = -17.0f;
float telhado2 = 4.0f;
float telhado3 = 0.0f;
float telhado4 = 17.0f;

float corCasaR = 0.97f;
float corCasaG = 0.67f;
float corCasaB = 0.50f;

float corPortaR = 0.65f;
float corPortaG = 0.48f;
float corPortaB = 0.32f;

float corJanelaR = 0.65f;
float corJanelaG = 0.48f;
float corJanelaB = 0.32f;

float corTelhadoR = 0.45f;
float corTelhadoG = 0.29f;
float corTelhadoB = 0.14f;   

float corR = 0.57f;
float corG = 0.15f;
float corB = 5.63f;

float Cx = 0.0;
float Cy = 0.0;

void Desenha(void)
{
	
	//Desenhar o sol
	float angle, raio_x, raio_y;
    int i, circle_points = 3000;
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 1.0f, 0.0f);
	
	glPointSize(0.0);
	
	glBegin(GL_POLYGON);
    raio_x = 8.0;
    raio_y = 8.0;
    for(i = 0; i < circle_points; i++) {
        angle = (2*PI*i)/circle_points;
        glVertex2f(-30.0+raio_x*cos(angle),32.0+raio_y*sin(angle));
    }
    
    glEnd();
	
	//Desenha tronco-árvore
	glBegin(GL_QUADS);
		glColor3f(0.45f, 0.29f, 0.14f);
		glVertex2f(35.0f,-15.0f);
		glVertex2f(35.0f,  -3.0f);       
		glVertex2f( 31.0f,  -3.0f);       
		glVertex2f( 31.0f,-15.0f);
	glEnd();
	
	//Desenha folhas1
	glBegin(GL_TRIANGLES);
		glColor3f(0.0f, 0.44f, 0.21f);
		glVertex2f(25.0f, -10.0f);   
		glVertex2f(  33.0f, 5.0f);    
		glVertex2f( 41.0f, -10.0f);       
	glEnd();
	//Desenha folhas2
	glBegin(GL_TRIANGLES);
		glColor3f(0.0f, 0.44f, 0.21f);
		glVertex2f(25.0f, -5.0f);   
		glVertex2f(  33.0f, 10.0f);    
		glVertex2f( 41.0f, -5.0f);       
	glEnd();
	//Desenha folhas3
	glBegin(GL_TRIANGLES);
		glColor3f(0.0f, 0.44f, 0.21f);
		glVertex2f(25.0f, 0.0f);   
		glVertex2f(  33.0f, 15.0f);    
		glVertex2f( 41.0f, 0.0f);       
	glEnd();
	
	//Desenha estrela1
	glBegin(GL_TRIANGLES);
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex2f(30.0f, 15.0f);   
		glVertex2f(33.0f, 20.0f);    
		glVertex2f(36.0f, 15.0f);       
	glEnd();
	//Desenha estrela2
	glBegin(GL_TRIANGLES);
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex2f(30.0f, 18.0f);   
		glVertex2f(33.0f, 13.0f);    
		glVertex2f(36.0f, 18.0f);       
	glEnd();
	
	
	//Desenha o chão
	glBegin(GL_QUADS); 
		glColor3f(0.0f, 1.0f, 0.0f);
	    glVertex2f(80.0, -14.80);
		glVertex2f(-80.0, -14.80);
		glVertex2f(-80.0, -80.0);
		glVertex2f(80.0, -80.0);
	glEnd();
	
	//Desenha a casa
	glBegin(GL_QUADS);
		glColor3f(corCasaR, corCasaG, corCasaB);
		glVertex2f(-15.0f + Cx,-15.0f + Cy);
		glVertex2f(-15.0f + Cx,  5.0f + Cy);       
		glVertex2f( 15.0f + Cx,  5.0f + Cy);       
		glVertex2f( 15.0f + Cx, -15.0f + Cy);
	glEnd();

		    
	//Desenha a janela
	glBegin(GL_QUADS);
	glColor3f(corJanelaR, corJanelaG, corJanelaB); 
		glVertex2f(4.0f + Cx,-8.0f + Cy);
		glVertex2f(4.0f + Cx,-2.0f + Cy);       
		glVertex2f(12.0f + Cx,-2.0f + Cy);       
		glVertex2f(12.0f + Cx,-8.0f + Cy);             
	glEnd();
	
	//Desenha as linhas da janela 
	glBegin(GL_LINES); 
		glColor3f(0.97f, 0.67f, 0.50f);       
		glVertex2f( 4.0f + Cx,-5.0f + Cy);      
		glVertex2f(12.0f + Cx,-5.0f + Cy);       
		glVertex2f(8.0f + Cx,-2.0f + Cy);    
		glVertex2f(8.0f + Cx,-8.0f + Cy);             
	glEnd();  
	
	//Desenha o telhado
	glBegin(GL_TRIANGLES);
		glColor3f(corTelhadoR, corTelhadoG, corTelhadoB);
		glVertex2f(telhado1 + Cx, telhado2 + Cy);   
		glVertex2f(telhado3 + Cx, telhado4 + Cy);    
		glVertex2f(telhado4 + Cx, telhado2 + Cy);       
	glEnd();
	
	//Desenha a porta 
	glBegin(GL_QUADS);
		glColor3f(corPortaR, corPortaG, corPortaB); 
		glVertex2f(porta1 + Cx,porta2 + Cy);
		glVertex2f(porta1 + Cx, porta3 + Cy);       
		glVertex2f(porta3 + Cx, porta3 + Cy);       
		glVertex2f(porta3 + Cx, porta2 +Cy); 
	glEnd();
	
	glFlush();
	
}

void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{

	if(h == 0) h = 1;

	glViewport(0, 0, w, h);


	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();


	if (w <= h) 
        gluOrtho2D (-50.0f, 50.0f, -50.0f, 50.0f*h/w);
    else 
        gluOrtho2D (-50.0f, 50.0f*w/h, -50.0f, 50.0f);
}

void Teclado (unsigned char key, int x, int y)
{
	if (key == 27)
	{
		exit(0);		
	}
	if (key == 'a') //aumenta a porta
	{
		porta1 += 0.0f;
		porta2 += 0.0f;
		porta3 += 5.0f;
	}
	if (key == 's') //reverte o "a"
	{
		porta1 = -10.0f; 
		porta2 = -14.5f;
		porta3 = -2.0f;
	}
	if (key == 'd') //diminui o telhado
	{
		telhado1 += 1.0f;
		telhado2 += 0.1f;
		telhado3 += 0.1f;
		telhado4 += -1.0f;
	}
	if (key == 'f') //reverte o "d"
	{
		telhado1 = -17.0f;
		telhado2 = 4.0f;
		telhado3 = 0.0f;
		telhado4 = 17.0f;
	}
	glutPostRedisplay();
}

void teclaEspecial(int ts, int x, int y)
{
    
    switch (ts)
    {
    case GLUT_KEY_UP:
        Cy += 5.0;
        break;
    case GLUT_KEY_DOWN:
        Cy -= 5.0;
        break;
    case GLUT_KEY_RIGHT:
        Cx += 5.0;
        break;
    case GLUT_KEY_LEFT:
        Cx -= 5.0;
        break;
    default:
        break;
    }
	glutPostRedisplay();
}


void mouse(int button, int state, int x, int y)
{

    if (button == GLUT_LEFT_BUTTON)
    {
        if (state == GLUT_DOWN)
            printf("RIGHT x = %i, y = %i \n", x, y);
    }
    else
    {
        if (button == GLUT_RIGHT_BUTTON)
        {
            if (state == GLUT_DOWN)
            corCasaR += 1.0f;
            corCasaG += 0.0f;
            corCasaB += 1.0f;
            
            corJanelaR += 0.0f;
            corJanelaG += 0.0f;
            corJanelaB += 0.1f;
            
            corPortaR += 0.0f;
            corPortaG += 0.0f;
            corPortaB += 0.1f;
            
            corJanelaR = 0.6f;
	    corJanelaG = 0.4f;
	    corJanelaB = 0.3f;
        }
    }
	glutPostRedisplay();
}


void Inicializa(void)
{
	glClearColor(0.0f, 0.5f, 1.0f, 0.0f); //define cor da janela como azul
}

int main(int argc, char*argv[])
{
	int sizex, sizey;

 	sizex = 100;
 	sizey = 100;
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(5,5); 
	glutInitWindowSize(450,450);
	glutCreateWindow("Desenho de uma casa 2D");
	
	glutDisplayFunc(Desenha);
	glutReshapeFunc(AlteraTamanhoJanela);
	glutKeyboardFunc (Teclado);
	glutMouseFunc(mouse);
	glutSpecialFunc(teclaEspecial);
	
	Inicializa();
	glutMainLoop();

	return 0;
}
	
	

