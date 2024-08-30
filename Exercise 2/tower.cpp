#include <iostream>
#include "tower.h"
#include "lift.h"

using namespace std;



Tower::Tower(int floor_count, int tower_capacity, int floor_capacity, int ground_capacity, int lift_capacity, int office_capacity, int officecount) :
floor_count(floor_count),
tower_capacity(tower_capacity),
ground(ground_capacity),
lift(lift_capacity, this),
population(0) {
    floors = new Groundfloor*[floor_count];
    floors[0] = new Lobby(floor_capacity);
    
    for (int i = 1; i < floor_count; i++) {
        floors[i] = new Floor(i, floor_capacity, officecount, office_capacity);
    }
    cout << endl << endl << endl;
              }



Tower::~Tower() {
    for (int i = 0; i < 4; i++) {
        delete floors[i];
    }
    delete [] floors;

    cout << "A tower has been destroyed " << endl;
}

bool Tower::enter(Visitor* v) {
    if (population < tower_capacity) {
        cout << "Visitor v " << v->getId() << " entered the tower. " << endl;
        bool ok = ground.enter(v);
        if (ok) {
            population++;
            return true;
        } else {
            cout << "Visitor v " << v->getId() << " could not enter the groundfloor. He will come back again tommorrow " << endl;
            outOfBuildingQueue.push(v);
            return false;
        }                
    } else {
        cout << "Visitor v " << v->getId() << " please come tomorrow! " << endl;
        return false;
    }
}

void Tower::exit(Visitor* v) {
    cout << "Visitor " << v->getId() << " left the tower. " << endl;
    delete v;
    
    if (outOfBuildingQueue.size() > 0) {
        Visitor * t = outOfBuildingQueue.front();
        outOfBuildingQueue.pop();
        enter(t);
    }
}

void Tower::run(int L) {
    for (int i = 0; i < L; i++) {
        lift.operate();
    }
}

