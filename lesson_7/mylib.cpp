/*
printArray
initArray
countPosEl
countNegEl 
sortArray 
writeObjToBinFile functions initialization
*/

#include <iostream>
#define SWAP_INT(NUMBER_1, NUMBER_2) \
  int TEMP = NUMBER_1; \
  NUMBER_1 = NUMBER_2; \
  NUMBER_2 = TEMP;

namespace Sudakov
{
  bool printArray(float* array, const size_t SIZE)
  {
    // take array and array size
    // print array to console (1.0 2.0 3.0 4.0 5.0 6.0); return true or false

    // func returns 'false' because it can not to print empty array
    if (array == nullptr || SIZE == 0)
      {
	return false;
      }
    // func prints elements to the one row separated by space " "
    for (int i = 0; i < SIZE; i++)
      {
	std::cout << array[i] << " ";
      }
    // cursor to the new string
    std::cout << std::endl;
    return true;
  }

  // overload func 'printArray' for int array
  bool printArray(int* array, const size_t SIZE)
  {
    // take array and array size
    // print array to console (1 2 3 4 5 6); return true or false

    // func returns 'false' because it can not to print empty array
    if (array == nullptr || SIZE == 0)
    {
      return false;
    }
    // func prints elements to the one row separated by space " "
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

  bool sortArray(int* array, const size_t SIZE)
  {
    if (array == nullptr || SIZE == 0)
      {
	return false;
      }
    size_t indexOfStartElement;
    int minElement;
    size_t minElementIndex;
    for (int i = 0; i < SIZE; i++)
      {
	indexOfStartElement = i;
	minElement = array[indexOfStartElement];
	minElementIndex = indexOfStartElement;
	for (int j = i; j < SIZE; j++)
	  {
	    if (array[j] < minElement)
	      {
		minElement = array[j];
		minElementIndex = j;
	      }
	  }
	if (minElement < array[i])
	  {
	    SWAP_INT(array[i], array[minElementIndex])
	      }
      }
    return true;
  }
}
