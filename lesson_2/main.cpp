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
#include <cstdlib>

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
    unsigned int winner : 2; // winner is first(X) or second(O) player
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
    char playersSteps[9] = {48};  // init by '0'
  };

  TTTGame g1;
  // g1.playersSteps init by 1,2,3...9 char
  for (int i = 0; i < 9; i++)
    {
      g1.playersSteps[i] = 49+i;
    }
  std::cout << "Size of TTTGame struct: " << sizeof(g1) << std::endl;
  
  // MOVE CHOICE
  g1.playerMove = 0; // X first move (0 or 1)
  g1.winner = 2; // draw default
  int tmpVar = 0; // tmp variable for check user input (1,2,3...9)
  
  // GAME
  for (int i = 0; i < 9; i++)
    {
      /*
1|2|3
-+-+-
4|5|6
-+-+-
7|8|9
      */
      // PRINT FIELD TO CONSOLE
      system("clear");
      for (int i = 0; i < 9; i++)
	{
	  std::cout << g1.playersSteps[i];
	  // wall between columns
	  if (((i%3) == 0) || (((i-1)%3) == 0)) { std::cout << '|'; }
	  // new line
	  if (((i+1)%3) == 0) { std::cout << std::endl; }
	  // wall between rows
	  if ((i == 2) || (i == 5)) { std::cout << "-+-+-" << std::endl; }
	}
      // MOVE
      // user input check
      while (true)
	{
	  // user input
	  if (g1.playerMove == 0)
	    { std::cout << "X user move: "; }
	  else
	    { std::cout << "O user move: "; }
	  std::cin >> tmpVar;
	  // input check 1 (1,2,3...9)
	  if ((tmpVar < 1) || (tmpVar > 9))
	    {
	      std::cout << "ERROR: Enter cell number from game field only!" << std::endl;
	      continue;
	    }
	  // input check 3 (FREE cell number from game field)
	  else
	    {
	      if (g1.playersSteps[tmpVar-1] == 'X' ||
		  g1.playersSteps[tmpVar-1] == 'O')
		{
		  std::cout << "ERROR: Enter free cell number only!" << std::endl;
		  continue;
		}
	      // correct user input
	      else
		{
		  std::cout << "Your move is done!" << std::endl;
		  break;
		}
	    }
	}
      // X MOVE
      if (g1.playerMove == 0)
	{
	  g1.playersSteps[tmpVar-1] = 'X';
	  g1.playerMove = 1;
	  // X WINNER CHECK
	  if (i > 2)
	    {
	      for (int i = 0; i < 8; i++)
		{
		  if (g1.playersSteps[g1.victOpt[i][0]] == 'X' &&
		      g1.playersSteps[g1.victOpt[i][1]] == 'X' &&
		      g1.playersSteps[g1.victOpt[i][2]] == 'X')
		    {
		      g1.winner = 0;
		      break;
		    }
		}
	    }
	}
      // O MOVE
      else if (g1.playerMove == 1)
	{
	  g1.playersSteps[tmpVar-1] = 'O';
	  g1.playerMove = 0;
	  // O WINNER CHECK
	  if (i > 2)
	    {
	      for (int i = 0; i < 8; i++)
		{
		  if (g1.playersSteps[g1.victOpt[i][0]] == 'O' &&
		      g1.playersSteps[g1.victOpt[i][1]] == 'O' &&
		      g1.playersSteps[g1.victOpt[i][2]] == 'O')
		    {
		      g1.winner = 1;
		      break;
		    }
		}
	    }
	}
      // END GAME CHECK
      if (g1.winner == 0)
	{
	  system("clear");
	  std::cout << "WINNER is X-player!" << std::endl;
	  break;
	}
      else if (g1.winner == 1)
	{
	  system("clear");
	  std::cout << "WINNER is O-player!" << std::endl;
	  break;
	}
    }
  // DRAW
  if (g1.winner == 2)
    {
      system("clear");
      std::cout << "DRAW!" << std::endl;
      
    }
  // PRINT FIELD TO CONSOLE
      for (int i = 0; i < 9; i++)
	{
	  std::cout << g1.playersSteps[i];
	  // wall between columns
	  if (((i%3) == 0) || (((i-1)%3) == 0)) { std::cout << '|'; }
	  // new line
	  if (((i+1)%3) == 0) { std::cout << std::endl; }
	  // wall between rows
	  if ((i == 2) || (i == 5)) { std::cout << "-+-+-" << std::endl; }
	}
  
  // TASK 5**
  std::cout << "#########TASK 5 - " << std::endl;
  return 0;
}
