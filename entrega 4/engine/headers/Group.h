//
// Created by ricardo on 30/04/21.
//

#ifndef ENGINE_GROUP_H
#define ENGINE_GROUP_H

#include <string>
#include <GL/glew.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <vector>
#include "Transformation.h"

using namespace std;

class Group {
private:
    Transformation transformation;
    vector<GLuint> pVbos;
    vector<GLuint> size;
    vector<GLuint> nVbos;
    vector<GLuint> tVbos;
    vector<GLuint> textures;
    float maxX;
    float maxZ;
    int numAst;
    vector<vector<float>> colors;
public:
    Group();
    Group(Transformation t,vector<GLuint> pvb,vector<GLuint> nvb ,vector<GLuint> tvb,vector<GLuint> texture,float maX ,float maZ ,int nAst);
    void setTransformation(Transformation t);
    Transformation getTransformation();
    void setAsteroides(float maX, float maZ, int nAst);
    int getNumAst();
    float getmaxX();
    float getmaxZ();
    void setpVbos(vector<GLuint> p);
    void setnVbos(vector<GLuint> n);
    void settVbos(vector<GLuint> t);
    void setSize(vector<GLuint> s);
    void setTextures(vector<GLuint> t);

    void setColors(vector<vector<float>> c);
    vector<GLuint> getpVbos();
    vector<GLuint> getnVbos();
    vector<GLuint> gettVbos();
    vector<GLuint> getSize();
    vector<GLuint> getTextures();
    vector<vector<float>> getColors();
};

#endif //ENGINE_GROUP_H
