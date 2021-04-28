//
// Created by igor1 on 27/04/2021.
//

#include "matrizes.h"

#include <utility>

//Construtor vazio
//Construtor de copia
//Construtor parametrizado
//Construtor de identidade (pode dar jeito)
//Construtor de Catmull



Matriz :: Matriz(int linhas, int colunas){ //Construtor vazio
    this->nlinhas = linhas;
    this->ncolunas = colunas;

    for(int i = 0;i<linhas;i++) {
        vector<float> v; //Criar i linhas
        for (int j = 0; j < colunas; j++) {//criar j colunas
            v.push_back(0);
        }
        this->matriz.push_back(v);
    }
}
//Construtor de copy
Matriz::Matriz(const Matriz &matriz): ncolunas(matriz.getColunas()), nlinhas(matriz.getLinhas()),matriz(matriz.matriz){}

//Construtor parametrizado
Matriz::Matriz(int nLinhas, int nColunas, vector<vector<float>> matrizP): nlinhas(nLinhas),ncolunas(nColunas),matriz(std::move(matrizP)) {}

//Construtor de identidade
Matriz::Matriz(int dim) {
    this->ncolunas = dim;
    this->nlinhas = dim;

    for (int i = 0; i < dim; i++) {
        vector<float> v;
        for (int j = 0; j < dim; j++) {
            if (i == j) {
                v.push_back(1);
            } else v.push_back(0);
        }
        this->matriz.push_back(v);
    }
}
//Construtor de Catmull
Matriz Matriz::MatrizCatmull() {

    vector <float> m1 { -0.5f,  1.5f,  -1.5f,  0.5f};
    vector <float> m2 { 1.0f,  -2.5f,   2.0f, -0.5f};
    vector <float> m3 { -0.5f,  0.0f,   0.5f,  0.0f};
    vector <float> m4 { 0.0f,   1.0f,   0.0f,  0.0f};

    vector<vector<float>> catmullTemp;
    catmullTemp.push_back(m1);
    catmullTemp.push_back(m2);
    catmullTemp.push_back(m3);
    catmullTemp.push_back(m4);

    Matriz catmull = Matriz(4, 4,catmullTemp);
    return catmull;
}
//Adicionar linhas e colunas a uma matriz , da jeito para preencher com os vetores do xml

void Matriz::adicionaLinha(vector<float>linha , int pos){
    this->matriz.at(pos) = std::move(linha);
}

void Matriz::adicionaLinhas(vector<vector<float>>linhas){
    for(const auto & linha : linhas){
        this->matriz.push_back(linha);
    }
}

void Matriz::adicionaColuna(vector<float>coluna , int pos){ //virar ao contrario, meter como linha e voltar a virar
    Matriz temp = this->transposta();
    temp.adicionaLinha(std::move(coluna),pos);
    vector<vector<float>> vecTemp = temp.transposta().getMatrizVetores();
    this->setMatriz(vecTemp);
}

void Matriz::adicionaColunas(vector<vector<float>>colunas){ //colunas todas ao contrario = matriz normal

    this->setMatriz(colunas);
    vector<vector<float>>temp = this->transposta().getMatrizVetores();
    this->setMatriz(temp);
}









//multiplicar Matriz A Matriz B  C = B * A

Matriz Matriz::operator*(Matriz & M) {
    Matriz mult(nlinhas,M.getColunas());
    if(ncolunas == M.getLinhas())
    {
        int i,j,x;
        float aux;
        for(i= 0;i < nlinhas; i++ ){
            for(j = 0; j < M.getColunas();j++){
                aux = 0.0;
                for(x = 0; x < ncolunas;x++)
                {
                    aux += matriz[i][x] * M(x,j);
                }
                mult(i,j) = aux;
            }
        }
        return mult;
    }

}


//buscar elemento de uma matriz

float &Matriz::operator()(const int lin, const int col) {
    return this->matriz[lin][col];
}

Matriz Matriz::transposta() {

    Matriz T(ncolunas,nlinhas);
    for(int i = 0; i < ncolunas;i++ ){
        for (int j = 0; j < nlinhas;j++ ){
            T(i,j) = this->matriz[j][i];
        }
    }
    return T;
}

//Getters de valores

int Matriz::getLinhas() const
{
    return this->nlinhas;
}

int Matriz::getColunas() const
{
    return this->ncolunas;
}


//get linha em vetor
vector<float> Matriz::getLinV(int l) {
    return this->matriz[l];
}
//get coluna em vetor
vector<float> Matriz::getColV(int c) {
    return (this->transposta().getLinV(c));
}
//get matriz
vector<vector<float>> Matriz::getMatrizVetores() {
    return this->matriz;
}

//set matriz
void Matriz::setMatriz( vector<vector<float>> &NovaMatriz) {
    matriz = NovaMatriz;


}
