#pragma once
#include <iostream>
class Seat
{
public:
    int row, column;
    bool vacant=true;
public:
    Seat(int row, int column);
    ~Seat();
    Seat();
    bool check();
    int GetRow();
    void occupy_free();
};

