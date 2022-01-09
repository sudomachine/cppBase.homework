
#pragma once
#include "IGenericPlayer.h"

class CComputer: public IGenericPlayer
{
 private:
  const char* m_name;
  char m_side;
 public:
  CComputer(const char* name, char side);
  ~CComputer();
  unsigned short getFieldCellFromPlayer();
  const char getSide() const;
  const char* getName() const;
};
