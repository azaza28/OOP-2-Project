#pragma once
#include <iostream>
#include <string>
#include "Cinema.h"
using namespace std;
class Ticket
{
protected:
    string time,movie, hall,date;
    int seat;
public:
    Ticket();
    void PrintTicket();
    void SetTicket(string movie,string date, string time, string hall,int seat);
    string GetHall();
    string GetMovie();
    string GetDate();
    string GetTime();
    int GetSeat();
};
