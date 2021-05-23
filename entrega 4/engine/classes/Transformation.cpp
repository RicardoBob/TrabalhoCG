//
// Created by ricardo on 30/04/21.
//

#include "../headers/Transformation.h"
#include <GL/glew.h>

#include <iostream>
#include "../headers/catmull.h"

using namespace std;

Transformation :: Transformation(){ translate = Translate(); rotate = Rotate(); scale = Scale(); }
Transformation :: Transformation(Translate t, Rotate r, Scale s){ translate = t; rotate = r; scale = s;}
void Transformation :: setTranslate(Translate t){ translate = t; }
void Transformation :: setRotate(Rotate r){ rotate = r; }
void Transformation :: setScale(Scale s){ scale = s; }
Translate Transformation :: getTranslate(){ return translate; }
Rotate Transformation :: getRotate(){ return rotate; }
Scale Transformation :: getScale(){ return scale; }
void Transformation ::apply(bool render){

    float time = (glutGet(GLUT_ELAPSED_TIME))/((float) 1000);

    if (translate.getTime() != 0.0f){

        float pos[4];
        float deriv[4];
        float X[4];
        float Y[4] = {0,1,0};
        float Z[4];

        if(render){drawOrbita(translate.getOrbita());}


        float gt = ((translate.getCurve().size())+time)/translate.getTime();


        getGlobalCatmullRomPoint(gt, pos, deriv, translate.getCurve());




        //cout  << pos[0]  << pos[1]<<pos[2] << endl;

        glTranslatef(pos[0],pos[1],pos[2]);

        X[0] = deriv[0]; X[1] = deriv[1]; X[2] = deriv[2]; X[3] = deriv[3];
        normalize(X);
        cross(X, Y, Z);

        // normalize ZZ and get YY
        normalize(Z);
        cross(Z, X, Y);

        // normalize YY and up = YY
        normalize(Y);
        //memcpy(up, Y, 3 * sizeof(float));

        // build rotation matrix
        float m[4][4];
        buildRotMatrix(X, Y, Z, (float*)m);
        glMultMatrixf((float*)m);

        if(rotate.getTime() == 0.0) {
            glRotatef(rotate.getAngle(), rotate.getX(), rotate.getY(), rotate.getZ());
        }
        else{
            glRotatef((time/rotate.getTime())*360, rotate.getX(), rotate.getY(), rotate.getZ());
        }
    }
    else {

        glTranslatef(translate.getX(),translate.getY(),translate.getZ());

        if(rotate.getTime() == 0.0) {
            glRotatef(rotate.getAngle(), rotate.getX(), rotate.getY(), rotate.getZ());
        }
        else{
            glRotatef((time/rotate.getTime())*360, rotate.getX(), rotate.getY(), rotate.getZ());
        }
    }

    glScalef(scale.getX(),scale.getY(),scale.getZ());

}

