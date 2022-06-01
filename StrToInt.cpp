#include "StrToInt.h"
int ToInt(string s)
{
    int value = 0;

    for (int i = 0; i < s.size(); i++)
    {
        value += (int(s[i]) - 48) * pow(10, s.size() - i - 1);
    }
    return value;
}
