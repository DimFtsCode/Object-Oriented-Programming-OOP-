#include <iostream>
#include "receptionist.h"

using namespace std;

Receptionist::Receptionist() : last_given_priority(1){      //human who gives priority to visitors
   
}

Receptionist::~Receptionist(){      //human's distractions
}

void Receptionist::assignPriority(Visitor* v) {
        if (v->getPriority() == 0) {
            ++last_given_priority;
            v->setPriority(last_given_priority);
            cout << "Visitor " << v->getId() << " was given priority and waits for the lift " << last_given_priority - 1 << endl;
        }
    
}