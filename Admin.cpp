#include "Admin.h"


void Admin::SetAdmin()
{
    SetUser();
    type="Admin";
    ofstream file;
    if(name!="" || password!="" || login!="")
    {
    file.open(".\\Users\\"+login+".txt",ios::app);
    file<<type<<endl;
    file.close();
    }
}

Admin::Admin()
{

}

Admin::Admin(string login_name, string Name, string passw)
{
        User::login = login_name;
        User::name = Name;
        User::password = passw;
        User::type = "Admin";
}
Admin::~Admin()
{

}

void Admin::ShowMovies(Cinema c)
{
    c.ShowMovies();
}

void Admin::ShowHalls(Cinema c)
{
    c.GetHalls();
}
void Admin::PrintCertainHall(Cinema c)
{
    c.PrintHall();
}
