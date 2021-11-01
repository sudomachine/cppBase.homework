// lesson_3

// coded by Sudakov Andrey

/*
1.
Написать программу, вычисляющую выражение a * (b + (c / d)) и выводящую 
результат с плавающей точкой, где a, b, c, d – целочисленные константы. 
Используйте static_cast или С-Style cast к float чтобы выполнить точное деление.
2.
Дано целое число. Если оно меньше или равно 21, то выведите на экран разницу 
между этим числом и числом 21. Если же заданное число больше, чем 21, 
необходимо вывести удвоенную разницу между этим числом и 21. При выполнении 
задания следует использовать тернарный оператор (?:).
3*
Описать трёхмерный целочисленный массив, размером 3х3х3 и указатель на 
значения внутри массива и при помощи операции разыменования вывести на экран 
значение центральной ячейки получившегося куба [1][1][1].
4**
Написать программу, вычисляющую выражение из первого задания, а переменные 
для неё объявлены и инициализировать в другом cpp файле. Используйте extern.
 */

#include <iostream>

int main()
{
  // TASK 1
  std::cout << "########## TASK 1 - expression a*(b+(c/d))" << std::endl;

  // variables init
  int nArr[4] = {0};
  char cArr[4] = {'a', 'b', 'c', 'd'};
  for (int i = 0; i < 4; i++)
    {
      std::cout << "Enter number for " << cArr[i] << ": ";
      std::cin >> nArr[i];
    }

  // expressions
  float expCpp = nArr[0] * (nArr[1] + (static_cast<float>(nArr[2]) / nArr[3]));
  float expC1 = nArr[0] * (nArr[1] + (float(nArr[2]) / nArr[3]));
  float expC2 = nArr[0] * (nArr[1] + ((float)nArr[2] / nArr[3]));

  // print to screen
  std:: cout << expCpp << "\tCpp style" << std::endl;
  std:: cout << expC1 << "\tC style 1" << std::endl;
  std:: cout << expC2 << "\tC style 2" << std::endl;

  // TASK 2
  std::cout << "########## TASK 2 - condition 21" << std::endl;

  // user input
  int yourInt;
  std::cout << "Input integer N: ";
  std::cin >> yourInt;

  // condition 21
  const int N = 21;
  int resultInt = (yourInt <= N) ? (yourInt-N) : ((yourInt-N)*2);

  //print to screen
  std::cout << "Result of comparison: " << resultInt << std::endl;

  // TASK 3*
  
  return 0;
}
