
#pragma once
#include "CPlayer.h"
#include "CComputer.h"
#include <iostream>

int main()
{
  srand(time(0));
  CPlayer human("Sudakov", 'X');
  CComputer ai("Jack", 'O');
  return 0;
}
