/*
printArray(), initArray(), countPosEl(), countNegEl() functions initialization
*/

#include <iostream>

bool printArray(float* array, const size_t SIZE)
{
  // take array and array size
  // print array to console (1 2 3 4 5 6); return true or false

  // if array not init or his size is zero
  if (array == nullptr || SIZE == 0)
    {
      return false;
    }
  // else print
  for (int i = 0; i < SIZE; i++)
    {
      std::cout << array[i] << " ";
    }
  // cursor to the new string
  std::cout << std::endl;
  return true;
}

void initArray(float* array, const size_t SIZE)
{
  // take array and array size
  // initialize array by random float numbers

  // if array not init or size is 0 then initialize by zeros
  if (array == nullptr || SIZE == 0)
    {
      array[SIZE] = {0.0f};
    }
  // initialize random numbers
  for (int i = 0; i < SIZE; i++)
    {
      array[i] = static_cast<float>(rand()%20-10);
    }
}

int countPosEl(float* array, const size_t SIZE)
{
  size_t amountPosEl = 0;
  for (int i = 0; i < SIZE; i++)
    {
      if (array[i] > 0)
	{
	  amountPosEl++;
	}
    }
  return amountPosEl;
}

int countNegEl(float* array, const size_t SIZE)
{
  size_t amountNegEl = 0;
  for (int i = 0; i < SIZE; i++)
    {
      if (array[i] < 0)
	{
	  amountNegEl++;
	}
    }
  return amountNegEl;
}
