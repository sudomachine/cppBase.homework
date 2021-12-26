

class IGenericPlayer
{
 public:
  virtual ~IGenericPlayer() {}
  virtual unsigned short getFieldCellFromPlayer() = 0;
  virtual const char getSide() const = 0;
  virtual const char* getName() const = 0;
};
