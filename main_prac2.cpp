//Semestre 2019 - 2
//************************************************************//
//****************Visual Studio 2017**********************************************************//
//************** Alumno (s): Bermudez Sotelo Gustavo *****************************************//
//*************	Lab. Computaci�n Gr�fica   Gpo: 02										******//
//**************Practica 7 Ejercicio Clase: Iluminacion de los planetas del Sistema Solar*****//
//************************************************************//

#include "Main.h"


// Variables used to calculate frames per second: (Windows)
DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;

//lunas un poco separadas de los planetas para que se vean correcctamente rotar en el planeta

//Variables used to create movement

int sol = 0;
int mercurio = 0;
int venus = 0;
int tierra = 0;
int luna = 0;
int marte = 0;
int luna1 = 0;
int luna2 = 0;
int jupiter = 0;
int luna1Jupiter = 0;
int luna2jupiter = 0;
int luna3jupiter = 0;
int saturno = 0;
int urano = 0;

float camaraZ = 0.0;
float camaraX = 0.0;

float LightAngle = 30.0f;

bool	light = false;		// Luz prende/apaga
bool	positional = true;

static int spin = 0;

GLfloat LuzAmbientalSol[] = { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat LuzDifusaSol[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat LuzEspecularSol[] = { 0.0f, 0.0f, 0.0f, 1.0f };
GLfloat LuzPosicionSol[] = { 0.0f, 0.0f, 0.0f, 1.0f };		// Light Position

GLfloat MercurioDiffuse[] = { 0.5f, 0.5f, 0.0f, 1.0f };			// Mercurio
GLfloat MercurioSpecular[] = { 0.60, 0.60, 0.50, 1.0 };
GLfloat MercurioShininess[] = { 32.0 };

GLfloat VenusDiffuse[] = { 0.5f, 0.0f, 0.0f, 1.0f };			// Venus 				
GLfloat VenusSpecular[] = { 0.7, 0.6, 0.6, 1.0 };
GLfloat VenusShininess[] = { 32 };

GLfloat TierraDiffuse[] = { 0.396f, 0.74151f, 0.69102f, 1.0f };	// Tierra  												
GLfloat TierraSpecular[] = { 0.297254, 0.30829, 0.30667, 1.0 };
GLfloat TierraShininess[] = { 12.8 };

GLfloat LunaTierraDiffuse[] = { 0.780392f, 0.568627f, 0.113725f, 1.0f };	// LunaTierra										
GLfloat LunaTierraSpecular[] = { 0.992157f, 0.941176f, 0.807843f, 1.0f };
GLfloat LunaTierraShininess[] = { 27.8974f };


GLfloat MarsDiffuse[] = { 0.5, 0.5, 0.4, 1.0f };			// Marte  
GLfloat MarsSpecular[] = { 0.7, 0.7, 0.4, 1.0 };
GLfloat MarsShininess[] = { 78.125 };

GLfloat MarsLuna1Diffuse[] = { 0.714f, 0.4284f, 0.18144f, 1.0f };			// MarteLuna1
GLfloat MarsLuna1Specular[] = { 0.393548f, 0.271906f, 0.166721f, 1.0f };
GLfloat MarsLuna1Shininess[] = { 25.6f };

GLfloat MarsLuna2Diffuse[] = { 0.396f, 0.74151f, 0.69102f, 0.8f };			// MarteLuna2
GLfloat MarsLuna2Specular[] = { 0.297254f, 0.30829f, 0.306678f, 0.8f };
GLfloat MarsLuna2Shininess[] = { 12.8f };

GLfloat JupiterDiffuse[] = { 0.18275f, 0.17f, 0.22525f, 0.82f };			// Jupiter	
GLfloat JupiterSpecular[] = { 0.332741f, 0.328634f, 0.346435f, 0.82f };
GLfloat JupiterShininess[] = { 38.4f };

GLfloat Luna1JupiterDiffuse[] = { 0.4f, 0.4f, 0.4f, 1.0f };			// Luna1Jupiter
GLfloat Luna1JupiterSpecular[] = { 0.774597f, 0.774597f, 0.774597f, 1.0f };
GLfloat Luna1JupiterShininess[] = { 76.8f };

GLfloat Luna2JupiterDiffuse[] = { 0.61424f, 0.04136f, 0.04136f, 0.55f };			// JupiterLuna2
GLfloat Luna2JupiterSpecular[] = { 0.727811f, 0.626959f, 0.626959f, 0.55f };
GLfloat Luna2JupiterShininess[] = { 76.8f };

GLfloat Luna3JupiterDiffuse[] = { 0.396f, 0.74151f, 0.69102f, 0.8f };			// JupiterLuna3
GLfloat Luna3JupiterSpecular[] = { 0.297254f, 0.30829f, 0.306678f, 0.8f };
GLfloat Luna3JupiterShininess[] = { 12.8f };

GLfloat SaturnoDiffuse[] = { 0.34615f, 0.3143f, 0.0903f, 1.0f };			// Saturno 
GLfloat SaturnoSpecular[] = { 0.797357f, 0.723991f, 0.208006f, 1.0f };
GLfloat SaturnoShininess[] = { 83.2f };

GLfloat Anillo1SaturnoDiffuse[] = { 0.5f,0.0f,0.0f,1.0f };			// Anillo1Saturno
GLfloat Anillo1SaturnoSpecular[] = { 0.7f,0.6f,0.6f,1.0f };
GLfloat Anillo1SaturnoShininess[] = { 32.0f };

GLfloat Anillo2SaturnoDiffuse[] = { 0.0f,0.50980392f,0.50980392f,1.0f };			// Anillo2Saturno
GLfloat Anillo2SaturnoSpecular[] = { 0.50196078f,0.50196078f,0.50196078f,1.0f };
GLfloat Anillo2SaturnoShininess[] = { 32.0f };

GLfloat UranoDiffuse[] = { 0.4f, 0.2368f, 0.1036f, 1.0f };			// Urano 
GLfloat UranoSpecular[] = { 0.774597f, 0.458561f, 0.200621f, 1.0f };
GLfloat UranoShininess[] = { 76.8f };


void InitGL(GLvoid)     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glLightfv(GL_LIGHT1, GL_AMBIENT, LuzAmbientalSol);				// Setup The Ambient Light
	glLightfv(GL_LIGHT1, GL_DIFFUSE, LuzDifusaSol);				// Setup The Diffuse Light
	glLightfv(GL_LIGHT1, GL_SPECULAR, LuzEspecularSol);

	glEnable(GL_LIGHT1);
}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(camaraX, 0.0, -5.0 + camaraZ);			//camara

	glLightfv(GL_LIGHT1, GL_POSITION, LuzPosicionSol);

	glEnable(GL_LIGHTING);

	glPushMatrix(); //Sistema solar, es el general para todo


	glPushMatrix();//sol
	glRotatef(sol, 0.0, 1.0, 0.0);	//El Sol gira sobre su eje pero para ello el rotatef queda fuera para que mueva a todo
	glDisable(GL_LIGHTING);
	glColor3f(1.0, 1.0, 0.0);	//Sol amarillo
	glutSolidSphere(1.9, 18, 18);  //Draw Sun (radio,H,V); mientras mas puntos tenga aqui mas circular se vera
	glEnable(GL_LIGHTING);


	glPushMatrix();//mercurio
	glRotatef(mercurio, 0, 1, 0);
	glTranslatef(3.2, 0, 0);
	glRotatef(mercurio, 0, 1, 0);
	glColor3f(0.5, 0.5, 0.5);

	glMaterialfv(GL_FRONT, GL_AMBIENT, MercurioDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MercurioSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MercurioShininess);

	glutSolidSphere(0.3, 8, 8);
	glPopMatrix();

	glPushMatrix();//venus
	glRotatef(venus, 0, 1, 0);
	glTranslatef(4.7, 0, 0);
	glRotatef(venus, 0, 1, 0);
	glColor3f(0.0, 0.8, 1.0);

	glMaterialfv(GL_FRONT, GL_AMBIENT, VenusDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, VenusSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, VenusShininess);

	glutSolidSphere(0.5, 9, 8);
	glPopMatrix();

	glPushMatrix();//tierra
	glRotatef(tierra, 0, 1, 0);
	glTranslatef(6.4, 0, 0);
	glRotatef(tierra, 0, 1, 0);
	glColor3f(0.7, 0.8, 1.0);

	glMaterialfv(GL_FRONT, GL_AMBIENT, TierraDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, TierraSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, TierraShininess);

	glutSolidSphere(0.7, 8, 8);

	glPushMatrix();//luna tierra
	glRotatef(luna, 0, 1, 0);
	glTranslatef(1.0, 0, 0);
	glRotatef(luna, 0, 1, 0);
	glColor3f(7.7, 7.8, 7.0);

	glMaterialfv(GL_FRONT, GL_AMBIENT, LunaTierraDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, LunaTierraSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, LunaTierraShininess);

	glutSolidSphere(0.1, 8, 8);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();//marte
	glRotatef(marte, 0, 1, 0);
	glTranslatef(8.4, 0, 0);
	glRotatef(marte, 0, 1, 0);
	glColor3f(1.0, 0.0, 0.0);

	glMaterialfv(GL_FRONT, GL_AMBIENT, MarsDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MarsSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MarsShininess);

	glutSolidSphere(0.4, 8, 8);

	glPushMatrix();//luna1 marte
	glRotatef(luna1, 0, 1, 0);
	glTranslatef(0.5, 0, 0);
	glRotatef(luna1, 0, 1, 0);
	glColor3f(0.1, 0.8, 0.8);

	glMaterialfv(GL_FRONT, GL_AMBIENT, MarsLuna1Diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MarsLuna1Specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MarsLuna1Shininess);

	glutSolidSphere(0.1, 8, 8);

	glPushMatrix();//luna2 marte
	glRotatef(luna2, 0, 1, 0);
	glTranslatef(0.5, 0, 0);
	glRotatef(luna2, 0, 1, 0);
	glColor3f(0.1, 0.8, 0.8);

	glMaterialfv(GL_FRONT, GL_AMBIENT, MarsLuna2Diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MarsLuna2Specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MarsLuna2Shininess);

	glutSolidSphere(0.1, 8, 8);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();


	glPushMatrix();//jupiter
	glRotatef(jupiter, 0, 1, 0);
	glTranslatef(11, 0, 0);
	glRotatef(jupiter, 0, 1, 0);
	glColor3f(1.0, 1.0, 0.7);

	glMaterialfv(GL_FRONT, GL_AMBIENT, JupiterDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, JupiterSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, JupiterShininess);

	glutSolidSphere(1, 8, 9);

	glPushMatrix();//luna1Jupiter
	glRotatef(luna1Jupiter, 0, 1, 0);
	glTranslatef(1.2, 0, 0);
	glRotatef(luna1Jupiter, 0, 1, 0);
	glColor3f(1.0, 0.4, 0.7);

	glMaterialfv(GL_FRONT, GL_AMBIENT, Luna1JupiterDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, Luna1JupiterSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, Luna1JupiterShininess);

	glutSolidSphere(0.1, 8, 9);

	glPushMatrix();//luna2Jupiter
	glRotatef(luna2jupiter, 0, 1, 0);
	glTranslatef(1.4, 0, 0);
	glRotatef(luna2jupiter, 0, 1, 0);
	glColor3f(1.0, 0.4, 0.7);

	glMaterialfv(GL_FRONT, GL_AMBIENT, Luna2JupiterDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, Luna2JupiterSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, Luna2JupiterShininess);

	glutSolidSphere(0.2, 9, 9);

	glPushMatrix();//luna3upiter
	glRotatef(luna3jupiter, 0, 1, 0);
	glTranslatef(1.6, 0, 0);
	glRotatef(luna3jupiter, 0, 1, 0);
	glColor3f(1.0, 1.0, 0.7);

	glMaterialfv(GL_FRONT, GL_AMBIENT, Luna3JupiterDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, Luna3JupiterSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, Luna3JupiterShininess);

	glutSolidSphere(0.2, 9, 9);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();


	glPushMatrix();//saturno
	glRotatef(saturno, 0, 1, 0);
	glTranslatef(16, 0, 0);
	glRotatef(saturno, 0, 1, 0);
	glColor3f(0.2, 0.6, 1.0);

	glMaterialfv(GL_FRONT, GL_AMBIENT, SaturnoDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, SaturnoSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, SaturnoShininess);

	glutSolidSphere(0.9, 9, 9);
	glRotatef(30, 1, 0, 0); //anillo1
	glColor3f(1, 0, 0);

	glMaterialfv(GL_FRONT, GL_AMBIENT, Anillo1SaturnoDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, Anillo1SaturnoSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, Anillo1SaturnoShininess);

	glutSolidTorus(0.5, 2, 9, 9);
	//glPopMatrix();
	glRotatef(90, 1, 0, 0); //anillo2		
	glColor3f(1, 1, 0);

	glMaterialfv(GL_FRONT, GL_AMBIENT, Anillo2SaturnoDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, Anillo2SaturnoSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, Anillo2SaturnoShininess);

	glutSolidTorus(0.4, 1.3, 10, 10);
	glPopMatrix();

	glPushMatrix();//urano
	glRotatef(urano, 0, 1, 0);
	glTranslatef(20, 0, 0);
	glRotatef(urano, 0, 1, 0);
	glColor3f(0.0, 1.0, 1.0);

	glMaterialfv(GL_FRONT, GL_AMBIENT, UranoDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, UranoSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, UranoShininess);

	glutSolidSphere(0.8, 9, 9);
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
		sol = (sol - 3) % 360;	//cuando llegue a 360� se vuelve a inicializar la variable y sigue girando //su el 5 le ponemos menos gira mas lento
		mercurio = (mercurio - 1) % 360;
		venus = (venus - 1) % 360;
		tierra = (tierra - 1) % 360;
		luna = (luna - 2) % 360;
		marte = (marte - 2) % 360;
		luna1 = (luna1 - 2) % 360;
		luna2 = (luna2 - 2) % 360;
		jupiter = (jupiter - 1) % 360;
		luna1Jupiter = (luna1Jupiter - 2) % 360;
		luna2jupiter = (luna2jupiter - 2) % 360;
		luna3jupiter = (luna3jupiter - 1) % 360;
		saturno = (saturno - 3) % 360;
		urano = (urano - 2) % 360;


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
	glutInitWindowSize(500, 500);	// Tama�o de la Ventana
	glutInitWindowPosition(20, 60);	//Posicion de la Ventana
	glutCreateWindow("Sistema Solar Sensual"); // Nombre de la Ventana
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut funci�n de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut funci�n en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut funci�n de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutIdleFunc(animacion);
	glutMainLoop();          // 

	return 0;
}