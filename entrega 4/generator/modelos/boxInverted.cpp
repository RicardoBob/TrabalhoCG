#include "modelos.h"

using namespace std;

void caixaInverted(float ladoX, float ladoY, float ladoZ, int slices) {

    ofstream fileBox("boxInverted.3d", ofstream::trunc);

    float distX = (ladoX * 2.0) / slices;
    float distY = (ladoY * 2.0) / slices;
    float distZ = (ladoZ * 2.0) / slices;

    float i;

    //Faces orientadas para cima e para baixo
    for (i = 0.0; i < slices; i++) {

        // Face de Baixo (Y = -ladoY)
        // Triangulo 1

        fileBox << (-ladoX) + (distX * i)         << ' ' << (-ladoY) << ' ' << ladoZ    << ' ' << 0 << ' ' << 1 << ' ' << 0 << ' ' << (distX*i)/(ladoX*2)      << ' ' << 1 << endl;
        fileBox << (-ladoX) + distX + (distX * i) << ' ' << (-ladoY) << ' ' << (ladoZ)  << ' ' << 0 << ' ' << 1 << ' ' << 0 << ' ' << (distX*(i+1))/(ladoX*2)  << ' ' << 1 << endl;
        fileBox << (-ladoX) + distX + (distX * i) << ' ' << (-ladoY) << ' ' << (-ladoZ) << ' ' << 0 << ' ' << 1 << ' ' << 0 << ' ' << (distX*(i+1))/(ladoX*2)  << ' ' << 0 << endl;

        // Triangulo 2

        fileBox << (-ladoX) + (distX * i)         << ' ' << (-ladoY) << ' ' << (-ladoZ) << ' ' << 0 << ' ' << 1 << ' ' << 0 << ' ' << (distX*i)/(ladoX*2)      << ' ' << 0 << endl;
        fileBox << (-ladoX) + (distX * i)         << ' ' << (-ladoY) << ' ' << ladoZ    << ' ' << 0 << ' ' << 1 << ' ' << 0 << ' ' << (distX*i)/(ladoX*2)      << ' ' << 1 << endl;
        fileBox << (-ladoX) + distX + (distX * i) << ' ' << (-ladoY) << ' ' << (-ladoZ) << ' ' << 0 << ' ' << 1 << ' ' << 0 << ' ' << (distX*(i+1))/(ladoX*2)  << ' ' << 0 << endl;


        // Face de Cima (Y = ladoY)
        // Triangulo 1

        fileBox << (-ladoX) + (distX * i)         << ' ' << ladoY << ' ' << (-ladoZ) << ' ' << 0 << ' ' << -1 << ' ' << 0 << ' ' << (distX*i)/(ladoX*2)      << ' ' << 0 << endl;
        fileBox << (-ladoX) + distX + (distX * i) << ' ' << ladoY << ' ' << (-ladoZ) << ' ' << 0 << ' ' << -1 << ' ' << 0 << ' ' << (distX*(i+1))/(ladoX*2)  << ' ' << 0 << endl;
        fileBox << (-ladoX) + (distX * i)         << ' ' << ladoY << ' ' << ladoZ    << ' ' << 0 << ' ' << -1 << ' ' << 0 << ' ' << (distX*i)/(ladoX*2)      << ' ' << 1 << endl;

        // Triangulo 2

        fileBox << (-ladoX) + (distX * i)         << ' ' << ladoY << ' ' << ladoZ    << ' ' << 0 << ' ' << -1 << ' ' << 0 << ' ' << (distX*i)/(ladoX*2)      << ' ' << 1 << endl;
        fileBox << (-ladoX) + distX + (distX * i) << ' ' << ladoY << ' ' << (-ladoZ) << ' ' << 0 << ' ' << -1 << ' ' << 0 << ' ' << (distX*(i+1))/(ladoX*2)  << ' ' << 0 << endl;
        fileBox << (-ladoX) + distX + (distX * i) << ' ' << ladoY << ' ' << ladoZ    << ' ' << 0 << ' ' << -1 << ' ' << 0 << ' ' << (distX*(i+1))/(ladoX*2)  << ' ' << 1 << endl;


        // Face de frente (Z = ladoZ)
        // Triangulo 1

        fileBox << (-ladoX) + (distX * i)         << ' ' << ladoY    << ' ' << ladoZ << ' ' << 0 << ' ' << 0 << ' ' << -1 << ' ' << (-ladoX) + (distX * i)     << ' ' << 1 << endl;
        fileBox << (-ladoX) + distX + (distX * i) << ' ' << ladoY    << ' ' << ladoZ << ' ' << 0 << ' ' << 0 << ' ' << -1 << ' ' << (-ladoX) + (distX * (i+1)) << ' ' << 1 << endl;
        fileBox << (-ladoX) + (distX * i)         << ' ' << (-ladoY) << ' ' << ladoZ << ' ' << 0 << ' ' << 0 << ' ' << -1 << ' ' << (-ladoX) + (distX * i)     << ' ' << 0 << endl;

        // Triangulo 2

        fileBox << (-ladoX) + (distX * i)         << ' ' << (-ladoY) << ' ' << ladoZ << ' ' << 0 << ' ' << 0 << ' ' << -1 << ' ' << (-ladoX) + (distX * i)     << ' ' << 0 << endl;
        fileBox << (-ladoX) + distX + (distX * i) << ' ' << ladoY    << ' ' << ladoZ << ' ' << 0 << ' ' << 0 << ' ' << -1 << ' ' << (-ladoX) + (distX * (i+1)) << ' ' << 1 << endl;
        fileBox << (-ladoX) + distX + (distX * i) << ' ' << (-ladoY) << ' ' << ladoZ << ' ' << 0 << ' ' << 0 << ' ' << -1 << ' ' << (-ladoX) + (distX * (i+1)) << ' ' << 0 << endl;

        // Face de Tras (Z = -ladoZ)
        // Triangulo 1

        fileBox << (-ladoX) + (distX * i)         << ' ' << ladoY    << ' ' << (-ladoZ) << ' ' << 0 << ' ' << 0 << ' ' << 1 << ' ' << (-ladoX) + (distX * i)     << ' ' << 1 << endl;
        fileBox << (-ladoX) + distX + (distX * i) << ' ' << (-ladoY) << ' ' << (-ladoZ) << ' ' << 0 << ' ' << 0 << ' ' << 1 << ' ' << (-ladoX) + (distX * (i+1)) << ' ' << 0 << endl;
        fileBox << (-ladoX) + distX + (distX * i) << ' ' << ladoY    << ' ' << (-ladoZ) << ' ' << 0 << ' ' << 0 << ' ' << 1 << ' ' << (-ladoX) + (distX * (i+1)) << ' ' << 1 << endl;

        // Triangulo 2

        fileBox << (-ladoX) + (distX * i)         << ' ' << (-ladoY) << ' ' << (-ladoZ) << ' ' << 0 << ' ' << 0 << ' ' << 1 << ' ' << (-ladoX) + (distX * i)     << ' ' << 0 << endl;
        fileBox << (-ladoX) + distX + (distX * i) << ' ' << (-ladoY) << ' ' << (-ladoZ) << ' ' << 0 << ' ' << 0 << ' ' << 1 << ' ' << (-ladoX) + (distX * (i+1)) << ' ' << 0 << endl;
        fileBox << (-ladoX) + (distX * i)         << ' ' << ladoY    << ' ' << (-ladoZ) << ' ' << 0 << ' ' << 0 << ' ' << 1 << ' ' << (-ladoX) + (distX * i)     << ' ' << 1 << endl;

        // Face da Esquerda (X = -ladoX)
        // Triangulo 1

        fileBox << (-ladoX) << ' ' << ladoY    << ' ' << (-ladoZ) + (distZ * i)         << ' ' << 1 << ' ' << 0 << ' ' << 0 << ' ' << (-ladoZ) + (distZ * i)     << ' ' << 1 << endl;
        fileBox << (-ladoX) << ' ' << (ladoY)  << ' ' << (-ladoZ) + distZ + (distZ * i) << ' ' << 1 << ' ' << 0 << ' ' << 0 << ' ' << (-ladoZ) + (distZ * (i+1)) << ' ' << 1 << endl;
        fileBox << (-ladoX) << ' ' << (-ladoY) << ' ' << (-ladoZ) + (distZ * i)         << ' ' << 1 << ' ' << 0 << ' ' << 0 << ' ' << (-ladoZ) + (distZ * i)     << ' ' << 0 << endl;

        // Triangulo 2
        fileBox << (-ladoX) << ' ' << (-ladoY) << ' ' << (-ladoZ) + (distZ * i)         << ' ' << 1 << ' ' << 0 << ' ' << 0 << ' ' << (-ladoZ) + (distZ * i)     << ' ' << 0 << endl;
        fileBox << (-ladoX) << ' ' << (ladoY)  << ' ' << (-ladoZ) + distZ + (distZ * i) << ' ' << 1 << ' ' << 0 << ' ' << 0 << ' ' << (-ladoZ) + (distZ * (i+1)) << ' ' << 1 << endl;
        fileBox << (-ladoX) << ' ' << (-ladoY) << ' ' << (-ladoZ) + distZ + (distZ * i) << ' ' << 1 << ' ' << 0 << ' ' << 0 << ' ' << (-ladoZ) + (distZ * (i+1)) << ' ' << 0 << endl;



        // Face da Direita (X = ladoX)

        fileBox << (ladoX) << ' ' << ladoY    << ' ' << (-ladoZ) + (distZ * i)         << ' ' << -1 << ' ' << 0 << ' ' << 0 << ' ' << (-ladoZ) + (distZ * i)     << ' ' << 1 << endl;
        fileBox << (ladoX) << ' ' << (-ladoY) << ' ' << (-ladoZ) + (distZ * i)         << ' ' << -1 << ' ' << 0 << ' ' << 0 << ' ' << (-ladoZ) + (distZ * i)     << ' ' << 0 << endl;
        fileBox << (ladoX) << ' ' << (ladoY)  << ' ' << (-ladoZ) + distZ + (distZ * i) << ' ' << 1  << ' ' << 0 << ' ' << 0 << ' ' << (-ladoZ) + (distZ * (i+1)) << ' ' << 1 << endl;

        // Triangulo 2
        fileBox << (ladoX) << ' ' << (-ladoY) << ' ' << (-ladoZ) + (distZ * i)         << ' ' << -1 << ' ' << 0 << ' ' << 0 << ' ' << (-ladoZ) + (distZ * i)     << ' ' << 0 << endl;
        fileBox << (ladoX) << ' ' << (-ladoY) << ' ' << (-ladoZ) + distZ + (distZ * i) << ' ' << -1 << ' ' << 0 << ' ' << 0 << ' ' << (-ladoZ) + (distZ * (i+1))     << ' ' << 0 << endl;
        fileBox << (ladoX) << ' ' << (ladoY)  << ' ' << (-ladoZ) + distZ + (distZ * i) << ' ' << 1  << ' ' << 0 << ' ' << 0 << ' ' << (-ladoZ) + (distZ * (i+1)) << ' ' << 1 << endl;

    }
    fileBox.close();
}