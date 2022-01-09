
#pragma once
#include "CGame.h"
#include <iostream>

int main()
{
  srand(time(0));
  CGame fg(3, 3, "MyMachine", "Sudakov");

  fg.declareSides();
  for (int i = 0; i < 9; i++)
    {
      // clear terminal
      fg.printGameField();
      fg.declareCurrentMove();
      fg.makeMove();
      if (fg.checkMoveForWinner())
	{
	  break;
	}
      fg.changeCurrentMove();
      std::cout << "Press any key...";
      std::cin.ignore();
      system("clear");
    }
  fg.printGameField();
  fg.declareGameResult();
}
