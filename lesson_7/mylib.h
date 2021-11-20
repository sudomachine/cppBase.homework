/*
this file contains the prototypes of printArray, initArray, countPosNegEl funcs
*/

#pragma once
#include <iostream>

bool printArray(float* array, const size_t SIZE);

void initArray(float* array, const size_t SIZE);

int countPosEl(float* array, const size_t SIZE);

int countNegEl(float* array, const size_t SIZE);
