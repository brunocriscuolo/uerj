#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <GL/glut.h>

using namespace std;
GLfloat angle, fAspect;

// variaveis globais
GLint Width = 400;
GLint Height = 350;
static GLfloat spin_z = 0.0;
static GLfloat spin_y = 0.0;
//char objectId = 'b';

// Função callback chamada para fazer o desenho
void Desenha(void)
{
	// Limpa a janela e o depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// Especifica sistema de coordenadas de projeção
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(angle, fAspect, 0.4, 500);
	// Especifica sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 10, 25, 0, 0, 0, 0, 1, 0);
	glRotatef(0.0, 1.0, 0.0, 0.0);
	glRotatef(spin_z, 0.0, 0.0, 1.0);
	glRotatef(spin_y, 0.0, 1.0, 0.0);
	// Desenha o teapot com a cor corrente (solid)
	glColor3f(0.6f, 0.1f, 0.1f);
	//glutSolidSphere(1.0, 50, 50);
	glutSolidCube(5.0);

	glutSwapBuffers();
}

// Inicializa parâmetros de iluminação
void Inicializa(void)
{
	GLfloat luzAmbiente[4] = { 0.2,0.2,0.2,1.0 };
	GLfloat luzDifusa[4] = { 0.7,0.7,0.7,1.0 };
	// "cor"
	GLfloat luzEspecular[4] = { 1.0, 1.0, 1.0, 1.0 };// "brilho"
	GLfloat posicaoLuz[4] = { 0.0, 50.0, 50.0, 1.0 };
	// Capacidade de brilho do material
	GLfloat especularidade[4] = { 1.0,1.0,1.0,1.0 };
	GLint especMaterial = 60;
	// Especifica que a cor de fundo da janela será preta
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	// Habilita o modelo de colorização de Gouraud
	glShadeModel(GL_SMOOTH);
	// Define a refletância do material
	glMaterialfv(GL_FRONT, GL_SPECULAR, especularidade);
	// Define a concentração do brilho
	glMateriali(GL_FRONT, GL_SHININESS, especMaterial);
	// Ativa o uso da luz ambiente
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);
	// Define os parâmetros da luz de número 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa);
	glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular);
	glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz);
	// Habilita a definição da cor do material a partir da cor corrente
	glEnable(GL_COLOR_MATERIAL);
	//Habilita o uso de iluminação
	glEnable(GL_LIGHTING);
	// Habilita a luz de número 0
	glEnable(GL_LIGHT0);
	// Habilita o depth-buffering
	glEnable(GL_DEPTH_TEST);
	angle = 45;
}

// Função callback chamada quando o tamanho da janela é alterado
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	// Para previnir uma divisão por zero
	if (h == 0) h = 1;
	// Especifica o tamanho da viewport
	glViewport(0, 0, w, h);
	// Calcula a correção de aspecto
	fAspect = (GLfloat)w / (GLfloat)h;
	glutPostRedisplay();
}

// Função callback chamada para gerenciar eventos do mouse
void GerenciaMouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
		if (state == GLUT_DOWN) { // Zoom-in
			if (angle >= 10) angle -= 5;
		}
	if (button == GLUT_RIGHT_BUTTON)
		if (state == GLUT_DOWN) { // Zoom-out
			if (angle <= 130) angle += 5;
		}
	glutPostRedisplay();
}

// rotaciona objeto
void spinDisplay(void)
{
	if (spin_z > 360.0)
		spin_z = spin_z - 360.0;
	if (spin_y > 360.0)
		spin_y = spin_y - 360.0;
	glutPostRedisplay();
}

// callback de teclado
void keyboard(unsigned char key, int x, int y)
{
	cout << key;
	switch (key) {
		case 27:
			exit(0);
			break;
		case 'a':
			spin_z = spin_z - 2.0;
			spinDisplay();
			break;
		case 's':
			spin_z = spin_z + 2.0;
			spinDisplay();
			break;
		case 'z':
			spin_y = spin_y - 2.0;
			spinDisplay();
			break;
		case 'w':
			spin_y = spin_y + 2.0;
			spinDisplay();
			break;
/*		case 'o':
			if (objectId == 'b')
				objectId = 'o';
			else
				objectId = 'b';
			glutPostRedisplay();
			break;*/
		default:
			return; }
}

// Programa Principal
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(Width, Height);
	glutCreateWindow("Esfera Iluminada");

	glutDisplayFunc(Desenha);
	glutReshapeFunc(AlteraTamanhoJanela);
	glutMouseFunc(GerenciaMouse);
	glutKeyboardFunc(keyboard);

	Inicializa();

	glutMainLoop();
}