
#pragma once
#include "CComputer.h"
#include "CPlayer.h"

class CGame
{
private:
  unsigned short m_sizeByHorizontal;
  unsigned short m_sizeByVertical;
  unsigned short m_numberOfMoves;
  char* m_field;
  CComputer* m_computer;
  CPlayer* m_player;
  char m_winner; // 'X' or 'O', default '?'
  // pointer (switcher) to computer or player
  // X side player always goes first
  IGenericPlayer* m_currentMove;
  static const unsigned short m_numberOfVictoryOptions = 8;
  static const unsigned short m_numberOfUnitsForVictory = 3;
  const unsigned short m_victoryOptions[m_numberOfVictoryOptions][m_numberOfUnitsForVictory] = {
					   {0,1,2}, {3,4,5}, {6,7,8},
					   {0,3,6}, {1,4,7}, {2,5,8},
					   {0,4,8}, {2,4,6}
  };
private:
  void declareDraw(const char* TEXT_FOR_DRAW);
  void declareWinner(const char* TEXT_FOR_WINNER);
public:
  CGame(unsigned short sizeByHorizontal,
	unsigned short sizeByVertical,
	const char* computerName,
	const char* playerName);
  ~CGame();
  void declareGameResult(const char* TEXT_FOR_WINNER = 0,
			 const char* TEXT_FOR_DRAW = 0);
  void makeMove();
  bool checkMoveForWinner();
  void declareCurrentMove();
  void declareSides();
  //char getWinnerStatus() const;
  void changeCurrentMove();
  void printGameField() const;
};
