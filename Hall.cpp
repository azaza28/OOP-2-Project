#include "Hall.h"

Hall::Hall()
{

}

void Hall::SetHall()
{
    cout<<" Insert Hall's Name: ";
    getline(cin,name);
    ofstream f;
    f.open(".\\Cinema\\Halls.txt",ios::app);
    f<<name<<endl;
    f.close();
    cout<<" Insert number of rows: ";
    rows=GetNumber();
    cout<<" Insert number of seats per row: ";
    columns=GetNumber();
    cout<<" Insert Ticket's Price per seat: ";
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
    seats=new Seat[rows*columns];
    ofstream file;
    file.open(".\\Cinema\\"+name+".dat",ios::out | ios::binary);
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            seats[j+columns*i]=*(new Seat(i+1,j+1));
            file.write((char*)&seats[j+columns*i],sizeof(Seat));
        }
    }
    file.close();
}

Hall::~Hall()
{
    delete[] seats;
}

void Hall::OpenHall(string n, int r, int c,float p)
{
    Seat s;
    ifstream file;
    file.open(".\\Cinema\\"+n+".dat",ios::binary);
    int i = 0;
    Seat *seats;
    seats=new Seat[r*c];
    while(file.read((char*)&seats[i],sizeof(Seat)))
    {
        i++;
    }
    this->seats=seats;
    this->name=n;
    this->rows=r;
    this->columns=c;
    this->price=p;
}

string Hall::GetName()
{
    return name;
}

int Hall::GetColumns()
{
    return columns;
}

int Hall::GetRows()
{
    return rows;
}

void Hall::printhall()
{
    string s="";
    for (int j = rows-1; j>=0;j--)
    {
        line1(columns);
        cout<<endl;
        line2(columns);
        cout<<endl;
        line3(columns);
        cout<<endl;
        int number;
        cout<<" ";
        for(int i=0;i<columns;i++)//line 4
        {
            number=i+columns*j;
            if(seats[number].check()==true)
            {
                if (number<9)
                {
                    s="0";
                }
                else
                {
                    s="";
                }
                cout<<" || "<<s<<number+1<<" ||"<<" ";
            }
            else
            {
                cout<<" || "<<"XX"<<" ||"<<" ";
            }
        }
        cout<<endl;
        line5(columns);
        cout<<endl;
        line6(columns);
        cout<<endl;
    }
}

void Hall::Occupy_Free(int number)
{
    seats[number-1].occupy_free();
}

bool Hall::Check(int number)
{
    return seats[number-1].check();
}

float Hall::GetPrice()
{
    return price;
}

void Hall::SaveHall()
{
    ofstream file;
    file.open(".\\Cinema\\"+name+".dat",ios::out | ios::binary);
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            file.write((char*)&seats[j+columns*i],sizeof(Seat));
        }
    }
    file.close();
}


void line1(int columns)
{
    cout<<" ";
    for(int i=0;i<columns;i++)
    {
        cout<<"  ______ "<<" ";
    }
}
void line2(int columns)
{
    cout<<" ";
    for(int i=0;i<columns;i++)
    {
        cout<<" | ____ |"<<" ";
    }
}
void line3(int columns)
{
    cout<<" ";
    for(int i=0;i<columns;i++)
    {
        cout<<" ||    ||"<<" ";
    }
}
void line5(int columns)
{
    cout<<" ";
    for(int i=0;i<columns;i++)
    {
        cout<<" ||____||"<<" ";
    }
}
void line6(int columns)
{
    cout<<" ";
    for(int i=0;i<columns;i++)
    {
        cout<<" |______|"<<" ";
    }
}
