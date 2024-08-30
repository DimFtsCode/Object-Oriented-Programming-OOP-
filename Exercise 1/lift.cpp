#include <iostream>
#include "lift.h"
#include "visitor.h"
#include "tower.h"


using namespace std;

Lift::Lift(int capacity, Tower* bs) : capacity(capacity),floor_number(-1), tower(bs) {     //lift's creation
    cout << "A lift has been created" << endl;
}

Lift::~Lift() {     //lift's distraction
    cout << "No more ups and downs!" << endl;
}

int Lift::getCapacity() {   //returns lift's capacity
    return capacity;
}

void Lift::enter() {        //checks if a visitor can enter the lift from groundhall
    if (floor_number == -1) {
        while (tower->ground.getPeople() > 0 && pq.size() < capacity) {
            Visitor* v = tower->ground.exit();            
            pq.push(v);
            cout << "Visitor " << v->getId() << "  in the lift" <<  endl;
                          
        }
    } else {        //from floor
        while (tower->floors[floor_number]->getPeople() > 0 && pq.size() < capacity) {
            Visitor* v = tower->floors[floor_number]->exit();
            if (v == NULL) {
                break;
            }
            pq.push(v);
            cout << "Visitor " << v->getId() << " enters the   lift from floor " << floor_number + 1 << " for office " << v->getOfficeNo() <<  endl;           
        }
    }
}

void Lift::stop_up() {  //stop to the next floor
    floor_number++;
}

void Lift::stop_down() {    //stop to the previous floor
    floor_number--;
}

void Lift::empty_all() {        //the lift gets empty on the groundhall
    if (pq.size() > 0) {
        queue <Visitor*> lift_out;
        
        while (pq.size() > 0) {
            Visitor* v = pq.front();
            pq.pop();
            lift_out.push(v);
        }

        while (lift_out.size() > 0) {
            Visitor* v = lift_out.front();
            lift_out.pop();
            
            if (v->getJobDone() == true) {      //if visitor has been to an office and finished his work
                tower->exit(v);
                cout << "Visitor " << v->getId() << " says: I cannot believe I finihed!! " << endl;
            } else {
                pq.push(v);
            }
        }
    }
}

void Lift::exit() {         //visitor exits the lift
    queue<Visitor*> lift_out;

    while (pq.size() > 0) {
        Visitor* v = pq.front();
        pq.pop();
        lift_out.push(v);
    }

    while (lift_out.size() > 0) {
        Visitor* v = lift_out.front();
        lift_out.pop();
        
        if (tower->floors[floor_number]->thereisRoom()
                && v->getOfficeNo() >= floor_number * tower->floors[floor_number]->getOfficesCount()
                && v->getOfficeNo() < (floor_number + 1) * tower->floors[floor_number]->getOfficesCount()) {
            if (tower->floors[floor_number]->getPeople() < tower->floors[floor_number]->getCapacity()) {
                cout << "Visitor " << v->getId() << " exits lift from floor " << floor_number + 1 << " for office " << v->getOfficeNo() <<  endl;
                tower->floors[floor_number]->enter(v);
            }
        } else {
            pq.push(v);
        }
    }
}


void Lift::operate() {      //lift's operation (up and down)    in the building
    cout << "-----   LIFT - ENTER   -----" << endl;
    enter();
    for (int i = 0; i < tower->floor_count; i++) {
        cout << "-----   LIFT - STEP UP -----" << endl;
        stop_up();
        cout << "-----   LIFT - EXIT    -----" << endl;
        exit();
    }

    for (int i = 0; i < tower->floor_count; i++) {
        cout << "----- LIFT - ENTER     -----" << endl;
        enter();
        cout << "----- LIFT - STEP DOWN -----" << endl;
        stop_down();
    }
    cout << "----- LIFT - EMPTY ALL -----" << endl;
    empty_all();
}
