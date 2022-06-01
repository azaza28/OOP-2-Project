#include "User.h"

User::User()
{
    User("Not Set","Not Set","Not Set","Not Set");
}

User::User(string name, string login, string password, string type)
{
    this->name=name;
    this->login=login;
    this->password=password;
    this->type=type;
}

void User::SetUser()
{
    cout<<" Insert '0' to EXIT.\n";
    cout<<" As that is your first session. Please\n";
    ChangeName();
    if(name=="0")
    {
        system("CLS");
        cout << "  ___________________________ "<<endl;
        cout << " |                           |"<<endl;
        cout << " |    CANCELING OPERATION    |"<<endl;
        cout << " |___________________________|"<<endl<<endl;
        Freeze(3);
        system("CLS");
        return;
    }
    ChangeLogin();
    if(login=="0")
    {
        system("CLS");
        cout << "  ___________________________ "<<endl;
        cout << " |                           |"<<endl;
        cout << " |    CANCELING OPERATION    |"<<endl;
        cout << " |___________________________|"<<endl<<endl;
        Freeze(3);
        system("CLS");
        return;
    }
    ChangePass();
    if(password=="0")
    {
        system("CLS");
        cout << "  ___________________________ "<<endl;
        cout << " |                           |"<<endl;
        cout << " |    CANCELING OPERATION    |"<<endl;
        cout << " |___________________________|"<<endl<<endl;
        Freeze(3);
        system("CLS");
        return;
    }
    if(name!="0" && login!="0" && password!="0")
    {
    cout<<" Account has been created successfully.\n";
    AccInfo();
    Freeze(3);
    ofstream file;
    file.open(".\\Users\\"+login+".txt", ios::out);
    file<<name<<endl;
    file<<login<<endl;
    file<<password<<endl;
    file.close();
    }
}

void User:: ChangeName()
{
    cout<<" Insert New Name: ";
    string inp = "";
    char a;
    for (int i = 0;;)
    {
        a = _getch();
        if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || a=='0')
        {
            if (i==0)
            {
                a=toupper(a);
            }
            inp += a;
            ++i;
            cout << a;
        }
        if (a == '\b' && i >= 1)
        {
            inp.pop_back();
            cout << "\b \b";
            --i;
        }
        if (a == '\r' && inp != "")
        {
            break;
        }
    }
    cout << endl;
    name=inp;
}

void User::ChangeLogin()
{
    cout<<" Insert New Login: ";
    string inp = "";
    char a;
    for (int i = 0;;)
    {
        a = _getch();
        if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9'))
        {
            inp += a;
            ++i;
            cout << a;
        }
        if (a == '\b' && i >= 1)
        {
            inp.pop_back();
            cout << "\b \b";
            --i;
        }
        if (a == '\r' && inp != "")
        {
            ifstream file(".\\Users\\"+inp+".txt",ios::in);
            if(file.good())
            {
                system("CLS");
                cout << "  ___________________________ "<<endl;
                cout << " |                           |"<<endl;
                cout << " |  UNFORTUNATELY THIS LOGIN |"<<endl;
                cout << " |  HAS BEEN TAKEN ALREADY   |"<<endl;
                cout << " |         TRY AGAIN         |"<<endl;
                cout << " |___________________________|"<<endl<<endl;
                Freeze(3);
                file.close();
                system("CLS");
                ChangeLogin();
                break;
            }
            else
                {
                    cout << endl;
                    login=inp;
                    break;
                }
        }
    }
}

void User::ChangePass()
{
    cout<<" Insert New Password: ";
    string inp = "";
    char a;
    for (int i = 0;;)
    {
        a = _getch();
        if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9'))
        {
            inp += a;
            ++i;
            cout << a;
        }
        if (a == '\b' && i >= 1)
        {
            inp.pop_back();
            cout << "\b \b";
            --i;
        }
        if (a == '\r' && inp != "")
        {
            break;
        }
    }
    cout << endl;
    password=inp;
}

string User::GetName()
{
    return name;
}
string User::GetLogin()
{
    return login;
}

string User::GetPass()
{
    return password;
}

void User::AccInfo()
{
    cout<<" Your Name: "<<name<<endl;
    cout<<" Your Login: "<<login<<endl;
    cout<<" Your Password: "<<password<<endl;
}


void User::change_password_file()
{   string cur_password;
    cout<<" Insert '0' to EXIT.\n";
    cout << " In order to set a new password We have verify your current password " << endl;
    cout << " Current Password: ";
    cin >> cur_password;
    if(cur_password=="0")
    {
        system("CLS");
        cout << "  ___________________________ "<<endl;
        cout << " |                           |"<<endl;
        cout << " |    CANCELING OPERATION    |"<<endl;
        cout << " |___________________________|"<<endl<<endl;
        Freeze(3);
        system("CLS");
        return;
    }
    if(cur_password == password)
    {
        ChangePass();
        ofstream file;
        file.open(".\\Users\\"+login+".txt", ios::out);
        file<<name<<endl;
        file<<login<<endl;
        file<<password<<endl;
        file<<type<<endl;
        file.close();
        cout << " Your password has been succesfully changed - congratulations" << endl;
    }else
    {
        system("CLS");
        cout << "  ___________________________ "<<endl;
        cout << " |                           |"<<endl;
        cout << " |       WRONG PASSWORD      |"<<endl;
        cout << " |          TRY AGAIN        |"<<endl;
        cout << " |___________________________|"<<endl<<endl;
        Freeze(3);
        system("CLS");
        change_password_file();
    }
}
