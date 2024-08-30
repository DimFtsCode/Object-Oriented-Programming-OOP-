#ifndef LIFT_H
#define	LIFT_H
#include <queue>
#include "visitor.h"
#include "receptionist.h"
#include "hall.h"
#include "office.h"
#include "lobby.h"
#include "floor.h"

class Tower;

class Lift {
private:
    queue<Visitor*> priorityQueue;
    int capacity;
    int floor_number;

    Tower* tower;
public:
    Lift(int capacity, Tower* bs);
    ~Lift();
    int getCapacity();
    void enter();
    void exit();
    void stop_up();
    void stop_down();
    void empty_all();
    void operate();
};


#endif	

