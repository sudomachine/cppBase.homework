

class IGenericPlayer
{
 public:
  virtual ~IGenericPlayer() {}
  virtual void move() = 0;
  virtual void setUnitToField(unsigned short fieldCell) = 0;
  virtual bool isValidMove(unsigned short fieldCell) = 0;
  virtual unsigned short getFieldCellFromPlayer() = 0;
  virtual void setSide(const char side) = 0;
  virtual const char getSide() = 0;
  virtual const char* getName() = 0;
};

  /*
move
- getFieldCellFromPlayer
- isValidMove ?
- setUnitToField
   */
