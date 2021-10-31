// lesson 2

// coded by Sudakov Andrey

// В одном main.cpp файле / проекте:
// 1.
// Создать и инициализировать переменные пройденных типов данных
// (short int, int, long long, char, bool, float, double).
// 2.
// Создать перечисление (enum) с возможными вариантами символов
// для игры в крестики-нолики.
// 3.
// Создать массив, способный содержать значения такого перечисления
// и инициализировать его.
// 4. *
// Создать структуру (struct) данных «Поле для игры в крестики-нолики»
// и снабдить его всеми необходимыми свойствами (подумайте что может
// понадобиться).
// 5. **
// Создать структуру (struct MyVariant) объединяющую: union MyData
// (int, float, char)
// и 3-и битовых поля (флага) указывающими какого типа значение в данный
// момент содержится
// в объединении (isInt, isFloat, isChar). Продемонстрировать пример
// использования в коде
// этой структуры.

#include <iostream>

int main()
{
  // TASK 1
  std::cout << "##########TASK 1 - different types data vars" << std::endl;
  
  short int snVar = 1;
  int nVar = 2;
  long lVar = 3;
  long int lnVar = 5;
  long long llVar = 4;
  char cVar = 's';
  bool bVar = true;
  float fVar = 2.0;
  float fVar_f = 2.0f;
  double dVar = 2.0f;

  std::cout << sizeof(snVar) << "\t Short Int type" << std::endl;
  std::cout << sizeof(nVar) << "\t Int type" << std::endl;
  std::cout << sizeof(lnVar) << "\t Long Int type" << std::endl;
  std::cout << sizeof(lVar) << "\t Long type" << std::endl;
  std::cout << sizeof(llVar) << "\t Long long type" << std::endl;
  std::cout << sizeof(cVar) << "\t Char type" << std::endl;
  std::cout << sizeof(bVar) << "\t Bool type" << std::endl;
  std::cout << sizeof(fVar) << "\t Float type" << std::endl;
  std::cout << sizeof(fVar_f) << "\t Float type with 'f'" << std::endl;
  std::cout << sizeof(dVar) << "\t Double type" << std::endl;

  // TASK 2
  std::cout << "##########TASK 2 - enum of TicTacToe" << std::endl;
  
  enum cell {EMPTY, X, O };
  cell cl;
  std::cout << "Size of cell enum: " <<  sizeof(cl) << std::endl;
  cl = EMPTY;
  std::cout << "Value of EMPTY: " << cl << std::endl;
  cl = X;
  std::cout << "Value of X: " << cl << std::endl;
  cl = O;
  std::cout << "Value of O: " << cl << std::endl;

  // TASK 3
  std::cout << "##########TASK 3 - array of TicTacToe cells" << std::endl;

  cell clArr[3][3] = {EMPTY}; // 0 - each element of array (3x3=9)
  std::cout << "Size of clArr: " << sizeof(clArr) << std::endl;

  // TASK 4*
  std::cout << "##########TASK 4 - struct of TicTacToe field" << std::endl;

  // TicTacToe Game
  struct TTTGame
  {
    unsigned int playerMove : 1; // X or O will be move first
    unsigned int winner : 1; // winner is first(X) or second(O) player
    unsigned int draw : 1; // default 1
    int victOpt[8][3] = {
		   {0,1,2},
		   {3,4,5},
		   {6,7,8},
		   {0,3,6},
		   {1,4,7},
		   {2,5,8},
		   {0,4,8},
		   {2,4,6}
    }; // victory options // 100 bytes
    //int xCells[5] = {9}; // all array alements are 9; // 20 bytes
    //int oCells[5] = {9}; // indexes of cells will be write here // 20 bytes
    char playersSteps[9] = {' '};
  };

  TTTGame g1;
  std::cout << "Size of TTTGame struct: " << sizeof(g1) << std::endl;
  /*
0|1|2
-+-+-
3|4|5
-+-+-
6|7|8
   */
  // move choice
  g1.playerMove = 0; // X first move
  for (int i = 0; i < 9; i++)
    {
      // move
      if (g1.playerMove == 0)
	// X move
	{
	  std::cin >> g1.playersSteps[i];
	}
      else if (g1.playerMove == 1)
	// O move
	{
	  std::cin >> g1.playersSteps[i];
	}
      // win check
      //break;
      // print field to console
      for (int i = 0; i < 9; i++)
	{
	  std::cout << g1.playersSteps[i];
	  if (((i+1)%3) == 0) {std::cout << std::endl;}
	}
    }
  
  // TASK 5**
  std::cout << "#########TASK 5 - " << std::endl;
  return 0;
}
