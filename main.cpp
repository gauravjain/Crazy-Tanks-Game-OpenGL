/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */
#include<windows.h>
#include <stdlib.h>
#include <stdio.h>
#include<time.h>
#include<math.h>
#include<dos.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
int count1=-100,count=-100,bcol=0,rt=0;
float tx1,tx,mv1=0,mv2=0;
float posX =-4, posY = -1.90,posX2 = -4,xx1,xx2,yy1,yy2, posY2 = -1.90, posZ = 0,move_unit = 0.1f;
float dx1,dx2,dy1,dy2;
float velocity=10,velocity2=10;
float m=0,m2=0,k=.1,k2=.1,x,y,jj=0;
int bomb,bomb2,u;
float col1=.5,col2=1,col,dcol1=.5,dcol2=1,dcol;
typedef struct {
    int width;
	int height;
	char* title;

	float field_of_view_angle;
	float z_near;
	float z_far;
} glutWindow;

glutWindow win;


GLfloat angle= 0.0;
void spin (void) {
angle+= 1.0;
glutPostRedisplay();




}


void rect(){

    glBegin(GL_POLYGON);
    glColor3f(.30, 0.2, 0.05);
    glVertex2f(-0.5, -0.2);
    glVertex2f(-0.5, 0.2);
    glVertex2f(0.5, 0.2);
    glVertex2f(0.5, -0.2);

    glEnd();
	glPushMatrix();
 glTranslatef(-.4,-.4,.0);

//glutSolidSphere(.2,3,40);
 glutWireTorus(.09,.21,10,30);



	  glColor3f(.5, col1, 1.0);

	glTranslatef(-.1,0.0,.0);

glutSolidSphere(.075,1000,1000);
glTranslatef(+.2,0.0,.0);

glutSolidSphere(.075,1000,1000);
glColor3f(.5, col2, 1.0);

glTranslatef(-.1,0.1,.0);

glutSolidSphere(.075,1000,1000);
glTranslatef(0.0,-0.2,.0);

glutSolidSphere(.075,1000,1000);

glPopMatrix();
/////////////////////
 glColor3f(.30, 0.2, 0.05);
glPushMatrix();
 glTranslatef(+.4,-.4,.0);

//glutSolidSphere(.2,3,40);
 glutWireTorus(.09,.21,10,30);



	  glColor3f(.5, col1, 1.0);

	glTranslatef(-.1,0.0,.0);

glutSolidSphere(.075,1000,1000);
glTranslatef(+.2,0.0,.0);

glutSolidSphere(.075,1000,1000);
glColor3f(.5, col2, 1.0);

glTranslatef(-.1,0.1,.0);

glutSolidSphere(.075,1000,1000);
glTranslatef(0.0,-0.2,.0);

glutSolidSphere(.075,1000,1000);

glPopMatrix();
//glRasterPos3d(0.0,0.0,0.0);
}

void rect1(){

    glBegin(GL_POLYGON);
    glColor3f(.30, 0.2, 0.05);
    glVertex2f(-0.5, -0.2);
    glVertex2f(-0.5, 0.2);
    glVertex2f(0.5, 0.2);
    glVertex2f(0.5, -0.2);

    glEnd();
	glPushMatrix();
 glTranslatef(-.4,-.4,.0);

//glutSolidSphere(.2,3,40);
 glutWireTorus(.09,.21,10,30);



	  glColor3f(.5, dcol1, 1.0);

	glTranslatef(-.1,0.0,.0);

glutSolidSphere(.075,1000,1000);
glTranslatef(+.2,0.0,.0);

glutSolidSphere(.075,1000,1000);
glColor3f(.5, dcol2, 1.0);

glTranslatef(-.1,0.1,.0);

glutSolidSphere(.075,1000,1000);
glTranslatef(0.0,-0.2,.0);

glutSolidSphere(.075,1000,1000);

glPopMatrix();
/////////////////////
 glColor3f(.30, 0.2, 0.05);
glPushMatrix();
 glTranslatef(+.4,-.4,.0);

//glutSolidSphere(.2,3,40);
 glutWireTorus(.09,.21,10,30);



	  glColor3f(.5, dcol1, 1.0);

	glTranslatef(-.1,0.0,.0);

glutSolidSphere(.075,1000,1000);
glTranslatef(+.2,0.0,.0);

glutSolidSphere(.075,1000,1000);
glColor3f(.5, dcol2, 1.0);

glTranslatef(-.1,0.1,.0);

glutSolidSphere(.075,1000,1000);
glTranslatef(0.0,-0.2,.0);

glutSolidSphere(.075,1000,1000);

glPopMatrix();
//glRasterPos3d(0.0,0.0,0.0);
}
void reshape(int wh, int hh){
    /* window ro reshape when made it bigger or smaller*/

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //clip the windows so its shortest side is 2.0
    if (wh < hh) {
        glOrtho(-2.0, 2.0, -2.0 * (GLfloat)hh / (GLfloat)wh, 2.0 * (GLfloat)hh / (GLfloat)wh, 2.0, 2.0);
    }
    else{
        glOrtho(-2.0, 2.0, -2.0 * (GLfloat)wh / (GLfloat)hh, 2.0 * (GLfloat)wh / (GLfloat)hh,2.0 , 2.0);
    }
    // set viewport to use the entire new window
    glViewport(0, 0, wh, hh);
}


void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
glLoadIdentity ();


gluLookAt (0.0, 0.0, 20.0, 0.0, 0.0, 0.0, 0.0, 1.0, .0);
	glTranslatef(0,-2.4,0);

	dx1=posX-.5;
 dx2=posX+.5;
 dy1=-posX2-.5;
	 dy2=-posX2+.5;
  glPushMatrix();
  //glTranslatef(-1,0.0,0);
 glTranslatef(posX,posY,posZ);
 tx=2*posX+k+.1;
 if(bomb=='b'||bomb=='n')
    rt++;
 if(count1<5)

    rect();

    glPopMatrix();
	glTranslatef(0,.3,0);
	if(count1<5)
	{
	glBegin (GL_LINES); /* or GL_LINE_STRIP or GL_LINE_LOOP*/
glVertex3f (posX, -2.0f, 0.0f);
glVertex3f (k+posX+.1, 0.0f-k, 0.0f);
glVertex3f (posX+.1, -2.0f, 0.0f);
glVertex3f (k+posX+.1, 0.0f-k, 0.0f);
glVertex3f (posX+.1, -2.0f, 0.0f);
glVertex3f (k+posX+.1, 0.0f-k, 0.0f);
	}

//gluCylinder(,.2,.2,.3,4,5);
//glVertex3f (8.0, 6.0, 0.0);
glEnd();

//glutWireCube(.20);
glTranslatef(k+posX+.1,0.0f-k,.0f);
glutSolidSphere(.1,30,30);
m=k/3.0;
if(rt%2==1)
{if(bomb=='b')
{bomb='z';
float angle=atan(1/m);

//float velocity;
	float time,distance,height;
	float gravity;

	gravity = 9.80665;

// begin program and ask for user input

	//velocity=10;
	//angle=45;

// output column headers


// calculate results and display w/ loop

	time = 0;
float y=height = 0;
	float x=distance = 0;

	while(height >-2)
		{
			//printf(" << distance << "] [" << height << "]" << endl;");


			printf(";;%d;%d;;",x,y);

   //glRasterPos3f(x+1,y,0.0);


glColor3f (1.0, .5, .50);

			xx1=x=distance = velocity * cos(angle) * time;
			yy1=y=height = (velocity * sin(angle))*time - (gravity * pow(time,2))/2;

			time+=.01;
			printf("mm%fmm%f",tx+x+4,y);
	printf("dx1,,%fdx2,,%f,,",dy1,dy2);

			if((y<-2)&&(dy1<=(tx+x+4.0+mv1)&&dy2>=(tx+x+4.0+mv1)))
			{

					printf(",,%dhaaaaaaaaaai,,,",count);

					count++;
			}
			glPushMatrix();
			glTranslatef(x,y,0.0f);


		if(bcol==5)
			{glColor3f (1.0, .5, .50);
			bcol=0;

			}
			else
			{
				glColor3f(0.0,0.0,0.0);
				bcol++;}

			glutSolidSphere(.10,10,22);

			glTranslatef(-x,-y,0.0f);
		glPopMatrix();


	glFlush();



	}
}

}
else
{

//glutSwapBuffers();

 glTranslatef(0.0,0.0,-posZ);
 glTranslatef(-k-posX-.1,-.3f,.0f);
////////////////////////////
glPushMatrix();

 glTranslatef(-posX2,posY2,posZ);
tx1=-posX2-k2-.1-posX2;

if(count<5)
 rect1();

    glPopMatrix();
	glTranslatef(0,.3,0);
	if(count<5)
	{
	glBegin (GL_LINES); /* or GL_LINE_STRIP or GL_LINE_LOOP*/
glVertex3f (-posX2, -2.0f, 0.0f);
glVertex3f (-k2-posX2-.1, 0.0f-k2, 0.0f);
glVertex3f (-posX2-.1, -2.0f, 0.0f);
glVertex3f (-k2-posX2-.1, 0.0f-k2, 0.0f);
glVertex3f (-posX2-.1, -2.0f, 0.0f);
glVertex3f (-k2-posX2-.1, 0.0f-k2, 0.0f);
	}
//gluCylinder(,.2,.2,.3,4,5);
//glVertex3f (8.0, 6.0, 0.0);
glEnd();
//glutWireCube(.20);
glTranslatef(-k2-posX2-.1,0.0f-k2,.0f);

glutSolidSphere(.1,30,30);
m2=k2/3.0;

if(bomb2=='n')
{bomb2='z';
float angle2=atan(1/m2);

//float velocity2;
	float time2,distance2,height2;
	float gravity2;

	gravity2 = 9.80665;

// begin program and ask for user input

	//velocity2=10;
	//angle=45;

// output column headers


// calculate results and display w/ loop

	time2 = 0;
float y2=height2 = 0;
	float x2=distance2 = 0;

	while(height2 >=-2)
		{
			//printf(" << distance << "] [" << height << "]" << endl;");




   //glRasterPos3f(x+1,y,0.0);


glColor3f (1.0, .5, .50);

			xx1=x2=distance2 = velocity2 * cos(angle2) * time2;
			yy2=y2=height2 = (velocity2 * sin(angle2))*time2 - (gravity2 * pow(time2,2))/2;

			time2+=.01;
	//printf("mm%fmm%f",tx1-x2,y2);
	//printf("dx1,,%fdx2,,%f,,",dx1,dx2);
if((y2<-2)&&(dx1<=(tx1-x2-(4.0+mv2))&&dx2>=(tx1-x2-(4.0+mv2))))
			{
			printf(",,%dhaaaaaaaaaai,,,",count1);

					count1++;
			}

	glPushMatrix();

//glColor3f (col, .5, .50);
			glTranslatef(-x2,y2,0.0f);

			if(bcol==5)
			{glColor3f (1.0, .5, .50);
			bcol=0;

			}
			else
			{
				glColor3f(0.0,0.0,0.0);
				bcol++;}

			glutSolidSphere(.10,10,22);

			glTranslatef(-x2,-y2,0.0f);
		glPopMatrix();


	glFlush();



	}
}

//glTranslatef(3.0f,0.0f,-4.0f);
glutSwapBuffers();

glFlush();
}}
/*void reshape (int w, int h) {
glViewport (0, 0, (GLsizei)w, (GLsizei)h);
glMatrixMode (GL_PROJECTION);
glLoadIdentity ();
gluPerspective (60, (GLfloat) w / (GLfloat) h, 1.0, 100.0);
glMatrixMode (GL_MODELVIEW);
}*/

void keyboard(unsigned char key,int xx, int yy) {





	printf("%c,,",key);
	if (key == 'b')
	bomb=key;
	else
	{ if(key=='a')
          { if(k>0)

		  k-=.1;}
	else if(key=='d')
        k+=.1;
    else if(key=='w')
        velocity+=0.5;
    else if(key=='s')
        velocity-=0.5;

	}
		//////

	if (key == 'n')
	{bomb2=key;

	}

	else
	{ if(key=='o')
         { if(k2>0)

		  k2-=.1;}
	else if(key=='u')
		k2+=.1;
	}

	switch (key){
        case 'j':
			if(posX2<-2)
			{
            posX2+=move_unit;;
			mv2-=move_unit;

			printf("xxxx%fxxx",-posX2);
			dcol=dcol1;
dcol1=dcol2;
dcol2=dcol;
			}
            break;

        case 'l':
			if(posX2>-6)
			{
            posX2-=move_unit;;
			mv2+=move_unit;

			dcol=dcol1;
dcol1=dcol2;
dcol2=dcol;
			}
        break;

        case 'i':
            velocity2+=0.5;
            break;

        case 'k':
        velocity2-=0.5;
        break;

        default:
         break;
    }
    glutPostRedisplay();



}


void keyboardown(int key, int x, int y)
{
    switch (key){
        case GLUT_KEY_RIGHT:
			if(posX<-2)
			{
            posX+=move_unit;
			mv1-=move_unit;
 //printf("xxxx%fxxx",posX);
			col=col1;
col1=col2;
col2=col;}
            break;

        case GLUT_KEY_LEFT:
			if(posX>-6)
			{
            posX-=move_unit;;
	mv1+=move_unit;
			col=col1;
col1=col2;
col2=col;
			}
        break;

        case GLUT_KEY_UP:
            //posY+=move_unit;;
            break;

        case GLUT_KEY_DOWN:
            //posY-=move_unit;;
        break;

        default:
         break;
    }
 //   glutPostRedisplay();
}
void initialize ()
{
    glMatrixMode(GL_PROJECTION);												// select projection matrix
    glViewport(0, 0, win.width, win.height);									// set the viewport
    glMatrixMode(GL_PROJECTION);												// set matrix mode
    glLoadIdentity();															// reset projection matrix
    GLfloat aspect =(GLfloat) win.width / win.height;
	gluPerspective(win.field_of_view_angle, aspect, win.z_near, win.z_far);		// set up a perspective projection matrix
    glMatrixMode(GL_MODELVIEW);													// specify which matrix is the current matrix
    glShadeModel( GL_SMOOTH );
    glClearDepth( 1.0f );														// specify the clear value for the depth buffer
    glEnable( GL_DEPTH_TEST );
    glDepthFunc( GL_LEQUAL );
    glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );						// specify implementation-specific hints
	glClearColor(0.0, 0.0, 0.0, 1.0);

	gluOrtho2D(-1.0, 1.0, -1.0, 1.0);// specify clear values for the color buffers
}



int main(int argc, char **argv)
{

	// set window values
	win.width = 640;
	win.height = 480;
	win.title = "OpenGL/GLUT Example. Visit http://openglsamples.sf.net ";
	win.field_of_view_angle = 30;
	win.z_near = 1.0f;
	win.z_far = 500.0f;

	// initialize and run program
	glutInit(&argc, argv);                                      // GLUT initialization
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH );  // Display Mode
	glutInitWindowSize(win.width,win.height);
	glutInitWindowPosition (10, 100);// set window size
	glutCreateWindow(win.title);								// create Window
	glutDisplayFunc(display);									// register Display Function
	glutIdleFunc( display );									// register Idle Function
    glutKeyboardFunc( keyboard );
	  glutSpecialFunc(keyboardown);
	// register Keyboard Handler
	initialize();
	glutIdleFunc(spin);
	glutMainLoop();												// run GLUT mainloop
	return EXIT_SUCCESS;
}
