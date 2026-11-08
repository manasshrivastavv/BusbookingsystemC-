
#include "bus.h"
#include "booking.h"
#include <cstdio>

int loadBuses(Bus buses[])
{
    ifstream file("buses.txt");
    int count=0;

    while(file>>buses[count].id
              >>buses[count].name
              >>buses[count].from
              >>buses[count].to
              >>buses[count].fare)
    {
        count++;

        if(count==20)
            break;
    }

    file.close();

    if(count==0)
    {
        buses[0]={101,"JaipurExpress","Jaipur","Delhi",500};
        buses[1]={102,"RoyalTravel","Jaipur","Agra",400};
        buses[2]={103,"CityBus","Delhi","Jaipur",600};

        count=3;
        saveBuses(buses,count);
    }

    return count;
}

void saveBuses(Bus buses[],int count)
{
    ofstream file("buses.txt");

    for(int i=0;i<count;i++)
        file<<buses[i].id<<" "<<buses[i].name<<" "
            <<buses[i].from<<" "<<buses[i].to<<" "
            <<buses[i].fare<<endl;

    file.close();
}

void viewBuses(Bus buses[],int count)
{
    cout<<"\n========== AVAILABLE BUSES ==========\n";

    for(int i=0;i<count;i++)
    {
        cout<<"Bus ID:"<<buses[i].id<<endl;
        cout<<"Bus Name:"<<buses[i].name<<endl;
        cout<<"From:"<<buses[i].from<<endl;
        cout<<"To:"<<buses[i].to<<endl;
        cout<<"Fare:Rs."<<buses[i].fare<<endl;
        cout<<"------------------------------------\n";
    }

    if(count==0)
        cout<<"No Buses Available!\n";
}

void showSeats(int busId)
{
    cout<<"\n========== SEAT LAYOUT ==========\n";
    cout<<"Available=[ ]  Booked=[X]\n\n";

    for(int i=1;i<=20;i+=4)
    {
        for(int j=i;j<i+2;j++)
        {
            if(isSeatBooked(busId,j))
                cout<<"[X]";
            else
                cout<<"["<<j<<"]";
        }

        cout<<"    ";

        for(int j=i+2;j<i+4;j++)
        {
            if(isSeatBooked(busId,j))
                cout<<"[X]";
            else
                cout<<"["<<j<<"]";
        }

        cout<<endl;
    }
}

void addBus(Bus buses[],int &count)
{
    if(count==20)
    {
        cout<<"Bus Limit Reached!\n";
        return;
    }

    Bus b;

    cout<<"Enter Bus ID:";
    cin>>b.id;

    for(int i=0;i<count;i++)
    {
        if(buses[i].id==b.id)
        {
            cout<<"Bus ID Already Exists!\n";
            return;
        }
    }

    cout<<"Enter Bus Name:";
    cin>>b.name;

    cout<<"Enter Starting Point:";
    cin>>b.from;

    cout<<"Enter Destination:";
    cin>>b.to;

    cout<<"Enter Fare:";
    cin>>b.fare;

    if(b.fare<=0)
    {
        cout<<"Invalid Fare!\n";
        return;
    }

    buses[count]=b;
    count++;

    saveBuses(buses,count);

    cout<<"Bus Added Successfully!\n";
}

void viewBusSeats(Bus buses[],int count)
{
    int id;

    viewBuses(buses,count);

    cout<<"Enter Bus ID:";
    cin>>id;

    for(int i=0;i<count;i++)
    {
        if(buses[i].id==id)
        {
            showSeats(id);
            return;
        }
    }

    cout<<"Bus Not Found!\n";
}
