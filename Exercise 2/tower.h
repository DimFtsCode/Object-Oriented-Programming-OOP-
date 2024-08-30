#ifndef TOWER_H
#define	TOWER_H

#include <queue>
#include "visitor.h"
#include "receptionist.h"
#include "hall.h"
#include "office.h"
#include "lobby.h"
#include "floor.h"
#include "lift.h"
#include "groundfloor.h"

class Tower {
public:
    int floor_count;
    int tower_capacity;
    Lobby ground;
    Lift lift;
    Groundfloor** floors;
    int population;
    queue<Visitor*> outOfBuildingQueue;

    Tower(int floor_count, int tower_capacity, int floor_capacity, int ground_capacity, int lift_capacity, int office_capacity, int officecount);
    ~Tower();
    bool enter(Visitor* v);
    void exit(Visitor* v);
    void run(int L);
};

#endif	

