//
// Created by ricardo on 30/04/21.
//

#ifndef ENGINE_TRANSFORMATION_H
#define ENGINE_TRANSFORMATION_H

#include <string>
#include <GL/glew.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <vector>
#include "Point.h"

using namespace std;

class Transformation {
private:
    Translate translate;
    Rotate rotate;
    Scale scale;
public:
    Transformation();
    Transformation(Translate t, Rotate r, Scale s);
    void setTranslate(Translate t);
    void setRotate(Rotate r);
    void setScale(Scale s);
    Translate getTranslate();
    Rotate getRotate();
    Scale getScale();
    void apply(bool render);
};

#endif //ENGINE_TRANSFORMATION_H


