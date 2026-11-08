#include "booking.h"
#include "bus.h"
#include <cstdio>
bool isSeatBooked(int busId,int seat)
{
    ifstream file("bookings.txt");
    Booking b;
    while(file>>b.id>>b.passenger>>b.busId>>b.seat>>b.fare)
        if(b.busId==busId && b.seat==seat) { file.close(); return true; }
    file.close();
    return false;
}
int getBookingId()
{
    ifstream file("bookings.txt");
    Booking b;
    int id=1000;
    while(file>>b.id>>b.passenger>>b.busId>>b.seat>>b.fare)
        if(b.id>id) id=b.id;
    file.close();
    return id+1;
}
void bookTicket(Bus buses[],int count)
{
    if(count==0) { cout<<"No Buses Available!\n"; return; }
    viewBuses(buses,count);
    int busId;
    cout<<"Enter Bus ID:"; cin>>busId;
    int index=-1;
    for(int i=0;i<count;i++)
        if(buses[i].id==busId) { index=i; break; }
    if(index==-1) { cout<<"Invalid Bus ID!\n"; return; }
    showSeats(busId);
    string name;
    int seat;
    cout<<"Enter Passenger Name:"; cin>>name;
    cout<<"Enter Seat Number:"; cin>>seat;
    if(seat<1 || seat>20) { cout<<"Invalid Seat Number!\n"; return; }
    if(isSeatBooked(busId,seat)) { cout<<"Seat Already Booked!\n"; return; }
    int bookingId=getBookingId();
    ofstream file("bookings.txt",ios::app);
    file<<bookingId<<" "<<name<<" "<<busId<<" "<<seat<<" "<<buses[index].fare<<endl;
    file.close();
    cout<<"\nTicket Booked Successfully!\n";
    cout<<"Booking ID:"<<bookingId<<endl;
    cout<<"Passenger:"<<name<<endl;
    cout<<"Bus Name:"<<buses[index].name<<endl;
    cout<<"Route:"<<buses[index].from<<" to "<<buses[index].to<<endl;
    cout<<"Seat Number:"<<seat<<endl;
    cout<<"Fare:Rs."<<buses[index].fare<<endl;
}
void myBookings()
{
    string name;
    cout<<"Enter Your Name:"; cin>>name;
    ifstream file("bookings.txt");
    Booking b;
    bool found=false;
    cout<<"\n========== MY BOOKINGS ==========\n";
    while(file>>b.id>>b.passenger>>b.busId>>b.seat>>b.fare)
        if(b.passenger==name)
        {
            found=true;
            cout<<"Booking ID:"<<b.id<<endl<<"Passenger:"<<b.passenger<<endl;
            cout<<"Bus ID:"<<b.busId<<endl<<"Seat Number:"<<b.seat<<endl;
            cout<<"Fare:Rs."<<b.fare<<endl<<"--------------------------------\n";
        }
    file.close();
    if(!found) cout<<"No Booking Found!\n";
}
void cancelTicket()
{
    string name;
    int bookingId;
    cout<<"Enter Your Name:"; cin>>name;
    cout<<"Enter Booking ID:"; cin>>bookingId;
    ifstream file("bookings.txt");
    ofstream temp("temp.txt");
    Booking b;
    bool found=false;
    while(file>>b.id>>b.passenger>>b.busId>>b.seat>>b.fare)
        if(b.id==bookingId && b.passenger==name) found=true;
        else temp<<b.id<<" "<<b.passenger<<" "<<b.busId<<" "<<b.seat<<" "<<b.fare<<endl;
    file.close(); temp.close();
    if(found) { remove("bookings.txt"); rename("temp.txt","bookings.txt"); cout<<"Ticket Cancelled Successfully!\n"; }
    else { remove("temp.txt"); cout<<"Booking Not Found!\n"; }
}
void viewAllBookings()
{
    ifstream file("bookings.txt");
    Booking b;
    bool found=false;
    cout<<"\n========== ALL BOOKINGS ==========\n";
    while(file>>b.id>>b.passenger>>b.busId>>b.seat>>b.fare)
    {
        found=true;
        cout<<"Booking ID:"<<b.id<<endl<<"Passenger:"<<b.passenger<<endl;
        cout<<"Bus ID:"<<b.busId<<endl<<"Seat Number:"<<b.seat<<endl;
        cout<<"Fare:Rs."<<b.fare<<endl<<"--------------------------------\n";
    }
    file.close();
    if(!found) cout<<"No Bookings Available!\n";
}
