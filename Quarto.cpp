 //Prof. Marco Antonio, abr/2020, ST765 FT UNICAMP
// Programa baseado no exercício "Parquinho.c" e "Jato.c"
// Aplicação de texturas
// Clara Anna Miranda - 155041
// Katherine Rocha - 106768
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include "image.h"


//#define TEXTURA_DO_CHAO "felpudo.rgb"
#define TEXTURA_DO_CHAO "piso.rgb"
#define TEXTURA_MADEIRA "madeira.rgb"
#define PI 3.1415
GLfloat tetaxz = 0;
GLfloat raioxz = 6;
GLfloat obs[3] = { 0.0,7.0,0.0 };
GLfloat look[3] = { 0.0,3.0,0.0 };


GLuint  textura_chao;
static int rodatudo = 0;

GLfloat planotext[4][2]={
  {-1,-1},
  {+1,-1},
  {+1,+1},
  {-1,+1}
};

GLfloat mesa_difusa[]    = { 1.0, 0.0, 1.0, 1.0 };
GLfloat mesa_especular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mesa_brilho[]    = { 50.0 };

GLfloat cadeira_difusa[]    = { 1.0, 0.0, 1.0, 1.0 };
GLfloat cadeira_especular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat cadeira_brilho[]    = { 20.0 };

GLfloat livro_difusa[]    = { 1.0, 0.0, 1.0, 1.0 };
GLfloat livro_especular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat livro_brilho[]    = { 20.0 };

GLfloat chao_difusa[]    = { 1.0, 0.0, 1.0, 1.0 };
GLfloat chao_especular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat chao_brilho[]    = { 50.0 };

GLfloat posicao_luz[]    = { 0.0, 4.0, 0.0, 1.0};
GLfloat cor_luz[]        = { 1.0, 1.0, 1.0, 1.0};
GLfloat cor_luz_amb[]    = { 0.3, 0.3, 0.3, 1.0};

GLint gouraud=0;


void display(void){
  glClear (GL_COLOR_BUFFER_BIT);
  
	  glEnable(GL_DEPTH_TEST);
	  glEnable(GL_LIGHTING);
	
	  glDepthMask(GL_TRUE);
	  glClearColor(1.0,1.0,1.0,1.0);
	  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	
	  if(gouraud){
	    glShadeModel(GL_SMOOTH);
	  }
	  else{
	    glShadeModel(GL_FLAT);
	  }
 

  	glPushMatrix();
	glRotatef ((GLfloat) rodatudo, 0.0, 1.0, 0.0); //Rotate do R
	
	
	/* calcula a posicao do observador */
	/*obs[0] = raioxz * cos(2 * PI*tetaxz / 360);
	obs[2] = raioxz * sin(2 * PI*tetaxz / 360);
	gluLookAt(obs[0], obs[1], obs[2], look[0], look[1], look[2], 0.0, 1.0, 0.0);*/
  
    

	//Textura do chao
	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
  	glBindTexture(GL_TEXTURE_2D,textura_chao);
    
  //chao
  //versao dois do chao
  	glEnable(GL_TEXTURE_2D);  //seta textura
  
  	//iluminação do chao
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, chao_difusa);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, chao_especular);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, chao_brilho);
  
  
  glBegin(GL_QUADS);
  	glColor3f(0.5, 0.8, 0.0);
  	glTexCoord2fv(planotext[0]); glVertex3f(-20,0.5,20);
  	glTexCoord2fv(planotext[1]); glVertex3f(20,0.5,20);
  	glTexCoord2fv(planotext[2]); glVertex3f(20,0.5,-20);
  	glTexCoord2fv(planotext[3]); glVertex3f(-20,0.5,-20);
  glEnd();
  
  glDisable(GL_TEXTURE_2D); //encerra textura
  
  /*
  //chao cubico sem textura
  	glBegin(GL_QUADS);
  	glColor3f(0.5, 0.8, 0.0);
	glVertex3f(-15,1.5,15);
   	glVertex3f(15,1.5,15);
  	glVertex3f(15,1.5,-15);
  	glVertex3f(-15,1.5,-15);
  	glEnd();
 */
  
	 //cadeira
	glColor3f(0.5, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(5.0, 5.0, 0.0);
	glScalef(0.5, 8.5, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(0.5, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(9.0, 5.0, 0.0);
	glScalef(0.5, 8.5, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();

	//encosto
	//ilumiacao cadeira	 
	
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, cadeira_difusa);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, cadeira_especular);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, cadeira_brilho);
  	
  
	glColor3f(0.5, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(7.0, 7.0, 0.0);
	glScalef(4.0, 4.0, 0.0);
	glutSolidCube(1.0);
	glPopMatrix();

	//assento
	glColor3f(0.5, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(7.0, 4.0, -2.0);
	glScalef(5.0, 0.5, 4.0);
	glutSolidCube(1.0);
	glPopMatrix();

	//pernas
	glColor3f(0.5, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(5.0, 2.5, -3.5);
	glScalef(0.5, 4.0, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(0.5, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(9.0, 2.5, -3.5);
	glScalef(0.5, 4.0, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();
	
	//iluminacao mesa
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mesa_difusa);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mesa_especular);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mesa_brilho);
	
	//mesa
	//tampo
	glColor3f(0.5, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(7.5, 6.5, -5.0);
	glScalef(15.0, 0.5, 8.0);
	glutSolidCube(1.0);
	glPopMatrix();


	//pernas da mesa
	glColor3f(0.5, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(0.5, 3.5, -2.0);
	glScalef(0.5, 6.5, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(0.5, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(14.5, 3.5, -2.0);
	glScalef(0.5, 6.5, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(0.5, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(14.5, 3.5, -8.0);
	glScalef(0.5, 6.5, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(0.5, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(0.5, 3.5, -8.0);
	glScalef(0.5, 6.5, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();
	
	//computador
	glColor3f(0.0, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(6.0, 7.0, -5.0);
	glScalef(5.0, 0.5, 5.0);
	glutSolidCube(1.0);
	glPopMatrix();
	
	glColor3f(0.0, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(6.0, 9.0, -7.5);
	glScalef(6.0, 4.0, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();
	

	//maça
	glColor3f(6,0.0,0);
	glPushMatrix();
	glTranslatef(1.0, 7.3, -3.0);
	glutSolidSphere(0.5, 10, 8);
	glPopMatrix();

	//cabo Maça
	glColor3f(0.0, 0.5, 0.0);
	glPushMatrix();
	glTranslatef(1.0, 7.8, -3.0);
	glScalef(0.2, 0.5, 0.2);
	glutSolidCube(1.0);
	glPopMatrix();


	//objeto Chakeira
	glColor3f(0.6, 0.6, 0.6);
	glPushMatrix();
	glTranslatef(12.5, 7.5, -6.0);
	//glScalef(0.5, 0.8, 0.5);
	glutSolidTeapot(1.0);
	glPopMatrix();
	
	
	//copo
	glColor3f(0.6, 0.6, 0.6);
	glPushMatrix();
	GLUquadricObj *quadric;
	quadric = gluNewQuadric();
  	gluQuadricTexture(quadric, GL_TRUE);
  	glTranslatef(10.5, 7.5, -2.0);
	glRotated(90, 1.0, 0.0, 0.0 );
	glTranslatef(0, 0, 0);
  	gluCylinder(quadric, 0.5, 0.5, 1, 12, 3);
  	glPopMatrix();
	
	//prateleira
	glColor3f(0.5, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(-10, 14, -20);
	glScalef(12.0, 0.5, 8);
	glutSolidCube(1.0);
	glPopMatrix();
	
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, livro_difusa);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, livro_especular);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, livro_brilho);
	
	//livro 1
	glColor3f(1.0, 0.2, 0.0);
	glPushMatrix();
	glTranslatef(-8, 17, -18);
	glScalef(1.0, 5, 3);
	glutSolidCube(1.0);
	glPopMatrix();
	
	
			glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, livro_difusa);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, livro_especular);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, livro_brilho);
	//livro 2
	glColor3f(0.0, 1.0, 0.5);
	glPushMatrix();
	glTranslatef(-7, 17, -18);
	glScalef(1.0, 5, 3);
	glutSolidCube(1.0);
	glPopMatrix();
	

		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, livro_difusa);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, livro_especular);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, livro_brilho);
		//livro 2
	glColor3f(0.0, 0.5, 1);
	glPushMatrix();
	glTranslatef(-6, 17, -18);
	glScalef(1.0, 5, 3);
	glutSolidCube(1.0);
	glPopMatrix();
	
	//livros deitados
	glColor3f(0.5, 0.0, 1);
	glPushMatrix();
	glTranslatef(-11.5, 15, -18);
	glScalef(5.0, 1, 3);
	glutSolidCube(1.0);
	glPopMatrix();
	
		//livros deitados
	glColor3f(1.0, 0.2, 0.2);
	glPushMatrix();
	glTranslatef(-11.5, 16, -18);
	glScalef(5.0, 1, 3);
	glutSolidCube(1.0);
	glPopMatrix();
	
			//livros deitados
	glColor3f(0.5, 1.0, 0.2);
	glPushMatrix();
	glTranslatef(-11.5, 17, -18);
	glScalef(5.0, 1, 3);
	glutSolidCube(1.0);
	glPopMatrix();
	
	

  glPopMatrix();
  glutSwapBuffers();
}

void carregar_texturas(void){
  IMAGE *img;
  GLenum gluerr;

  /* textura do chao */
  
    glGenTextures(1, &textura_chao);
  	glBindTexture(GL_TEXTURE_2D, textura_chao);
  
  	if(!(img=ImageLoad(TEXTURA_DO_CHAO))) {
    	fprintf(stderr,"Error reading a texture.\n");
    	exit(-1);
  	}

  	gluerr=gluBuild2DMipmaps(GL_TEXTURE_2D, 3, 
			   img->sizeX, img->sizeY, 
			   GL_RGB, GL_UNSIGNED_BYTE, 
			   (GLvoid *)(img->data));
  	if(gluerr){
 	   fprintf(stderr,"GLULib%s\n",gluErrorString(gluerr));
 	   exit(-1);
 	}

  	glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
 /*	 glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
  	glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_LINEAR);
 	 glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
 	 glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);*/
  
}

void reshape (int w, int h){
  glViewport (0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  gluPerspective(55.0, (GLfloat) w/(GLfloat) h, 1.0, 60.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef (0.0, -8.0, -30.0);
  
}

void keyboard(unsigned char key, int x, int y){
  switch (key) {
 case 'r':
    rodatudo = (rodatudo + 5) % 360;
    glutPostRedisplay();
    break;
  case 'R':
    rodatudo = (rodatudo - 5) % 360;
    glutPostRedisplay();
    break;/*
case 'T':
		rodatudo = (rodatudo + 5) % 360;
		glutPostRedisplay();
		break;
	case 't':
		rodatudo = (rodatudo - 5) % 360;
		glutPostRedisplay();*/
		break;
   case 27:                                         // tecla Esc (encerra o programa)
	exit(0);
	break;
  }
}

void init(void){
  glClearColor (1.0f, 0.5f, 1.0f, 1.0f);
  carregar_texturas();
 
 gouraud=1;
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

  glLightfv(GL_LIGHT0, GL_DIFFUSE, cor_luz);
  glLightfv(GL_LIGHT0, GL_SPECULAR, cor_luz);
  glLightfv(GL_LIGHT0, GL_AMBIENT, cor_luz_amb);
  glLightfv(GL_LIGHT0, GL_POSITION, posicao_luz);

  
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);


  glEnable(GL_AUTO_NORMAL);
  glEnable(GL_NORMALIZE);

  
}


int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize (500, 500); 
  glutInitWindowPosition (100, 100);
  glutCreateWindow (argv[0]);
  init ();
  glutDisplayFunc(display); 
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutMainLoop();
  return 0;
}


