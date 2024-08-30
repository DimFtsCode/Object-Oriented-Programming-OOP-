
#ifndef GROUNDFLOOR_H
#define	GROUNDFLOOR_H

#include "visitor.h"
#include "hall.h"

class Groundfloor {
protected:
    Hall lobby;
    
    int floor_number;
    int capacity;
    int population;
    int office_count;
    int office_capacity;
    
public:
    Groundfloor(int floor_number, int capacity, int office_count, int office_capacity);
    virtual ~Groundfloor();
    
    int getCapacity();    
    int getPeople();
    
    virtual bool thereisRoom();
    virtual int getOfficesCount();
    
    virtual bool enter(Visitor* v) = 0;
    virtual Visitor* exit() = 0;
};

#endif	

