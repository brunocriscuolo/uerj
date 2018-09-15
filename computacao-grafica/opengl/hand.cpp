/*------------------------------------------------------------------+
 |                                                                  |
 |	UERJ - Universidade do Estado do Rio de Janeiro             |
 |	CTC: Centro de Tecnologia e Ciências                        |
 |	IME: Instituto de Matemática e Estatística                  |
 |	Departamento de Informática e Ciência da Computação         |
 |                                                                  |
 | 	TRABALHO FINAL DE COMPUTAÇÃO GRÁFICA                        |
 |                                                                  |
 | 	Bruno Costa ....... mat:201320712211                        |
 | 	Daniel Calábria ... mat:201320486511                        |  
 |                                                                  |
 |                                                                  |
 +------------------------------------------------------------------*/


#include <GL/glut.h>
#include <math.h>

using namespace std;

//Variáveis Globais
#define PI 3.1415927
// Inicializando a posição dos objetos que compõem a mão.
static int hand = 0;
static int thumb = 0;
static int thumb2 = 0;
static int pointer = 0;
static int middle = 0;
static int ring = 0;
static int pinky = 0;

static GLfloat spinX = 0.0;
static GLfloat spinY = 0.0;
static GLfloat spinZ = 0.0;

// Definindo o tamanho da janela (altura e largura).
GLfloat width = 1000;
GLfloat height = 1000;
// Define a proporção da tela.
// É usada no cálculo de correção do aspecto.
GLfloat aspect;
GLfloat angle;


// Função que define as fontes de luz e iluminação do objeto.
void initLighting(void) 
{
 	
	GLfloat envLight[4] = {0.3, 0.3, 0.3, 1.0};
	GLfloat diffLight[4] = {0.2, 0.2, 0.2, 1.0};
	GLfloat specLight[4] = {0.1, 0.1, 0.1, 1.0};
	GLfloat posLight[4] = {0.3, 0.1, 0.0, 0.0};
	// Capacidade de brilho do material
	GLfloat specularity[4] = { -0.5,-0.5,-0.5,0.0 };
	GLint specMaterial = 1;
	// Define a refletância do material
	glMaterialfv(GL_FRONT, GL_SPECULAR, specularity);
	// Define a concentração do brilho
	glMateriali(GL_FRONT, GL_SHININESS, specMaterial);
	// Ativa o uso da luz ambiente
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, envLight);
	// Define os parâmetros da luz de número 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, envLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specLight);
	glLightfv(GL_LIGHT0, GL_POSITION, posLight);
	// Habilita a definição da cor do material a partir da cor corrente
	glEnable(GL_COLOR_MATERIAL);
	//Habilita o uso de iluminação
	glEnable(GL_LIGHTING);
	// Habilita a luz de número 0
	glEnable(GL_LIGHT0);
}

// Função de inicialização.
void init(void) 
{
	// Especifica que a cor de fundo da janela será preta.
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	// Habilita o modelo de colorização de Gouraud.
	glShadeModel(GL_SMOOTH);
	// Habilita o depth-buffering.
	glEnable(GL_DEPTH_TEST);
	angle = 30.0;
}


// Função que desenha um cilindro sólido.
void glutSolidCylinder(GLfloat radius, GLfloat height)
{
    GLfloat x = 0.0;
    GLfloat y = 0.0;
    GLfloat angle = 0.0;
    GLfloat angle_stepsize = 0.1;

    // Desenha o "tubo" do cilindro.
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f(x, y, height);
            glVertex3f(x, y, 0.0);
            angle = angle + angle_stepsize;
        }
        glVertex3f(radius, 0.0, height);
        glVertex3f(radius, 0.0, 0.0);
    glEnd();

    // Desenha os circulos superior e inferor do cilindro.
    // Esses círculos são os discos que "tapam" o desenho do cilindro.
    glBegin(GL_POLYGON);
    angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f(x, y, height);
            angle = angle + angle_stepsize;
        }
        glVertex3f(radius, 0.0, height);
    glEnd();
}


// Função que desenha todos os elementos que compõem a mão.
void DrawHand(void)
{
	// Limpa a janela e o depth buffer.
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   	glPushMatrix();
   
   	// Constrói o tablado de suporte.
	glPushMatrix();
	glTranslatef(0.0, 0.0, 0.0);
	glPushMatrix();
	glColor3f(0.1,0.4,0.2);
	glScalef(0.1, 1.0, 2.0);
	glutSolidCube(1);
	glPopMatrix();
	glPopMatrix();


	// Constrói o punho.
	glPushMatrix();
	glColor3f(1.0,0.6,0.4);
	glScalef(1.0, 0.4, 1.0);
	glRotatef(90, 0.0, 1.0, 0.0);
	glutSolidCylinder(0.5, 0.5);
	glPopMatrix();
	glTranslatef(0.5, 0.0, 0.0);
	glRotatef((GLfloat)hand, 0.0, 0.0, 1.0);
	glPushMatrix();
	glScalef(0.4, 0.6, 1.22);
	glutSolidSphere(0.5, 50, 50);
	glPopMatrix();


	// Constrói a palma da mão.
	glTranslatef(0.0, 0.0, 0.0);
	glPushMatrix();
	glColor3f(1.0,0.6,0.4);
	glScalef(0.4, 0.5, 1.02);
	glRotatef(90, 0.0, 1.0, 0.0);
	glutSolidCylinder(0.6, 0.85);
	glTranslatef(0.0, 0.0, 0.85);
	glutSolidSphere(0.6, 50, 50);
	glPopMatrix();


	// Constrói o dedo polegar.
	glPushMatrix();
	glTranslatef(0.125, 0.145, 0.55);
	glRotatef(-(GLfloat)thumb, 1.0, 0.0, 0.0);
	glColor3f(1.0,0.6,0.4);
	glutSolidSphere(0.15, 50, 50);
	glPushMatrix();
	glRotatef(22, 0.0, 1.0, 0.0);
	glColor3f(1.0,0.6,0.4);
	glScalef(0.2, 0.2, 0.35);
	glutSolidCylinder(0.5, 0.9);
	glPopMatrix(); 

	glTranslatef(0.13, 0.0, 0.31);
	glRotatef((GLfloat)thumb2, -1.0, 1.0, 1.0);
	glColor3f(1.0,0.6,0.4);
	glutSolidSphere(0.11, 50, 50);
	glPushMatrix(); 
	glColor3f(1.0,0.6,0.4);
	glRotatef(30, 0.0, 1.0, 0.0);
	glScalef(0.2, 0.2, 0.25);
	glutSolidCylinder(0.5, 1);
	glPopMatrix(); 
	
	glTranslatef(0.13, 0.0, 0.22);
	glColor3f(1.0,0.6,0.4);
	glutSolidSphere(0.1, 50, 50);
	glPopMatrix();


	// Constrói as três partes do dedo indicador.
	glPushMatrix();
	glTranslatef(0.3, 0.0, -0.04);
	glRotatef((GLfloat)pointer, 0.0, 0.0, 1.0);
	glTranslatef (0.0, 0.0, 0.5);
	glPushMatrix();
	glColor3f(1.0,0.6,0.4);
	glutSolidSphere(0.15, 50, 50);
	glScalef(0.4, 0.2, 0.2);
	glRotatef(90, 0.0, 1.0, 0.0);
	glutSolidCylinder(0.5, 1);
	glPopMatrix();

	glTranslatef(0.4, 0.0, 0.0);
	glRotatef((GLfloat)pointer, 0.0, 0.0, 1.0);
	glTranslatef(0.0, 0.0, 0.0);
	glPushMatrix();
	glColor3f(1.0,0.6,0.4);
	glutSolidSphere(0.11, 50, 50);
	glScalef(0.3, 0.2, 0.2);
	glRotatef(90, 0.0, 1.0, 0.0);
	glutSolidCylinder(0.5, 1);
	glPopMatrix();

	glTranslatef(0.3, 0.0, 0.0);
	glRotatef((GLfloat)pointer, 0.0, 0.0, 1.0);
	glTranslatef(0.0, 0.0, 0.0);
	glPushMatrix();
	glColor3f(1.0,0.6,0.4);
	glutSolidSphere(0.11, 50, 50);
	glScalef(0.2, 0.2, 0.2);
	glRotatef(90, 0.0, 1.0, 0.0);
	glutSolidCylinder(0.5, 1);
	glPopMatrix();
	glTranslatef(0.2, 0.0, 0.0);
	glPushMatrix();
	glColor3f(1.0,0.6,0.4);
	glutSolidSphere(0.1, 50, 50);
	glPopMatrix();
	glPopMatrix();


	// Constrói as três partes do dedo médio.
	glPushMatrix();
	glTranslatef(0.3, 0.0, 0.05);
	glRotatef((GLfloat)middle, 0.0, 0.0, 1.0);
	glTranslatef (0.15, 0.0, 0.1);
	glPushMatrix();
	glColor3f(1.0,0.6,0.4);
	glutSolidSphere(0.15, 50, 50);
	glScalef(0.4, 0.2, 0.2);
	glRotatef(90, 0.0, 1.0, 0.0);
	glutSolidCylinder(0.5, 1);
	glPopMatrix();

	glTranslatef(0.4, 0.0, 0.0);
	glRotatef((GLfloat)middle, 0.0, 0.0, 1.0);
	glTranslatef(0.0, 0.0, 0.0);
	glPushMatrix();
	glColor3f(1.0,0.6,0.4);
	glutSolidSphere(0.11, 50, 50);
	glScalef(0.3, 0.2, 0.2);
	glRotatef(90, 0.0, 1.0, 0.0);
	glutSolidCylinder(0.5, 1);
	glPopMatrix();

	glTranslatef(0.3, 0.0, 0.0);
	glRotatef((GLfloat)middle, 0.0, 0.0, 1.0);
	glTranslatef(0.0, 0.0, 0.0);
	glPushMatrix();
	glColor3f(1.0,0.6,0.4);
	glutSolidSphere(0.11, 50, 50);
	glScalef(0.2, 0.2, 0.2);
	glRotatef(90, 0.0, 1.0, 0.0);
	glutSolidCylinder(0.5, 1);
	glPopMatrix();
	glTranslatef(0.2, 0.0, 0.0);
	glPushMatrix();
	glColor3f(1.0,0.6,0.4);
	glutSolidSphere(0.1, 50, 50);
	glPopMatrix();
	glPopMatrix();


	// Constrói as três partes do dedo anelar.
	glPushMatrix();
	glTranslatef(0.3, 0.0, 0.25);
	glRotatef((GLfloat)ring, 0.0, 0.0, 1.0);
	glTranslatef (0.08, 0.0, -0.4);
	glPushMatrix();
	glColor3f(1.0,0.6,0.4);
	glutSolidSphere(0.15, 50, 50);
	glScalef(0.4, 0.2, 0.2);
	glRotatef(90, 0.0, 1.0, 0.0);
	glutSolidCylinder(0.5, 1);
	glPopMatrix();

	glTranslatef(0.4, 0.0, 0.0);
	glRotatef((GLfloat)ring, 0.0, 0.0, 1.0);
	glTranslatef(0.0, 0.0, 0.0);
	glPushMatrix();
	glColor3f(1.0,0.6,0.4);
	glutSolidSphere(0.11, 50, 50);
	glScalef(0.3, 0.2, 0.2);
	glRotatef(90, 0.0, 1.0, 0.0);
	glutSolidCylinder(0.5, 1);
	glPopMatrix();

	glTranslatef(0.3, 0.0, 0.0);
	glRotatef((GLfloat)ring, 0.0, 0.0, 1.0);
	glTranslatef(0.0, 0.0, 0.0);
	glPushMatrix();
	glColor3f(1.0,0.6,0.4);
	glutSolidSphere(0.11, 50, 50);
	glScalef(0.2, 0.2, 0.2);
	glRotatef(90, 0.0, 1.0, 0.0);
	glutSolidCylinder(0.5, 1);
	glPopMatrix();
	glTranslatef(0.2, 0.0, 0.0);
	glPushMatrix();
	glColor3f(1.0,0.6,0.4);
	glutSolidSphere(0.1, 50, 50);
	glPopMatrix();
	glPopMatrix();


	// Constrói as três partes do dedo mínimo.
	glPushMatrix();
	glTranslatef(0.3, 0.0, 0.15);
	glRotatef((GLfloat)pinky, 0.0, 0.0, 1.0);
	glTranslatef (-0.05, 0.0, -0.6);
	glPushMatrix();
	glColor3f(1.0,0.6,0.4);
	glutSolidSphere(0.15, 50, 50);
	glScalef(0.4, 0.2, 0.2);
	glRotatef(90, 0.0, 1.0, 0.0);
	glutSolidCylinder(0.5, 1);
	glPopMatrix();

	glTranslatef(0.4, 0.0, 0.0);
	glRotatef((GLfloat)pinky, 0.0, 0.0, 1.0);
	glTranslatef(0.0, 0.0, 0.0);
	glPushMatrix();
	glColor3f(1.0,0.6,0.4);
	glutSolidSphere(0.11, 50, 50);
	glScalef(0.3, 0.2, 0.2);
	glRotatef(90, 0.0, 1.0, 0.0);
	glutSolidCylinder(0.5, 1);
	glPopMatrix();

	glTranslatef(0.3, 0.0, 0.0);
	glRotatef((GLfloat)pinky, 0.0, 0.0, 1.0);
	glTranslatef(0.0, 0.0, 0.0);
	glPushMatrix();
	glColor3f(1.0,0.6,0.4);
	glutSolidSphere(0.11, 50, 50);
	glScalef(0.2, 0.2, 0.2);
	glRotatef(90, 0.0, 1.0, 0.0);
	glutSolidCylinder(0.5, 1);
	glPopMatrix();
	glTranslatef(0.2, 0.0, 0.0);
	glPushMatrix();
	glColor3f(1.0,0.6,0.4);
	glutSolidSphere(0.1, 50, 50);
	glPopMatrix();
	glPopMatrix();


	glPopMatrix();
	glutSwapBuffers();
}


// Callback de redesenho da janela do glut.
void reshape(GLsizei w, GLsizei h)
{
	// Para previnir uma divisão por zero.
	if (h == 0) { h = 1; }
	// Especifica o tamanho da viewport.
	glViewport(0, 0, w, h);
	// Calcula a correção de aspecto.
	aspect = (GLfloat)w / (GLfloat)h;
	glutPostRedisplay();
}


// Função que exibe os objetos na tela.
void display(void) {
    glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluPerspective(angle, aspect, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(1.0,10.0,0.0, 0,0,0.0, 0,-1,0);
	glRotatef(spinX, 1.0, 0.0, 0.0);
	glRotatef(spinY, 0.0, 1.0, 0.0);
	glRotatef(spinZ, 0.0, 0.0, 1.0);
	glTranslatef (-1.0, 0.0, 0.0);
    DrawHand();
	glFlush();
	glutSwapBuffers();
}


// Função de rotação do objeto.
void spinDisplay(void)
{
	if (spinX > 360.0) {
		spinX = spinX - 360.0;
	}
	if (spinZ > 360.0) {
		spinZ = spinZ - 360.0;
	}
	if (spinY > 360.0) {
		spinY = spinY - 360.0;
	}
	glutPostRedisplay();
}


// Callback de teclado.
void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
		// As teclas "h" e "shift+h" movem o punho. 
		case 'h':
			if (hand < 45) {
				hand = (hand + 5) % 360;
	    		glutPostRedisplay();
	    	}	
	    	break;
		case 'H':
			if (hand > -30) {
				hand = (hand - 5) % 360;
	    		glutPostRedisplay();
	    	}
	    	break;
	 
		// As teclas "v" e "shift+v" fecham e abrem o polegar. 
		case 'v':
			if (thumb < 75) {
		    	thumb = (thumb + 5) % 360;
		    	glutPostRedisplay();
		    }
		    if (thumb2 < 45) {
		    	thumb2 = (thumb2 + 5) % 360;
		    	glutPostRedisplay();
		    }
		    break;
		case 'V':
			if (thumb > 0) {
		    	thumb = (thumb - 5) % 360;
		    	glutPostRedisplay();
		    }
		  	if (thumb2 > 0) {
		    	thumb2 = (thumb2 - 5) % 360;
		    	glutPostRedisplay();
		    }
		    break;

		// As teclas "y" e "shift+y" fecham e abrem o dedo indicador. 
		case 'y':
			if (pointer < 45) {
		    	pointer = (pointer + 5) % 360;
		    	glutPostRedisplay();
		    }
		    break;
		case 'Y':
			if (pointer > 0) {
		    	pointer = (pointer - 5) % 360;
		    	glutPostRedisplay();
		    }
		    break;
		
		// As teclas "u" e "shift+u" fecham e abrem o dedo méido.
		case 'u':
			if (middle < 45) {
		    	middle = (middle + 5) % 360;
		    	glutPostRedisplay();
		    }
		    break;
		case 'U':
			if (middle > 0) {
		    	middle = (middle - 5) % 360;
		    	glutPostRedisplay();
		    }
		    break;
		 
		// As teclas "i" e "shift+i" fecham e abrem o dedo anelar.
		case 'i':
			if (ring < 45) {
			    ring = (ring + 5) % 360;
			    glutPostRedisplay();
			}
			break;
		case 'I':
			if (ring > 0) {
			    ring = (ring - 5) % 360;
			    glutPostRedisplay();
			}
			break;

		// As teclas "o" e "shift+o" fecham e abrem o dedo mínimo.
		case 'o':
			if (pinky < 45) {
	    		pinky = (pinky + 5) % 360;
	    		glutPostRedisplay();
	    	}
	    	break;
		case 'O':
			if (pinky > 0) {
			    pinky = (pinky - 5) % 360;
			    glutPostRedisplay();
			}
			break;

		// As teclas "c" e "shift+C" fecham e abrem
		// todos os dedos da mão, simultâneamente.
		case 'c':
		    if (thumb < 80) {
		    	thumb = (thumb + 5) % 360;
		    	glutPostRedisplay();
		    }
		    if (thumb2 < 40) {
		    	thumb2 = (thumb2 + 5) % 360;
		    	glutPostRedisplay();
		    }
		    if (pointer < 40) {
		    	pointer = (pointer + 5) % 360;
		    	glutPostRedisplay();
		    }
		    if (middle < 40) {
		    	middle = (middle + 5) % 360;
		    	glutPostRedisplay();
		    }
		    if (ring < 40) {
		    	ring = (ring + 5) % 360;
		    	glutPostRedisplay();
		    }
		    if (pinky < 40) {
		    	pinky = (pinky + 5) % 360;
		    	glutPostRedisplay();
		   	}
		   	break;
		case 'C':
		    if (thumb > 0) {
		    	thumb = (thumb - 5) % 360;
		    	glutPostRedisplay();
		    }
		    if (thumb2 > 0) {
		    	thumb2 = (thumb2 - 5) % 360;
		    	glutPostRedisplay();
		    }
		    if (pointer > 0) {
		    	pointer = (pointer - 5) % 360;
		    	glutPostRedisplay();
		    }
		    if (middle > 0) {
		    	middle = (middle - 5) % 360;
		    	glutPostRedisplay();
		    }
		    if (ring > 0) {
		    	ring = (ring - 5) % 360;
		    	glutPostRedisplay();
		    }
			if (pinky > 0) {
		    	pinky = (pinky - 5) % 360;
		    	glutPostRedisplay();
			}
			break;

		case 'z':
			if (angle >= 10) {
				angle -= 5;
				glutPostRedisplay();
			}
			break;
		case 'Z':
			if (angle <= 90) {
				angle += 5;
				glutPostRedisplay();
			}
			break;

		case 'w':
			spinZ = spinZ - 2.0;
			spinDisplay();
			break;
		case 'a':
			spinY = spinY + 2.0;
			spinDisplay();
			break;
		case 's':
			spinZ = spinZ + 2.0;
			spinDisplay();
			break;
		case 'd':
			spinY = spinY - 2.0;
			spinDisplay();
			break;
		case 'e':
			spinX = spinX + 2.0;
			spinDisplay();
			break;
		case 'q':
			spinX = spinX - 2.0;
			spinDisplay();
			break;

		case'p':
			if (thumb < 90) {
		    	thumb = (thumb + 5) % 360;
		    	glutPostRedisplay();
		    }
		    if (thumb2 < 10) {
		    	thumb2 = (thumb2 + 5) % 360;
		    	glutPostRedisplay();
		    }
		    if (pointer < 40) {
		       	pointer = (pointer + 5) % 360;
		       	glutPostRedisplay();
		    }
		    break;
		case 'P': 
			if (thumb > 0) {
		    	thumb = (thumb - 5) % 360;
		    	glutPostRedisplay();
		    }
		  	if (thumb2 > 0) {
		    	thumb2 = (thumb2 - 5) % 360;
		    	glutPostRedisplay();
		    }
		    if (pointer > 0) {
		    	pointer = (pointer - 5) % 360;
		    	glutPostRedisplay();
		    }
			break;

			
		// A tecla ESC encerra o programa e fecha a janela de exibição.
		case 27:
	    	exit(0);
	    	break;
		default:
	   		return;
	}
}


// Programa principal.
int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize (width, height); 
   glutCreateWindow ("OpenGL | Virtual Hand");
   
   init();
   initLighting();

   glutDisplayFunc(display); 
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);

   glutMainLoop();
}
