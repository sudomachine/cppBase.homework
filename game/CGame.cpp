
#pragma once
#include "CGame.h"
#include <iostream>

// constr
CGame::CGame(unsigned short sizeByHorizontal,
	     unsigned short sizeByVertical,
	     const char* computerName,
	     const char* playerName)
{
  m_sizeByHorizontal = sizeByHorizontal;
  m_sizeByVertical = sizeByVertical;
  m_numberOfMoves = sizeByHorizontal * sizeByVertical;
  // 1. memory allocation !!!
  m_field = new char[m_numberOfMoves];
  for (unsigned short i = 0; i < m_numberOfMoves; i++)
    {
      m_field[i] = 48+i+1;
    }
  // random assignment: X or O (50/50); X side player always goes first
  char computerSide = ((rand() % 2) == 0) ? 'X' : 'O';
  // opposite value: X-->O, O-->X
  char playerSide = (computerSide == 'X') ? 'O' : 'X';
  // 2. memory allocation !!!
  m_computer = new CComputer(computerName, computerSide);
  // 3. memory allocation !!!
  m_player = new CPlayer(playerName, playerSide);
  m_winner = '?'; // default value
  // X side player always goes first
  if (computerSide == 'X')
    {
      m_currentMove = m_computer;
    }
  else
    {
      m_currentMove = m_player;
    }
}

// destr
CGame::~CGame()
{
  // 1. freeing up memory
  delete[] m_field;
  // 2. freeing up memory
  delete m_computer;
  // 3. freeing up memory
  delete m_player;
}

void CGame::makeMove()
{
  unsigned short cellFromPlayer;// = m_currentMove->getFieldCellFromPlayer() - 1;
  while (true)
    {
      cellFromPlayer = m_currentMove->getFieldCellFromPlayer() - 1;
      // from 0 to 8
      if (cellFromPlayer < 0 || cellFromPlayer > 8)
	{
	  if (m_currentMove == m_player)
	    {
	      std::cout << "Wrong cell of game field!" << std::endl;
	    }
	  continue;
	}
      // field cell is not empty
      else if (m_field[cellFromPlayer] == 'X' || m_field[cellFromPlayer] == 'O')
	{
	  if (m_currentMove == m_player)
	    {
	      std::cout << cellFromPlayer+1 << " cell is not empty!" << std::endl;
	    }
	  continue;
	}
      // correct field cell from player or computer
      else
	{
	  m_field[cellFromPlayer] = m_currentMove->getSide();
	  break;
	}
    }
  // print to console the number of cell which mahcine is chose
  if (m_currentMove == m_computer)
    {
      std::cout << m_currentMove->getName() << " moved on " << cellFromPlayer+1 << " cell." << std::endl; 
    }
}
bool CGame::checkMoveForWinner()
{
  // check each victory option (m_numberOfVictoryOptions)
  for (int i = 0; i < m_numberOfVictoryOptions; i++)
    {
      // check each unit (field index) on the game field (X or O) (m_numberOfUnitsForVictory)
      for (int j = 0; j < m_numberOfUnitsForVictory; j++)
	{
	  // each unit must be X or O for victory
	  if (m_field[m_victoryOptions[i][j]] != m_currentMove->getSide())
	    {
	      break;
	    }
	  // if all three units are current player side (X or O) then it is victory!
	  if (j == m_numberOfUnitsForVictory-1)
	    {
	      m_winner = m_currentMove->getSide();
	    }
	}
      // exit from checking
      if (m_winner != '?')
	{
	  break;
	}
    }
  
  if (m_winner == '?')
    {
      return false;
    }
  else
    {
      return true;
    }
}
void CGame::declareGameResult(const char* TEXT_FOR_WINNER,
			      const char* TEXT_FOR_DRAW)
{
  if (m_winner == '?')
    {
      this->declareDraw(TEXT_FOR_DRAW);
    }
  // winner is X or O
  else
    {
      this->declareWinner(TEXT_FOR_WINNER);
    }
}
void CGame::declareDraw(const char* TEXT_FOR_DRAW)
{
  std::cout << "Draw!" << std::endl;
  if (TEXT_FOR_DRAW)
    {
      std::cout << TEXT_FOR_DRAW << std::endl;
    }
}
void CGame::declareWinner(const char* TEXT_FOR_WINNER)
{
  std::cout << "Winner is " << m_currentMove->getName() \
	    << " (" << m_currentMove->getSide() << ")" << std::endl;
  if (TEXT_FOR_WINNER)
    {
      std::cout << TEXT_FOR_WINNER << std::endl;
    }
}
void CGame::declareCurrentMove()
{
  std::cout << "Current move: " << m_currentMove->getName() \
	    << " (" << m_currentMove->getSide() << ")" << std::endl;
}
void CGame::declareSides()
{
  std::cout << "Side " << m_player->getSide() << " - " << m_player->getName() << std::endl;
  std::cout << "Side " << m_computer->getSide() << " - " << m_computer->getName() << std::endl;
}

void CGame::changeCurrentMove()
{
  if (m_currentMove->getSide() == m_computer->getSide())
    {
      m_currentMove = m_player;
    }
  else
    {
      m_currentMove = m_computer;
    }
}
/*
char CGame::getWinnerStatus() const
{
  // ? or X or O
  return m_winner;
}
*/

void CGame::printGameField() const
{
  // field printing
  for (unsigned short v = 0; v < m_sizeByVertical; v++)
    {
      // +-+-+ printing
      for (unsigned short h2 = 0; h2 < m_sizeByHorizontal; h2++)
	{
	  std::cout << "+-";
	}
      std::cout << "+" << std::endl;
      // |X|O|X| printing
      for (unsigned short h = 0; h < m_sizeByHorizontal; h++)
	{
	  std::cout << "|" << m_field[v * m_sizeByHorizontal + h];
	}
      std::cout << "|" << std::endl;
    }
  // +-+-+ last printing
  for (unsigned short h2 = 0; h2 < m_sizeByHorizontal; h2++)
    {
      std::cout << "+-";
    }
  std::cout << "+" << std::endl;
}
