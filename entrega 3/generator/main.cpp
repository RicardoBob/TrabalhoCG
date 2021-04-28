// ConsoleApplication1.cpp 
/*
 Plane (a square in the XZ plane, centred in the origin, made with 2 triangles) 
 Box (requires X, Y and Z dimensions, and optionally the number of divisions per edge) 
 Sphere (requires radius, slices and stacks) 
 Cone (requires bottom radius, height, slices and stacks) 

*/

//C:\>generator sphere 1 10 10 sphere.
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <fstream>
#include <cstring>
#include "modelos\modelos.h"
using namespace std;


int main(int argc, char *argv[]) {
    if (std::strcmp(argv[1], "plane") == 0) { // generate plane lado plane.3d
        if (argc == 3) {
            float lado = (atof(argv[2])) /
                         2.0; // nao faz sentido o lado ser negativo, logo nao podemos deixar que se faca isso
            plano(lado);
        } else {
            printf("Comando invalido");
        }
    }

    if (std::strcmp(argv[1], "box") == 0) { // generate box ladox ladoy ladoz slices box.3d
        if (argc == 6 || argc == 5) {
            float ladoX = (atof(argv[2])) / 2.0;
            float ladoY = (atof(argv[3])) / 2.0;
            float ladoZ = (atof(argv[4])) / 2.0;
            if (argc == 6) {
                int slices = (atoi(argv[5]));
                caixa(ladoX, ladoY, ladoZ, slices);
            } else {
                caixa(ladoX, ladoY, ladoZ, 1);
            }
        } else {
            printf("Comando invalido");
        }
    }

    if (std::strcmp(argv[1], "sphere") == 0) { // generate box ladox ladoy ladoz slices box.3d
        if (argc == 5) {
            float radius = (atof(argv[2]));
            int slices = (atoi(argv[3]));
            int stacks = (atoi(argv[4]));
            sphere(radius, slices, stacks);
        } else {
            printf("Comando invalido");
        }
    }

    if (std::strcmp(argv[1], "cone") == 0) {
        if (argc == 6) {
            float radius = (atof(argv[2]));
            float height = (atof(argv[3]));
            int slices = (atoi(argv[4]));
            int stacks = (atoi(argv[5]));
            cone(radius, height, slices, stacks);
        } else {
            printf("Comando invalido");
        }

    }
    if (std::strcmp(argv[1], "bezier") == 0) {
        if (argc == 4) {
            string file = argv[2];
            int tessellation = (atoi(argv[3]));
            bezier2file(file, tessellation);
        } else {
            printf("Comando invalido");
        }
    }
}