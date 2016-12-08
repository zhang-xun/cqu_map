#include "pointer.h"

Pointer::Pointer()
{
    this->x = 0;
    this->y = 0;
}


Pointer::Pointer(int x, int y)
{
    this->x = x;
    this->y = y;
}



int Pointer::getx()
{
    return this->x;
}


int Pointer::gety()
{
    return this->y;
}
