#include <iostream>
#include "hall.h"

using namespace std;

Hall::Hall() {
    cout << "A hall has been constructed  " << endl;
}   //construct the hall

Hall::~Hall() {
    cout << "A hall has been destroyed " << endl;
}       //distruct the hall

bool Hall::enter(Visitor* v) {
    PriorityQueue.push(v);
    return true;
}

Visitor* Hall::exit() {
    Visitor* v = PriorityQueue.front();
    PriorityQueue.pop();
    return v;
}


