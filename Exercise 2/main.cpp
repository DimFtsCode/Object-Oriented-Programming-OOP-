#include <iostream>
#include <cstdlib>
#include <queue>
#include "visitor.h"
#include "receptionist.h"
#include "hall.h"
#include "office.h"
#include "lobby.h"
#include "floor.h"
#include "lift.h"
#include "tower.h"
#include "goodvisitor.h"
#include "badvisitor.h"

using namespace std;

int main(int argc, char** argv) {
    int tower_capacity = 280;
    int floor_capacity = 20;
    int lobby_capacity = 20;
    int lift_capacity = 10;
    int office_capacity = 5;
    int officecount = 10;
    int k = 10;
    int l = 3;
    int floor_count = 4;

    if (argc == 9) {
        tower_capacity = atoi(argv[1]);
        floor_capacity = atoi(argv[2]);
        lobby_capacity = atoi(argv[3]);
        lift_capacity = atoi(argv[5]);
        office_capacity = atoi(argv[4]);
        officecount = atoi(argv[5]);
        k = atoi(argv[9]);
        l = atoi(argv[10]);
    }

    Tower bs(floor_count, tower_capacity, floor_capacity, lobby_capacity, lift_capacity, office_capacity, officecount);

    for (int i = 0; i < k; i++) {
        int dice = rand()%3;
        if (dice < 2) {
            Visitor* v = new GoodVisitor(i, rand() % (floor_count * officecount));
            bs.enter(v);
        } else {
            Visitor* v = new BadVisitor(i, rand() % (floor_count * officecount));
            bs.enter(v);
        }
    }

    bs.run(l);

    cout << endl << endl << endl;

    return 0;
}



