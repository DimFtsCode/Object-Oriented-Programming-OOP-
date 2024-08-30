#include <iostream>
#include "groundfloor.h"

using namespace std;

    Office::Office(int office_no, int capacity) : office_no(office_no), capacity(capacity) {        //office creation
        cout << "Office  " << office_no << "has been created! "  << endl;
    }

    Office::~Office() {     //office distraction
        cout << "Office " << office_no << " End of work! " << endl;
    }

    int Office::getCapacity() {     //office's capacity
        return capacity;
    }

    int Office::getPeople() {       //office's population
        return pq.size();
    }

    bool Office:: thereisRoom() {       //check if there is room
        return pq.size() < capacity;
    }

    void Office::enter(Visitor* v) {        //visitor enters the office
        cout << "Visitor " << v->getId() << " entered the office no" << office_no << endl;
        pq.push(v);
    }

    Visitor* Office:: exit() {          //visitor exits the office
        if (pq.size() == 0) {
            return NULL;
        }
        Visitor* v = pq.front();
        pq.pop();

        cout << "Visitor " << v->getId() << " exited office no " << office_no << endl;
        return v;
    }

