// lesson 5

// coded by Sudakov Andrey

/*
1
Написать функцию которая выводит массив double чисел на экран. 
Параметры функции это сам массив и его размер. Вызвать эту функцию из main.
2
Задать целочисленный массив, состоящий из элементов 0 и 1. 
Например: [ 1, 1, 0, 0, 1, 0, 1, 1, 0, 0 ]. Написать функцию, заменяющую в 
принятом массиве 0 на 1, 1 на 0. Выводить на экран массив до изменений и после.
3
Задать пустой целочисленный массив размером 8. Написать функцию, 
которая с помощью цикла заполнит его значениями 1 4 7 10 13 16 19 22. 
Вывести массив на экран.
4* 
Написать функцию, которой на вход подаётся одномерный массив и 
число n (может быть положительным, или отрицательным), 
при этом метод должен циклически сместить все элементы массива на n позиций.
5**
Написать функцию, которой передается не пустой одномерный целочисленный массив, 
она должна вернуть истину если в массиве есть место, в котором сумма левой и 
правой части массива равны. Примеры: checkBalance([1, 1, 1, || 2, 1]) → true, 
checkBalance ([2, 1, 1, 2, 1]) → false, checkBalance ([10, || 1, 2, 3, 4]) → 
true. Абстрактная граница показана символами ||, эти символы в массив не входят.
 */

#include <iostream>
#include <iterator>

// task 1
void printArray (double* dArray, const size_t ARRAY_SIZE)
{
  // take ptr to array and size of array
  // prints elements of array to screen

  // prints nothing if array is empty
  if (dArray == nullptr || ARRAY_SIZE <= 0)
    {
      std::cout << "" << std::endl;
    }
  // prints array
  for (int i = 0; i < ARRAY_SIZE; i++)
    {
      std::cout << dArray[i] << ' ';
    }
  std::cout << std::endl;
}

// task 2
void bitDenial(int* bitArray, const size_t ARRAY_SIZE)
   {
     // take ptr to bit array and size of array
     // each bit 1 changes to 0, 0 to 1

     for (int i = 0; i < ARRAY_SIZE; i++)
       {
	 if (bitArray[i] == 0)
	   {
	     bitArray[i] = 1;
	   }
	 else if (bitArray[i] == 1)
	   {
	     bitArray[i] = 0;
	   }
       }
   }

// task 3
void arrayInit(int *array)
{
  // take ptr to array
  // initializes the array of 1 4 7 10 13 16 19 22
  
  const size_t ARRAY_SIZE = 8;
  short initializer = 1; // array initializer
  
  for (int i = 0; i < ARRAY_SIZE; i++)
    {
      array[i] = initializer;
      initializer += 3;
    }
}

// task 4
void arrayShift(int* array, const size_t SIZE, int n)
{
  // take ptr to array, size and int n
  // shifts all elements of array by n positions

  for (int i = 0; i < SIZE; i++)
    {
      array[i] += n;
    }
}

// optional func for task 5 - sum of array elements from i1 to i2
int amountArrElem(int* array, int i1, int i2)
{
  // take ptr to array, first index and second index
  // returns amount of array elements from i1 to i2

  int amount = 0;
  for (i1; i1 <= i2; i1++)
    {
      amount += array[i1];
    }
  return amount;
}

// task 5
bool checkBalance(int *array, const size_t SIZE)
{
  // take ptr to array and size
  // return true or false

  int leftSide;
  int rightSide;
  for (int i = 0; i < SIZE-1; i++)
    {
      // balance counting
      leftSide = amountArrElem(array, 0, i);
      rightSide = amountArrElem(array, i+1, SIZE-1);
      // left and right sides comparison
      if (leftSide == rightSide)
	{
	  return true; // exit from func (true)
	}
      // else - next step of comparison
    }
  return false; // exit from func (false)
}

int main()
{
  // task 1
  std::cout << "##### TASK 1 - Array Print" << std::endl;
  const size_t ARR_SIZE_1 = 6;
  double arr[ARR_SIZE_1] = {0.0,1.1,2.2,3.3,4.4,5.5};
  printArray(arr, ARR_SIZE_1);

  // task 2
  std::cout << "##### TASK 2 - Bit Denial" << std::endl;
  const size_t ARR_SIZE_2 = 8;
  int arr1[ARR_SIZE_2] = {0,1,1,0,0,0,1,1};
  // array print before func using
  for (int i = 0; i < ARR_SIZE_2; i++) { std::cout << arr1[i] << ' '; }
  std::cout << std::endl;
  // func using
  bitDenial(arr1, ARR_SIZE_2);
  // array print after func using
  for (int i = 0; i < ARR_SIZE_2; i++) { std::cout << arr1[i] << ' '; }
  std::cout << std::endl;

  // task 3
  std::cout << "##### TASK 3 - Array Initialization" << std::endl;
  const size_t ARR_SIZE_3 = 8; // by task condition
  int array[ARR_SIZE_3] = {}; // empty array by task condition
  // prints empty array to the screen
  for (int i = 0; i < ARR_SIZE_3; i++) { std::cout << array[i] << ' '; }
  std::cout << std::endl;
  // array initialization
  arrayInit(array);
  // prints initialized array
  for (int i = 0; i < ARR_SIZE_3; i++) { std::cout << array[i] << ' '; }
  std::cout << std::endl;

  // task 4
  std::cout << "##### TASK 4 - Array Offset" << std::endl;
  arrayShift(array, ARR_SIZE_3, -5); // array from task 3
  for (auto el: array) { std::cout << el << ' '; }
  std::cout << std::endl;

  // task 5
  std::cout << "##### TASK 5 - Check Balance" << std::endl;
  const size_t SIZE_1 = 5;
  const size_t SIZE_2 = 2;
  const size_t SIZE_7 = 1;
  int testBalance1[SIZE_1] = {1, 2, 3, 4, 2}; // true
  int testBalance2[SIZE_2] = {1, 2}; // false
  int testBalance3[SIZE_1] = {1,1,1,2,1}; // true
  int testBalance4[SIZE_1] = {2,1,1,2,1}; // false
  int testBalance5[SIZE_1] = {10,1,2,3,4}; // true
  int testBalance6[SIZE_1] = {1,2,3,4,10}; // true
  int testBalance7[SIZE_7] = {10}; // false

  std::cout << std::boolalpha;
  std::cout << "{1, 2, 3, 4, 2} -> " << checkBalance(testBalance1, SIZE_1) << std::endl;
  std::cout << "{1, 2} -> " << checkBalance(testBalance2, SIZE_2) << std::endl;
  std::cout << "{1,1,1,2,1} -> " << checkBalance(testBalance3, SIZE_1) << std::endl;
  std::cout << "{2,1,1,2,1} -> " << checkBalance(testBalance4, SIZE_1) << std::endl;
  std::cout << "{10,1,2,3,4} -> " << checkBalance(testBalance5, SIZE_1) << std::endl;
  std::cout << "{1,2,3,4,10} -> " << checkBalance(testBalance6, SIZE_1) << std::endl;
  std::cout << "{10} -> " << checkBalance(testBalance7, SIZE_7) << std::endl;
  return 0;
}
