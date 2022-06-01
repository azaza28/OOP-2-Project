#include "YesOrNo.h"

int YesOrNo()
{
    cout<<" 1. Yes"<<endl;
    cout<<" 2. No"<<endl;
    cout<<" Choice: ";
    string num = "";
    char a;
    for (int i = 0;;)
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
    int value = ToInt(num);
    return value;
}
