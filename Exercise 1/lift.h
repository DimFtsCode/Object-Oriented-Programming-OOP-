#ifndef LIFT_H
#define	LIFT_H

#include "visitor.h"
#include "receptionist.h"
#include "hall.h"
#include "office.h"
#include "groundfloor.h"
#include "floor.h"
#include <queue>

class Tower;

class Lift {
private:
    std::  queue<Visitor*> pq;
    std::  queue<Visitor*> lift_out;
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





#endif	/* LIFT_H */

