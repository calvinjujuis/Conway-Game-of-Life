#ifndef _CELL_H_
#define _CELL_H_

class Cell {
  public:
    virtual bool getState() = 0;
    virtual void setAlive() = 0;
    virtual void setDead() = 0;
    virtual void flip() = 0;
    virtual void updateNeighbours(int live) = 0;
    virtual int getLive() = 0;
    virtual void update() = 0;
    virtual ~Cell();
};

#endif