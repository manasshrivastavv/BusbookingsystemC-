#include "classes.h"
#include "bus.h"
#include "booking.h"
#include "admin.h"
int main()
{
    Bus buses[20];
    int count=loadBuses(buses);
    int choice;
    do
    {
        cout<<"\n========== BUS BOOKING SYSTEM ==========\n";
        cout<<"1.View Available Buses\n2.Book Ticket\n3.My Bookings\n";
        cout<<"4.Cancel Ticket\n5.Admin Panel\n6.Exit\n";
        cout<<"Enter Choice:"; cin>>choice;
        switch(choice)
        {
            case 1: viewBuses(buses,count); break;
            case 2: bookTicket(buses,count); break;
            case 3: myBookings(); break;
            case 4: cancelTicket(); break;
            case 5: adminPanel(buses,count); break;
            case 6: cout<<"Thank You For Using Bus Booking System!\n"; break;
            default: cout<<"Invalid Choice!\n";
        }
    }while(choice!=6);
    return 0;
}
