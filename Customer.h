#pragma once
#include <iostream>
#include <string>
#include "YesOrNo.h"
#include "User.h"
#include "GetNumber.h"
#include "Cinema.h"
#include "Ticket.h"

using namespace std;

class Customer:public User
{
protected:
    float bal;
    Ticket* tickets;
public:
    static int ticket_num;
    Customer();
    Customer(string name,string login, string password, float bal);
    void SetCustomer();
    void BalTopUp();
    void BuyTicket(Cinema c);
    void OpenTickets();
    void AccInfo();
    void DisplayTickets();
    float GetBalance();
    void ReturnTicket();
    void NewPass();
};
