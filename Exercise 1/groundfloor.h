
#ifndef GROUNDFLOOR_H
#define	GROUNDFLOOR_H
#include "visitor.h"
#include "receptionist.h"
#include "hall.h"
#include "office.h"
#include <queue>

using namespace std;

class GroundFloor {
private:
    int capacity;
    int population;
    Hall hall;
    Receptionist receptionist;
    std::  queue<Visitor*> pq;
public:

   GroundFloor(int capacity) ;

   ~GroundFloor() ;

    int getCapacity(); 

    int getPeople();

    bool thereisRoom();

    bool enter(Visitor * v);
    
    Visitor* exit();
};

#endif	/* GROUNDFLOOR_H */

