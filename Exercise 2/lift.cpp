#include <iostream>
#include "lift.h"
#include "visitor.h"
#include "tower.h"

using namespace std;

Lift::Lift(int capacity, Tower* bs) : capacity(capacity), floor_number(-1), tower(bs) {
    cout << "A Lift has been constructed with capacity " << capacity << endl;
}       //construct lift

Lift::~Lift() {
    cout << "A Lift has been destructed. " << endl;
}       //distract floor

int Lift::getCapacity() {
    return capacity;
}

void Lift::enter() {
    if (floor_number == -1) {
        while (tower->ground.getPeople() > 0 && priorityQueue.size() < capacity) {
            Visitor* v = tower->ground.exit();            
            priorityQueue.push(v);
            cout << "Visitor " << v->getId() << " enters Lift from ground floor" << " for office " << v->getOfficeNo() <<  endl;
        }
    } else {
        while (tower->floors[floor_number]->getPeople() > 0 && priorityQueue.size() < capacity) {
            Visitor* v = tower->floors[floor_number]->exit();
            if (v == NULL) {
                break;
            }
            priorityQueue.push(v);
            cout << "Visitor " << v->getId() << " enters lift from floor " << floor_number + 1 << " for office " << v->getOfficeNo() <<  endl;           
        }
    }
}

void Lift::stop_up() {
    floor_number++;
}

void Lift::stop_down() {
    floor_number--;
}

void Lift::empty_all() {
    if (priorityQueue.size() > 0) {
        queue<Visitor*> outwards;

        while (priorityQueue.size() > 0) {
            Visitor* v = priorityQueue.front();
            priorityQueue.pop();
            outwards.push(v);
        }

        while (outwards.size() > 0) {
            Visitor* v = outwards.front();
            outwards.pop();
            
            if (v->getJobDone() == true) {
                tower->exit(v);
            } else {
                priorityQueue.push(v);
            }
        }
        
        
    }
}

void Lift::exit() {
    queue<Visitor*> Out;

    while (priorityQueue.size() > 0) {
        Visitor* v = priorityQueue.front();
        priorityQueue.pop();
        Out.push(v);
    }

    while (Out.size() > 0) {
        Visitor* v = Out.front();
        Out.pop();
        
        if (tower->floors[floor_number]->thereisRoom()
                && v->getOfficeNo() >= floor_number * tower->floors[floor_number]->getOfficesCount()
                && v->getOfficeNo() < (floor_number + 1) * tower->floors[floor_number]->getOfficesCount()) {
            if (tower->floors[floor_number]->getPeople() < tower->floors[floor_number]->getCapacity()) {
                cout << "Visitor " << v->getId() << " exits lift from floor " << floor_number + 1 << " for office " << v->getOfficeNo() <<  endl;
                tower->floors[floor_number]->enter(v);
            }
        } else {
            priorityQueue.push(v);
        }
    }
}

void Lift::operate() {
    cout << "---------- Lift operation - ENTER" << endl;
    enter();
    for (int i = 0; i < tower->floor_count; i++) {
        cout << "---------- Lift operation - STEP UP" << endl;
        stop_up();
        cout << "---------- Lift operation - EXIT" << endl;
        exit();
    }

    for (int i = 0; i < tower->floor_count; i++) {
        cout << "---------- Lift operation - ENTER" << endl;
        enter();
        cout << "---------- Lift operation - STEP DOWN" << endl;
        stop_down();
    }
    cout << "---------- Lift operation - EMPTY ALL" << endl;
    empty_all();
}