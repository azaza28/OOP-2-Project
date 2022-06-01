#pragma once
#include <iostream>
#include "Admin.h"
#include <fstream>
#include <string>
using namespace std;

class Manager:public Admin
{
public:
    Manager();
    Manager(string name, string login, string passw);
    ~Manager();
    void SetManager();
    void SeeMovies();
};
