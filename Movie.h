#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "StrToInt.h"
#include "GetNumber.h"

using namespace std;

class Movie
{
protected:
    string name;
    string time;
    string date;
    string hall;
    float price;
public:
    Movie();
    void SetMovie(string n, string d, string t, string h,float p);
    ~Movie();
    void SetMovie();
    void ChangeHall();
    void ChangeTime();
    void ChangeDate();
    void ChangeName();
    string GetHall();
    string GetTime();
    string GetDate();
    string GetName();
    string SetDate();
    string SetTime();
    void DeleteMovie();
    void Display();
    float GetPrice();
    void ChangePrice();
};
