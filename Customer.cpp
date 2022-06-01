#include "Customer.h"

int Customer::ticket_num=0;

Customer::Customer()
{
    bal=0;
    ticket_num=0;
}

float Customer::GetBalance()
{
        return this->bal;
}


Customer::Customer(string name,string login, string password, float bal)
{
    this->name=name;
    this->login=login;
    this->password=password;
    this->bal=bal;
    this->type = "Customer";
}

void Customer::AccInfo()
{
    OpenTickets();
    cout<<" Your Name: "<<name<<endl;
    cout<<" Your Login: "<<login<<endl;
    cout<<" Your Password: "<<password<<endl;
    cout<<" Your Balance: "<<bal<<endl;
    cout<<" Ticket Number: "<<ticket_num<<endl;
}

void Customer::SetCustomer()
{
    SetUser();
    if(name!="0" && login != "0" && password !="0")
    {
    cout<<" Do you want to top up your account now?"<<endl;
    int ch;
    ch=YesOrNo();
    bal=0;
    if (ch==1)
    {
        BalTopUp();
    }
    type="Customer";
    ofstream file;
    file.open(".\\Users\\"+login+".txt",ios::app);
    file<<type<<endl;
    file<<bal<<endl;
    file.close();
    }
}

void Customer::BalTopUp()
{
    cout<<" Insert amount of money that you want your account to be top upped: ";
    bal+=GetNumber();
}

void Customer::BuyTicket(Cinema c)
{
    cout<<" Insert '0' to EXIT.\n";
    cout<<" Select a Ticket from the following options:"<<endl;
    c.OpenCinema();
    c.ShowMovies();
    if(c.GetMovieNum()==0)
    {
        system("CLS");
        cout << "  ___________________________ "<<endl;
        cout << " |                           |"<<endl;
        cout << " |  UNFORTUNATELY THERE IS   |"<<endl;
        cout << " |     NO ANY RELEASE YET    |"<<endl;
        cout << " |___________________________|"<<endl<<endl;
        Freeze(3);
        system("CLS");
        return;
    }
    int ch;
    cout<<" CHOICE: ";
    ch=GetNumber();
    if(ch==0)
    {
        return;
    }
    if(ch<0 || ch>c.GetMovieNum())
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
    int i = 0;
    int seat;
    while(true)
    {
        if(c.halls[i].GetName()==c.movies[ch-1].GetHall())
        {
            c.halls[i].printhall();
            cout<<" Select a seat:"<<endl<<" ";
            cin>>seat;
            if (seat==0)
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
            if (seat>c.halls[i].GetRows()*c.halls[i].GetColumns() || seat<0)
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
            if(c.halls[i].Check(seat))
            {
                c.halls[i].Occupy_Free(seat);
                c.SaveCinema();
                break;
            }
            else
            {
                system("CLS");
                cout << "  ____________________________ "<<endl;
                cout << " |                            |"<<endl;
                cout << " | TAKEN SEAT HAS BEEN CHOSEN |"<<endl;
                cout << " |____________________________|"<<endl<<endl;
                Freeze(3);
                system("CLS");
                return;
            }
        }
        i++;
    }
    if(bal < c.movies[ch-1].GetPrice())
    {
        system("CLS");
        cout << "  ____________________________ "<<endl;
        cout << " |                            |"<<endl;
        cout << " |    TOP UP YOUR BALANCE     |"<<endl;
        cout << " |____________________________|"<<endl<<endl;
        cout<<" No enough money on your balance."<<endl;
        Freeze(3);
        return;
    }
    this->bal-=c.movies[ch-1].GetPrice();
    ofstream filec;
    filec.open(".\\Users\\"+login+".txt",ios::out);
    filec<<name<<endl;
    filec<<login<<endl;
    filec<<password<<endl;
    filec<<type<<endl;
    filec<<bal<<endl;
    filec.close();
    c.IncreaseFinance(c.movies[ch-1].GetPrice());
    Ticket t;
    t.SetTicket(c.movies[ch-1].GetName(),c.movies[ch-1].GetDate(),c.movies[ch-1].GetTime(),c.movies[ch-1].GetHall(),seat);
    ofstream file;
    file.open(".\\Users\\Tickets\\"+login+"Tickets.txt",ios::app);
    file<<c.movies[ch-1].GetName()<<endl;
    file<<c.movies[ch-1].GetDate()<<endl;
    file<<c.movies[ch-1].GetTime()<<endl;
    file<<c.movies[ch-1].GetHall()<<endl;
    file<<seat<<endl;
    file.close();
    cout<<" Ticket was bought successfully"<<endl;
    this->ticket_num+=1;
}

void Customer::OpenTickets()
{
    ifstream file;
    file.open(".\\Users\\Tickets\\"+login+"Tickets.txt");
    string m,d,t,h;
    string s;
    int num=0;
    while(getline(file,m))
    {
        num++;
    }
    ticket_num=0;
    tickets=new Ticket[num/5];
    file.close();
    ifstream file2;
    file2.open(".\\Users\\Tickets\\"+login+"Tickets.txt");
    for(int i =0; i<num/5;i++)
    {
        getline(file2,m);
        getline(file2,d);
        getline(file2,t);
        getline(file2,h);
        getline(file2,s);
        float  n=ToInt(s);
        tickets[i].SetTicket(m,d,t,h,n);
        this->ticket_num+=1;
    }
    this->tickets=tickets;
    file2.close();
}

void Customer::DisplayTickets()
{
    OpenTickets();
    if(ticket_num==0)
    {
        system("CLS");
        cout << "  ___________________________"<<endl;
        cout << " |                           |"<<endl;
        cout << " |  UNFORTUNATELY YOU HAVE   |"<<endl;
        cout << " |  NOT BOUGHT TICKETS YET   |"<<endl;
        cout << " |___________________________|"<<endl<<endl;
        Freeze(3);
        system("CLS");
        return;
    }
    for(int i = 0; i < ticket_num;i++)
    {
    cout << "  ___________________________ "<<endl;
    cout << " |                           |"<<endl;
    cout << " |         TICKET #"<<i+1<<"         |"<<endl;
    cout << " |___________________________|"<<endl;
    tickets[i].PrintTicket();
        cout<<endl;
    }
}

void Customer::ReturnTicket()
{
    cout<<" Insert '0' to EXIT.\n";
    cout<<" Select a Ticket that you want to return.\n(Note that only 80% of the price will be returned)\n";
    DisplayTickets();
    int ch;
    if(ticket_num==0)
    {
        return;
    }
    ch=GetNumber();
    if(ch==0)
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
    if(ch<0 || ch>ticket_num)
    {
        system("CLS");
        cout << "  ___________________________ "<<endl;
        cout << " |                           |"<<endl;
        cout << " |         WRONG INPUT       |"<<endl;
        cout << " |___________________________|"<<endl<<endl;
        system("CLS");
        return;
    }
    ch-=1;
    Cinema c;
    c.OpenCinema();
    for(int i = 0; i < c.GetHallNum();i++)
    {
        if(tickets[ch].GetHall()==c.halls[i].GetName())
        {
            c.DecreaseFinance(c.movies[i].GetPrice()*0.8);
            bal+=c.movies[i].GetPrice()*0.8;
            c.halls[i].Occupy_Free(tickets[ch].GetSeat());
            c.SaveCinema();
        }
    }
    this->ticket_num-=1;
    if(ticket_num==0)
    {
        ofstream filee;
        filee.open(".\\Users\\Tickets\\"+login+"Tickets.txt",ios::out);
    }
    else
    {
    ifstream file4;
    string m,d,t,h,se;
    int s;
    int i=0;
    ch-=1;
    file4.open(".\\Users\\Tickets\\"+login+"Tickets.txt");
    while(getline(file4,m))
    {
        getline(file4,d);
        getline(file4,t);
        getline(file4,h);
        getline(file4,se);
        s=ToInt(se);
        if(tickets[ch].GetMovie()!=m && tickets[ch].GetDate()!=d &&tickets[ch].GetTime()!=t && tickets[ch].GetHall()!=h&&tickets[ch].GetSeat()==s)
        {
            tickets[i].SetTicket(m,d,t,h,s);
        }
        i++;
    }
    file4.close();
    ofstream filet;
    filet.open(".\\Users\\Tickets\\"+login+"Tickets.txt",ios::out);
    for(int i = 0; i < ticket_num;i++)
    {
        filet<<tickets[i].GetMovie()<<endl;
        filet<<tickets[i].GetDate()<<endl;
        filet<<tickets[i].GetTime()<<endl;
        filet<<tickets[i].GetHall()<<endl;
        filet<<tickets[i].GetSeat()<<endl;
    }
    filet.close();
    }
    c.OpenCinema();
    OpenTickets();
    cout<<" Ticket has been returned successfully.\n";
}

void Customer::NewPass()
{
    ChangePass();
    ofstream file;
    if(name!="" || password!="" || login!="")
    {
    file.open(".\\Users\\"+login+".txt", ios::out);
    file<<type<<endl;
    file<<bal<<endl;
    file.close();
    }
}
