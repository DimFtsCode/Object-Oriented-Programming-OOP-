#include <iostream>
#include "lobby.h"
#include "groundfloor.h"
#include <cstdlib>

using namespace std;


Office::Office(int office_no, int capacity) : office_no(office_no), capacity(capacity) {
    cout << "Office  " << office_no << " has been constructed with capacity " << capacity << endl;
}   //office instructor

Office::~Office() {
    cout << "Office " << office_no << " has been destructed " << endl;
}       //lobby distructor

int Office::getCapacity() {
    return capacity;
}

int Office::getPeople() {
    return prioriotyQueue.size();
}

bool Office::thereisRoom() {
    return prioriotyQueue.size() < capacity;
}

void Office::enter(Visitor* v) {
    cout << "Visitor " << v->getId() << " entered the office with number " << office_no << endl;
    prioriotyQueue.push_back(v);
    
    int i = rand()%prioriotyQueue.size();   // pick a noiser
    Visitor* temp = prioriotyQueue[i];
    for (int j=i+1;j<prioriotyQueue.size();j++) {
        temp->influence(prioriotyQueue[j]);        
    }
    
    int sum_pat = 0;
    int sum_ang = 0;
    
    for (int i=0;i<prioriotyQueue.size();i++) {
        sum_pat += prioriotyQueue[i]->getPatience();
        sum_ang += prioriotyQueue[i]->getAnger();
    }
    
    if (sum_pat - sum_ang > 100 ) {
        cout << "Peace and cerenity in the floor !!!"  << endl;
    } else {
        cout << "What a mess in the floor !!! " <<  endl;
    }
}

Visitor* Office::exit() {
    if (prioriotyQueue.size() == 0) {
        return NULL;
    }
    Visitor* v = prioriotyQueue.front();
    prioriotyQueue.pop_front();

    cout << "Visitor " << v->getId() << " exited office with number " << office_no << endl;
    return v;
}

