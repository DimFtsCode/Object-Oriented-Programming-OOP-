#include <iostream>
#include "groundfloor.h"

using namespace std;


    GroundFloor::GroundFloor(int capacity) : capacity(capacity), population(0) {    //floor creation
        cout << "A ground floor has been created with capacity " << capacity << endl;
    }

    GroundFloor::~GroundFloor() {       //floor distraction
        cout << "End of service for ground floor! " << endl;
    }

    int GroundFloor::getCapacity() {    //floor capacity
        return capacity;
    }

    int GroundFloor::getPeople() {  //floor's population
        return population;
    }

    bool GroundFloor::thereisRoom() {   //check if there is room 
        return population < capacity;
    }

    bool GroundFloor:: enter(Visitor * v) {     //visitor enters the groundhall or not
        if (thereisRoom()) {
            cout << "Visitor " << v->getId() << " entered ground floor " << endl;
            hall.enter(v);
            population++;
            return true;
        } else {
            cout << "Please, come tomorrow " << endl;
            return false;
        }
    }

    Visitor* GroundFloor::exit() {  //visitor's exit
        Visitor* v = hall.exit();
        if (v != NULL) {
            receptionist.assignPriority(v);
            population--;
        }
        return v;
    }
