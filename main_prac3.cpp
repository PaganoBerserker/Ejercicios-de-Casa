//Semestre 2019 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): Bermudez Sotelo Gustavo *********************************//
//*************     	 	Pracica 3 Ejercicio en Casa Funcion en 3D******//
//*************Lab. Computación Gráfica Grupo: 02	*******************************//
//************************************************************//

//#include <gl/gl.h>     // The GL Header File
//#include <GL/glut.h>   // The GL Utility Toolkit (Glut) Header
//#include <stdlib.h>
#include "Main.h"

float angleX = 0.0f;
float angleY = 0.0f;
float angleZ = 0.0f;
float transX = 0.0f;
float transY = 0.0f;
float transZ = -5.0f;





void InitGL(GLvoid)     // Inicializamos parametros
{

	//glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	//glEnable(GL_LIGHTING);
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing que se realizara
	//glEnable ( GL_COLOR_MATERIAL );
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void prisma(double a, double b) //declaramos tipo de valor para los vertices
{


	GLfloat vertice[8][3] = {
				{a ,-a, a},    //Coordenadas Vértice 0 V 0
				{-a ,-a, a},    //Coordenadas Vértice 1 V 1
				{-a ,-a, -a},    //Coordenadas Vértice 2 V 2
				{a ,-a, -a},    //Coordenadas Vértice 3 V 3
				{b , b, b},    //Coordenadas Vértice 4 V 4
				{b , b, -b},    //Coordenadas Vértice 5 V 5
				{-b , b, -b},    //Coordenadas Vértice 6 V 6
				{-b , b, b},    //Coordenadas Vértice 7 V 7
	};
	//Frente
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.3, 0.1);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[1]);
	glEnd();
	//Derecha
	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.1, 0.1);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[4]);
	glEnd();
	//Atras
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 0.0);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[2]);
	glEnd();
	//Izquierda
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[2]);
	glEnd();
	//Fondo
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[2]);
	glVertex3fv(vertice[3]);
	glEnd();
	//Superior
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.2, 1.0);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[7]);
	glEnd();
}

void prisma2(double A, double B, double C, double D, double E, double F, double G, double H, double I, double J,
	double K, double L, double M, double N, double O, double P, double Q, double R, double S, double T, double U,
	double V, double X, double Y) //Prisma2 
{


	GLfloat vertice[8][3] = {
				{A, B, C},    //Coordenadas Vértice 0 V 0
				{D, E, F},    //Coordenadas Vértice 1 V 1
				{G, H, I},    //Coordenadas Vértice 2 V 2
				{J, K, L},    //Coordenadas Vértice 3 V 3
				{M, N, O},    //Coordenadas Vértice 4 V 4
				{P, Q, R},    //Coordenadas Vértice 5 V 5
				{S, T, U},    //Coordenadas Vértice 6 V 6
				{V, X, Y},    //Coordenadas Vértice 7 V 7
	};

	//Frente
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[1]);
	glEnd();
	//Derecha
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[4]);
	glEnd();
	//Atras
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 1.0);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[2]);
	glEnd();
	//Izquierda
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.3, 0.4);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[2]);
	glEnd();
	//Superior
	glBegin(GL_POLYGON);
	glColor3f(0.9, 0.6, 0.6);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[2]);
	glVertex3fv(vertice[3]);
	glEnd();
	//inferior
	glBegin(GL_POLYGON);
	glColor3f(0.1, 1.0, 0.9);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[7]);
	glEnd();
}

void prisma3(double base, double tapa, double altura)
{


	GLfloat vertice[8][3] = {
				{base ,-altura, base},    //Coordenadas Vértice 0 V 0
				{-base ,-altura, base},    //Coordenadas Vértice 1 V 1
				{-base ,-altura, -base},    //Coordenadas Vértice 2 V 2
				{base ,-altura, -base},    //Coordenadas Vértice 3 V 3
				{tapa , altura, tapa},    //Coordenadas Vértice 4 V 4
				{tapa , altura, -tapa},    //Coordenadas Vértice 5 V 5
				{-tapa , altura, -tapa},    //Coordenadas Vértice 6 V 6
				{-tapa , altura, tapa},    //Coordenadas Vértice 7 V 7
	};

	glBegin(GL_POLYGON);	//Front
	glColor3f(2.0, 0.0, 0.0);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[1]);
	glEnd();
	//Derecha
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.3, 0.5);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[4]);
	glEnd();
	//Atras
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 1.0);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[2]);
	glEnd();
	//Izquierda
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[2]);
	glEnd();
	//Superior
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[2]);
	glVertex3fv(vertice[3]);
	glEnd();
	//Inferior
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.5, 0.4);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[7]);
	glEnd();
}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limpiamos pantalla y Depth Buffer
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//Poner Código Aquí.


	glTranslatef(transX, transY, transZ);
	glRotatef(angleY, 0, 1, 0);

	glTranslatef(-2, 0, 0); //Origen del prisma
	prisma(3, 2);		   //1 Tamaño de la base del prisma, 2 Tamaño de la tapa del prisma


	glTranslatef(0, 0, 0); //en este caso se ponen las coordenas vertice por vertice
	prisma2(2, -2, 2, -2, -2, 2, -2, -2, -2, 2, -2, -2, 2, 2, 2, 2, 2, -2, -2, 2, -2, -2, 2, 2);
	//vertice 1,vertice 2,vertice 3,vertice 4,vertice 5,vertice 6,vertice 7,vertice 8

	glTranslatef(4, 5, 0); //Origen
	prisma3(3, 2, 3);		   //Primer dato para el tamaño de la base	
						   //segundo para el tamaño de la superior
						   //tercer para la altura


	glutSwapBuffers();
	//glFlush();
	// Swap The Buffers
}

void reshape(int width, int height)   // Creamos funcion Reshape
{
	if (height == 0)										// Prevenir division entre cero
	{
		height = 1;
	}

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);						//Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	//glOrtho(-5,5,-5,5,0.1,20);	
	glFrustum(-0.5, 0.5, -0.5, 0.5, 0.1, 50.0);
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
	case 'w': //te metes hacia el cubo
	case 'W':
		transZ += 0.2f;
		printf("Posicion en Z: %f\n", transZ);
		break;

	case 's': //te sales del cubo
	case 'S':
		transZ -= 0.2f;
		printf("Posicion en Z: %f\n", transZ);
		break;

	case 'a': //se mueve a izquierda
	case 'A':
		transX -= 0.2f;
		break;

	case 'd': //Se mueve a la derecha
	case 'D':
		transX += 0.2f;
		break;

	case 'q': //se mueve hacia arriba
	case 'Q':
		transY += 0.2f;
		break;

	case 'e': // se mueve hacia abajo
	case 'E':
		transY -= 0.2f;
		break;

	case 27:        // Cuando Esc es presionado...
		exit(0);   // Salimos del programa
		break;
	default:        // Cualquier otra
		break;
	}
	glutPostRedisplay();
}

void arrow_keys(int a_keys, int x, int y)  // Funcion para manejo de teclas especiales (arrow keys)
{
	switch (a_keys) {
	case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		angleX += 1.0f;
		break;
		//glutFullScreen ( ); // Full Screen Mode
		//break;
	case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		angleX -= 1.0f;
		break;
		//glutReshapeWindow ( 500, 500 ); // Cambiamos tamano de Ventana
		//break;
	case GLUT_KEY_LEFT:
		angleY += 1.0f;
		break;
	case GLUT_KEY_RIGHT:
		angleY -= 1.0f;
		break;
	default:
		break;
	}
	glutPostRedisplay();
}


int main(int argc, char** argv)   // Main Function
{
	glutInit(&argc, argv); // Inicializamos OpenGL
	//glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	glutInitWindowSize(500, 500);	// Tamaño de la Ventana
	glutInitWindowPosition(0, 0);	//Posicion de la Ventana
	glutCreateWindow("Practica 3"); // Nombre de la Ventana
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutMainLoop();          // 

	return 0;
}