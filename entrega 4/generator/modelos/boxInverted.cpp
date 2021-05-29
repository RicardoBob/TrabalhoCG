#include "modelos.h"

using namespace std;

void caixaInverted(float ladoX, float ladoY,float ladoZ, int slices){

    ofstream fileBox("boxInverted.3d", ofstream::trunc);

    float distX = (ladoX*2.0)/slices;
    float distY = (ladoY*2.0)/slices;
    float distZ = (ladoZ*2.0)/slices;

    float i;

    //Faces orientadas para cima e para baixo
    for(i = 0.0; i < slices; i++){

        // Face de Baixo (Y = -ladoY)
        // Triangulo 1
        fileBox <<(-ladoX) + distX + (distX*i) << ' ' << (-ladoY) << ' ' << (ladoZ) << endl;
        fileBox << (-ladoX) + (distX*i) << ' ' << (-ladoY) << ' ' << ladoZ << endl;
        fileBox << (-ladoX) + distX + (distX*i) << ' ' << (-ladoY) << ' ' << (-ladoZ) << endl;

        // Triangulo 2
        fileBox << (-ladoX) + (distX*i) << ' ' << (-ladoY) << ' ' << ladoZ << endl;
        fileBox << (-ladoX) + (distX*i) << ' ' << (-ladoY) << ' ' << (-ladoZ) << endl;
        fileBox << (-ladoX) + distX + (distX*i) << ' ' << (-ladoY) << ' ' << (-ladoZ) << endl;


        // Face de Cima (Y = ladoY)
        // Triangulo 1
        fileBox   << (-ladoX) + distX + (distX*i) << ' ' << ladoY << ' ' << (-ladoZ) << endl;
        fileBox   << (-ladoX)+(distX*i)  << ' ' << ladoY << ' ' << (-ladoZ) << endl;
        fileBox   << (-ladoX) + (distX*i) << ' ' << ladoY << ' ' << ladoZ << endl;

        // Triangulo 2
        fileBox   <<(-ladoX) + distX + (distX*i)  << ' ' << ladoY << ' ' << (-ladoZ) << endl;
        fileBox   <<(-ladoX) + (distX*i) << ' ' << ladoY << ' ' << ladoZ << endl;
        fileBox   <<(-ladoX) + distX + (distX*i) << ' ' << ladoY << ' ' << ladoZ << endl;


        // Face de frente (Z = ladoZ)
        // Triangulo 1
        fileBox   <<(-ladoX) + distX + (distX*i)  << ' ' << ladoY   << ' ' << ladoZ << endl;
        fileBox   <<(-ladoX) + (distX*i)   << ' '  << ladoY  << ' '  << ladoZ << endl;
        fileBox   <<(-ladoX) + (distX*i)  << ' ' << (-ladoY)  << ' ' << ladoZ << endl;

        // Triangulo 2
        fileBox   <<(-ladoX) + distX + (distX*i)  << ' ' << ladoY  << ' ' << ladoZ << endl;
        fileBox   <<(-ladoX)  +(distX*i)  << ' ' << (-ladoY)  << ' ' << ladoZ << endl;
        fileBox   <<(-ladoX) + distX + (distX*i)   << ' ' << (-ladoY)  << ' ' << ladoZ << endl;

        // Face de Tras (Z = -ladoZ)
        // Triangulo 1
        fileBox   <<(-ladoX) + distX + (distX*i) << ' ' << (-ladoY) << (-ladoZ) << endl;
        fileBox   <<(-ladoX) + (distX*i) << ' ' << ladoY << (-ladoZ) << endl;
        fileBox   <<(-ladoX) + distX + (distX*i)<< ' ' << ladoY << (-ladoZ) << endl;

        // Triangulo 2
        fileBox   <<(-ladoX) + distX + (distX*i)<< ' ' << (-ladoY) << ' '<< (-ladoZ) << endl;
        fileBox   <<(-ladoX) + (distX*i) << ' ' << (-ladoY) << ' '<< (-ladoZ) << endl;
        fileBox   <<(-ladoX) + (distX*i) << ' '  << ladoY << ' '<< (-ladoZ) << endl;

        // Face da Esquerda (X = -ladoX)
        // Triangulo 1
        fileBox   <<(-ladoX) << ' '<< (ladoY)<< ' ' << (-ladoZ) + distZ + (distZ*i) << endl;
        fileBox   <<(-ladoX) << ' '<< ladoY << ' ' << (-ladoZ) + (distZ*i) << endl;
        fileBox   <<(-ladoX) << ' '<< (-ladoY) << ' '<< (-ladoZ) + (distZ*i) << endl;

        // Triangulo 2
        fileBox   <<(-ladoX)<< ' ' << (ladoY) << ' '<< (-ladoZ) + distZ + (distZ*i) << endl;
        fileBox   <<(-ladoX)<< ' ' << (-ladoY)<< ' ' << (-ladoZ) + (distZ*i) << endl;
        fileBox   <<(-ladoX)<< ' ' << (-ladoY) << ' '<< (-ladoZ) + distZ + (distZ*i) << endl;



        // Face da Direita (X = ladoX)
        fileBox   <<(ladoX)<< ' ' << (-ladoY)<< ' ' << (-ladoZ) + (distZ*i) << endl;
        fileBox   <<(ladoX) << ' '<< ladoY << ' '<< (-ladoZ) + (distZ*i) << endl;
        fileBox   <<(ladoX)<< ' ' << (ladoY)<< ' ' << (-ladoZ) + distZ + (distZ*i) << endl;

        // Triangulo 2
        fileBox   <<(ladoX) << ' '<< (-ladoY)<< ' ' << (-ladoZ) + distZ + (distZ*i) << endl;
        fileBox   <<(ladoX)<< ' ' << (-ladoY)<< ' ' << (-ladoZ) + (distZ*i) << endl;
    fileBox   <<(ladoX)<< ' ' << (ladoY)<< ' ' << (-ladoZ) + distZ tftf
    fileBox.close();
}