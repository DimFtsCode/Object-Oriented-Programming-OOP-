#include "groundfloor.h"
#include <iostream>

using namespace std;

Groundfloor::Groundfloor(int floor_number, int capacity, int office_count, int office_capacity) : floor_number(floor_number), capacity(capacity), population(0), office_count(office_count), office_capacity(office_capacity) {
    cout << "A groundfloor has been created ! " << endl;
}   //construct groundfloor

Groundfloor::~Groundfloor() {
    cout << "A groundfloor has been destroyed ! " << endl;
}       //distruct groundfloor

int Groundfloor::getCapacity() {
    return capacity;
}

int Groundfloor::getPeople() {
    return population;
}

bool Groundfloor::thereisRoom() {
    return population < capacity;
}

int Groundfloor::getOfficesCount() {
    return office_count;
}