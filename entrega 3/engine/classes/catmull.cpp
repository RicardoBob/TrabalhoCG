#include "../headers/matrizes.h"
#include <GL/glew.h>
#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>


//Catmull

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

//t = tessellation , vecP = vector de pontos de translacao
void getCatmullRomPoint(float t, vector<vector<float>>vecP, float *pos, float *deriv) {

    // catmull-rom matrix
    Matriz catmull = Matriz::MatrizCatmull();

    // compute A = M * P
    Matriz P =  Matriz(4,3);
    P.adicionaColunas(vecP);
    Matriz A = catmull * P;

    // compute pos = T * A;
    vector<float> vpos;
    vector<float> tempT = {t*t*t, t*t, t,1};
    Matriz tempTMatriz = Matriz(1,4);
    tempTMatriz.adicionaColuna(tempT,0);
    vpos = (tempTMatriz*A).getLinV(0);
    for (int i = 0; i<4; i++){
        pos[i] = vpos[i];
    }

    // compute deriv = T' * A
    vector<float> vderiv;
    vector<float> tempTDeriv = {3*t*t, 2*t, 1,0};
    Matriz tempTMatrizDeriv = Matriz(4,1);
    tempTMatriz.adicionaLinha(tempTDeriv,0);
    vderiv = (tempTMatrizDeriv*A).getLinV(0);
    for (int i = 0; i<4; i++){
        deriv[i] = vderiv[i];
    }

}


// given  global t, returns the Point in the curve
void getGlobalCatmullRomPoint(float gt, float *pos, float *deriv, vector<float> pontosControlo) {

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
    float pos[3];
    float deriv[3];

    float gt = 0;

    glDisable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glBegin(GL_LINE_LOOP);
        for (int i = 0; i < 100; i++) {
            getGlobalCatmullRomPoint(gt, pos, deriv, PontosControlo);
            glVertex3f(pos[0], pos[1],pos[2]);
            gt += 0.01;
        }
    glEnd();
    glEnable(GL_LIGHTING);

}


/*
void draw(){
    static float time = 0;
    float pos[3], deriv[3];
    renderCatmullRomCurve(pontosControlo do XML)

    glPushMatrix();
    getGlobalCatmullRomPoint(time,pos,deriv,pontosControlo);
    glTranslatef(pos[0],pos[1],pos[2]);
    glScalef(0.5,0.5, 0.5);
    glutWireTeapot(1);
    glPopMatrix();
///////----
    void Translate :: apply(){
    if(time == 0) {
        glTranslatef(x, y, z);
    }
    else{
        float tempo = glutGet(GLUT_ELAPSED_TIME)/time;
        float pos[3];
        float deriv[3];
        renderCatmullRomCurve(curve);
        getGlobalCatmullRomPoint(tempo,pos,deriv,curve);
        glTranslatef(pos[0],pos[1],pos[2]);
    }
}

}
 */