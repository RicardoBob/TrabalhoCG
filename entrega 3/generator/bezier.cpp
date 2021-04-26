//
// Created by luisaraujo on 31/05/20.
//

#include "bezier.h"
using namespace std;


//Calcula um ponto da curva
float* bezierFormula(float t, float* p0, float* p1, float* p2, float *p3){
    float* result = new float[3];

    float aux = (1-t);

    float b0 = aux * aux * aux; // (1-t)^3
    float b1 = 3 * (aux * aux) * t; // 3*t*(1-t)^2
    float b2 = 3 * aux * (t * t); // 3*(t^2)*(1-t)
    float b3 = t * t * t; // t^3


    result[0] = b0 * p0[0] + b1 * p1[0] + b2 * p2[0] + b3 * p3[0];
    result[1] = b0 * p0[1] + b1 * p1[1] + b2 * p2[1] + b3 * p3[1];
    result[2] = b0 * p0[2] + b1 * p1[2] + b2 * p2[2] + b3 * p3[2];

    return result;


}

float* bezier(float n, float m, float** points, int* index){
    int i;
    float* point = new float[3];
    float* result = new float[3];
    int j = 0;
    int N = 0;
    float guardaControlPoints[4][3]; //Guarda os pontos de controlo
    float guardaPontosBezier[4][3];//Guarda os pontos da curva de bezier

    for(i=0; i < 16; i++){

        guardaControlPoints[j][0] = points[index[i]][0];
        guardaControlPoints[j][1] = points[index[i]][1];
        guardaControlPoints[j][2] = points[index[i]][2];
        j++;

        if(j % 4 == 0){//Por cada 4 pontos de controlo vai fazer a curva original

            //Vai buscar um ponto da curva real de bezier
            point = bezierFormula(n, guardaControlPoints[0], guardaControlPoints[1], guardaControlPoints[2], guardaControlPoints[3]);

            guardaPontosBezier[N][0] = point[0];
            guardaPontosBezier[N][1] = point[1];
            guardaPontosBezier[N][2] = point[2];
            j = 0;
            N++;
        }
    }
    //Faz a curva horizontal do ponto vermelho (slides stor)
    result = bezierFormula(m, guardaPontosBezier[0], guardaPontosBezier[1], guardaPontosBezier[2], guardaPontosBezier[3]);

    return result;
}

void bezier2file(string ficheiroALer, int tessellation){

    ifstream read(ficheiroALer); //Abre o .patch para ler
    ofstream write("beziercurve.3d"); //Abre o bezier para escrever
    string line, value;
    int linhasIndices, linhasPontos, nPatches, p1, lerCoords;
    int position;

    float subdivisao = 1.0 / tessellation;


    if(read.is_open()){ //Verifica se o ficheiro abriu direito

        getline(read, line); //Vai buscar a primeira linha
        int numPatches = atoi(line.c_str()); //Nessa linha vai estar o nº de patches
        int** indicePontosControlo = new int*[numPatches]; //[patch][]
        float*** pontosFinais = new float**[numPatches]; //[patch][indice][]

        //Vamos buscar os indices de cada patch
        for(linhasIndices = 0; linhasIndices < numPatches; linhasIndices++){
            getline(read, line);
            indicePontosControlo[linhasIndices] = new int[16];//Array com 16 pontos de controlo

            for(p1 = 0; p1 < 16; p1++){
                position = line.find(',');
                value = line.substr(0, position);
                indicePontosControlo[linhasIndices][p1] = atoi(value.c_str());
                line.erase(0, position + 1);
            }


        }

        getline(read, line); //Ler numero de pontos (290)
        int numPontos = atoi(line.c_str());
        float** pontos = new float*[numPontos];



        for(linhasPontos = 0; linhasPontos < numPontos; linhasPontos++){
            getline(read, line);
            pontos[linhasPontos] = new float[3]; //array de 3 floats para as coordenadas

            for(lerCoords = 0; lerCoords < 3; lerCoords++){
                position = line.find(",");
                value = line.substr(0, position);
                pontos[linhasPontos][lerCoords] = atof(value.c_str());

                line.erase(0, position + 1);
            }
        }

        for(nPatches = 0; nPatches < numPatches; nPatches++){
            pontosFinais[nPatches] = new float*[4];//[32][4]

            for(int lin = 0; lin < tessellation; lin++ ) {

                for(int col = 0; col < tessellation; col++) {

                    float x1 = subdivisao * lin;
                    float y1 = subdivisao * col;
                    float x2 = subdivisao * (lin + 1 );
                    float y2 = subdivisao * (col + 1 );

                    pontosFinais[nPatches][0] = bezier(x1, y1, pontos, indicePontosControlo[nPatches]);
                    pontosFinais[nPatches][1] = bezier(x1, y2, pontos, indicePontosControlo[nPatches]);
                    pontosFinais[nPatches][2] = bezier(x2, y1, pontos, indicePontosControlo[nPatches]);
                    pontosFinais[nPatches][3] = bezier(x2, y2, pontos, indicePontosControlo[nPatches]);


                    write << pontosFinais[nPatches][0][0] << " " << pontosFinais[nPatches][0][1] << " " << pontosFinais[nPatches][0][2] << endl;
                    write << pontosFinais[nPatches][2][0] << " " << pontosFinais[nPatches][2][1] << " " << pontosFinais[nPatches][2][2] << endl;
                    write << pontosFinais[nPatches][3][0] << " " << pontosFinais[nPatches][3][1] << " " << pontosFinais[nPatches][3][2] << endl;

                    write << pontosFinais[nPatches][0][0] << " " << pontosFinais[nPatches][0][1] << " " << pontosFinais[nPatches][0][2] << endl;
                    write << pontosFinais[nPatches][3][0] << " " << pontosFinais[nPatches][3][1] << " " << pontosFinais[nPatches][3][2] << endl;
                    write << pontosFinais[nPatches][1][0] << " " << pontosFinais[nPatches][1][1] << " " << pontosFinais[nPatches][1][2] << endl;

                }
            }
        }
        write.close();
        read.close();
    } else {
        printf("Ficheiro de Input Inválido!");
    }
}
