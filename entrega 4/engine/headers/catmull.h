#include <string>
#include <GL/glew.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <vector>

#ifndef ENGINE_CATMULL_H
#define ENGINE_CATMULL_H

using namespace std;

void buildRotMatrix(float *x, float *y, float *z, float *m);
void cross(float *a, float *b, float *res);
void normalize(float *a);
float length(float *v);
void multMatrixVector(float *m, float *v, float *res);
void getCatmullRomPoint(float t, vector<vector<float>>vecP,  float* pos, float* deriv);
void getGlobalCatmullRomPoint(float gt, float* pos, float* deriv, vector<vector<float>> pontosControlo);
void renderCatmullRomCurve(vector<vector<float>> PontosControlo);
void drawOrbita(GLuint index,GLuint size);

#endif //ENGINE_CATMULL_H