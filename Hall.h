#pragma once
#include "Seat.h"
#include "GetNumber.h"
#include <fstream>
#include <string>
#include "Movie.h"
using namespace std;

class Hall
{
protected:
    int rows, columns;
    string name;
    float price;
    Seat *seats=NULL;
public:
    Hall();
    ~Hall();
    void SetHall();
    void printhall();
    void Occupy_Free(int number);
    void OpenHall(string n, int r, int c, float p);
    void ChangeName();
    string GetName();
    int GetRows();
    int GetColumns();
    float GetPrice();
    void SaveHall();
    bool Check(int number);
};

void line1(int column);
void line2(int column);
void line3(int column);
void line5(int column);
void line6(int column);
