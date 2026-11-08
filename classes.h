#ifndef CLASSES_H
#define CLASSES_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Bus { int id; string name; string from; string to; int fare; };
struct Booking { int id; string passenger; int busId; int seat; int fare; };
#endif
