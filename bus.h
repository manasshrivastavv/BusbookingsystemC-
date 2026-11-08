#ifndef BUS_H
#define BUS_H
#include "classes.h"
int loadBuses(Bus buses[]);
void saveBuses(Bus buses[],int count);
void viewBuses(Bus buses[],int count);
void showSeats(int busId);
void addBus(Bus buses[],int &count);
void viewBusSeats(Bus buses[],int count);
#endif
