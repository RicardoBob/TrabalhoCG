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
    vector<string> file;
public:
    Group();
    Group(Transformation t,vector<string> f);
    void setTransformation(Transformation t);
    void setFile(vector<string> file);
    Transformation getTransformation();
    vector<string> getFile();
};

#endif //ENGINE_GROUP_H
