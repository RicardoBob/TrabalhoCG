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




void caixa(float ladoX, float ladoY,float ladoZ, int slices){

    ofstream fileBox("box.3d", ofstream::trunc);

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
        fileBox   <<(ladoX)<< ' ' << (ladoY)<< ' ' << (-ladoZ) + distZ + (distZ*i) << endl;

    }
    fileBox.close();
}

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

void cone(float radius, float height, int slices, int stacks) {
    float ang = 2 * M_PI / (float)slices;

    ofstream fileCone("cone.3d");

    //base
    for (int i = 0; i <= slices; i++) {
        float angulo = i * ang;

        fileCone << (sin(angulo) * radius) << ' ' << (0.0f) << ' ' << (cos(angulo) * radius) << endl;
        fileCone << (0.0f) << ' ' << 0.0f << ' ' << (0.0f) << endl;
        fileCone << (sin(ang + angulo) * radius) << ' ' << (0.0f) << ' ' << (cos(ang + angulo) * radius) << endl;
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
                fileCone << (sin(ang + angulo) * radiusbaixo) << ' ' << (hbaixo) << ' ' << (cos(ang + angulo) * radiusbaixo) << endl;
                fileCone << (sin(ang + angulo) * radiuscima) << ' ' << (hcima) << ' ' << (cos(ang + angulo) * radiuscima) << endl;
                fileCone << (sin(angulo) * radiuscima) << ' ' << (hcima) << ' ' << (cos(angulo) * radiuscima) << endl;

                // Triangulo base em baixo
                fileCone << (sin(ang + angulo) * radiusbaixo) << ' ' << (hbaixo) << ' ' << (cos(ang + angulo) * radiusbaixo) << endl;
                fileCone << (sin(angulo) * radiuscima) << ' ' << (hcima) << ' ' << (cos(angulo) * radiuscima) << endl;
                fileCone << (sin(angulo) * radiusbaixo) << ' ' << (hbaixo) << ' ' << (cos(angulo) * radiusbaixo) << endl;

            }
        }
        else {
            for (int i = 0; i <= slices; i++) {
                float angulo = i * ang;

                // Pico do Cone
                fileCone << (sin(ang + angulo) * radiusbaixo) << ' ' << (hbaixo) << ' ' << (cos(ang + angulo) * radiusbaixo) << endl;
                fileCone << (0.0f) << ' ' << (hcima) << ' ' << (0.0f) << endl;
                fileCone << (sin(angulo) * radiusbaixo) << ' ' << (hbaixo) << ' ' << (cos(angulo) * radiusbaixo) << endl;
            }
        }
    }
    fileCone.close();
}

int main(int argc, char *argv[])
{
    if (std::strcmp(argv[1], "plane") == 0) { // generate plane lado plane.3d
        if(argc == 3){
            float lado = (atof(argv[2])) / 2.0; // nao faz sentido o lado ser negativo, logo nao podemos deixar que se faca isso
            plano(lado);
        }
        else{
            printf("Comando invalido");
        }
    }

    if (std::strcmp(argv[1], "box") == 0) { // generate box ladox ladoy ladoz slices box.3d
        if(argc == 6 || argc == 5){
            float ladoX = (atof(argv[2])) / 2.0;
            float ladoY = (atof(argv[3])) / 2.0;
            float ladoZ = (atof(argv[4])) / 2.0;
            if(argc == 6){
                float slices = (atof(argv[5]));
                caixa(ladoX, ladoY, ladoZ, slices);
            }
            else{
                caixa(ladoX, ladoY, ladoZ, 1);
            }
        }
        else{
            printf("Comando invalido");
        }
    }

    if (std::strcmp(argv[1], "sphere") == 0) { // generate box ladox ladoy ladoz slices box.3d
        if(argc == 5){
            float radius = (atof(argv[2]));
            float slices = (atof(argv[3]));
            float stacks = (atof(argv[4]));
            sphere(radius, slices, stacks);
        }
        else{
            printf("Comando invalido");
        }
    }

    if (std::strcmp(argv[1], "cone") == 0) {
        if (argc == 6){
            float radius = (atof(argv[2]));
            float height = (atof(argv[3]));
            float slices = (atof(argv[4]));
            float stacks = (atof(argv[5]));
            cone(radius,height, slices, stacks);
        }
        else{
            printf("Comando invalido");
        }
    }
}