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
#include "tinyxml2-master/tinyxml2.h"

using namespace tinyxml2;
using namespace std;

#define ESCAPE 27

//----------------------- VARIAVEIS GLOBAIS
std::vector<float> vertex;
std::vector<string> files;

//-------CAMERA ----------
//angulo da rotacao para a direcao da camera
float angle = 0;
float angle1 = -5000;
//vetor que representa a direcao da camera
float lx = 0;
float ly = 0;
float lz = 1;
// posicao XZ da camera
float xc = 0;
float yc = 0;
float zc = 10;
//velocidade da camera
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

//Para sair da janela
void processNormalKeys(unsigned char key, int x, int y){
    if (key == ESCAPE)
    {
        glutDestroyWindow(window);
        exit(0);
    }
}
bool mouseCaptured = true; //se o rato esta dentro da janela

void processSpecialKeys(int key, int x, int y){ //andar com a camera
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

bool warp = false;

void mouseMove(int x, int y){
    if (warp)
    {
        warp = false;
        return;
    }
    int dx = x - 100; //reset no x
    int dy = y - 100; //reset no y
    angle = angle + dx * rotSpeed;
    angle1 = angle1 + dy * rotSpeed;
    lx = sin(angle1)*sin(angle);
    ly = -cos(angle1);
    lz = -sin(angle1)*cos(angle);
    if (mouseCaptured)
    {
        warp = true;
        glutWarpPointer(100, 100); //colar o rato numa posicao para nao sair
    }
}


void drawFromFile() { //desenhar a partir do vetor
    glBegin(GL_TRIANGLES);
    for(int i = 0; i<vertex.size(); i+=3){
        glColor3f(1.0f,0.5f,0.0f);
        glVertex3f(vertex[i],vertex[i+1],vertex[i+2]);
    }
    glEnd();
}

void readFile(){
    float x,y,z;
    string linha;
    for(string i : files){
        ifstream file("../../generator/cmake-build-debug/" + i); //pathing relativo
        while(std::getline(file,linha)) {
            istringstream in(linha);
            in >> x;
            in >> y;
            in >> z;

            vertex.push_back(x);
            vertex.push_back(y);
            vertex.push_back(z);
        }
        file.close();
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

int readXML(){
    //Buscar a root do XML
    XMLNode * pRoot = config.FirstChildElement("model");
    if (pRoot == nullptr) return -1;
    //Buscar o primeiro elemento da root
    XMLElement *element = pRoot->FirstChildElement("path");
    if (element == nullptr) return -1;
    //Buscar em loop o resto dos elementos e guardar em vector
    while (element != nullptr){
        std::string path = element->GetText();
        files.push_back(path);
        element = element->NextSiblingElement("path");
    }
    return 1;
}


int main(int argc, char **argv) {
    //ler
    int readOk = readXML();
    if (readOk == -1) return -1;
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

// put here the registration of the keyboard callback
    glutSpecialFunc(processSpecialKeys);
    glutPassiveMotionFunc(mouseMove);

//  OpenGL settings
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

// enter GLUT's main cycle
    glutMainLoop();

    return 1;
}
