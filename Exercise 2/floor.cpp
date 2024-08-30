#include <iostream>
#include "groundfloor.h"
#include "floor.h"

using namespace std;


Floor::Floor(int floor_number, int capacity, int offices_count, int office_capacity) : Groundfloor(floor_number, capacity, offices_count, office_capacity) {
    offices = new Office*[offices_count];
    for (int i = 0; i < offices_count; i++) {
        offices[i] = new Office((floor_number - 1) * offices_count + i, office_capacity);
    }
    cout << "A floor has been constructed with capacity " << capacity << " and " << offices_count << " offices " << endl;
}       //construct floor

Floor::~Floor() {       //distractor
    for (int i = 0; i < office_count; i++) {
        delete offices[i];
    }
    delete offices;

    cout << "A floor has been destroyed " << endl;
}

bool Floor::enter(Visitor* v) {     //visitor enters a floor
    if (thereisRoom()) {
        int target_office = v->getOfficeNo() % office_count;
        if (offices[target_office]->thereisRoom()) {
            offices[target_office]->enter(v);
        } else {
            cout << "Visitor " << v->getId() << " entered floor " << floor_number << " for office " << v->getOfficeNo() <<  endl;
            lobby.enter(v);
        }
        population++;
        
        return true;

    } else {
        cout << "Visitor " << v->getId() << " could not enter the floor " << floor_number << " for office " << v->getOfficeNo() <<  endl;
        return false;
    }
}

Visitor* Floor::exit() {        //visitor exits a floor
    Visitor* v = lobby.exit();
    if (v != NULL) {
        int target_office = v->getOfficeNo() % office_count;
        if (offices[target_office]->thereisRoom()) {
            offices[target_office]->enter(v);
        } else {
            lobby.enter(v);
        }
    }

    for (int i = 0; i < office_count; i++) {
        if (offices[i]->getPeople() > 0) {
            Visitor* v = offices[i]->exit();
            if (v != NULL) {
                population--;
                cout << "Visitor " << v->getId() << " exited floor with number " << floor_number << " for office " << v->getOfficeNo() <<  endl;
                return v;
            }
        }
    }
    return NULL;
}