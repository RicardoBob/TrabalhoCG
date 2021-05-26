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
    vector<GLuint> pVbosSize;
    vector<GLuint> nVbos;
    vector<GLuint> nVbosSize;
    vector<GLuint> tVbos;
    vector<GLuint> tVbosSize;
    vector<string> textures;
    float maxX;
    float maxZ;
    int numAst;
public:
    Group();
    Group(Transformation t,vector<GLuint> pvb,vector<GLuint> nvb ,vector<GLuint> tvb,vector<string> texture,float maX ,float maZ ,int nAst);
    void setTransformation(Transformation t);
    Transformation getTransformation();
    void setAsteroides(float maX, float maZ, int nAst);
    int getNumAst();
    float getmaxX();
    float getmaxZ();
    void setpVbos(vector<GLuint> p);
    void setnVbos(vector<GLuint> n);
    void settVbos(vector<GLuint> t);
    void setpVbosSize(vector<GLuint> p);
    void setnVbosSize(vector<GLuint> n);
    void settVbosSize(vector<GLuint> t);
    void setTextures(vector<string> t);
    vector<GLuint> getpVbos();
    vector<GLuint> getnVbos();
    vector<GLuint> gettVbos();
    vector<GLuint> getpVbosSize();
    vector<GLuint> getnVbosSize();
    vector<GLuint> gettVbosSize();
    vector<string> getTextures();
};

#endif //ENGINE_GROUP_H
