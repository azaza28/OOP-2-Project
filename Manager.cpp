#include "Manager.h"
void Manager::SetManager()
{
    SetUser();
    type="Manager";
    ofstream file;
    if(name!="0" && password!="0" && login!="0")
    {
    file.open(".\\Users\\"+login+".txt",ios::app);
    file<<type<<endl;
    file.close();
    }
}

Manager::Manager()
{

}

Manager::Manager(string name, string login, string passw)
{
    User::login = login;
    User::name = name;
    User::password = passw;
    User::type = "Manager";
}

Manager::~Manager()
{

}

