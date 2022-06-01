#pragma once
#include <iostream>
#include <string>
#include "User.h"
#include "Cinema.h"
class Admin:public User
{
public:
    Admin();
    Admin(string login_name, string Name, string passw); // parametrized constructor
    ~Admin();
    void SetAdmin();
    void ShowMovies(Cinema c);
    void ShowHalls(Cinema c);
    void PrintCertainHall(Cinema c);
};
