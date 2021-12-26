
#pragma once
#include "IGenericPlayer.h"

class CPlayer: public IGenericPlayer
{
 private:
  const char* m_name;
  char m_side;
 public:
  CPlayer(const char* name, const char side);
  ~CPlayer();
  unsigned short getFieldCellFromPlayer();
  const char getSide() const;
  const char* getName() const;
};
