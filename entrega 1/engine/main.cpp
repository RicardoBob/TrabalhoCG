#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <stdlib.h>
#include <GL/glut.h>
#endif


#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "tinyxml2/tinyxml2.h"

using namespace tinyxml2;
using namespace std;

#define ESCAPE 27

//----------------------- VARIAVEIS GLOBAIS
std::vector<float> vertex;
std::vector<string> files;

//-------CAMERA ----------
// angle of rotation for the camera direction
float angle = 0;
float angle1 = -5000;
// actual vector representing the camera's direction
float lx = 0;
float ly = 0;
float lz = 1;
// XZ position of the camera
float xc = 0;
float yc = 0;
float zc = 10;
float speed = 0.1;
float rotSpeed = 0.0005;

int window;
//---------FPS
int timebase;
float frames;
//------ XML

XMLDocument config;
XMLError eResult = config.LoadFile("config.xml");



//-----------------------------------

void changeSize(int w, int h) {

    // Prevent a divide by zero, when window is too short
    // (you cant make a window with zero width).
    if(h == 0)
        h = 1;

    // compute window's aspect ratio
    float ratio = w * 1.0 / h;

    // Set the projection matrix as current
    glMatrixMode(GL_PROJECTION);
    // Load Identity Matrix
    glLoadIdentity();

    // Set the viewport to be the entire window
    glViewport(0, 0, w, h);

    // Set perspective
    gluPerspective(45.0f ,ratio, 1.0f ,1000.0f);

    // return to the model view matrix mode
    glMatrixMode(GL_MODELVIEW);
}

void processNormalKeys(unsigned char key, int x, int y){
    if (key == ESCAPE)
    {
        glutDestroyWindow(window);
        exit(0);
    }
}
bool mouseCaptured = true;

void processSpecialKeys(int key, int x, int y){
    switch (key) {
        case GLUT_KEY_UP:
            xc += lx * speed;
            yc += ly * speed;
            zc += lz * speed;
            break;
        case GLUT_KEY_DOWN:
            xc -= lx * speed;
            yc -= ly * speed;
            zc -= lz * speed;
            break;
        case GLUT_KEY_LEFT:
            xc += lz * speed;
            zc -= lx * speed;
            break;
        case GLUT_KEY_RIGHT:
            xc -= lz * speed;
            zc += lx * speed;
            break;
        case GLUT_KEY_F1:
            mouseCaptured = !mouseCaptured;
            if (mouseCaptured)
            {
                glutSetCursor(GLUT_CURSOR_NONE);
            }
            else
            {
                glutSetCursor(GLUT_CURSOR_INHERIT);
            }
            break;
        default:
            break;
    }
}

bool warping = false;

void mouseMove(int x, int y){
    if (warping)
    {
        warping = false;
        return;
    }
    int dx = x - 100;
    int dy = y - 100;
    angle = angle + dx * rotSpeed;
    angle1 = angle1 + dy * rotSpeed;
    lx = sin(angle1)*sin(angle);
    ly = -cos(angle1);
    lz = -sin(angle1)*cos(angle);
    if (mouseCaptured)
    {
        warping = true;
        glutWarpPointer(100, 100);
    }
}


void drawFromFile() {
    glBegin(GL_TRIANGLES);
    for(int i = 0; i<vertex.size(); i+=3){
        glColor3f(1.0f,0.5f,0.0f);
        glVertex3f(vertex[i],vertex[i+1],vertex[i+2]);
    }
    glEnd();
}

void readFile(){
    float x,y,z;
    for(string i : files){
        ifstream file(i);
        file >> x;
        file >> y;
        file >> z;

        vertex.push_back(x);
        vertex.push_back(y);
        vertex.push_back(z);
    }
}

void drawEixos(){
    glBegin(GL_LINES);
        // X axis in red
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(-100.0f, 0.0f, 0.0f);
        glVertex3f(100.0f, 0.0f, 0.0f);
        // Y Axis in Green
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f(0.0f,-100.0f, 0.0f);
        glVertex3f(0.0f, 100.0f, 0.0f);
        // Z Axis in Blue
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f(0.0f, 0.0f,-100.0f);
        glVertex3f(0.0f, 0.0f, 100.0f);
    glEnd();
}


void renderScene() {

    // clear buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // set the camera
    glLoadIdentity();
    gluLookAt(xc, yc, zc,
              xc + lx, yc + ly, zc + lz,
              0, 1, 0);

    // put the geometric transformations here


    // put drawing instructions here

    //loop que percorre lista de ficheiros no xml e corre Parser de XML?
    //

    drawEixos();

    //------------FPS

    frames++;

    int time = glutGet(GLUT_ELAPSED_TIME);
    if (time - timebase > 1000) {
        float fps = (frames * 1000.0) / (time - timebase);
        timebase = time;
        frames = 0;
        std::string str = std::to_string(fps);
        const char *c = str.c_str();
        glutSetWindowTitle(c);
    }
    //-------------
    drawFromFile();

    // End of frame
    glutSwapBuffers();
}

void readXML(){
    
}


// write function to process keyboard events






int main(int argc, char **argv) {
    //ler

    readFile();
    timebase = glutGet(GLUT_ELAPSED_TIME);

// init GLUT and the window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(800,800);
    window = glutCreateWindow("CG@DI-UM");

// Required callback registry
    glutDisplayFunc(renderScene);
    glutIdleFunc(renderScene);
    glutReshapeFunc(changeSize);
    glutSpecialFunc(processSpecialKeys);
    glutPassiveMotionFunc(mouseMove);



// put here the registration of the keyboard callback


//  OpenGL settings
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

// enter GLUT's main cycle
    glutMainLoop();

    return 1;
}
