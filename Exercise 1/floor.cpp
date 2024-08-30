#include <iostream>
#include "floor.h"

using namespace std;

    Floor::Floor(int floor_number, int capacity, int offices_count, int office_capacity) : floor_number(floor_number), capacity(capacity), offices_count(offices_count), population(0) {
        offices = new Office*[offices_count];       //floor creation
        for (int i = 0; i < offices_count; i++) {      
            offices[i] = new Office((floor_number - 1) * offices_count + i, office_capacity);
        }
        cout << "A Floor has been created with number: " <<floor_number << endl;
    }

    Floor::~Floor() {       //floor distraction
        for (int i = 0; i < offices_count; i++) {
            delete offices[i];
        }
        delete offices;

        cout << "End of service for floor: "<<floor_number <<"!!!"<< endl;
    }

    int Floor::getCapacity() {  //gets office capacity
        return capacity;
    }

    int Floor::getOfficesCount() {      //gets the number of the offices
        return offices_count;
    }

    int Floor::getPeople() {        //gets the population
        return population;
    }

    bool Floor::thereisRoom() {     //checks if there is room
        return population < capacity;
    }

    bool Floor:: enter(Visitor* v) {        //checks if a visitor can enter the room
        if (population < capacity) {
            int target_office = v->getOfficeNo() % offices_count;
            if (offices[target_office]->thereisRoom()) {
                offices[target_office]->enter(v);
            } else {
                cout << "Visitor " << v->getId() << " entered floor " << floor_number << " for office " << v->getOfficeNo() <<  endl;
                hall.enter(v);
            }
            population++;
            return true;

        } else {
            cout << "Visitor " << v->getId() << "Sorry, floor number floor:" << floor_number <<" is full"   <<   endl;
            return false;
        }
    }

    Visitor* Floor:: exit() {       //checks if there is room in order to exit from floor
        Visitor* v = hall.exit();
        if (v != NULL) {
            int target_office = v->getOfficeNo() % offices_count;
            if (offices[target_office]->thereisRoom()) {
                offices[target_office]->enter(v);
            } else {
                hall.enter(v);
                cout<< "Visitor" <<v->getId()<<"Please, wait outside for entrance in office number"<< v->getOfficeNo()<<"with priority:"<<v->getPriority()<<endl;
            }
        }

        for (int i = 0; i < offices_count; i++) {
            if (offices[i]->getPeople() > 0) {
                Visitor* v = offices[i]->exit();
                if (v != NULL) {
                    population--;
                    cout << "Visitor " << v->getId() << " exited floor with number " << floor_number << " for office " << v->getOfficeNo()   <<endl;
                    return v;
                }
            }
        }
        return NULL;
    }


