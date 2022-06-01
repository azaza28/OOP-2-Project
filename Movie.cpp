#include "Movie.h"

Movie::Movie()
{
    name=date=time=hall="Not Set";
    price=0.0;
}
Movie::~Movie()
{

}

void Movie::SetMovie(string n, string d, string t, string h,float p)
{
    name=n;
    date=d;
    time=t;
    hall=h;
    price=p;
}
void Movie::SetMovie()
{
    cout<<" Insert Movie's Name: ";
    getline(cin,name);
    cout<<" Insert Movie's Date: ";
    this->date=SetDate();
    cout<<" Insert Movie's Time: ";
    this->time=SetTime();
    cout<<" Select Hall:"<<endl;
    ifstream file;
    file.open(".\\Cinema\\Cinema.txt",ios::in);
    string s;
    getline(file,s);
    int hall_num=ToInt(s);
    string *Halls= new string[hall_num];
    int i = 0;
    int coun = 1;
    while(i<4*hall_num)
    {
        getline(file,s);
        if (i%4==0)
        {
            Halls[i/4]=s;
            cout<<" "<<coun<<". "<<s<<endl;
            coun++;
        }
        i++;
    }
    file.close();
    int ch;
    ch=GetNumber();
    if (ch<0 || ch>hall_num)
    {
        cout << "  ___________________________ "<<endl;
        cout << " |                           |"<<endl;
        cout << " |        WRONG INPUT        |"<<endl;
        cout << " |___________________________|"<<endl<<endl;
        return;
    }
    ifstream file2;
    i=0;
    file2.open(".\\Cinema\\Cinema.txt",ios::in);
    while(i<5*hall_num-1)
    {
        getline(file2,s);
        if (i==4*(ch-1)+1)
        {
            hall=s;
            getline(file2,s);
            getline(file2,s);
            getline(file2,s);
            this->price=stof(s);
            break;
        }
        i++;
    }
    this->hall=Halls[ch-1];
    file2.close();
    ofstream file1;
    file1.open(".\\Cinema\\Movies.txt", ios::app);
    file1<<name<<endl;
    file1<<date<<endl;
    file1<<time<<endl;
    file1<<hall<<endl;
    file1<<price<<endl;
    file1.close();
}
void Movie::ChangeDate()
{
    cout<<" Current Date: "<<date<<endl;
    cout<<" Insert New Date: ";
    date=SetDate();
}
void Movie::ChangeName()
{
    cout<<" Current Name: "<<name<<endl;
    cout<<" Insert New Name: ";
    cin.ignore();
    getline(cin,name);
}
void Movie::ChangeTime()
{
    cout<<" Current Time: "<<time<<endl;
    cout<<" Insert New Time: ";
    time=SetTime();
}
void Movie::ChangeHall()
{
    cout<<" Select a Hall: "<<endl;
    string s;
    ifstream file;
    file.open(".\\Cinema\\Cinema.txt",ios::out);
    getline(file,s);
    int hall_num=ToInt(s);
    int i = 0;
    int coun=0;
    string *Halls=new string[hall_num];
    while(i<4*hall_num)
    {
        getline(file,s);
        if (i%4==0)
        {
            Halls[i/4]=s;
            coun++;
            if(s!=hall)
                cout<<" "<<coun<<". "<<s<<endl;
        }
        i++;
    }
    int ch;
    ch=GetNumber();
    hall=Halls[ch-1];
}

void Movie::ChangePrice()
{
    cout<<" Current Price: "<<price<<endl;
    cout<<" Insert New Price: ";
    string num = "";
    char a;
    for (int i = 0;;)
    {
        a = _getch();
        if (a>='0' && a<='9' || a =='.')
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
            this->price=stof(num);
            break;
        }
    }
    cout << endl;
}

void Movie::Display()
{
    cout<<"  Name: "<<name<<endl;
    cout<<"  Date: "<<date<<endl;
    cout<<"  Time: "<<time<<endl;
    cout<<"  Hall: "<<hall<<endl;
    cout<<"  Price: "<<price<<endl;
}

string Movie::GetDate()
{
    return date;
}
string Movie::GetName()
{
    return name;
}
string Movie::GetTime()
{
    return time;
}
string Movie::GetHall()
{
    return hall;
}

string Movie::SetDate()
{
    string date = "";
    char a;
    for (int i = 0;;)
    {
        a = _getch();
        if (a >= '0' && a <= '9' && i < 8)
        {
            date += a;
            ++i;
            cout << a;
        }
        if (i%2==0 && i!=6 && i!=8 && a!='\r' && a >= '0' && a <= '9')
        {
            cout << '/';
            date+='/';
        }
        if (a == '\b' && i >= 1)
        {
            if ((i==2 || i==4) && i != 8)
            {
                cout << "\b \b";
                date.pop_back();
            }
            date.pop_back();
            --i;
            cout << "\b \b";
        }
        if (a == '\r' && date != "" && i == 8)
        {
            break;
        }
    }
    cout << endl;
    return date;
}


string Movie::SetTime()
{
    string time = "";
    char a;
    for (int i = 0;;)
    {
        if(i==0)
        {
            a = _getch();
            if(a>='0' &&a<='2')
            {
                time += a;
                ++i;
                cout << a;
            }
        }
        a = _getch();
        if (a >= '0' && a <= '9' && i < 4 && i !=0)
        {
            time += a;
            ++i;
            cout << a;
        }
        if (i == 2 && i != 0 && a!='\r')
        {
            cout << ':';
            time+=':';
        }
        if (a == '\b' && i >= 1)
        {
            if (i % 2 == 0 && i != 4)
            {
                cout << "\b \b";
                cout << "\b \b";
                time.pop_back();
                time.pop_back();
            }
            time.pop_back();
            --i;
            cout << "\b \b";
        }
        if (a == '\r' && time != "" && i == 4)
        {
            break;
        }
    }
    cout << endl;
    return time;
}

float Movie::GetPrice()
{
    return price;
}
