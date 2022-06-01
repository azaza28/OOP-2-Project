#pragma once
#include "Hall.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include "Freeze.h"
using namespace std;
class Cinema
{
protected:
    int hall_num;
    int movie_num;
    float financial_situation;
public:
    Hall* halls=NULL;
    Movie *movies=NULL;
    Cinema();
    ~Cinema();
    int GetHallNum();
    void SetHalls();
    int GetMovieNum();
    void GetHalls();
    void OpenCinema();
    void ShowMovies();
    void SaveCinema();
    void DeleteMovie();
    void PrintHall();
    float GetFinance();
    void IncreaseFinance(float amount);
    void DecreaseFinance(float amount);
    void Save_Finance();
    void EditMovie();
    void SetMovie();
};
    string SetDate();
    string SetTime();
