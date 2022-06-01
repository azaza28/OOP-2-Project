#include "GetTime.h"

string GetTime()
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
