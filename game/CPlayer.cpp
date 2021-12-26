
#pragma once
#include "CPlayer.h"

CPlayer::CPlayer(const char* name)
{
  // constr
  m_name = name;
}
CPlayer::~CPlayer()
{
  // destr
}

void CPlayer::move()
{
  // func body
}

void CPlayer::setUnitToField(unsigned short fieldCell)
{
  // func body
}

bool CPlayer::isValidMove(unsigned short fieldCell)
{
  // func body
  return true;
}

unsigned short CPlayer::getFieldCellFromPlayer()
{
  // func body
  return 0;
}

void CPlayer::setSide(const char side)
{
  // func body
}

const char CPlayer::getSide()
{
  // func body
  return 'X';
}

const char* CPlayer::getName()
{
  // func body
  return "Sudakov";
}




