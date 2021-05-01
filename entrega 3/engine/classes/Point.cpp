//
// Created by ricardo on 30/04/21.
//

#include "../headers/Point.h"
#include <vector>
#include <iostream>

using namespace std;

Point :: Point(){ x = 0.0f ;y =0.0f ; z = 0.0f; }
Point ::Point(float x1, float y1, float z1) { x = x1 ; y = y1; z = z1; }
float Point ::getX(){return x ;}
float Point ::getY(){return y;}
float Point ::getZ(){return z;}
void Point ::setX(float x1){ this->x = x1; }
void Point ::setY(float y1){ this->y = y1; }
void Point ::setZ(float z1){ this->z = z1; }


Translate :: Translate() : Point() { time = 0.0f; curve = vector<float>(); }
Translate :: Translate(float x, float y, float z, float time, vector<float> curva ) : Point(x,y,z) { setTime(time); setCurve(curva);}
Translate :: Translate(float x, float y, float z){ setX(x); setY(y); setZ(z); setTime(0.0f); curve = vector<float>(); }
void Translate :: setTime(float a){ time = a; }
void Translate :: setCurve(vector<float>curva){ curve = curva; }
float Translate :: getTime(){ return time; }
vector<vector<float>> Translate :: getCurve(){

    vector<vector<float>> curva;

    for(int i = 0 ; i < (curve.size()/3) ;i++  ){ //i entre 0 e 4
        vector<float> vaux;
        for (int j = 0; j <3 ; j++){ //j entre 0 e 3
            float aux = curve.at((i*3)+j);
            vaux.push_back(aux);
        }
        curva.push_back(vaux);
        vaux.clear();
    }
    return curva;
}


Scale :: Scale() : Point(1,1,1) {}
Scale :: Scale(float x, float y, float z) : Point(x,y,z){}


Rotate :: Rotate() : Point() {angle = 0.0f; time = 0.0f;}
Rotate :: Rotate(float x, float y, float z, float angle, float t) : Point(x,y,z) { setAngle(angle); setTime(t); }
void Rotate :: setAngle(float a){ angle = a; }
void Rotate ::setTime(float t) {time = t;}
float Rotate ::getTime() {return this->time;}
float Rotate :: getAngle(){ return this->angle; }

