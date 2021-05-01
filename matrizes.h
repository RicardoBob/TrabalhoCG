//
// Created by igor1 on 27/04/2021.
//

#ifndef ENGINE_MATRIZES_H
#define ENGINE_MATRIZES_H

#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

using std::vector;

class Matriz {
private:


    int nlinhas;
    int ncolunas;
    vector<vector<float>> matriz;

public:
    Matriz(int linhas,int colunas);
    Matriz(const Matriz &matriz);
    Matriz(int nLinhas,int mColunas,vector<vector<float>> mMatrix);
    Matriz(int dim);
    static Matriz MatrizCatmull();

    Matriz transposta();
    Matriz operator*(Matriz &);
    float& operator()(const int lin,const int col);

    //Getters

    //G
    int getLinhas() const;
    int getColunas() const;


    vector<vector<float>> getMatrizVetores();

    void setMatriz(vector<vector<float>> NovaMatriz);

    vector<float> getLinV(int l);

    vector<float> getColV(int c);

    void adicionaColuna(vector<float> linha, int pos);

    void adicionaColunas(vector<vector<float>> linhas);

    void adicionaLinha(vector<float> linha, int pos);

    void adicionaLinhas(vector<vector<float>> linhas);

    void toString();
};


#endif //ENGINE_MATRIZES_H
