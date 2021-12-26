
#pragma once
#include "IGenericPlayer.h"

class CPlayer: public IGenericPlayer
{
 private:
  const char* m_name;
  char m_side;
 public:
  CPlayer(const char* name);
  ~CPlayer();
  void move();
  void setUnitToField(unsigned short fieldCell);
  bool isValidMove(unsigned short fieldCell);
  unsigned short getFieldCellFromPlayer();
  void setSide(const char side);
  const char getSide();
  const char* getName();
};
