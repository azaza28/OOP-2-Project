#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <thread>
#include "Cinema.h"
#include "Customer.h"
#include "Manager.h"
#include "Freeze.h"

using namespace std;

void Auth();
void CreateAcc();
void Customer_menu(Customer & c);
void Manager_menu(Manager &c);
void Admin_menu(Admin &a);

void menu()
{
    //Check the cinema in here
        int choice;   // for switch
        do{
            cout << "  ___________________________ "<<endl;
            cout << " |                           |"<<endl;
            cout << " |       ~~~MAIN MENU~~~     |"<<endl;
            cout << " |___________________________|"<<endl;
            cout << " |                           |"<<endl;
            cout << " | 1.Sign in to your account |"  << endl;
            cout << " |___________________________|"<<endl;
            cout << " |                           |"<<endl;
            cout << " | 2.Register a new account  |" << endl;
            cout << " |___________________________|"<<endl;
            cout << " |                           |"<<endl;
            cout << " |         3. EXIT           |" << endl;
            cout << " |___________________________|"<<endl<<endl;
            cout << " CHOICE: ";
            cin >> choice;
            switch(choice)
            {
            case 1:
                system("CLS");
                Auth();
                break;
            case 2:
                system("CLS");
                CreateAcc();
                cout << endl;
                break;
            case 3:
                system("CLS");
                cout << " ~~~GOOD BYE~~~" << endl;
                cout << " ~~~GOOD BYE~~~" << endl;
                cout << " ~~~GOOD BYE~~~" << endl;
                Freeze(2);
                exit(0);
                break;
            default:
                system("CLS");
                    cout << "  ___________________________ "<<endl;
                    cout << " |                           |"<<endl;
                    cout << " | CHOOSE FROM GIVEN OPTIONS |"<<endl;
                    cout << " |___________________________|"<<endl<<endl;
                Freeze(3);
                system("CLS");
                break;
            }

        }while(choice != 3);
}

void recover_acc()
{
    cout << "  ___________________________ "<<endl;
    cout << " |                           |"<<endl;
    cout << " |   ACCOUNT RECOVERY TOOL   |"<< endl;
    cout << " |___________________________|"<<endl<<endl;
    cout << " In order to RECOVER your account - you should enter your Name and Login" << endl;
    string name, username;
    cout << " Enter your Name: ";
    cin >> name;
    cout << " Enter your Login: ";
    cin >> username;
    string name_of_user, login_user, password_user, type_user, balance;
    fstream file;
    file.open(".\\Users\\"+username+".txt", ios::in);
    if (file.good())
    {
        getline(file,name_of_user);
        getline(file,login_user);
        getline(file,password_user);
        getline(file,type_user);
        if(type_user == "Customer")
        {   getline(file,balance);
            if(login_user == username && name_of_user == name)
            {
                cout<<endl;
                cout << " Your account has been recovered" << endl;
                cout << " Your account's Information is following: " << endl;
                cout << " Name: " << name_of_user << endl;
                cout << " Login: " << login_user << endl;
                cout << " Password: " << password_user << endl;
                cout << " Type: " << type_user << endl;
                cout << " Balance: " << balance << endl;
                Freeze(3);
                system("CLS");
            }
            else
            {
                cout << " Your account has not been recovered." << endl;
                Freeze(3);
                system("CLS");
                menu();
            }
        }
        else
        {
            if(login_user == username && name_of_user == name)
            {
                cout << " Your account has been recovered" << endl;
                cout << " Your account' Information is following: " << endl;
                cout << " Name: " << name_of_user << endl;
                cout << " Login: " << login_user << endl;
                cout << " Password: " << password_user << endl;
                cout << " Type: " << type_user << endl;
            }
            else
            {
                cout << " Your account has not been recovered." << endl;
                Freeze(3);
                system("CLS");
                menu();
            }
        }
    }
}

void CreateAcc()
{
    cout << "  ___________________________ "<<endl;
    cout << " |                           |"<<endl;
    cout << " |      CREATE ACCOUNT       |"<<endl;
    cout << " |___________________________|"<<endl<<endl;
    cout << "     WHAT IS YOUR POSITION:   "<<endl;
    cout << "  ___________________________ "<<endl;
    cout << " |                           |"<<endl;
    cout << " |         1.Customer        |"<<endl;
    cout << " |___________________________|"<<endl;
    cout << " |                           |"<<endl;
    cout << " |         2.Admin           |"<<endl;
    cout << " |___________________________|"<<endl;
    cout << " |                           |"<<endl;
    cout << " |         3.Manager         |"<<endl;
    cout << " |___________________________|"<<endl<<endl;
    cout<<" Insert '0' to go back\n";
    cout<<"\n CHOICE: ";
    int ch=GetNumber();
    if(ch<0 || ch>3)
    {
        system("CLS");
        cout << "  ___________________________ "<<endl;
        cout << " |                           |"<<endl;
        cout << " |        WRONG INPUT        |"<<endl;
        cout << " |___________________________|"<<endl<<endl;
        Freeze(3);
        system("CLS");
        return;
    }
    if(ch==0)
    {
        system("CLS");
        cout << "  ___________________________ "<<endl;
        cout << " |                           |"<<endl;
        cout << " |    CANCELING OPERATION    |"<<endl;
        cout << " |___________________________|"<<endl<<endl;
        Freeze(3);
        system("CLS");
        menu();
    }
    if(ch==1)
    {
        system("CLS");
        Customer c;
        c.SetCustomer();
    }
    if(ch==2)
    {
        system("CLS");
        Admin a;
        a.SetAdmin();
    }
    if(ch==3)
    {
        system("CLS");
        Manager m;
        m.SetManager();
    }
    system("CLS");
    Auth();
}

void Auth()
{
    int error_trials_number = 0;
    string login="";
while(true)
{
    cout << "  ___________________________ "<<endl;
    cout << " |                           |"<<endl;
    cout << " |       AUTHENTICATION      |"<<endl;
    cout << " |___________________________|"<<endl<<endl;
    cout<<" Insert '0' to go back.\n";
    cout<<" Login name: ";
    if (login=="")
    {
        cin>>login;
    }
    else
    {
        cout<<login<<endl;
    }
    if(login=="0")
    {
        system("CLS");
        cout << "  ___________________________ "<<endl;
        cout << " |                           |"<<endl;
        cout << " |    CANCELING OPERATION    |"<<endl;
        cout << " |___________________________|"<<endl<<endl;
        menu();
    }
    ifstream file;
    string name,password,type;
    file.open(".\\Users\\"+login+".txt", ios::in);
    if(!file.good())
    {
        system("CLS");
        cout << "  ___________________________ "<<endl;
        cout << " |                           |"<<endl;
        cout << " |      NO SUCH ACCOUNT      |"<<endl;
        cout << " |      LET'S CREATE NEW     |"<<endl;
        cout << " |___________________________|"<<endl<<endl;
        Freeze(2);
        system("CLS");
        CreateAcc();
        Auth();
    }
    getline(file,name);
    getline(file,login);
    getline(file,password);
    getline(file,type);
    cout<<" Password: ";
    char a;
    string pass = "";
    //Reads character by character the password without showing it to user
    for (int i = 0;;)
    {
        a = _getch();
        if (a == '\r' && pass == "0")
        {
            system("CLS");
            cout << "  ___________________________ "<<endl;
            cout << " |                           |"<<endl;
            cout << " |    CANCELING OPERATION    |"<<endl;
            cout << " |___________________________|"<<endl<<endl;
            Auth();
        }
            if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9'))
            {
                pass += a;
                ++i;
                cout << "*";
            }
            if (a == '\b' && i >= 1)
            {
                pass.pop_back();
                cout << "\b \b";
                --i;
            }
            if (a == '\r' && pass != "")
            {
                break;
            }
        }
    cout << endl;


    if(pass!=password)
    {
        system("CLS");
        error_trials_number += 1;
        cout << "  ___________________________ "<<endl;
        cout << " |                           |"<<endl;
        cout << " |       WRONG PASSWORD      |"<<endl;
        cout << " |___________________________|"<<endl<<endl;
        Freeze(2);
        system("CLS");
        if(error_trials_number == 3)
        {
            int ch_2;
            cout << " It seems you are having a trouble with your memory" << endl;
            cout << " 1. Let's Create a new account.\n";
            cout << " 2. Recover your account " << endl;
            //cout << "Do you want to create a new account ?[y/n]" << endl;
            cout<<" Choice: ";
            string num = "";
            char a;
            for (int i = 0;;)//reads 1 | 2
            {
                a = _getch();
                if (a>='1' && a<='2' && i < 1)
                {
                    num += a;
                    ++i;
                    cout << a;
                }
                if (a == '\b' && i >= 1)
                {
                    num.pop_back();
                    cout << "\b \b";
                    --i;
                }
                if (a == '\r' && num != "")
                {
                    break;
                }
            }
            cout << endl;
            ch_2 = ToInt(num);
            if(ch_2 == 1)
            {
                system("CLS");
                CreateAcc();
                Auth();
            }
            else if(ch_2 == 2)
            {
                system("CLS");
                recover_acc();
                error_trials_number = 0;
            }
        }
    }
    else
        {
        if(type=="Customer")
        {
            string balance;
            float bal;
            getline(file,balance);
            bal=stof(balance);//converting string to float
            file.close();
            Customer c(name,login,password,bal);
            Customer_menu(c);//parametrized constructor
            menu();
        }
        else if(type=="Admin")
        {
            file.close();
            Admin a(login,name,password);
            Admin_menu(a);
            menu();
        }
        else if(type=="Manager")
        {
            file.close();
            Manager m(name,login,password);
            Manager_menu(m);
            menu();
        }
        }
    }
}


int main()
{
    ifstream cinema_file;
    cinema_file.open(".\\Cinema\\Cinema.txt", ios::in);
    if(!cinema_file.good())
    {
        Cinema c;
        c.SetHalls();
        system("CLS");
    }
    menu();
    system("pause");
    return 0;
}



void Customer_menu(Customer &customer)
{   system("CLS");
    Cinema c;
    cout << "  ___________________________ "<<endl;
    cout << " |                           |"<<endl;
    cout << " |       CUSTOMER MENU       |"<<endl;
    cout << " |___________________________|"<<endl<<endl;
    cout << " Customer: " << customer.GetName() << endl;
    int choi;
    do
    {
        c.OpenCinema();
        system("CLS");
        cout << " Your Balance: $" << customer.GetBalance() << endl<<endl;
        cout << "  ___________________________ "<<endl;
        cout << " |                           |"<<endl;
        cout << " |    1.SEE NEW RELEASES     |"<<endl;
        cout << " |___________________________|"<<endl;
        cout << " |                           |"<<endl;
        cout << " |       2.BUY TICKET        |"<<endl;
        cout << " |___________________________|"<<endl;
        cout << " |                           |"<<endl;
        cout << " |      3.SHOW TICKETS       |"<<endl;
        cout << " |___________________________|"<<endl;
        cout << " |                           |"<<endl;
        cout << " |      4.RETURN TICKET      |"<<endl;
        cout << " |___________________________|"<<endl;
        cout << " |                           |"<<endl;
        cout << " |     5.CHANGE PASSWORD     |"<<endl;
        cout << " |___________________________|"<<endl;
        cout << " |                           |"<<endl;
        cout << " |   6.ACCOUNT INFORMATION   |"<<endl;
        cout << " |___________________________|"<<endl;
        cout << " |                           |"<<endl;
        cout << " |     7.BALANCCE TOP UP     |"<<endl;
        cout << " |___________________________|"<<endl;
        cout << " |                           |"<<endl;
        cout << " |          8.EXIT           |"<<endl;
        cout << " |___________________________|"<<endl<<endl;
        cout << " CHOICE: ";
        cin >> choi;
        switch(choi)
        {
        case 1:
            system("CLS");
            cout << "  ___________________________ "<<endl;
            cout << " |                           |"<<endl;
            cout << " |       NEW RELEASES        |"<<endl;
            cout << " |___________________________|"<<endl<<endl;
            c.ShowMovies();
            break;
        case 2:
            system("CLS");
            cout << "  ___________________________ "<<endl;
            cout << " |                           |"<<endl;
            cout << " |        BUY TICKET         |"<<endl;
            cout << " |___________________________|"<<endl<<endl;
            customer.BuyTicket(c);
            break;
        case 3:
            system("CLS");
            cout << "  ___________________________ "<<endl;
            cout << " |                           |"<<endl;
            cout << " |        YOUR TICKETS       |"<<endl;
            cout << " |___________________________|"<<endl<<endl;
            customer.DisplayTickets();
            break;
        case 4:
            system("CLS");
            cout << "  ___________________________ "<<endl;
            cout << " |                           |"<<endl;
            cout << " |      TICKET RETURN        |"<<endl;
            cout << " |___________________________|"<<endl<<endl;
            customer.ReturnTicket();
            break;
        case 5:
            system("CLS");
            cout << "  ___________________________ "<<endl;
            cout << " |                           |"<<endl;
            cout << " |      CHANGE PASSWORD      |"<<endl;
            cout << " |___________________________|"<<endl<<endl;
            cout<<" Insert '0' to EXIT.\n";
            customer.NewPass();
            break;
        case 6:
            system("CLS");
            cout << "  ___________________________ "<<endl;
            cout << " |                           |"<<endl;
            cout << " |    ACCOUNT INFORMATION    |"<<endl;
            cout << " |___________________________|"<<endl<<endl;
            customer.AccInfo();
            break;
        case 7:
            system("CLS");
            cout << "  ___________________________ "<<endl;
            cout << " |                           |"<<endl;
            cout << " |      BALANCE TOP UP       |"<<endl;
            cout << " |___________________________|"<<endl<<endl;
            cout<<" Insert '0' to EXIT.\n\n";
            customer.BalTopUp();
            break;
        case 8:
            system("CLS");
            menu();
            break;
        default:
            system("CLS");
            cout << "  ___________________________ "<<endl;
            cout << " |                           |"<<endl;
            cout << " | CHOOSE FROM GIVEN OPTIONS |"<<endl;
            cout << " |___________________________|"<<endl<<endl;
            Freeze(3);
            return;
        }
        if(choi!=8)
        {
        cout<<" Do you want to perform anything else?\n";
        int yn;
        yn=YesOrNo();
        if(yn==2)
        {
            system("CLS");
            cout << "  ___________________________ "<<endl;
            cout << " |                           |"<<endl;
            cout << " |   THANK YOU FOR SESSION   |"<<endl;
            cout << " |___________________________|"<<endl<<endl;
            Freeze(3);
            system("CLS");
            menu();
        }
        else
        {
            system("CLS");
        }
    }
    }while(choi != 8);
    system("CLS");

}

void Manager_menu(Manager &manager)
{   Cinema c;
    Movie m;
    cout << "  ___________________________ "<<endl;
    cout << " |                           |"<<endl;
    cout << " |       MANAGER MENU        |"<<endl;
    cout << " |___________________________|"<<endl<<endl;
    cout << " Manager: " << manager.GetName()<< endl;
    int choi;
    do
    {
        c.OpenCinema();
        system("CLS");
        cout << "  ___________________________ "<<endl;
        cout << " |                           |"<<endl;
        cout << " |        1.ADD MOVIE        |"<<endl;
        cout << " |___________________________|"<<endl;
        cout << " |                           |"<<endl;
        cout << " |       2.MOVIES INFO       |"<<endl;
        cout << " |___________________________|"<<endl;
        cout << " |                           |"<<endl;
        cout << " |       3.EDIT MOVIE        |"<<endl;
        cout << " |___________________________|"<<endl;
        cout << " |                           |"<<endl;
        cout << " |      4.DELETE MOVIE       |"<<endl;
        cout << " |___________________________|"<<endl;
        cout << " |                           |"<<endl;
        cout << " |   5.PRINT CERTAIN HALL    |"<<endl;
        cout << " |___________________________|"<<endl;
        cout << " |                           |"<<endl;
        cout << " |       6.SHOW HALLS        |"<<endl;
        cout << " |___________________________|"<<endl;
        cout << " |                           |"<<endl;
        cout << " |    7.CINEMA'S BALANCE     |"<<endl;
        cout << " |___________________________|"<<endl;
        cout << " |                           |"<<endl;
        cout << " |     8.CHANGE PASSWORD     |"<<endl;
        cout << " |___________________________|"<<endl;
        cout << " |                           |"<<endl;
        cout << " |          9. EXIT          |"<<endl;
        cout << " |___________________________|"<<endl<<endl;
        cout<<" CHOICE: ";
        cin >> choi;
        switch(choi)
        {
        case 1:
            system("CLS");
            cout << "  ___________________________ "<<endl;
            cout << " |                           |"<<endl;
            cout << " |         ADD MOVIE         |"<<endl;
            cout << " |___________________________|"<<endl<<endl;
            c.SetMovie();
            break;
        case 2:
            system("CLS");
            cout << "  ___________________________ "<<endl;
            cout << " |                           |"<<endl;
            cout << " |         ALL MOVIES        |"<<endl;
            cout << " |___________________________|"<<endl<<endl;
            c.ShowMovies();
            break;
        case 3:
            system("CLS");
            cout << "  ___________________________ "<<endl;
            cout << " |                           |"<<endl;
            cout << " |         MOVIE EDIT        |"<<endl;
            cout << " |___________________________|"<<endl<<endl;
            c.EditMovie();
            break;
        case 4:
            system("CLS");
            cout << "  ___________________________ "<<endl;
            cout << " |                           |"<<endl;
            cout << " |        MOVIE DELETE       |"<<endl;
            cout << " |___________________________|"<<endl<<endl;
            c.DeleteMovie();
            break;
        case 5:
            system("CLS");
            cout << "  ___________________________ "<<endl;
            cout << " |                           |"<<endl;
            cout << " |        PRINT HALL         |"<<endl;
            cout << " |___________________________|"<<endl<<endl;
            c.PrintHall();
            break;
        case 6:
            system("CLS");
            cout << "  ___________________________ "<<endl;
            cout << " |                           |"<<endl;
            cout << " |         ALL HALLS         |"<<endl;
            cout << " |___________________________|"<<endl<<endl;
            c.GetHalls();
            break;
        case 7:
            system("CLS");
            cout << "  ___________________________ "<<endl;
            cout << " |                           |"<<endl;
            cout << " |          BALANCE          |"<<endl;
            cout << " |___________________________|"<<endl<<endl;
            cout<<" Cinema's Balance: "<<c.GetFinance()<<endl;
            break;
        case 8:
            system("CLS");
            cout << "  ___________________________ "<<endl;
            cout << " |                           |"<<endl;
            cout << " |      CHANGE PASSWORD      |"<<endl;
            cout << " |___________________________|"<<endl<<endl;
            cout<<" Insert '0' to EXIT.\n";
            manager.change_password_file();
            break;
        case 9:
            system("CLS");
            menu();
            break;
        default:
            system("CLS");
            cout << "  ___________________________ "<<endl;
            cout << " |                           |"<<endl;
            cout << " | CHOOSE FROM GIVEN OPTIONS |"<<endl;
            cout << " |___________________________|"<<endl<<endl;
            Freeze(3);
            system("CLS");
            break;
        };
        if(choi!=9)
        {
        cout<<" Do you want to perform anything else?\n";
        int yn;
        yn=YesOrNo();
        if(yn==2)
        {
            system("CLS");
            cout << "  ___________________________ "<<endl;
            cout << " |                           |"<<endl;
            cout << " |   THANK YOU FOR SESSION   |"<<endl;
            cout << " |___________________________|"<<endl<<endl;
            Freeze(3);
            system("CLS");
            menu();
        }
        else
        {
            system("CLS");
        }
        }
    }while(choi != 9);
    system("CLS");
}

void Admin_menu(Admin &admin)
{   system("CLS");
    Cinema c;
    cout << "  ___________________________ "<<endl;
    cout << " |                           |"<<endl;
    cout << " |       MANAGER MENU        |"<<endl;
    cout << " |___________________________|"<<endl<<endl;
    cout << " Admin: " << admin.GetName() << endl;
    int choice;
    do
    {
        c.OpenCinema();
        system("CLS");
        cout << "  ___________________________ "<<endl;
        cout << " |                           |"<<endl;
        cout << " |       1.MOVIES INFO       |"<<endl;
        cout << " |___________________________|"<<endl;
        cout << " |                           |"<<endl;
        cout << " |   2.PRINT CERTAIN HALL    |"<<endl;
        cout << " |___________________________|"<<endl;
        cout << " |                           |"<<endl;
        cout << " |       3.SHOW HALLS        |"<<endl;
        cout << " |___________________________|"<<endl;
        cout << " |                           |"<<endl;
        cout << " |    4.CINEMA'S BALANCE     |"<<endl;
        cout << " |___________________________|"<<endl;
        cout << " |                           |"<<endl;
        cout << " |     5.CHANGE PASSWORD     |"<<endl;
        cout << " |___________________________|"<<endl;
        cout << " |                           |"<<endl;
        cout << " |          6. EXIT          |"<<endl;
        cout << " |___________________________|"<<endl<<endl;
        cout<<" CHOICE: ";
        cin >> choice;
        switch(choice)
        {
        case 1:
            system("CLS");
            cout << "  ___________________________ "<<endl;
            cout << " |                           |"<<endl;
            cout << " |         ALL MOVIES        |"<<endl;
            cout << " |___________________________|"<<endl<<endl;
            c.ShowMovies();
            break;
        case 2:
            system("CLS");
            cout << "  ___________________________ "<<endl;
            cout << " |                           |"<<endl;
            cout << " |        PRINT HALL         |"<<endl;
            cout << " |___________________________|"<<endl<<endl;
            c.PrintHall();
            break;
        case 3:
            system("CLS");
            cout << "  ___________________________ "<<endl;
            cout << " |                           |"<<endl;
            cout << " |         ALL HALLS         |"<<endl;
            cout << " |___________________________|"<<endl<<endl;
            c.GetHalls();
            break;
        case 4:
            system("CLS");
            cout << "  ___________________________ "<<endl;
            cout << " |                           |"<<endl;
            cout << " |          BALANCE          |"<<endl;
            cout << " |___________________________|"<<endl<<endl;
            cout<<" Cinema's Balance: "<<c.GetFinance()<<endl;
            break;
        case 5:
            system("CLS");
            cout << "  ___________________________ "<<endl;
            cout << " |                           |"<<endl;
            cout << " |      CHANGE PASSWORD      |"<<endl;
            cout << " |___________________________|"<<endl<<endl;
            cout<<" Insert '0' to EXIT.\n";
            admin.change_password_file();
            break;
        case 6:
            system("CLS");
            menu();
            break;
        default:
            system("CLS");
            cout << "  ___________________________ "<<endl;
            cout << " |                           |"<<endl;
            cout << " | CHOOSE FROM GIVEN OPTIONS |"<<endl;
            cout << " |___________________________|"<<endl<<endl;

            Freeze(3);
            system("CLS");
            break;
        }
        if(choice!=6)
        {
        cout<<" Do you want to perform anything else?\n";
        int yn;
        yn=YesOrNo();
        if(yn==2)
        {
            system("CLS");
            cout << "  ___________________________ "<<endl;
            cout << " |                           |"<<endl;
            cout << " |   THANK YOU FOR SESSION   |"<<endl;
            cout << " |___________________________|"<<endl<<endl;
            Freeze(3);
            system("CLS");
            menu();
        }
        else
        {
            system("CLS");
        }
        }
    }while(choice != 6);
    system("CLS");
}


