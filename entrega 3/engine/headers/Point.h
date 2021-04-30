 //
// Created by ricardo on 30/04/21.
//

#ifndef ENGINE_POINT_H
#define ENGINE_POINT_H

#include <string>
#include <GL/glew.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <vector>

using namespace std;

class Point {
private:
    float x,y,z;
public:
    Point();
    Point(float x, float y, float z);
    float getX();
    float getY();
    float getZ();
    void setX(float x);
    void setY(float y);
    void setZ(float z);
};

class Translate : public Point{
private:
    float time;
    vector<float> curve{};
public:
    Translate();
    Translate(float x, float y, float z);
    Translate(float x, float y, float z, float time, vector<float> curve);

    void setTime(float a);
    void setCurve(vector<float> curve);

    float getTime();
    vector<float> getCurve();
};

class Scale : public Point{
public:
    Scale();
    Scale(float x, float y, float z);
};

class Rotate : public Point{
private:
    float angle;
    float time;
public:
    Rotate();
    Rotate(float x, float y, float z, float angle, float t);
    void setAngle(float a);
    void setTime(float t);
    float getAngle();
    float getTime();
};

#endif //ENGINE_POINT_H
