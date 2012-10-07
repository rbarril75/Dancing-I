/*
* by Ryan Barril 
* CS 418 - Interactive Graphics
* MP1 - "Dancing I"
* Created 9/13/2012
*/

#include <stdio.h>
#include <stdlib.h>
#include <GLUT/glut.h>

#ifndef max
	#define max( a, b ) ( ((a) > (b)) ? (a) : (b) )
#endif

#ifndef min
	#define min( a, b ) ( ((a) < (b)) ? (a) : (b) )
#endif

// Options
// Set dancing to 0 or 1 for a stationary or dancing I, respectively.
// Set outlines to 0 or 1 for a non-outlined or outlined I, respectively.
int dancing = 1;	// set to make the I dance
int outlines = 0;	// set to outline the I's mesh triangles
int FPS = 60;		// frames per second
float xLoc = 0;		// horizontal starting position

float randFrac() {
	return ((float) rand()) / (float) RAND_MAX;
}

// return a float between -0.1 and +0.1
// used to randomize dancing movement
float randMove() {
	if (dancing)
		return randFrac() * 0.2 + -0.1;
	return 0.0;
}

void drawDancingI() {
	// dancing I randomly shuffles to left or right
	// prevented from going offscreen
	if (dancing) {
		if (randFrac() * 100.0 > 50.0)
			xLoc = min(3.5, xLoc + 0.7);
		else
			xLoc = max(-3.5, xLoc - 0.7);
	}
	
	// set vertices
	float topNE_x = +0.6 + xLoc + randMove(); float topNE_y = +1.0 + randMove();	
	float topNW_x = -0.6 + xLoc + randMove(); float topNW_y = +1.0 + randMove();
	float topSW_x = -0.6 + xLoc + randMove(); float topSW_y = +0.6 + randMove();
	float topSE_x = +0.6 + xLoc + randMove(); float topSE_y = +0.6 + randMove();
	float trunkNE_x = +0.2 + xLoc + randMove(); float trunkNE_y = +0.6 + randMove();
	float trunkNW_x = -0.2 + xLoc + randMove(); float trunkNW_y = +0.6 + randMove();
	float trunkSW_x = -0.2 + xLoc + randMove(); float trunkSW_y = -0.6 + randMove();
	float trunkSE_x = +0.2 + xLoc + randMove(); float trunkSE_y = -0.6 + randMove();
	float botNE_x = +0.6 + xLoc + randMove(); float botNE_y = -0.6 + randMove();
	float botNW_x = -0.6 + xLoc + randMove(); float botNW_y = -0.6 + randMove();
	float botSW_x = -0.6 + xLoc + randMove(); float botSW_y = -1.0 + randMove();
	float botSE_x = +0.6 + xLoc + randMove(); float botSE_y = -1.0 + randMove();
	
	// draw orange/blue I
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(.76, .296, .09);
		glVertex2f(trunkNW_x, trunkNW_y);
		glVertex2f(topSW_x, topSW_y);
	glColor3f(.925, .345, 0);
		glVertex2f(topNW_x, topNW_y);
		glVertex2f(topNE_x, topNE_y);
	glColor3f(.76, .296, .09);
		glVertex2f(trunkNE_x, trunkNE_y);
	glColor3f(.265, .149, .352);
		glVertex2f(trunkSE_x, trunkSE_y);
		glVertex2f(trunkSW_x, trunkSW_y);
	glEnd();
	
	glBegin(GL_TRIANGLES);
	glColor3f(.925, .345, 0);
		glVertex2f(topNE_x, topNE_y);
	glColor3f(0.76, .296, .09);
		glVertex2f(topSE_x, topSE_y);
		glVertex2f(trunkNE_x, trunkNE_y);
	glEnd();
	
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(.265, .149, .352);
		glVertex2f(botNW_x, botNW_y);
	glColor3f(.1, .1, .44);
		glVertex2f(botSW_x, botSW_y);
	glColor3f(.265, .149, .352);
		glVertex2f(trunkSW_x, trunkSW_y);
	glColor3f(.1, .1, .44);
		glVertex2f(botSE_x, botSE_y);
	glColor3f(.265, .149, .352);
		glVertex2f(trunkSE_x, trunkSE_y);
		glVertex2f(botNE_x, botNE_y);
	glEnd();
	
	// draw borders of I's mesh triangles
	if (outlines) {
		glLineWidth(4.0);
		glBegin(GL_LINE_STRIP);
		glColor3f(0, 0, 0);
		glVertex2f(topNW_x, topNW_y);
		glVertex2f(trunkNW_x, trunkNW_y);
		glVertex2f(topSW_x, topSW_y);
		glVertex2f(topNW_x, topNW_y);
		glVertex2f(topNE_x, topNE_y);
		glVertex2f(topSE_x, topSE_y);
		glVertex2f(trunkNE_x, trunkNE_y);
		glVertex2f(topNE_x, topNE_y);
		glVertex2f(trunkNW_x, trunkNW_y);
		glVertex2f(trunkNE_x, trunkNE_y);
		glVertex2f(trunkSE_x, trunkSE_y);
		glVertex2f(botNE_x, botNE_y);
		glVertex2f(botSE_x, botSE_y);
		glVertex2f(trunkSW_x, trunkSW_y);
		glVertex2f(trunkNW_x, trunkNW_y);
		glVertex2f(trunkSE_x, trunkSE_y);
		glVertex2f(botSE_x, botSE_y);
		glVertex2f(botSW_x, botSW_y);
		glVertex2f(trunkSW_x, trunkSW_y);
		glVertex2f(botNW_x, botNW_y);
		glVertex2f(botSW_x, botSW_y); 
		glEnd();
		
		glBegin(GL_LINES);
		glVertex2f(trunkSW_x, trunkSW_y);
		glVertex2f(trunkSE_x, trunkSE_y);
		glEnd();
	}
}

/* Does not work. May be revisited.
void drawBackground() {	
	unsigned char * data;
	data = (unsigned char*) malloc(512*512*3);
	FILE * fp = fopen("img.bmp", "r");
	fread(data, 1, 512*512*3, fp);
	fclose(fp);
	
	GLuint textureid;
	
	glGenTextures(1, &textureid);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureid);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, 4, 512, 512, 0, GL_BGR, GL_UNSIGNED_BYTE, data);	

	int w = glutGet(GLUT_WINDOW_WIDTH) * 4;
	int h = glutGet(GLUT_WINDOW_HEIGHT) * 4;
	
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-4.5, -2.25, 0.0);
	glTexCoord2f(1, 0.0);
	glVertex3f(4.5, -2.25, 0.0);
	glTexCoord2f(1, 1);
	glVertex3f(4.5, 2.25, 0.0);
	glTexCoord2f(0.0, 1);
	glVertex3f(-4.5, 2.25, 0.0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	//free(data);
	//glEnable(GL_DEPTH_TEST);
}
*/

void display(void) {		
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	
	glMatrixMode(GL_MODELVIEW);	// reset OpenGL transformation matrix
	glLoadIdentity();			// reset transformation matrix to identity
	
	// set view
	// eye is at : (0,0,3)
	// look at center is at : (0,0,0)
	// up direction is +y axis
	gluLookAt(0.f,0.f,3.f,0.f,0.f,0.f,0.f,1.f,0.f);

	drawDancingI();

	glFlush();
	glutSwapBuffers();	// swap front/back framebuffer to avoid flickering 
}

void reshape (int w, int h) {
	// reset viewport (drawing screen) size
	//glViewport(0, 0, w, h);

	// reset OpenGL projection matrix
	float fAspect = ((float) w) / h; 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(70.f, fAspect, 0.001f, 15.f);
}

void keyboard(unsigned char key, int x, int y) {
	if (key == 27) 
		exit(0); // ESC hit, so quit
}
				 
void timer(int v) {
	glutPostRedisplay();				// trigger display function again
	glutTimerFunc(30000/FPS,timer,v);	// restart timer again
}

// check if argument is 0 or 1
int validArg(char* arg) {
	if (arg == NULL)
		return 0;
	
	int argint = atoi(arg);
	if (argint == 0 || argint == 1)
		return 1;
	
	return 0;
}

int main(int argc, char** argv) {
	
	glutInit(&argc, (char**)argv);

	// set up for double-buffering & RGB color buffer & depth test
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	
	// option to provide arguments for dancing and outlines
	if (validArg(argv[1])) {
		dancing = atoi(argv[1]);
		if (validArg(argv[2]))
			outlines = atoi(argv[2]);
		else {
			printf("Usage: ./barril_mp1 <dancing> <outlines> ");
			printf("where dancing = 0|1 and outlines = 0|1\n");
			exit(1);
		}
	}
	
	// set up window
	glutInitWindowSize (1000, 500); 
	glutInitWindowPosition (100, 100);
	glutCreateWindow ((const char*) "Dancing I");
	
	glClearColor(1, 1, 1, 1.0); // set background color

	// set up the call-back functions 
	glutDisplayFunc(display);  // called when drawing 
	glutReshapeFunc(reshape);  // called when change window size
	glutKeyboardFunc(keyboard); // called when received keyboard interaction
	glutTimerFunc(100, timer, FPS); // a periodic timer. Usually used for updating animation
	
	glutMainLoop(); // start the main callback loop
	
	return 0;
}
