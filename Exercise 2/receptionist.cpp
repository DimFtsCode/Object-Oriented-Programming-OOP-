#include <iostream>
#include "receptionist.h"

using namespace std;

Receptionist::Receptionist() : last_given_priority(1) {
        
    }       //receptionist instructor

Receptionist::~Receptionist() {;
        
    }  //receptionist instructor 

void Receptionist::assignPriority(Visitor* v) {
    if (v->getPriority() == 0) {
        ++last_given_priority;
        v->setPriority(last_given_priority);
        cout << "Visitor " << v->getId() << " was assigned priority " << last_given_priority - 1 << endl;
    }
}

