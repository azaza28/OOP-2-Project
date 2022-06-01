#include "Ticket.h"
Ticket::Ticket()
{
    time=movie=hall=date="Not Set";
    int seat = 0;
}
void Ticket::SetTicket(string movie,string date, string time, string hall,int seat)
{
    this->movie=movie;
    this->date=date;
    this->time=time;
    this->hall=hall;
    this->seat=seat;
}
void Ticket::PrintTicket()
{
    cout<<" *Movie: "<<movie<<endl<<" *Date: "<<date<<endl<<" *Time: "<<time<<endl<<" *Hall: "<<hall<<endl<<" *Seat: "<<seat<<endl;
}

string Ticket::GetHall()
{
    return hall;
}
string Ticket::GetMovie()
{
    return movie;
}
string Ticket::GetDate()
{
    return date;
}
string Ticket::GetTime()
{
    return time;
}
int Ticket::GetSeat()
{
    return seat;
}
