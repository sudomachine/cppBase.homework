

class IGenericPlayer
{
 public:
  virtual void move() = 0;
  virtual void setUnitToField(unsigned short fieldCell) = 0;
  virtual bool isValidMove(unsigned short fieldCell) = 0;
  virtual unsigned short getFieldCellFromPlayer() = 0;
};

  /*
move
- getFieldCellFromPlayer
- isValidMove ?
- setUnitToField
   */
