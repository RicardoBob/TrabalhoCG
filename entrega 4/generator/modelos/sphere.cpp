#include "modelos.h"
#include <vector>

using namespace std;

void sphere(float radius, int slices, int stacks) {

    ofstream fileSphere("sphere.3d", ios::trunc );

    float stackStep = (float) M_PI / stacks;
    float sliceStep = 2 * (float) M_PI / slices;

    float alpha = 0.0f;         //latitude  0 <= alpha < 360
    float betha = (float) M_PI / 2;        //longitude pi/2 <= betha <= -pi/2

    float p1x;
    float p1y;
    float p1z;

    float p2x;
    float p2y;
    float p2z;

    float p3x;
    float p3y;
    float p3z;

    float p4x;
    float p4y;
    float p4z;

    vector<float> textura, normais;

    float textureX;
    float textureY;

    // p3 -- p4
    //  |  / |
    //  | /  |
    // p1 -- p2

    // dividido em 2 triangulos (p1,p2,p4) e (p1,p4,p3)

    for (int i = 0; i < stacks ; i++) {

        alpha = 0.0f;
        betha = (float) M_PI / 2 - i * stackStep;

        textureY = ((float)i/(float)stacks);

        for (int j = 0; j < slices; j++) {

            textureX = (float) j / (float) slices;

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

            // vertice
            // normal
            // textura

            fileSphere << p1x << " " << p1y << " " << p1z << " "  << p1x/radius << " " << p1y/radius << " " << p1z/radius << " "<<(asin( p1x/radius) /(float)M_PI) + 0.5  << " " << (asin(p1y/radius) /(float)M_PI) + 0.5 << " "  << endl;

            fileSphere << p2x << " " << p2y << " " << p2z  << " "<< p2x/radius << " " << p2y/radius << " " << p2z/radius << " "  <<  (asin( p2x/radius) /(float)M_PI) + 0.5 << " " << (asin(p2y/radius) /(float)M_PI) + 0.5 << " "  << endl;

            fileSphere << p4x << " " << p4y << " " << p4z << " " << p4x/radius << " " << p4y/radius << " " << p4z/radius << " "  << (asin( p4x/radius) /(float)M_PI) + 0.5 << " " << (asin(p4y/radius) /(float)M_PI) + 0.5 << " "  << endl;



            fileSphere << p1x << " " << p1y << " " << p1z << " "  << p1x/radius << " " << p1y/radius << " " << p1z/radius << " "<< (asin(p1x/radius) /(float) M_PI) + 0.5  << " " << (asin(p1y/radius) /(float)M_PI) + 0.5 << " "  << endl;

            fileSphere << p4x << " " << p4y << " " << p4z << " " << p4x/radius << " " << p4y/radius << " " << p4z/radius << " "  << (asin(p4x/radius) /(float) M_PI) + 0.5 << " " << (asin(p4y/radius) /(float)M_PI) + 0.5<< " "  << endl;

            fileSphere << p3x << " " << p3y << " " << p3z << " " << p3x/radius << " " << p3y/radius << " " << p3z/radius << " " << (asin(p3x/radius) / (float) M_PI) + 0.5 << " " << (asin(p3y/radius) /(float)M_PI) + 0.5<< " " << endl;


        }
    }

    fileSphere.close();
}
