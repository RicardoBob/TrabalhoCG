//
// Created by ricardo on 30/04/21.
//

#include "../headers/Group.h"
#include <string>


using namespace std;
Group :: Group() { transformation = Transformation(); pVbos = vector<GLuint>();nVbos = vector<GLuint>();tVbos = vector<GLuint>();textures = vector<string>() ; maxX = 0.0f;maxZ = 0.0f;numAst = 0;}
Group::Group(Transformation t, vector<GLuint> pvb, vector<GLuint> nvb, vector<GLuint> tvb, vector<string> texture, float maX, float maZ, int nAst)

{ transformation = t; pVbos = pvb;nVbos = nvb; tVbos = tvb;textures = texture; maxX = maX;maxZ = maZ, numAst = nAst; }
void Group :: setTransformation(Transformation t) { this->transformation = t;}
Transformation Group :: getTransformation() { return this->transformation;}

void Group:: setpVbos(vector<GLuint> p){ this->pVbos = p;}
void Group::setnVbos(vector<GLuint> n){this->nVbos = n;}
void Group::settVbos(vector<GLuint> t){this->tVbos = t;}
void Group::setTextures(vector<string> t){this->textures = t;}
void Group::setColors(vector<vector<float>> c) {this->colors = c;}
vector<GLuint> Group ::  getpVbos(){return this->pVbos;}
vector<GLuint>Group ::  getnVbos(){return this->nVbos;}
vector<GLuint> Group :: gettVbos(){return this->tVbos;}
vector<string> Group :: getTextures(){return this->textures;}
void Group:: setSize(vector<GLuint> s){ this->size = s;}
vector<GLuint> Group :: getSize(){return this->size;}
vector<vector<float>> Group ::getColors() {return this->colors;}


void Group :: setAsteroides(float maX ,float maZ ,int nAst){ this->numAst = nAst; this->maxX = maX; this->maxZ = maZ;}
int Group :: getNumAst(){return this->numAst;}
float Group :: getmaxX(){return this->maxX;}
float Group :: getmaxZ(){return this->maxZ;}

