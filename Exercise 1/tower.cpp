#include <iostream>
#include "tower.h"
#include "lift.h"

using namespace std;

     Tower::Tower(int floor_count, int Tower_capacity, int floor_capacity, int ground_capacity, int lift_capacity, int office_capacity, int officecount) :
     floor_count(floor_count),Tower_capacity(Tower_capacity),ground(ground_capacity),lift(lift_capacity, this),population(0) {
      
        floors = new Floor*[floor_count];
        for (int i = 0; i < floor_count; i++) {
            floors[i] = new Floor(i + 1, floor_capacity, officecount, office_capacity);
        }
          cout << "A new building is ready for serving citizens!" << endl;
    }
        

    Tower::~Tower() {
        for (int i = 0; i < 4; i++) {
            delete floors[i];
        }
        delete [] floors;

        cout << "Service not available any longer.Go elsewhere!" << endl;
    }

    bool Tower:: enter(Visitor* v) {
        if (population < Tower_capacity) {
            cout << "Visitor v " << v->getId() << " entered the tower. " << endl;
            bool ok = ground.enter(v);
            if (ok) {
                population++;
                return true;
            } else {
                cout << "Visitor v " << v->getId() << " could not enter the ground floor. " << endl;
                return false;
            }
        } else {
            cout << "Visitor v " << v->getId() << " Please, come tomorrow " << endl;
            return false;
        }
    }

    void Tower::exit(Visitor* v) {
        cout << "Visitor " << v->getId() << " left the building. " << endl;
        delete v;
    }

    void Tower:: run(unsigned L) {
        for (unsigned i = 0; i < L; i++) {
            lift.operate();
        }
    }
