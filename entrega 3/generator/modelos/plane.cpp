//
// Created by igor1 on 27/04/2021.
//

#include "modelos.h"

using namespace std;

void plano(float a){

    ofstream fileQuadrado("plane.3d", ios::trunc);

    //Triangulo 1

    fileQuadrado   << a << " 0 " << -a  << endl ; //(1,0,-1)
    fileQuadrado   << -a << " 0 " << -a << endl; //(-1,0,-1)
    fileQuadrado   << -a << " 0 " << a << endl; //(-1,0,1)

    //Triangulo 2

    fileQuadrado   << a << " 0 " << -a << endl; //(1,0,-1)
    fileQuadrado   << -a << " 0 " << a << endl; //(-1,0,1)
    fileQuadrado   << a << " 0 " << a << endl;  //(1,0,1)


    fileQuadrado.close();
}