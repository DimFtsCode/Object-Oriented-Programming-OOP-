#include <iostream>
#include <cstdlib>
#include <queue>
#include "visitor.h"
#include "receptionist.h"
#include "hall.h"
#include "office.h"
#include "groundfloor.h"
#include "floor.h"
#include "lift.h"
#include "tower.h"

using namespace std;

int main(int argc, char** argv) {
    int tower_capacity = 240;
    int floor_capacity = 50;
    int ground_capacity = 50;
    int lift_capacity = 8;
    int office_capacity = 5;
    int officecount = 10;
    int visitors_population = 10;
    int l = 4;
    int floor_count = 4;

    if (argc == 9) {
        tower_capacity = atoi(argv[1]);
        floor_capacity = atoi(argv[2]);
        ground_capacity = atoi(argv[3]);
        lift_capacity = atoi(argv[4]);
        office_capacity = atoi(argv[5]);
        officecount = atoi(argv[6]);
        visitors_population = atoi(argv[7]);
        l = atoi(argv[8]);
    }

    Tower tower(floor_count, tower_capacity, floor_capacity, ground_capacity, lift_capacity, office_capacity, officecount);

    for (int i = 0; i < visitors_population; i++) {         //new visitors
        Visitor* v = new Visitor(i, rand() % (floor_count * officecount));
        tower.enter(v);
    }

    tower.run(l);       //tower's operation

    cout << endl;

    return 0;
}


