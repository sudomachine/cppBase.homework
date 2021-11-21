/*
this file contains the prototypes of 
printArray
initArray
overload printArray
countPosEl 
countNegEl
sortArray
funcs

and struct Employee
*/

#pragma once
#include <iostream>
#include <string>

namespace Sudakov
{
  bool printArray(float* array, const size_t SIZE);

  // overload printArray
  bool printArray(int* array, const size_t SIZE);

  void initArray(float* array, const size_t SIZE);

  int countPosEl(float* array, const size_t SIZE);

  int countNegEl(float* array, const size_t SIZE);

  bool sortArray(int* array, const size_t SIZE);

#pragma pack(push, 1)
  struct Employee
  {
    std::string firstName;
    std::string secondName;
    unsigned short age;
    float salary;
  };
#pragma pack(pop)
}
