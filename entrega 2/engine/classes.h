//
// Created by ricardo on 29/03/21.
//

#ifndef MAIN_CPP_CLASSES_H
#define MAIN_CPP_CLASSES_H

#endif //MAIN_CPP_CLASSES_H

#include <string>

using namespace std;

class Group {
public: // Access specifier
    Group();
    Group(int a);
    void setId(int a);
    int getId();
};

class Translate : public Group{
public:
    Translate();
    Translate(float x, float y, float z);
    void setX(float a);
    void setY(float a);
    void setZ(float a);
    float getX();
    float getY();
    float getZ();
};

class Scale : public Group{
public:
    Scale();
    Scale(float x, float y, float z);
    void setX(float a);
    void setY(float a);
    void setZ(float a);
    float getX();
    float getY();
    float getZ();
};

class Rotate : public Group{
public:
    Rotate();
    Rotate(float x, float y, float z, float angle);
    void setX(float a);
    void setY(float a);
    void setZ(float a);
    void setAngle(int a);
    float getX();
    float getY();
    float getZ();
    float getAngle();
};

class Model : public Group{
public:
    Model();
    Model(string file);
    void setFile(string a);
    string getFile();
};
