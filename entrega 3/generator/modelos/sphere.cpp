//
// Created by igor1 on 27/04/2021.
//

#include "modelos.h"

using namespace std;

void sphere(float radius, int slices, int stacks) {

    ofstream fileSphere("sphere.3d", ios::trunc );

    float stackStep = M_PI / stacks;
    float sliceStep = 2 * M_PI / slices;

    float alpha = 0.0f; 		//latitude  0 <= alpha < 360
    float betha = M_PI / 2;		//longitude pi/2 <= betha <= -pi/2

    float p1x = 0.0f;
    float p1y = 0.0f;
    float p1z = 0.0f;

    float p2x = 0.0f;
    float p2y = 0.0f;
    float p2z = 0.0f;

    float p3x = 0.0f;
    float p3y = radius * sin(betha);
    float p3z = 0.0f;

    float p4x = 0.0f;
    float p4y = 0.0f;
    float p4z = 0.0f;

    //1� -> 2� stack temos setores triangulares:
    //    p3		---------- 1 stack (topo)
    //   /  \
	// p1 -- p2		---------- 2 stack

    betha -= stackStep;

    for (int j = 0; j < slices; j++) {
        alpha = j * sliceStep;

        p1x = radius * cos(betha) * sin(alpha);
        p1y = radius * sin(betha);
        p1z = radius * cos(betha) * cos(alpha);

        p2x = radius * cos(betha) * sin(alpha + sliceStep);
        p2y = radius * sin(betha);
        p2z = radius * cos(betha) * cos(alpha + sliceStep);

        fileSphere << p1x << " " << p1y << " " << p1z << endl;
        fileSphere << p2x << " " << p2y << " " << p2z << endl;
        fileSphere << p3x << " " << p3y << " " << p3z << endl;

    }

    // para o resto da esfera temos setores da forma de um trapezio:
    // p3 -- p4
    //  |  / |
    //  | /  |
    // p1 -- p2

    // dividido em 2 triangulos (p1,p2,p4) e (p1,p4,p3)

    for (int i = 1; i < stacks - 1; i++) {  //n�o chegar a ultima stack (igual ao caso da 1� stack)

        alpha = 0.0f;
        betha = M_PI / 2 - i * stackStep;

        for (int j = 0; j < slices; j++) {
            alpha = j * sliceStep;

            p3x = radius * cos(betha) * sin(alpha);
            p3y = radius * sin(betha);
            p3z = radius * cos(betha) * cos(alpha);

            p4x = radius * cos(betha) * sin(alpha + sliceStep);
            p4y = radius * sin(betha);
            p4z = radius * cos(betha) * cos(alpha + sliceStep);

            p2x = radius * cos(betha - stackStep) * sin(alpha + sliceStep);
            p2y = radius * sin(betha - stackStep);
            p2z = radius * cos(betha - stackStep) * cos(alpha + sliceStep);

            p1x = radius * cos(betha - stackStep) * sin(alpha);
            p1y = radius * sin(betha - stackStep);
            p1z = radius * cos(betha - stackStep) * cos(alpha);

            fileSphere << p1x << " " << p1y << " " << p1z << endl;
            fileSphere << p2x << " " << p2y << " " << p2z << endl;
            fileSphere << p4x << " " << p4y << " " << p4z << endl;

            fileSphere << p1x << " " << p1y << " " << p1z << endl;
            fileSphere << p4x << " " << p4y << " " << p4z << endl;
            fileSphere << p3x << " " << p3y << " " << p3z << endl;

        }
    }

    //nas ultimas duas stacks temos setores triangulares:
    //  p1 -- p2  	---------- n-1 stack
    //   \    /
    // 	   p3		---------- n stack (bottom)
    betha = M_PI / 2 - (stacks - 1)*stackStep;

    p3x = 0.0f;
    p3y = radius * sin(betha - stackStep);
    p3z = 0.0f;
    \
	for (int j = 0; j < slices; j++) {
        alpha = j * sliceStep;

        p1x = radius * cos(betha) * sin(alpha);
        p1y = radius * sin(betha);
        p1z = radius * cos(betha) * cos(alpha);

        p2x = radius * cos(betha) * sin(alpha + sliceStep);
        p2y = radius * sin(betha);
        p2z = radius * cos(betha) * cos(alpha + sliceStep);

        fileSphere << p1x << " " << p1y << " " << p1z << endl;
        fileSphere << p3x << " " << p3y << " " << p3z << endl;
        fileSphere << p2x << " " << p2y << " " << p2z << endl;

    }

    fileSphere.close();
}