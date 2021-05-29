//
// Created by igor1 on 27/04/2021.
//

#include "modelos.h"

using namespace std;

void cone(float radius, float height, int slices, int stacks) {
    float ang = 2 * M_PI / (float)slices;

    ofstream fileCone("cone.3d");
    float texturaX;
    float texturaY;

    //base
    for (int i = 0; i <= slices; i++) {
        float angulo = i * ang;

        fileCone << (sin(angulo) * radius) << ' ' << (0.0f) << ' ' << (cos(angulo) * radius) << " " << (sin(angulo) * radius) / radius << " " << -(1.0f) << " " << (cos(angulo) * radius) / radius << " " << endl;
        fileCone << (0.0f) << ' ' << (0.0f) << ' ' << (0.0f) << " " << (0.0f) << " " << -(1.0f) << " " << (0.0f) << " " << endl;
        fileCone << (sin(ang + angulo) * radius) << ' ' << (0.0f) << ' ' << (cos(ang + angulo) * radius) << " " << (sin(ang + angulo) * radius) / radius << " " << -(1.0f) << " " << (cos(ang + angulo) * radius) / radius << " " << endl;
    }

    //superfice do cone
    float tanalfa = radius / height;


    for (int j = 0; j < stacks; j++) {
        float hcima = (j + 1) * (height / stacks);
        float hbaixo = j * (height / stacks);

        float radiuscima = (height - hcima) * tanalfa;
        float radiusbaixo = (height - hbaixo) * tanalfa;

        if (j != stacks - 1) {
            for (int i = 0; i <= slices; i++) {
                float angulo = i * ang;

                // Triangulo base em cima
                fileCone << (sin(ang + angulo) * radiusbaixo) << ' ' << (hbaixo) << ' ' << (cos(ang + angulo) * radiusbaixo) << (sin(ang + angulo) * radiusbaixo) / radiusbaixo << " " << (hbaixo) / radiusbaixo << " " << (cos(ang + angulo) * radiusbaixo) / radiusbaixo << " " << endl;
                fileCone << (sin(ang + angulo) * radiuscima) << ' ' << (hcima) << ' ' << (cos(ang + angulo) * radiuscima) << " " << (sin(ang + angulo) * radiuscima) / radiuscima << " " << (hcima)/radiuscima << (cos(ang + angulo) * radiuscima) / radiuscima << " " << endl;
                fileCone << (sin(angulo) * radiuscima) << ' ' << (hcima) << ' ' << (cos(angulo) * radiuscima) << " " << (sin(angulo) * radiuscima) / radiuscima << " " << (hcima) / radiuscima << " " << (cos(angulo) * radiuscima) / radiuscima << " " << endl;

                // Triangulo base em baixo
                fileCone << (sin(ang + angulo) * radiusbaixo) << ' ' << (hbaixo) << ' ' << (cos(ang + angulo) * radiusbaixo) << " " << (sin(ang + angulo) * radiusbaixo) / radiusbaixo << " " << (hbaixo) / radiusbaixo << " " << (cos(ang + angulo) * radiusbaixo) / radiusbaixo << " " << endl;
                fileCone << (sin(angulo) * radiuscima) << ' ' << (hcima) << ' ' << (cos(angulo) * radiuscima) << " " << (sin(angulo) * radiuscima) / radiuscima << " " << (hcima) / radiuscima << " " << (cos(angulo) * radiuscima) / radiuscima << " " << endl;
                fileCone << (sin(angulo) * radiusbaixo) << ' ' << (hbaixo) << ' ' << (cos(angulo) * radiusbaixo) << " " << (sin(angulo) * radiusbaixo) / radiusbaixo << " " << (hbaixo) / radiusbaixo << (cos(angulo) * radiusbaixo) / radiusbaixo << " " << endl;

            }
        }
        else {
            for (int i = 0; i <= slices; i++) {
                float angulo = i * ang;

                // Pico do Cone
                fileCone << (sin(ang + angulo) * radiusbaixo) << ' ' << (hbaixo) << ' ' << (cos(ang + angulo) * radiusbaixo) << " " << (sin(ang + angulo) * radiusbaixo) / radiusbaixo << " " << (hbaixo) / radiusbaixo << " " << (cos(ang + angulo) * radiusbaixo) / radiusbaixo << " " << endl;
                fileCone << (0.0f) << ' ' << (hcima) << ' ' << (0.0f) << " " << (0.0f) << " " << (hcima) / radiusbaixo << " " << (0.0f) << " " << endl;
                fileCone << (sin(angulo) * radiusbaixo) << ' ' << (hbaixo) << ' ' << (cos(angulo) * radiusbaixo) << " " << (sin(angulo) * radiusbaixo) / radiusbaixo << " " << (hbaixo) / radiusbaixo << (cos(angulo) * radiusbaixo) / radiusbaixo << " " << endl;
            }
        }
    }
    fileCone.close();
}