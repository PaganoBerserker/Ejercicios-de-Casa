//Semestre 2019 - 2
//************************************************************//
//****************Visual Studio 2017******************//
//************** Alumno (s): Bermudez Sotelo Gustavo *********************************//
//*************	Lab. Computación Gráfica   Gpo.:02	******//
//*************			Átomo			******//
//************************************************************//
#include "Main.h"


// Variables used to calculate frames per second: (Windows)
DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;


//Variables used to create movement

int sol = 0;
int electron1 = 0;
int electron2 = 0;
int electron3 = 0;
int electron4 = 0;


float transZ = -5.0f;
float transX = 0.0f;
float angleX = 0.0f;
float angleY = 0.0f;

float camaraZ = 0.0;
float camaraX = 0.0;

GLfloat SunDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat SunSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat SunPosition[] = { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position

GLfloat EarthDiffuse[] = { 0.2f, 0.2f, 1.0f, 1.0f };			// Tierra
GLfloat EarthSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat EarthShininess[] = { 50.0 };

GLfloat MoonDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };			// Luna
GLfloat MoonSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat MoonShininess[] = { 50.0 };

GLfloat MarsDiffuse[] = { 0.8f, 0.4f, 0.1f, 1.0f };			// Marte
GLfloat MarsSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat MarsShininess[] = { 50.0 };

void InitGL(GLvoid)     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);


}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	//glTranslatef(camaraX,0.0,-5.0+camaraZ);			//camara
	glTranslatef(transX, 0.0f, transZ);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleX, 1.0, 0.0, 0.0);
	glPushMatrix(); //Sistema solar



	glPushMatrix();//Nucleo

	glRotatef(sol, 0.0, 1.0, 0.0);	//Sol 
	glColor3f(1.0, 0.0, 0.0);
	glutSolidSphere(1.5, 20, 20);    //numero de puntos para formar la figura

	glPopMatrix();

	glPushMatrix();//Anillo amarillo

	glRotatef(145, 1, 0, 0);
	glRotatef(sol, 0, 0, 1);	//Rotacion de anillo, podemos comentarlo para que deje de girar
	glColor3f(1, 1, 0);	//Anillo amarillo
	glutSolidTorus(0.1, 2.8, 20, 20);   //numero de puntos para formar el anillo

	glPushMatrix();//creamos átomo
	glRotatef(electron1, 0.0, 0.0, 1.0);
	glTranslatef(2.8, 0, 0);   //trasladamos para crear
	glColor3f(1, 1, 0);	//electron amarillo
	glutSolidSphere(0.2, 20, 20);   //modificamos el tamaño del electron y el numero de puntos que lo conforman
	glPopMatrix();
	glPopMatrix();


	glPushMatrix(); //anillo Rosa
	glRotatef(45, 1, 0, 0);   //45° mitad del atomo
	glRotatef(sol, 0, 0, 1);	//Rotacion de anillo, podemos comentarlo para que deje de girar
	glColor3f(1, 0, 1);	//Anillo Rosa
	glutSolidTorus(0.1, 3.0, 20, 20);  //numero de puntos para formar el anillo

	glPushMatrix();//Creamos átomo
	glRotatef(electron2, 0.0, 0.0, 1.0); //rotacion de electron
	glTranslatef(3, 0, 0);////trasladamos para crear 
	glColor3f(1, 1, 0);	//elecron amarillo
	glutSolidSphere(0.2, 20, 20);  //modificamos el tamaño del electron y el numero de puntos que lo conforman
	glPopMatrix();
	glPopMatrix();


	glPushMatrix();//anillo verde

	glRotatef(90, 1, 0, 0);   //Rotacion a 90°
	glColor3f(1, 0, .5);	
	glutSolidTorus(0.1, 3.2, 20, 20);  //numero de puntos para formar el anillo

	glPushMatrix();//creamos átomo
	glRotatef(electron3, 0.0, 0.0, 1.0);
	glTranslatef(3.2, 0, 0);////trasladamos para crear
	glColor3f(0, 0, 1);	//electrón azul
	glutSolidSphere(0.2, 20, 20);   //modificamos el tamaño del electron y el numero de puntos que lo conforman
	glPopMatrix();
	glPopMatrix();


	glPushMatrix();//anillo azul
	glRotatef(160, 1, 0, 0);
	glColor3f(0, 0, 1);	//Anillo azul
	glutSolidTorus(0.1, 3.4, 20, 20); //numero de puntos para formar el anillo

	glPushMatrix();//creacion átomo
	glRotatef(electron4, 0.0, 0.0, 1.0);
	glTranslatef(3.4, 0, 0); //trasladamos para crear
	glColor3f(0, 1, 0);	//electrón verde
	glutSolidSphere(0.2, 20, 20);  //modificamos el tamaño del electron y el numero de puntos que lo conforman
	glPopMatrix();
	glPopMatrix();

	glutSwapBuffers();
}

void animacion()
{
	// Calculate the number of frames per one second:
	//dwFrames++;
	dwCurrentTime = GetTickCount(); // Even better to use timeGetTime()
	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;

	if (dwElapsedTime >= 30)
	{
		sol = (sol - 2) % 360;
		electron1 = (electron1 - 4) % 360;
		electron2 = (electron2 - 3) % 360;
		electron3 = (electron3 - 3) % 360;
		electron4 = (electron4 - 2) % 360;

		dwLastUpdateTime = dwCurrentTime;
	}

	glutPostRedisplay();
}

void reshape(int width, int height)   // Creamos funcion Reshape
{
	if (height == 0)										// Prevenir division entre cero
	{
		height = 1;
	}

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista

	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	//glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
	case 'w':   //Movimientos de camara
	case 'W':
		camaraZ += 0.5f;
		break;
	case 's':
	case 'S':
		camaraZ -= 0.5f;
		break;
	case 'a':
	case 'A':
		camaraX -= 0.5f;
		break;
	case 'd':
	case 'D':
		camaraX += 0.5f;
		break;

	case 'i':		//Movimientos de Luz
	case 'I':

		break;
	case 'k':
	case 'K':

		break;

	case 'l':   //Activamos/desactivamos luz
	case 'L':
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

		break;
	case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...

		break;
	case GLUT_KEY_LEFT:

		break;
	case GLUT_KEY_RIGHT:

		break;
	default:
		break;
	}
	glutPostRedisplay();
}







int main(int argc, char** argv)   // Main Function
{
	glutInit(&argc, argv); // Inicializamos OpenGL
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	glutInitWindowSize(500, 500);	// Tamaño de la Ventana
	glutInitWindowPosition(20, 60);	//Posicion de la Ventana
	glutCreateWindow("Atomo bien chido"); // Nombre de la Ventana
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutIdleFunc(animacion);
	glutMainLoop();          // 

	return 0;
}