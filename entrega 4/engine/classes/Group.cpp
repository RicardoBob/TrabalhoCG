//
// Created by ricardo on 30/04/21.
//

#include "../headers/Group.h"
#include <string>


using namespace std;
Group :: Group() { transformation = Transformation(); file = vector<string>(); maxX = 0.0f;maxZ = 0.0f;numAst = 0;}
Group :: Group(Transformation t,vector<string> f,float maX ,float maZ ,int nAst ) { transformation = t; file = f; maxX = maX;maxZ = maZ, numAst = nAst; }
void Group :: setTransformation(Transformation t) { this->transformation = t;}
void Group :: setFile(vector<string> f) { this->file = f; }
Transformation Group :: getTransformation() { return this->transformation;}
vector<string> Group :: getFile(){ return this->file; };
void Group :: setAsteroides(float maX ,float maZ ,int nAst){ this->numAst = nAst; this->maxX = maX; this->maxZ = maZ;}
int Group :: getNumAst(){return this->numAst;}
float Group :: getmaxX(){return this->maxX;}
float Group :: getmaxZ(){return this->maxZ;}
