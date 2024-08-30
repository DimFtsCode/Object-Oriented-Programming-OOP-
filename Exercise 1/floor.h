

#ifndef FLOOR_H
#define	FLOOR_H
#include "visitor.h"
#include "receptionist.h"
#include "hall.h"
#include "office.h"
#include "groundfloor.h"
#include <queue>

using namespace std;

class Floor {
private:
    int floor_number;
    int capacity;
    int population;
    int offices_count;
    Office** offices;   
    Hall hall;
    std::  queue<Visitor*> pq;
    
public:

    Floor(int floor_number, int capacity, int offices_count, int office_capacity);

    ~Floor() ;

    int getCapacity() ;

    int getOfficesCount() ;

    int getPeople() ;

    bool thereisRoom() ;

    bool enter(Visitor* v) ;

    Visitor* exit() ;
};
        








#endif	/* FLOOR_H */

