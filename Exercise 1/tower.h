#ifndef TOWER_H
#define	TOWER_H

#include "visitor.h"
#include "receptionist.h"
#include "hall.h"
#include "office.h"
#include "groundfloor.h"
#include "floor.h"
#include "lift.h"
#include <queue>

class Lift;
class Tower;

class Tower {
public:
    int floor_count;
    int Tower_capacity;
    int population;
    GroundFloor ground;
    Lift lift;
    Floor** floors;
    

    Tower(int floor_count, int Tower_capacity, int floor_capacity, int ground_capacity, int lift_capacity, int office_capacity, int officecount);

    ~Tower();

    bool enter(Visitor* v) ;
    void exit(Visitor* v) ;
    void run(unsigned L) ;
};






#endif	/* TOWER_H */

