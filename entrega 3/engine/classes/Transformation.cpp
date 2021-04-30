//
// Created by ricardo on 30/04/21.
//

#include "../headers/Transformation.h"
#include <GL/glew.h>
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
void Transformation ::apply(){
    float time = (glutGet(GLUT_ELAPSED_TIME))/((float) 1000);

    if (translate.getTime() != 0.0f){
        float pos[3];
        float deriv[3];
        float gt = (translate.getCurve().size()+time)/translate.getTime();
        renderCatmullRomCurve(translate.getCurve());
        getGlobalCatmullRomPoint(gt,pos,deriv,translate.getCurve());
        glTranslatef(pos[0],pos[1],pos[2]);
    }
    else {
        glTranslatef(translate.getX(),translate.getY(),translate.getZ());
    }

    if(rotate.getTime() == 0.0) {
        glRotatef(rotate.getAngle(), rotate.getX(), rotate.getY(), rotate.getZ());
    }
    else{
        glRotatef((time/rotate.getTime())*360, rotate.getX(), rotate.getY(), rotate.getZ());
    }

    glScalef(scale.getX(),scale.getY(),scale.getZ());
}

/*
        int pointer =i*grupos[i].getVertices().size()/3;

        //Desenhar os corpos com os vbos e texturas
        glBindBuffer(GL_ARRAY_BUFFER,verticesVBO[0]);
        glVertexPointer(3,GL_FLOAT,0,0);

        glBindBuffer(GL_ARRAY_BUFFER,normaisVBO[0]);
        glNormalPointer(GL_FLOAT,0,0);

        glBindTexture(GL_TEXTURE_2D, idsTextura[i]);
        glBindBuffer(GL_ARRAY_BUFFER,texturaVBO[0]);
        glTexCoordPointer(2,GL_FLOAT,0,0);

        glDrawArrays(GL_TRIANGLES,pointer,grupos[i].getVertices().size()*3);
        glBindTexture(GL_TEXTURE_2D, 0);

        glPopMatrix();

    }
}
 */

