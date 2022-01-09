
#pragma once
#include "CComputer.h"
#include <iostream>

CComputer::CComputer(const char* name, char side)
{
  // constr
  m_name = name;
  m_side = side;
}

CComputer::~CComputer()
{
  // destr
}

unsigned short CComputer::getFieldCellFromPlayer()
{
  unsigned short fieldCell = 0;
  fieldCell = rand() % 9; // from 0 to 8
  return fieldCell;
}

const char CComputer::getSide() const
{
  return m_side;
}

const char* CComputer::getName() const
{
  return m_name;
}
