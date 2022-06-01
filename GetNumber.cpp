#include "GetNumber.h"

int GetNumber()
{
    string num = "";
    char a;
    for (int i = 0;;)
    {
        a = _getch();
        if (a>='0' && a<='9')
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
    int value = ToInt(num);
    if (value < 0)
    {
        system("CLS");
        cout <<"Wrong Input.\nTry Again.\n";
        GetNumber();
    }
    cout << endl;
    return value;
}
