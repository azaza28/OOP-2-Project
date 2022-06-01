#include "Cinema.h"

Cinema::Cinema()
{
    hall_num=0;
    movie_num=0;
    financial_situation=0;
    fstream finance;
    finance.open(".\\Cinema\\finance.dat", ios::binary|ios::in|ios::out);
    if(finance.good())
    {
        finance.read((char *) & financial_situation, sizeof(float));
    }
}

int Cinema::GetHallNum()
{
    return hall_num;
}

void Cinema::SetHalls()
{
    cout << "  ___________________________ "<<endl;
    cout << " |                           |"<<endl;
    cout << " |     BUILDING CINEMA       |"<<endl;
    cout << " |___________________________|"<<endl<<endl;
    cout << " It seems you don't have Cinema yet" << endl;
            cout<<endl;
    cout<<" Insert number of Halls in your Cinema: ";
    hall_num=GetNumber();
    if(hall_num<=0)
    {
        system("CLS");
        cout << "  ___________________________ "<<endl;
        cout << " |                           |"<<endl;
        cout << " |        WRONG INPUT        |"<<endl;
        cout << " |___________________________|"<<endl<<endl;
        Freeze(3);
        system("CLS");
        SetHalls();
    }
    ofstream file;
    file.open(".\\Cinema\\Cinema.txt",ios::out);
    file<<hall_num<<endl;
    halls=new Hall[hall_num];
    ofstream f;
    f.open(".\\Cinema\\Halls.txt",ios::out);
    f.close();
    ofstream f1;
    f1.open(".\\Cinema\\Movies.txt",ios::out);
    f1.close();
    for(int i = 0; i < hall_num; i++)
    {
        halls[i]=*(new Hall());
        system("CLS");
        cout<<" Hall #"<<i+1<<":"<<endl;
        halls[i].SetHall();
        file<<halls[i].GetName()<<endl;
        file<<halls[i].GetRows()<<endl;
        file<<halls[i].GetColumns()<<endl;
        file<<halls[i].GetPrice()<<endl;
    }
    cout<<" The cinema has been build(LOL) successfully.\n";
}

Cinema::~Cinema()
{
    delete[] halls;
    delete[] movies;
}

int Cinema:: GetMovieNum()
{
    return movie_num;
}

void Cinema::OpenCinema()
{
    ifstream file;
    string l;
    file.open(".\\Cinema\\Cinema.txt", ios::in);
    getline(file,l);
    this->hall_num=ToInt(l);
    Hall *halls;
    halls=new Hall[hall_num];
    for(int i = 0; i < hall_num; i++)
    {
        getline(file,l);
        string n=l;
        getline(file,l);
        int r=ToInt(l);
        getline(file,l);
        int c=ToInt(l);
        getline(file,l);
        float p=stof(l);
        halls[i].OpenHall(n,r,c,p);
    }
    file.close();
    this->halls=halls;
    ifstream file3;
    int i=0;
    string n;
    file3.open(".\\Cinema\\Movies.txt",ios::in);
    while(getline(file3,n))
    {
        i++;
    }
    file3.close();
    this->movie_num=i/5;
    Movie *movies;
    movies=new Movie[movie_num];
    ifstream file4;
    string d,t,h,pr;
    float p;
    i=0;
    file4.open(".\\Cinema\\Movies.txt",ios::in);
    while(getline(file4,n))
    {
        getline(file4,d);
        getline(file4,t);
        getline(file4,h);
        getline(file4,pr);
        p=stof(pr);
        movies[i].SetMovie(n,d,t,h,p);
        i++;
    }
    file4.close();
    this->movies=movies;
}

void Cinema::GetHalls()
{
    for(int i = 0; i < hall_num; i++)
    {
        cout<<" "<<i+1<<". "<<halls[i].GetName()<<endl;
    }
}

void Cinema::ShowMovies()
{
    if (movie_num==0)
    {
        system("CLS");
        cout << "  ___________________________"<<endl;
        cout << " |                           |"<<endl;
        cout << " |  UNFORTUNATELY THERE IS   |"<<endl;
        cout << " |     NO ANY MOVIE YET      |"<<endl;
        cout << " |___________________________|"<<endl<<endl;
        Freeze(3);
        system("CLS");
        return;
    }
    for(int i = 0; i < movie_num;i++)
    {
        cout << "  ___________________________ "<<endl;
        cout << " |                           |"<<endl;
        cout << " |          MOVIE #"<<i+1<<"         |"<<endl;
        cout << " |___________________________|"<<endl<<endl;
        movies[i].Display();
    }
}

void Cinema::SaveCinema()
{
    ofstream file;
    file.open(".\\Cinema\\Cinema.txt",ios::out);
    file<<hall_num<<endl;
    for(int i = 0; i < hall_num; i++)
    {
        halls[i].SaveHall();
        file<<halls[i].GetName()<<endl;
        file<<halls[i].GetRows()<<endl;
        file<<halls[i].GetColumns()<<endl;
        file<<halls[i].GetPrice()<<endl;
    }
    file.close();
    ofstream filem;
    ifstream file3;
    int i=0;
    string n;
    file3.open(".\\Cinema\\Movies.txt",ios::in);
    while(getline(file3,n))
    {
        i++;
    }
    file3.close();
    this->movie_num=i/5;
    filem.open(".\\Cinema\\Movies.txt",ios::out);
    for(int i = 0; i < movie_num;i++)
    {
        filem<<movies[i].GetName()<<endl;
        filem<<movies[i].GetDate()<<endl;
        filem<<movies[i].GetTime()<<endl;
        filem<<movies[i].GetHall()<<endl;
        filem<<movies[i].GetPrice()<<endl;
    }
    filem.close();
    Save_Finance();
}

void Cinema::DeleteMovie()
{
    OpenCinema();
    cout<<" Insert '0' to EXIT.\n";
    cout<<" Select movie, that you want to delete:\n";
    ShowMovies();
    int ch;
    cout<< "CHOICE: ";
    ch=GetNumber();
    if(ch==0)
    {
        system("CLS");
        cout << "  ___________________________ "<<endl;
        cout << " |                           |"<<endl;
        cout << " |    CANCELING OPERATION    |"<<endl;
        cout << " |___________________________|"<<endl<<endl;
        return;
    }
    if(ch<0 || ch>movie_num)
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
    this->movie_num-=1;
    ifstream file4;
    string n,d,t,h,pr;
    float p;
    int i=0;
    ch-=1;
    file4.open(".\\Cinema\\Movies.txt",ios::in);
    while(getline(file4,n))
    {
        getline(file4,d);
        getline(file4,t);
        getline(file4,h);
        getline(file4,pr);
        p=stof(pr);
        if(movies[ch].GetName()!=n && movies[ch].GetDate()!=d &&movies[ch].GetTime()!=t && movies[ch].GetHall()!=h &&movies[ch].GetPrice()!=p)
        {
            movies[i].SetMovie(n,d,t,h,p);
        }
        i++;
    }
    file4.close();
    ofstream filem;
    filem.open(".\\Cinema\\Movies.txt",ios::out);
    for(int i = 0; i < movie_num;i++)
    {
        filem<<movies[i].GetName()<<endl;
        filem<<movies[i].GetDate()<<endl;
        filem<<movies[i].GetTime()<<endl;
        filem<<movies[i].GetHall()<<endl;
        filem<<movies[i].GetPrice()<<endl;
    }
    filem.close();
    OpenCinema();
    cout<<" Movie has been deleted successfully.\n";
}

void Cinema::PrintHall()
{
    GetHalls();
    cout<<" Select a hall that you want to print: ";
    int h=GetNumber();
    if (h<0 || h > hall_num)
    {
        system("CLS");
        cout << "  ___________________________ "<<endl;
        cout << " |                           |"<<endl;
        cout << " |        WRONG INPUT        |"<<endl;
        cout << " |___________________________|"<<endl<<endl;
        Freeze(3);
        return;
    }
    halls[h-1].printhall();
}

float Cinema::GetFinance()
{
   return financial_situation;
}

void Cinema::DecreaseFinance(float amount)
{
    if(amount < financial_situation)
        {
            financial_situation -= amount;
            Save_Finance();
        }
}

void Cinema::IncreaseFinance(float amount)
{
    financial_situation += amount;
    Save_Finance();
}

void Cinema::Save_Finance()
{
    fstream file;
    file.open(".\\Cinema\\finance.dat", ios::binary|ios::out);
    file.write((char *) & financial_situation, sizeof(float));
}

void Cinema::EditMovie()
{
    system("CLS");
    cout<<" Insert '0' to EXIT.\n";
    cout<<" Select movie, that you want to Edit:\n";
    ShowMovies();
    cout<< "CHOICE: ";
    int mov=GetNumber()-1;
    if(mov==-1)
    {
        system("CLS");
        cout << "  ___________________________ "<<endl;
        cout << " |                           |"<<endl;
        cout << " |    CANCELING OPERATION    |"<<endl;
        cout << " |___________________________|"<<endl<<endl;
        return;
    }
    if(mov<0 || mov>movie_num)
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
    cout << "  ___________________________ "<<endl;
    cout << " |                           |"<<endl;
    cout << " |       1.CHANGE NAME       |"<<endl;
    cout << " |___________________________|"<<endl;
    cout << " |                           |"<<endl;
    cout << " |       2.CHANGE DATE       |"<<endl;
    cout << " |___________________________|"<<endl;
    cout << " |                           |"<<endl;
    cout << " |       3.CHANGE TIME       |"<<endl;
    cout << " |___________________________|"<<endl;
    cout << " |                           |"<<endl;
    cout << " |       4.CHANGE HALL       |"<<endl;
    cout << " |___________________________|"<<endl;
    cout << " |                           |"<<endl;
    cout << " |      5.CHANGE PRICE       |"<<endl;
    cout << " |___________________________|"<<endl<<endl;
    cout<<" Insert '0' to EXIT.\n\n";
    cout<<" CHOICE: ";
    int ch=GetNumber();
    if(ch==0)
    {
        system("CLS");
        cout << "  ___________________________ "<<endl;
        cout << " |                           |"<<endl;
        cout << " |    CANCELING OPERATION    |"<<endl;
        cout << " |___________________________|"<<endl<<endl;
        return;
    }
    if(ch<0 || ch>5)
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
    switch(ch)
    {
    case 1:
        system("CLS");
        cout << "  ___________________________ "<<endl;
        cout << " |                           |"<<endl;
        cout << " |        CHANGE NAME        |"<<endl;
        cout << " |___________________________|"<<endl<<endl;
        movies[mov].ChangeName();
        break;
    case 2:
        system("CLS");
        cout << "  ___________________________ "<<endl;
        cout << " |                           |"<<endl;
        cout << " |        CHANGE DATE        |"<<endl;
        cout << " |___________________________|"<<endl<<endl;
        movies[mov].ChangeDate();
        break;
    case 3:
        system("CLS");
        cout << "  ___________________________ "<<endl;
        cout << " |                           |"<<endl;
        cout << " |        CHANGE TIME        |"<<endl;
        cout << " |___________________________|"<<endl<<endl;
        movies[mov].ChangeTime();
        break;
    case 4:
        system("CLS");
        cout << "  ___________________________ "<<endl;
        cout << " |                           |"<<endl;
        cout << " |        CHANGE HALL        |"<<endl;
        cout << " |___________________________|"<<endl<<endl;
        movies[mov].ChangeHall();
        break;
    case 5:
        cout << "  ___________________________ "<<endl;
        cout << " |                           |"<<endl;
        cout << " |        CHANGE PRICE       |"<<endl;
        cout << " |___________________________|"<<endl<<endl;
        system("CLS");
        movies[mov].ChangePrice();
    }
    ofstream filem;
    filem.open(".\\Cinema\\Movies.txt",ios::out);
    for(int i = 0; i < movie_num;i++)
    {
        filem<<movies[i].GetName()<<endl;
        filem<<movies[i].GetDate()<<endl;
        filem<<movies[i].GetTime()<<endl;
        filem<<movies[i].GetHall()<<endl;
        filem<<movies[i].GetPrice()<<endl;
    }
    filem.close();
    OpenCinema();
    cout<<" Movie has been edited successfully.\n";
}

void Cinema::SetMovie()
{
    cout<<" Insert '0' to EXIT.\n";
    string name,date,time;
    cout<<" Insert Movie's Name: ";
    cin.ignore();
    getline(cin,name);
    if(name=="0")
    {
        system("CLS");
        return;
    }
    cout<<" Insert Movie's Date: ";
    date=SetDate();
    cout<<" Insert Movie's Time: ";
    time=SetTime();
    cout<<" Select Hall:"<<endl;
    GetHalls();
    int ch;
    ch=GetNumber();
    if (ch<0 || ch>hall_num)
    {
        cout<<" Wrong Input."<<endl<<" Try Again."<<endl;
        ch=GetNumber();
    }
    ofstream file1;
    file1.open(".\\Cinema\\Movies.txt", ios::app);
    file1<<name<<endl;
    file1<<date<<endl;
    file1<<time<<endl;
    file1<<halls[ch-1].GetName()<<endl;
    file1<<halls[ch-1].GetPrice()<<endl;
    file1.close();
    OpenCinema();
}

string SetDate()
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

string SetTime()
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
        if (i == 2 && i != 0 && a!='\r' && a >= '0' && a <= '9')
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

