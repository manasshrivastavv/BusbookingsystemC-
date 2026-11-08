#ifndef BOOKING_H
#define BOOKING_H
#include "classes.h"
bool isSeatBooked(int busId,int seat);
int getBookingId();
void bookTicket(Bus buses[],int count);
void myBookings();
void cancelTicket();
void viewAllBookings();
#endif
