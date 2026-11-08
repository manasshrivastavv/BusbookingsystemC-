#include "admin.h"
#include "bus.h"
#include "booking.h"
void adminPanel(Bus buses[],int &count)
{
    string password;
    cout<<"Enter Admin Password:"; cin>>password;
    if(password!="admin123") { cout<<"Wrong Password!\n"; return; }
    int choice;
    do
    {
        cout<<"\n========== ADMIN PANEL ==========\n";
        cout<<"1.Add Bus\n2.View All Buses\n3.View All Bookings\n";
        cout<<"4.View Bus Seat Status\n5.Exit Admin\n";
        cout<<"Enter Choice:"; cin>>choice;
        switch(choice)
        {
            case 1: addBus(buses,count); break;
            case 2: viewBuses(buses,count); break;
            case 3: viewAllBookings(); break;
            case 4: viewBusSeats(buses,count); break;
            case 5: cout<<"Admin Logout Successfully!\n"; break;
            default: cout<<"Invalid Choice!\n";
        }
    }while(choice!=5);
}
