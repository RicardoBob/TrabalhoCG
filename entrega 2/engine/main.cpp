#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <stdlib.h>
#include <GL/glut.h>
#endif

#ifndef XMLCheckResult
#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Erraor: %i\n", a_eResult); return a_eResult; }
#endif
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <tuple>
#include "tinyxml2-master/tinyxml2.h"
#include "classes.h"


using namespace tinyxml2;
using namespace std;

#define ESCAPE 27
//---------TREE----------
typedef struct node{
    Group* g;
    string label;
    vector<struct node*> next;
} *Tree;

//------------VARIAVEIS GLOBAIS--------------
vector<string> files;
vector< vector<float> > vertex;
Tree classTree;
int ngroup = 0;

//-----------------CAMERA--------------------
bool warp = false;
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

/*
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
        while((file,linha)) {
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
 */

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
        float fps = frames * 1000.0 / (time - timebase);
        timebase = time;
        frames = 0;
        string str = to_string(fps);
        const char *c = str.c_str();
        glutSetWindowTitle(c);
    }

    // End of frame
    glutSwapBuffers();
}


void groupParser(XMLElement *grupo, Tree parentNode){
    //inicializar vars
    grupo = grupo->FirstChildElement();

    float x,y,z,angulo = 0.0f;
    string file = "";

    while (grupo != nullptr){
        //translate
        if(strcmp(grupo->Value(),"translate") == 0){
            if(grupo->Attribute("X")){
                grupo->QueryFloatAttribute("X",&x);
            }
            if(grupo->Attribute("Y")){
                grupo->QueryFloatAttribute("Y",&y);
            }
            if(grupo->Attribute("Z")) {
                grupo->QueryFloatAttribute("Z", &z);
            }

            Tree aux = new struct node;
            aux->g = new Translate(x,y,z);
            aux->label = "translate";
            aux->next.clear();
            parentNode->next.push_back(aux);
            printf("translate\n");
        }

        //scale
        if(strcmp(grupo->Value(),"scale") == 0){
            if(grupo->Attribute("X")){
                grupo->QueryFloatAttribute("X",&x);
            }
            if(grupo->Attribute("Y")){
                grupo->QueryFloatAttribute("Y",&y);
            }
            if(grupo->Attribute("Z")){
                grupo->QueryFloatAttribute("Z",&z);
            }
            Tree aux = new struct node;
            aux->g = new Scale(x,y,z);
            aux->label = "scale";
            aux->next.clear();
            parentNode->next.push_back(aux);
            printf("scale\n");
        }

        //rotate
        if(strcmp(grupo->Value(),"rotate") == 0){
            if(grupo->Attribute("X")){
                grupo->QueryFloatAttribute("X",&x);
            }
            if(grupo->Attribute("Y")){
                grupo->QueryFloatAttribute("Y",&y);
            }
            if(grupo->Attribute("Z")){
                grupo->QueryFloatAttribute("Z",&z);
            }
            if(grupo->Attribute("angle")){
                grupo->QueryFloatAttribute("angle",&angulo);
            }
            Tree aux = new struct node;
            aux->g = new Rotate(x,y,z,angulo);
            aux->label = "rotate";
            aux->next.clear();
            parentNode->next.push_back(aux);
            printf("rotate\n");
        }

        //Modelos
        if(strcmp(grupo->Value(),"models") == 0){
            XMLElement* modelos = grupo->FirstChildElement("model");
            while(modelos != nullptr){
                const char *nome = modelos->Attribute("file");
                if(nome != nullptr){
                    file = string(nome);
                }
                Tree aux = new struct node;
                aux->g = new Model(file);
                aux->label = "model";
                aux->next.clear();
                parentNode->next.push_back(aux);
                modelos = modelos->NextSiblingElement();
                printf("modelo\n");
            }
        }

        //Subgrupos
        if(strcmp(grupo->Value(),"group") == 0){
            //inicializar a subarvore do grupo para ser adicionada na arvore de classes
            Tree subTree = new struct node;
            subTree->g = new Group(ngroup++);
            subTree->label = "group";
            subTree->next.clear();
            groupParser(grupo, subTree);
            parentNode->next.push_back(subTree);
        }
        grupo = grupo->NextSiblingElement();
    }
}

int readXML(){
    //
    //init XML
    XMLDocument config ;
    XMLError eResult = config.LoadFile("config.xml");
    XMLCheckResult(eResult);
    //Buscar a root do XML
    XMLNode * pRoot = config.FirstChildElement("scene");
    if (pRoot == nullptr) {
        return -1;
    }
    //inicializar a arvore de classes
    classTree = new struct node;
    classTree->g = new Group(ngroup++);
    classTree->label = "root";
    classTree->next.clear();

    //Procurar o primeiro group
    XMLElement *grupo = pRoot->FirstChildElement("group");
    if (grupo == nullptr) return -1;

    //Percorrer o grupos e adicionar à arvore de classes
    while (grupo != nullptr) {
        printf("grupo\n");
        //inicializar a subarvore do grupo para ser adicionada na arvore de classes
        Tree subTree = new struct node;
        subTree->g = new Group(ngroup++);
        subTree->label = "group";
        subTree->next.clear();
        groupParser(grupo,subTree);
        classTree->next.push_back(subTree);
        grupo = grupo->NextSiblingElement();
    }
    return 1;
}


int readTree(Tree tree,string str){
    if(tree == nullptr){ return -1;}
    string interval = "     ";
    printf("%s%s\n",str.c_str(),tree->label.c_str());
    for(node *n : tree->next){
        if(strcmp(n->label.c_str(),"group") == 0){
            string nova = "";
            nova.append(interval);
            nova.append(str);
            nova.append("1");
            readTree(n,nova);
        }
        if(strcmp(n->label.c_str(),"translate") == 0){
            printf("%s%s\n",(interval+str+"1").c_str(),n->label.c_str());
        }
        if(strcmp(n->label.c_str(),"rotate") == 0){
            printf("%s%s\n",(interval+str+"1").c_str(),n->label.c_str());
        }
        if(strcmp(n->label.c_str(),"scale") == 0){
            printf("%s%s\n",(interval+str+"1").c_str(),n->label.c_str());
        }
        if(strcmp(n->label.c_str(),"model") == 0){
            printf("%s%s\n",(interval+str+"1").c_str(),n->label.c_str());
        }
    }
    return 1;
}

int main(int argc, char **argv) {
    //ler
    readXML();
    string bruh = "";
    readTree(classTree,bruh);

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
