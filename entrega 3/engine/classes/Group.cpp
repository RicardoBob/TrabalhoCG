//
// Created by ricardo on 30/04/21.
//

#include "../headers/Group.h"
#include <string>


using namespace std;
Group :: Group() { transformation = Transformation(); file = vector<string>(); }
Group :: Group(Transformation t,vector<string> f) { transformation = t; file = f; }
void Group :: setTransformation(Transformation t) { this->transformation = t;}
void Group :: setFile(vector<string> f) { this->file = f; }
Transformation Group :: getTransformation() { return this->transformation;}
vector<string> Group :: getFile(){ return this->file; };

