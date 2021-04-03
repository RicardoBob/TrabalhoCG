//
// Created by ricardo on 29/03/21.
//

#ifndef MAIN_CPP_CLASSES_H
#define MAIN_CPP_CLASSES_H

#endif //MAIN_CPP_CLASSES_H

#include <string>
#include <GL/glew.h>
#include <stdlib.h>
#include <GL/glut.h>
using namespace std;

class Group {
    private:
        int id;
    public:
        Group();
        Group(int a);
        void setId(int a);
        int getId();
        virtual void apply();
};

class Translate : public Group{
    private:
        float x,y,z;
    public:
        Translate();
        Translate(float x, float y, float z);
        void setX(float a);
        void setY(float a);
        void setZ(float a);
        float getX();
        float getY();
        float getZ();
        void apply();
};

class Scale : public Group{
    private:
        float x,y,z;
    public:
        Scale();
        Scale(float x, float y, float z);
        void setX(float a);
        void setY(float a);
        void setZ(float a);
        float getX();
        float getY();
        float getZ();
        void apply();
};

class Rotate : public Group{
    private:
        float x,y,z,angle;
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
        void apply();
};

class Model : public Group{
    private:
        string file;
    public:
        Model();
        Model(string file);
        void setFile(string a);
        string getFile();
        void apply();
};
