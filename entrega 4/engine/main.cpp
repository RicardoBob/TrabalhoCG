#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glew.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <IL/il.h>
#endif

#ifndef XMLCheckResult
#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <iterator>
#include <sstream>
#include <vector>
#include <tuple>
#include "tinyxml2-master/tinyxml2.h"
#include "headers/Group.h"
#include "headers/catmull.h"


using namespace tinyxml2;
using namespace std;



#define ESCAPE 27
//---------TREE----------
typedef struct node{
    Group* g;
    vector<struct node*> next;
} *Tree;

//file struct
typedef struct ficheiro{
    string name;
    GLuint indexp;
    GLuint indexn;
    GLuint indext;
    GLuint size;
} *File;

//------------VARIAVEIS GLOBAIS--------------
vector<File> Vbos;
Tree classTree;
int iread ;
bool render = true;
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
        case GLUT_KEY_F2:
            render = !render;
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
    float x,y,z; // ponto
    float tx,ty; // textura
    float nx,ny,nz; // normal
    string linha;

    File vbo = new struct ficheiro;
    vbo->name = file;
    vector<float> vertexp;

    vector<float> vertexn;

    vector<float> vertext;

    vertexp.clear();
    vertexn.clear();
    vertext.clear();

    while(getline(f,linha)) {
        istringstream in(linha);
        in >> x;
        in >> y;
        in >> z;
        in >> nx;
        in >> ny;
        in >> nz;
        in >> tx;
        in >> ty;

        vertexp.push_back(x);
        vertexp.push_back(y);
        vertexp.push_back(z);

        vertexn.push_back(nx);
        vertexn.push_back(ny);
        vertexn.push_back(nz);

        vertext.push_back(tx);
        vertext.push_back(ty);

    }
    vbo->size = vertexp.size()/3;
    f.close();
    Vbos.push_back(vbo);

    //criar vbo
    glGenBuffers(1,&(vbo->indexp));
    //copiar vbo para a grafica
    glBindBuffer(GL_ARRAY_BUFFER,vbo->indexp);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertexp.size(), vertexp.data(),GL_STATIC_DRAW);

    /*
    //criar vbo
    glGenBuffers(1,&(vbo->indexn));
    //copiar vbo para a grafica
    glBindBuffer(GL_ARRAY_BUFFER,vbo->indexn);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertexn.size(), vertexn.data(),GL_STATIC_DRAW);

    //criar vbo
    glGenBuffers(1,&(vbo->indext));
    //copiar vbo para a grafica
    glBindBuffer(GL_ARRAY_BUFFER,vbo->indext);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertext.size(), vertext.data(),GL_STATIC_DRAW);
    */
    return vbo;

}

vector<GLuint> buildOrbita(vector<float> vertices){
    float pos[4];
    float deriv[4];
    float gt = 0;
    vector<float> vertex;
    vector<vector<float>> pontos;
    for(int i = 0;i < vertices.size();i+=3){
        vector<float> aux;
        aux.push_back(vertices[i]);
        aux.push_back(vertices[i+1]);
        aux.push_back(vertices[i+2]);
        pontos.push_back(aux);
    }
    for (int i = 0; i < 100; i++) {
        getGlobalCatmullRomPoint(gt, pos, deriv, pontos);
        vertex.push_back(pos[0]);
        vertex.push_back(pos[1]);
        vertex.push_back(pos[2]);
        gt += 0.01;
    }

    GLuint res0;
    GLuint res1;
    res1 = vertex.size()/3;

    glGenBuffers(1,&res0);
    glBindBuffer(GL_ARRAY_BUFFER,res0);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertex.size(), vertex.data(),GL_STATIC_DRAW);

    vector<GLuint> vbo;
    vbo.push_back(res0);
    vbo.push_back(res1);
    return vbo;
}



void groupParser(XMLElement *grupo, Tree parentNode){
    //inicializar vars
    grupo = grupo->FirstChildElement();
    Group* g = new Group();

    Translate trans = Translate();
    Rotate rot = Rotate();
    Scale sca = Scale();
    vector<string> ficheiros;

    int numAsteroides = 0;

    float maxX = 0.0f;

    float maxZ = 0.0f;

    vector<float> color;
    color.push_back(-1.0f);
    color.push_back(-1.0f);
    color.push_back(-1.0f);

    vector<vector<float>> colors;
    vector<GLuint> pvbo;
    vector<GLuint> nvbo;
    vector<GLuint> tvbo;
    vector<GLuint> size;
    vector<string> tex;
    //
    while (grupo != nullptr){
        float x = 0.0f;
        float y = 0.0f;
        float z = 0.0f;
        float angulo = 0.0f;
        float timeTran = 0.0f;
        float timeRot = 0.0f;

        string file = "";

        //Asteroides
        if(strcmp(grupo->Value(),"asteroide") == 0){
            if(grupo->Attribute("num")){
                grupo->QueryIntAttribute("num",&numAsteroides);
            }
            if(grupo->Attribute("maxX")){
                grupo->QueryFloatAttribute("maxX",&maxX);
            }
            if(grupo->Attribute("maxZ")) {
                grupo->QueryFloatAttribute("maxZ", &maxZ);
            }

        }



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
            if(grupo->Attribute("time")) {

                vector<float> vertices;
                grupo->QueryFloatAttribute("time", &timeTran);
                XMLElement* ponto = grupo->FirstChildElement("point");
                while(ponto != nullptr){
                    if(ponto->Attribute("X")){
                        ponto->QueryFloatAttribute("X",&x);
                    }
                    if(ponto->Attribute("Y")){
                        ponto->QueryFloatAttribute("Y",&y);
                    }
                    if(ponto->Attribute("Z")) {
                        ponto->QueryFloatAttribute("Z", &z);
                    }
                    vertices.push_back(x);
                    vertices.push_back(y);
                    vertices.push_back(z);

                    ponto = ponto->NextSiblingElement();
                }

                trans.setTime(timeTran);
                trans.setCurve(vertices);
                vector<GLuint> orbita;
                orbita = buildOrbita(vertices);
                trans.setOrbita(orbita[0]);
                trans.setSize(orbita[1]);
            }
            trans.setX(x);
            trans.setY(y);
            trans.setZ(z);
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
            sca.setX(x);
            sca.setY(y);
            sca.setZ(z);
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

            if(grupo->Attribute("time")){
                grupo->QueryFloatAttribute("time",&timeRot);
            }

            rot.setX(x);
            rot.setY(y);
            rot.setZ(z);
            rot.setTime(timeRot);
            rot.setAngle(angulo);
        }

        //Modelos
        string bababui = grupo->Value();
        if(strcmp(grupo->Value(),"models") == 0){
            XMLElement* modelos = grupo->FirstChildElement();
            while(modelos != nullptr){
                const char *texture = "";
                color[0] = -1.0f;
                color[1] = -1.0f;
                color[2] = -1.0f;
                if(modelos->Attribute("file")) {
                    const char *nome = modelos->Attribute("file");
                    int flag = 0;
                    File aux;
                    if (nome != nullptr) {
                        for(File f : Vbos){
                            if(strcmp(f->name.c_str(),nome) == 0){
                                flag = 1;
                                aux = f;
                                break;
                            }
                        }
                        if (flag == 0){
                            aux = readFile(nome);
                        }
                        pvbo.push_back(aux->indexp);
                        nvbo.push_back(aux->indexn);
                        tvbo.push_back(aux->indext);
                        size.push_back(aux->size);
                    }
                }
                if(modelos->Attribute("texture")){
                    texture = modelos->Attribute("texture");
                }
                if(modelos->Attribute("diffR")){
                    modelos->QueryFloatAttribute("diffR",&color[0]);
                }
                if(modelos->Attribute("diffG")){
                    modelos->QueryFloatAttribute("diffG",&color[1]);
                }
                if(modelos->Attribute("diffB")){
                    modelos->QueryFloatAttribute("diffB",&color[2]);
                }
                colors.push_back(color);
                tex.push_back(texture);
                modelos = modelos->NextSiblingElement();
            }
        }


        //Subgrupos
        if(strcmp(grupo->Value(),"group") == 0){
            //inicializar a subarvore do grupo para ser adicionada na arvore de classes

            Tree subTree = new struct node;
            subTree->next.clear();
            groupParser(grupo, subTree);
            parentNode->next.push_back(subTree);
        }
        grupo = grupo->NextSiblingElement();
    }
    g->setAsteroides(maxX,maxZ,numAsteroides);
    Transformation transformation = Transformation(trans,rot,sca);
    g->setTransformation(transformation);
    g->setSize(size);
    g->setnVbos(nvbo);
    g->setpVbos(pvbo);
    g->settVbos(tvbo);
    g->setTextures(tex);
    g->setColors(colors);
    parentNode->g = g;
}


int readXML(){
    //
    //init XML
    XMLDocument config ;
    XMLError eResult = config.LoadFile("config.xml");
    XMLCheckResult(eResult);

    classTree = new struct node;
    classTree->g = new Group();
    classTree->next.clear();

    //Procurar o primeiro group
    XMLElement *grupo = config.FirstChildElement("scene");
    if (grupo == nullptr) {
        return -1;
    }

    while (grupo != nullptr) {
        //inicializar a subarvore do grupo para ser adicionada na arvore de classes
        Tree subTree = new struct node;
        subTree->next.clear();
        groupParser(grupo,subTree);
        classTree->next.push_back(subTree);

        grupo = grupo->NextSiblingElement();

    }
    return 1;
}


void drawAsteroides(int asteroides, float maxX, float maxZ, node *pNode) {

    map<float,float> pontos;

    int flagPonto = 1;
    srand(5151);
    float r ,xf,zf,alpha;
    for(int i = 0; i<=asteroides;i++ ){



        r = sqrt(rand()) / RAND_MAX;
        alpha = rand() * 2 * M_PI / RAND_MAX;

        xf = cos(alpha) * (r+ maxX);
        zf = sin(alpha) * (r+ maxZ);


        // 1 caso não exista overlap de asteroides & 0 caso exista
        for (auto itr : pontos) {
            float fst= itr.first;
            float snd = itr.second;
            float dst = (fst-xf) - (snd-zf); //guarda a dist. entre as asteroides
            if(fabs(dst) < 8.0f){
                flagPonto = 0;
                }else
                {
                    flagPonto = 1;
                }
            }

            if (fabs(xf) < r + maxX*7 && fabs(zf) < r + maxZ*8 && flagPonto ) {
                glPushMatrix();
                glTranslatef(xf,0.0f,zf);
                glRotatef(90,0.0f,0.0f,1.0f);


            for (int j = 0; j < pNode->g->getpVbos().size(); j++){

                glBindBuffer(GL_ARRAY_BUFFER, pNode->g->getpVbos()[j]);
                glVertexPointer(3, GL_FLOAT, 0, 0);
                glDrawArrays(GL_TRIANGLES, 0, pNode->g->getSize()[j]);

            }

            glPopMatrix();
            cout << xf <<" "<< zf << endl;
            pontos.insert(pair<float,float>(xf,zf));
        }
    }

}

int readTree(Tree tree){
    if(tree == nullptr){ return -1;}

    for(node *n : tree->next) {
        glPushMatrix();

        //Detetar que é um grupo de asteroides
        if(n->g->getNumAst() != 0){
            //
            n->g->getTransformation().apply(render);
            int numAsteroides = n->g->getNumAst();
            float maxX = n->g->getmaxX();
            float maxZ = n->g->getmaxZ();
            drawAsteroides(numAsteroides, maxX, maxZ, n);
        }
        else{
            n->g->getTransformation().apply(render);

            for (int i = 0; i < n->g->getpVbos().size(); i++){

                glBindBuffer(GL_ARRAY_BUFFER, n->g->getpVbos()[i]);
                glVertexPointer(3, GL_FLOAT, 0, 0);

                //glBindBuffer(GL_ARRAY_BUFFER, n->g->getnVbos()[i]);
                //glVertexPointer(3, GL_FLOAT, 0, 0);
                glDrawArrays(GL_TRIANGLES, 0, n->g->getSize()[i]);
            }
        }
        readTree(n);
        glPopMatrix();
    }
    return 1;
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
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    // put drawing instructions here

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
    //cout << Vbos.size() << endl;
    // End of frame
    glutSwapBuffers();

}


int main(int argc, char **argv) {
    //ler

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
    glEnable(GL_NORMALIZE);
    glShadeModel (GL_SMOOTH);
    glEnableClientState(GL_VERTEX_ARRAY);

    readXML();

// enter GLUT's main cycle
    glutMainLoop();

    return 1;
}
