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
#define IS_INCLUDED(USER_NUMBER, RIGHT_LIMIT_EXCLUDED) \
  ((USER_NUMBER >= 0) && (USER_NUMBER < RIGHT_LIMIT_EXCLUDED))
#define ARRAY_SIZE 5
#define SWAP_INT(NUMBER_1, NUMBER_2) \
  TEMP = NUMBER_1; \
  NUMBER_1 = NUMBER_2; \
  NUMBER_2 = TEMP;

void task1()
{
  std::cout << "##### TASK 1" << std::endl;
  // initialization
  const size_t SIZE = 5;
  float arr[SIZE] = {0.0f};
  // func using
  initArray(arr, SIZE);
  printArray(arr, SIZE);
  std::cout << "Amount of positive elements: " << countPosEl(arr, SIZE) << std::endl;
  std::cout << "Amount of negative elements: " << countNegEl(arr, SIZE) << std::endl;
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
  int a = 10, b = 20;
  SWAP_INT(a,b);
  std::cout << a << " " << b << std::endl;
}

int main()
{
  srand(time(0));
  //  task1();
  //  task2();
  task3();
  return 0;
}
