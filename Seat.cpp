#include "Seat.h"
Seat::Seat(int row, int column)
{
    this->row=row;
    this->column=column;
}
Seat::Seat()
{
    row=0;
    column=0;
}
Seat::~Seat()
{

}

int Seat::GetRow()
{
    return row;
}

bool Seat:: check()
{
    return vacant;
}
void Seat::occupy_free()
{
    this->vacant = !vacant;
}
