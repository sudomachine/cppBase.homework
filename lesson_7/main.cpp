// lesson 7

// coded by Sudakov Andrey

/*
1
Создайте проект из 2х cpp файлов и заголовочного (main.cpp, mylib.cpp, mylib.h) во
втором модуле mylib объявить 3 функции: для инициализации массива (типа float), 
печати его на экран и подсчета количества отрицательных и положительных элементов.
Вызывайте эти 3-и функции из main для работы с массивом.
2
Описать макрокоманду (через директиву define), проверяющую, входит ли переданное 
ей число (введенное с клавиатуры) в диапазон от нуля (включительно) до переданного
ей второго аргумента (исключительно) и возвращает true или false, вывести на экран
«true» или «false».
3
Задайте массив типа int. Пусть его размер задается через директиву препроцессора 
#define. Инициализируйте его через ввод с клавиатуры. Напишите для него свою 
функцию сортировки (например Пузырьком). Реализуйте перестановку элементов как 
макрокоманду SwapINT(a, b). Вызывайте ее из цикла сортировки.
4*
Объявить структуру Сотрудник с различными полями. Сделайте для нее побайтовое 
выравнивание с помощью директивы pragma pack. Выделите динамически переменную 
этого типа. Инициализируйте ее. Выведите ее на экран и ее размер с помощью sizeof.
Cохраните эту структуру в текстовый файл.
5*
Сделайте задание 1 добавив свой неймспейс во втором модуле 
(первое задание тогда можно не делать).
*/

#include "mylib.h"
#include <iostream>
#include <fstream>
#define IS_INCLUDED(USER_NUMBER, RIGHT_LIMIT_EXCLUDED) \
  ((USER_NUMBER >= 0) && (USER_NUMBER < RIGHT_LIMIT_EXCLUDED))
#define ARRAY_SIZE 6

void task1()
{
  std::cout << "##### TASK 1" << std::endl;
  // initialization
  const size_t SIZE = 5;
  float arr[SIZE] = {0.0f};
  // func using
  Sudakov::initArray(arr, SIZE);
  Sudakov::printArray(arr, SIZE);
  std::cout << "Amount of positive elements: " \
	    << Sudakov::countPosEl(arr, SIZE) << std::endl;
  std::cout << "Amount of negative elements: " \
	    << Sudakov::countNegEl(arr, SIZE) << std::endl;
}

void task2()
{
  std::cout << "##### TASK 2" << std::endl;
  // declaring
  int rightN, checkN;
  // user input
  std::cout << "Verification number: ";
  std::cin >> checkN;
  std::cout << "Right limit of range (excluded): ";
  std::cin >> rightN;
  // IS_INCLUDED directive using
  std::cout << std::boolalpha << IS_INCLUDED(checkN, rightN) << std::endl;
}

void task3()
{
  std::cout << "##### TASK 3" << std::endl;
  int userArray[ARRAY_SIZE] = {0};
  // user input
  std::cout << "Enter values of array elements:" << std::endl;
  for (int i = 0; i < ARRAY_SIZE; i++)
    {
      std::cout << i+1 << " element >> ";
      std::cin >> userArray[i];
      }
  // sort and print functions using
  Sudakov::printArray(userArray, ARRAY_SIZE);
  Sudakov::sortArray(userArray, ARRAY_SIZE);
  Sudakov::printArray(userArray, ARRAY_SIZE);
  /*
  // TESTS
  const int TEST_ARRAY_SIZE = 7;
  const int Q_TEST = 6;
  int testArray[Q_TEST][TEST_ARRAY_SIZE] = {
					    {},
					    {0,0,0,0,0,0,0},
					    {-1,-7,-9,-100,-7,-1,-7},
					    {1,6,3,1000,1,3,1},
					    {0,6,-10,0,1,-1,9},
					    {10,5,10,5,-1,-1,0}};
  for (int i = 0; i < Q_TEST; i++)
    {
      std::cout << "TEST " << i+1 << std::endl;
      Sudakov::printArray(testArray[i], TEST_ARRAY_SIZE);
      Sudakov::sortArray(testArray[i], TEST_ARRAY_SIZE);
      Sudakov::printArray(testArray[i], TEST_ARRAY_SIZE);
    }
  */
}

void task4()
{
  std::cout << "##### TASK 4" << std::endl;
  // struct initialization
  Sudakov::Employee* andrey = new Sudakov::Employee{"Sudakov", "Andrey", 25, 40'000.00f};
  // print to console
  std::cout << "FirstName: " << andrey->firstName << std::endl \
	    << "SecondName: " << andrey->secondName << std::endl \
	    << "Age: " << andrey->age << std::endl \
	    << "Salary: " << andrey->salary << std::endl;
  std::cout << "Allocated memory of employee object: " \
	    << sizeof(andrey) << "b"<< std::endl;
  // write to file
  const char fileName[256] = "EmployeeStruct.bin";
  std::ofstream fstrm(fileName, std::ios_base::binary);
  if (fstrm.is_open())
    {
      fstrm.write((char*)&andrey, sizeof(andrey));
      fstrm.close();
    }
}

void task5()
{
  std::cout << "##### TASK 5" << std::endl;
  std::cout << "'Sudakov' namespace was added to task 1" << std::endl;
}

int main()
{
  srand(time(0));
  task1();
  task2();
  task3();
  task4();
  task5();
  return 0;
}
