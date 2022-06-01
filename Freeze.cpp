#include "Freeze.h"

void Freeze(int time)
{
    this_thread::sleep_for(chrono::seconds{time});
}
