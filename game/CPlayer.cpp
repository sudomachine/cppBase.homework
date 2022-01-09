
#pragma once
#include "CPlayer.h"
#include <iostream>

CPlayer::CPlayer(const char* name, const char side)
{
  // constr
  m_name = name;
  m_side = side;
}
CPlayer::~CPlayer()
{
  // destr
}

unsigned short CPlayer::getFieldCellFromPlayer()
{
  unsigned short fieldCell = 0;
  std::cout << "Enter field cell to move >> ";
  std::cin >> fieldCell;
  return fieldCell;
}

const char CPlayer::getSide() const
{
  if (m_side)
    {
      return m_side;
    }
  else
    {
      return '?';
    }
}

const char* CPlayer::getName() const
{
  return m_name;
}




