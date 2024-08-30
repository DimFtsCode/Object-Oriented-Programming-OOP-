#include <iostream>
#include "lobby.h"

using namespace std;


Lobby::Lobby(int capacity) :  Groundfloor(0, capacity, 0, 0) {
    cout << "A lobby has been constructed with capacity " << capacity << endl;
}       //lobby instructor

Lobby::~Lobby() {
    cout << "A lobby has been destroyed " << endl;
}   //lobby distructor

bool Lobby::enter(Visitor * v) {
    if (thereisRoom()) {
        cout << "Visitor " << v->getId() << " entered the lobby " << endl;
        lobby.enter(v);
        population++;
        return true;
    } else {
        cout << "Visitor " << v->getId() << " could not enter the agency " << endl;
        return false;
    }
}

Visitor* Lobby::exit() {
    Visitor* v = lobby.exit();
    if (v != NULL) {
        receptionist.assignPriority(v);
        population--;
    }
    return v;
}
