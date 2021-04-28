//
// Created by igor1 on 26/04/2021.
//

#ifndef MAIN_CPP_BEZIER_H
#define MAIN_CPP_BEZIER_H

#endif //MAIN_CPP_BEZIER_H

#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

#define _USE_MATH_DEFINES
void plano(float a);
void caixa(float ladoX, float ladoY,float ladoZ, int slices);
void cone(float radius, float height, int slices, int stacks);
void sphere(float radius, int slices, int stacks);
void bezier2file(std::string ficheiroALer, int tessellation);

