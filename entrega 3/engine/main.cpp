#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glew.h>
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
#include "matrizes.h"


using namespace tinyxml2;
using namespace std;



#define ESCAPE 27
//---------TREE----------
typedef struct node{
    Group* g;
    string label;
    vector<struct node*> next;
} *Tree;

//file struct
typedef struct ficheiro{
    string name;
    vector<float> vertex;
    GLuint index,size;
} *File;

//------------VARIAVEIS GLOBAIS--------------
vector<File> Vbos;
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
float speed = 0.8;
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



File readFile(string file){
    ifstream f("../../generator/cmake-build-debug/" + file);
    float x,y,z;
    string linha;
    File vbo = new struct ficheiro;
    vbo->name = file;
    vbo->vertex.clear();

    while(getline(f,linha)) {
        istringstream in(linha);
        in >> x;
        in >> y;
        in >> z;

        vbo->vertex.push_back(x);
        vbo->vertex.push_back(y);
        vbo->vertex.push_back(z);
    }
    vbo->size = vbo->vertex.size()/3;
    f.close();
    Vbos.push_back(vbo);

    //criar vbo
    glGenBuffers(1,&(vbo->index));


    //copiar vbo para a grafica
    glBindBuffer(GL_ARRAY_BUFFER,vbo->index);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * (vbo->vertex).size(), vbo->vertex.data(),GL_STATIC_DRAW);


    return vbo;
}

//Catmull
float camX = 0, camY, camZ = 5;
int startX, startY, tracking = 0;

int alpha = 0, beta = 0, r = 5;

#define POINT_COUNT 5
// Points that make up the loop for catmull-rom interpolation
float p[POINT_COUNT][3] = {{-1,-1,0},{-1,1,0},{1,1,0},{0,0,0},{1,-1,0}};

void buildRotMatrix(float *x, float *y, float *z, float *m) {

    m[0] = x[0]; m[1] = x[1]; m[2] = x[2]; m[3] = 0;
    m[4] = y[0]; m[5] = y[1]; m[6] = y[2]; m[7] = 0;
    m[8] = z[0]; m[9] = z[1]; m[10] = z[2]; m[11] = 0;
    m[12] = 0; m[13] = 0; m[14] = 0; m[15] = 1;
}


void cross(float *a, float *b, float *res) {

    res[0] = a[1]*b[2] - a[2]*b[1];
    res[1] = a[2]*b[0] - a[0]*b[2];
    res[2] = a[0]*b[1] - a[1]*b[0];
}


void normalize(float *a) {

    float l = sqrt(a[0]*a[0] + a[1] * a[1] + a[2] * a[2]);
    a[0] = a[0]/l;
    a[1] = a[1]/l;
    a[2] = a[2]/l;
}


float length(float *v) {

    float res = sqrt(v[0]*v[0] + v[1]*v[1] + v[2]*v[2]);
    return res;

}

void multMatrixVector(float *m, float *v, float *res) {

    for (int j = 0; j < 4; ++j) {
        res[j] = 0;
        for (int k = 0; k < 4; ++k) {
            res[j] += v[k] * m[j * 4 + k];
        }
    }

}

//t = tessellation (?) , vecP = vector de pontos de translacao
void getCatmullRomPoint(float t, vector<vector<float>>vecP, vector<float> *pos, vector<float> *deriv) {

    // catmull-rom matrix
    Matriz catmull = Matriz::MatrizCatmull();

    // compute A = M * P
    Matriz P =  Matriz(4,3);
    P.adicionaColunas(vecP);
    Matriz A = catmull * P;

    // compute pos = T * A;
    vector<float> tempT = {t*t*t, t*t, t,1};
    Matriz tempTMatriz = Matriz(1,4);
    tempTMatriz.adicionaColuna(tempT,0);
    *pos = (tempTMatriz*A).getLinV(0);

    // compute deriv = T' * A

    vector<float> tempTDeriv = {3*t*t, 2*t, 1,0};
    Matriz tempTMatrizDeriv = Matriz(4,1);
    tempTMatriz.adicionaLinha(tempTDeriv,0);
    *deriv = (tempTMatrizDeriv*A).getLinV(0);

}


// given  global t, returns the point in the curve
void getGlobalCatmullRomPoint(float gt, vector<float> *pos, vector<float> *deriv, vector<float> pontosControlo) {

    int nPontos = pontosControlo.size();
    float t = gt * nPontos; // this is the real global t
    int index = floor(t);  // which segment
    t = t - index; // where within  the segment

    // indices store the points
    int indices[4];
    indices[0] = (index + nPontos-1)%nPontos;
    indices[1] = (indices[0]+1)%nPontos;
    indices[2] = (indices[1]+1)%nPontos;
    indices[3] = (indices[2]+1)%nPontos;

    vector<vector<float>>vecP;
    vector<float>vecPAux;
    for (int i = 0; i<4;i++ ){
        vecPAux.push_back(pontosControlo[indices[i]]);
        vecP.push_back(vecPAux);
        vecPAux.clear();
    }

    getCatmullRomPoint(t,vecP, pos, deriv);
}

void renderCatmullRomCurve(vector<float> PontosControlo) {

// draw curve using line segments with GL_LINE_LOOP
    vector <float> *pos = new vector<float>(3);
    vector <float> *deriv = new vector<float>(3);

    float gt = 0;

    glDisable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glBegin(GL_LINE_LOOP);

    for (int i = 0; i < 100; i++) {
        getGlobalCatmullRomPoint(gt, pos, deriv, PontosControlo);
        glVertex3f(pos->at(0), pos->at(1), pos->at(2));
        gt += 0.01;
    }
    glEnd();
    glEnable(GL_LIGHTING);

}

//Para desenhar orbitas saber o num de grupos??


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

void groupParser(XMLElement *grupo, Tree parentNode){
    //inicializar vars
    grupo = grupo->FirstChildElement();

    while (grupo != nullptr){
        float x = 0.0f;
        float y = 0.0f;
        float z = 0.0f;
        float angulo = 0.0f;
        string file = "";

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


int readTree(Tree tree){
    if(tree == nullptr){ return -1;}
    for(node *n : tree->next){
        if(strcmp(n->label.c_str(),"group") == 0){
            glPushMatrix();
            readTree(n);
            glPopMatrix();
        }
        if(strcmp(n->label.c_str(),"translate") == 0){
            (n->g)->apply();
        }
        if(strcmp(n->label.c_str(),"rotate") == 0){
            (n->g)->apply();
        }
        if(strcmp(n->label.c_str(),"scale") == 0){
            (n->g)->apply();
        }

        if(strcmp(n->label.c_str(),"model") == 0){
            int flag = 0;
            File aux;
            for(File vbo : Vbos){
                if(strcmp((dynamic_cast<Model*>(n->g))->getFile().c_str(),vbo->name.c_str()) == 0) {
                    aux = vbo;
                    flag = 1;
                    break;
                }
            }

            if (flag == 0){
                aux = readFile((dynamic_cast<Model*>(n->g))->getFile());
                Vbos.push_back(aux);
            }

            glBindBuffer(GL_ARRAY_BUFFER,aux->index);
            glVertexPointer(3,GL_FLOAT,0,0);
            glDrawArrays(GL_TRIANGLES,0,aux->size);

        }
    }
    return 1;
}


void renderScene() {

    static float t = 0;
    float pos[3], deriv[3];
    // clear buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // set the camera
    glLoadIdentity();
    gluLookAt(xc, yc, zc,
              xc + lx, yc + ly, zc + lz,
              0, 1, 0);

    // put the geometric transformations here
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    // put drawing instructions here

    renderCatmullRomCurve(pontosControlo do XML)

    glPushMatrix();
        getGlobalCatmullRomPoint(t,pos,deriv,pontosControlo);
        glTranslatef(pos[0],pos[1],pos[2]);
        glScalef(0.5,0.5, 0.5);
        glutWireTeapot(1);
    glPopMatrix();


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

    readTree(classTree);
    // End of frame
    glutSwapBuffers();
    //Usar o contador de frames para tempo tmb?
    t+=0.01;

}


int main(int argc, char **argv) {
    //ler
    readXML();

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
    glewInit();
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glEnableClientState(GL_VERTEX_ARRAY);

// enter GLUT's main cycle
    glutMainLoop();

    return 1;
}
