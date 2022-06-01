#pragma once
#include <string>
#include <iostream>
#include <conio.h>
#include <fstream>
#include <sys/stat.h>
#include "Freeze.h"

using namespace std;
class User
{
protected:
    string name, login, password,type;
    int user_num=0;
public:
    User();
    User(string name, string login, string password, string type);
    void SetUser();
    void ChangeName();
    void ChangePass();
    void ChangeLogin();
    string GetName();
    string GetLogin();
    string GetPass();
    void AccInfo();
    void change_password_file();
};
