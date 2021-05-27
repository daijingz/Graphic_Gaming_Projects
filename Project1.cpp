// Name: Jingze Dai
// Assumption 1£º For the displayed graph, it has background color white.

#include <iostream>
#include "gl/glut.h"
using namespace std;

// Vertex Array Includes x, y and z coordinates of a point in 3D system
typedef GLfloat vertex3 [3];
// Vertex list of different shapes £¨Body cube, Ground rectangle, Top pyramid£©
vertex3 Cube[8] = {{0,0,0}, {0,1,0}, {1,0,0}, {1,1,0}, {0,0,1}, {0,1,1}, {1,0,1}, {1,1,1}};
vertex3 Rect[4] = {{-1.0f, 0.0f, -0.5f}, {2.0f, 0.0f, 2.5f}, {-1.0f, 0.0f, 2.5f}, {2.0f, 0.0f, -0.5f}};
vertex3 Pyramid[5] = {{0.5f, 1.5f, 0.5f}, {-0.2f, 1.0f, -0.2f}, {-0.2f, 1.0f, 1.2f}, {1.2f, 1.0f, -0.2f}, {1.2f, 1.0f, 1.2f}};

// Initialize Function
void initialize() {
	// Set background color: White
	glClearColor(1.0, 1.0, 1.0, 0.0);
}

// Produce a 3D matrix system
void showMatrix() {
	GLdouble m[16];
	glGetDoublev(GL_MODELVIEW, m);
	for (int i=0; i<4; i++) {
		cout << m[i*4] << " " << m[i*4+1] << " " << m[i*4+2] << " " << m[i*4+3] << endl;
	}
	cout << endl;
}

// Use provided 3d coordinates to draw a Cube in coordinate system for Body() Function
void Quad (GLint n1, GLint n2, GLint n3, GLint n4) {
	glBegin (GL_LINE_LOOP);
		glVertex3fv(Cube[n1]);
		glVertex3fv(Cube[n2]);
		glVertex3fv(Cube[n3]);
		glVertex3fv(Cube[n4]);
	glEnd();
}

// Use provided 3d coordinates to draw a Rectangle in coordinate system for Ground() Function
void Ground_Rect (GLint n1, GLint n2, GLint n3, GLint n4) {
	glBegin (GL_LINE_LOOP);
		glVertex3fv(Rect[n1]);
		glVertex3fv(Rect[n2]);
		glVertex3fv(Rect[n3]);
		glVertex3fv(Rect[n4]);
	glEnd();
}

// Use provided 3d coordinates to draw a pyramid in coordinate system for Top() Function
void Top_Tri (GLint n1, GLint n2, GLint n3) {
	glBegin (GL_LINE_LOOP);
		glVertex3fv(Pyramid[n1]);
		glVertex3fv(Pyramid[n2]);
		glVertex3fv(Pyramid[n3]);
	glEnd();
}

// Ground() method draws big ground rectangle 
void Ground(){
	glColor3f(0.0, 1.0, 0.0); // Ground rectangle color is green
	Ground_Rect(0,3,1,2); // Calling method to draw ground rectangle
}

//Body() method draws body cube
void Body(){
	glColor3f(1.0, 0.0, 0.0); // Body cube line color is red
	Quad(4,0,2,6); // Drawing rectangles to form a cube
	Quad(7,5,4,6);
	Quad(6,2,3,7);
	Quad(5,1,0,4);
	Quad(2,0,1,3);
	Quad(7,3,1,5);
}

// Top() method draws top pyramid
void Top(){
	glColor3f(0.0, 0.0, 1.0); // Top pyramid line color is blue
	Top_Tri(0,1,2); // Drawing triangles to form a pyramid
	Top_Tri(0,2,4);
	Top_Tri(0,4,3);
	Top_Tri(0,3,1);
}

void render(){
	Ground(); // Render (draw) Ground big rectangle
	Body(); // Render (draw) Body cube
	Top(); // Render (draw) Top triangle
}

// Display method
void display(void){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear all OpenGL color and depth buffers

	glLoadIdentity(); // Make sure the current matrix is identity matrix

	gluLookAt(2.0, 2.0, 6.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); // Determines location and angle of observation on screen

	render(); // Call render() method to draw different shapes

	glutSwapBuffers(); // Swaps the buffers of the current window if double buffered
}

// Reshape method
void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei) w, (GLsizei) h); // Set the view port

	glMatrixMode(GL_PROJECTION); // Applies subsequent matrix operations to the projection

	glLoadIdentity(); // Replaces the current matrix with the identity matrix

	glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 40.0); // Describes a perspective matrix that produces a perspective projection

	glMatrixMode(GL_MODELVIEW); // Applies subsequent matrix operations to the modelview matrix stack
}

// Main Program
void main(int argc, char **argv){
	glutInit( &argc, argv ); // Initialize GLUT library to be ready to use all GLUT methods

	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // Display using modes

	glutInitWindowSize(500, 500); // Ensure displaying windows size

  	glutInitWindowPosition(100, 100); // Ensure displaying windows location at screen

	int windowHandle = glutCreateWindow("C++ OpenGL Program 1"); // Create a displaying window with given title

	glutSetWindow(windowHandle); // Set the current window

	glutDisplayFunc(display); // Run Display Function

	glutReshapeFunc(reshape); // Run Reshape Function

	initialize(); // Run initialize function and initialize background issues

	glutMainLoop(); // Enter GLUT main loop
}
