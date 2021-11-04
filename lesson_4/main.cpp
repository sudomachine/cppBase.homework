// lesson_4

// coded by Sudakov Andrey

/*
1
Написать программу, проверяющую что сумма двух (введенных с клавиатуры) чисел 
лежит в пределах от 10 до 20 (включительно), если да – вывести строку "true", 
в противном случае – "false";
2
Написать программу, выводящую на экран строку “true”, если две целочисленные 
константы (или просто числа), объявленные в её начале либо обе равны десяти 
сами по себе, либо их сумма равна десяти. Иначе "false".
3
Написать программу которая выводит на экран список всех нечетных чисел он 1 до 50. 
Например: "Your numbers: 1 3 5 7 9 11 13 …". Для решения используйте любой С++ цикл.
4*
Написать программу, проверяющую, является ли некоторое число - простым. 
Простое число — это целое положительное число, которое делится без остатка только 
на единицу и себя само. Пример простого числа 17, не простого 33 (делется на 3 и 11).
5*
Пользователь вводит с клавиатуры число (год): от 1 до 3000. Написать программу, 
которая определяет является ли этот год високосным. Каждый 4-й год является 
високосным, кроме каждого 100-го, при этом каждый 400-й – високосный. 
Вывести результаты работы программы в консоль.
 */

#include <iostream>
#include <cmath>

// task 1
bool isTenToTwenty(int* pN1, int* pN2)
{
  // take two pointers to two int numbs
  // return bool: (n1+n2) in [10; 20]
  
  if ((*pN1 + *pN2) >= 10 && (*pN1 + *pN2) <= 20)
    {
      return true;
    }
  else
    {
      return false;
    }
}

// task 5
bool isLeap(short* pYear)
{
  // take pointer to year
  // return bool: leap or not leap
  
  if (*pYear % 400 == 0)
    {
      return true;
    }
  else if (*pYear % 100 == 0)
    {
      return false;
    }
  else if (*pYear % 4 == 0)
    {
      return true;
    }
  else
    {
      return false;
    }
}

const short EXIT_NUM = 0;

int main()
{
  // TASK 1
  std::cout << "########## TASK 1 - (n1+n2) in [10; 20]" << std::endl;

  // declaring
  int n1, n2;
  
  do
    {
      // user input
      std::cout << "Enter the first number (0 to exit): ";
      std::cin >> n1;
      // if 0 than exit
      if (n1 == EXIT_NUM)
	{
	  std::cout << "Next task." << std::endl;
	  break;
	}
      std::cout << "Enter the second number: ";
      std::cin >> n2;
      // print to console
      std::cout << "Amount of " << n1 << " and " << n2 \
		<< ((isTenToTwenty(&n1, &n2)) ? " is " : " is not ") \
		<< "in the limit [10; 20]" << std::endl;
    }
  while (n1);

  // TASK 2
  std::cout << "########## TASK 2 - (n1 == 10 && n2 == 10) || ((n1+n2) == 10)"\
	    << std::endl;

  // declaring
  int nA, nB;
  const int TEN = 10;
  bool taskAnswer;

  do
    {
      taskAnswer = false; // default
      // user input
      std::cout << "Enter the first number (0 to exit): ";
      std::cin >> nA;
      // if 0 than exit
      if (nA == EXIT_NUM)
	{
	  std::cout << "Next task." << std::endl;
	  break;
	}
      std::cout << "Enter the second number: ";
      std::cin >> nB;
      // condition
      if ((nA == TEN && nB == TEN) || (nA+nB == TEN))
	{
	  taskAnswer = true;
	}
      //print to console
      std::cout << "Answer: " << ((taskAnswer) ? "true" : "false") << std::endl;
    }
  while (nA);

  // TASK 3
  std::cout << "########## TASK 3 - Odd Numbers from x1 to x2" << std::endl;

  // declaring
  int x1, x2, x1_isEven;

  do
    {
      // user input
      std::cout << "Enter the first number (0 to exit): ";
      std::cin >> x1;
      // if 0 than exit
      if (x1 == EXIT_NUM)
	{
	  std::cout << "Next task." << std::endl;
	  break;
	}
      std::cout << "Enter the second number: ";
      std::cin >> x2;
      x1_isEven = (x1 % 2 == 0) ? 1 : 0;
      
      // print to console
      std::cout << "Odd numbers: ";
      // None odd numbers
      if (x1 > x2) 
	{
	  std::cout << "None" << std::endl;
	  continue;
	}
      else if (x1 == x2 && ((x1%2 == 0) && (x2%2 == 0)))
	{
	  std::cout << "None" << std::endl;
	  continue;
	}
      // main cycle
      for (x1; x1 < x2; x1+=2)
	{
	  std::cout << x1 + x1_isEven << ' ';
	}
      // exclusive situation when x1 & x2 are odd
      if ((x1%2 == 1) && (x2%2 == 1)) 
	{
	  std::cout << x1;
	}
      std::cout << std::endl;
    }
  while (x1);

  // TASK 4*
  std::cout << "########## TASK 4 - Prime Number" << std::endl;

  // declaring
  unsigned long long nPrime = 1;
  bool nIsPrime;
  int qDivisor;
  const unsigned long long MAX_DIVISOR = 1'000'000'000;

  // user input 
  while (nPrime)
    {
      std::cout << "Enter the positive number (0 to exit): ";
      std::cin >> nPrime;
      if (nPrime == EXIT_NUM)
	{
	  std::cout << "Next task." << std::endl;
	  break; 
	}
      std::cout << "Please wait..." << std::endl;

      // prime number check
      qDivisor = 0; // counter
      nIsPrime = true; // default
      if (nPrime == 1 || nPrime == 2) // prime number; out of cycle
	{
	  nIsPrime = true;
	}
      else if (nPrime % 2 == 0) // even numbers are not prime, expt 2
	{
	  nIsPrime = false;
	}
      else if (nPrime > 2) // cycle with limit MAX
	{
	  for (int divisor = 3; divisor < MAX_DIVISOR; divisor++)
	    {
	      if (nPrime % divisor == 0) // detected divisor
		{
		  qDivisor++;
		  if (qDivisor > 1)
		    {
		      nIsPrime = false;
		      break;
		    }
		}
	    }
	}
      // print to console
      std::cout << ((nIsPrime) ? "Prime!" : "Composite!") << std::endl;
      }

  // TASK 5**
  std::cout << "########## TASK 5 - Leap Year" << std::endl;

  // declaring
  short year;
  const short MIN_YEAR = 1;
  const short MAX_YEAR = 3000;
  
  // user input
  do
    {
      std::cout << "Enter a year (0 to exit): ";
      std::cin >> year;
      if (year < MIN_YEAR || year > MAX_YEAR)
	{
	  std::cout << "You can enter year from 1 to 3000 only!" << std::endl;
	}
      else if (year == EXIT_NUM)
	{
	  std::cout << "Goodbye!" << std::endl;
	  break;
	}
      else
	{
	  std::cout << ((isLeap(&year)) ? "Leap!" : "Not leap!") << std::endl;
	}
    }
  while (year);
    
  return 0;
}
