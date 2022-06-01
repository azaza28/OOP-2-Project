#include "GetDate.h"

string GetDate()
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
        if (i==2 || i==4 && a!='\r')
        {
            cout << '/';
            date+='/';
        }
        if (a == '\b' && i >= 1)
        {
            if ((i==2 || i==4) && i != 8)
            {
                cout << "\b \b";
                cout << "\b \b";
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
