// lesson 6

// coded by Sudakov Andrey

/*
1
Выделить в памяти динамический одномерный массив типа int. 
Размер массива запросить у пользователя. 
Инициализировать его числами степенями двойки: 1, 2, 4, 8, 16, 32, 64, 128 ... 
Вывести массив на экран. Не забыть освободить память. =) Разбить программу на функции.
2
Динамически выделить матрицу 4х4 типа int. 
Инициализировать ее псевдослучайными числами через функцию rand. 
Вывести на экран. Разбейте вашу программу на функции которые вызываются из main.
3
Написать программу, которая создаст два текстовых файла (*.txt), 
примерно по 50-100 символов в каждом (особого значения не имеет с каким 
именно содержимым). Имена файлов запросить у польлзователя.
4*
Написать функцию, «склеивающую» эти файлы в третий текстовый файл 
(имя файлов спросить у пользователя).
5*
Написать программу, которая проверяет присутствует ли указанное пользователем 
при запуске программы слово в указанном пользователем файле 
(для простоты работаем только с латиницей). 
Используем функцию find которая есть в строках std::string.
*/

#include <iostream>
#include <string>
#include <fstream>

bool printArray(int* array, size_t size);

int addDegreeOfTwo(int degree);

int addRandNum(int randNum);

typedef int (*ExeFuncOverEl)(int); // execute function over elements

bool initArray(int* array, size_t size, ExeFuncOverEl pFunc);

void task1()
{
  // TASK 1
  
  // declaring and alloc mem
  int* ptrArray;
  int arraySize;
  std::cout << "Array Size >> ";
  std::cin >> arraySize;
  ptrArray = new int[arraySize];
  // init and print to console
  initArray(ptrArray, arraySize, addDegreeOfTwo);
  printArray(ptrArray, arraySize);
  // freeing up mem
  delete[] ptrArray;
  ptrArray = nullptr;
}

void task2()
{
  // TASK 2

  // declaring
  int** array2D;
  int arraySize = 4;
  // memory allocation
  array2D = new int*[arraySize];
  for (int i = 0; i < arraySize; i++)
    {
      array2D[i] = new int[arraySize];
      // init array and print to console
      initArray(array2D[i], arraySize, addRandNum);
      printArray(array2D[i], arraySize);
      std::cout << std::endl; // next string of matrix
    }
  // freeing up memory
  for (int i = 0; i < arraySize; i++)
    {
      delete[] array2D[i];
    }
  delete[] array2D;
  array2D = nullptr;
}

void task3()
{
  // TASK 3

  const unsigned short Q_FILE = 2;
  const unsigned short Q_SYMBOLS = 100;
  for (int i = 0; i < Q_FILE; i++)
    {
      // declaring
      std::string fileName;
      // user input
      std::cout << "File Name " << i+1 << " >> ";
      std::cin >> fileName;
      // open file
      std::ofstream fileObj;
      fileObj.open(fileName);
      if (fileObj.is_open())
	{
	  // write to file a set of random numbers
	  for (int i = 0; i < Q_SYMBOLS; i++)
	    {
	      fileObj << rand()%10 << " ";
	    }
	  fileObj << std::endl;
	}
      fileObj.close();
    }
}

int main()
{
  srand(time(0));
  std::cout << "##### TASK 1" << std::endl;
  task1();
  std::cout << "##### TASK 2" << std::endl;
  task2();
  std::cout << "##### TASK 3" << std::endl;
  task3();
  return 0;
}

int addRandNum(int randNum)
{
  return (rand() % ((randNum+1) * ((rand()%100)+1)));
}

bool initArray(int* array, size_t size, ExeFuncOverEl generateEl)
{
  // take array, size and func to generate the elements of array
  // initialize the array, return true (if init) or false (if not init)
  if (array == nullptr || size == 0)
    {
      return false;
    }
  else
    {
      for (int i = 0; i < size; i++)
	{
	  array[i] = generateEl(i);
	}
      return true;
    }
}

int addDegreeOfTwo(int degree)
{
  // take int number and degree
  // return sum of nubmer and degree of two
  
  int degreeOfTwo = 1;
  for (int i = 0; i < degree; i++)
    {
      degreeOfTwo = 2*degreeOfTwo;
    }
  return (degreeOfTwo);
}

bool printArray(int* array, size_t size)
{
  // take array and size
  // print array to console

  // empty array, nothing to print
  if (array == nullptr || size == 0)
    {
      return false;
    }
  // not empty array, print to console
  else
    {
      for (int i = 0; i < size; i++)
	{
	  std::cout << array[i] << " ";
	}
      std::cout << std::endl;
      return true;
    }
}


