#include <GL/glut.h>
// Função callback chamada para fazer o desenho
void Desenha(void)
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	// Limpa a janela de visualização com a cor de fundo especificada
	glClear(GL_COLOR_BUFFER_BIT);
	// Especifica que a cor corrente é verde
	glColor3f(0.0f, 1.0f, 0.0f);
	// Desenha um quadrado preenchido com a cor corrente
	glBegin(GL_QUADS);
	glVertex2i(100,150);
	glVertex2i(100,100);
	glVertex2i(150,100);
	glVertex2i(150,150);
	glEnd();
	// Executa os comandos OpenGL
	glFlush();
}

// Inicializa parâmetros de rendering
void Inicializa (void)
{
	// Define a cor de fundo da janela de visualização como preta
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

// Função callback chamada quando o tamanho da janela é alterado
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	// Evita a divisao por zero
	if(h == 0) h = 1;
	// Especifica as dimensões da Viewport
	glViewport(0, 0, w, h);
	// Inicializa a matriz de projeção
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// Estabelece World Window (left, right, bottom, top)
	if (w <= h)
	gluOrtho2D (0.0f, 250.0f, 0.0f, 250.0f*h/w);
	else
	gluOrtho2D (0.0f, 250.0f*w/h, 0.0f, 250.0f);
}

// Programa Principal
int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400,350);
	glutInitWindowPosition(10,10);
	glutCreateWindow("Quadrado");
	glutDisplayFunc(Desenha);
	glutReshapeFunc(AlteraTamanhoJanela);
	Inicializa();
	glutMainLoop();
}