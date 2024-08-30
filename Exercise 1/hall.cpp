#include <iostream>
#include "hall.h"


using namespace std;


    Hall::Hall() {  //hall's creation
        cout << "The Entrance has been created!" << endl;
    }

    Hall::~Hall() { //hall's distraction
        cout << "End of waiting people! " << endl;
    }

    bool Hall::enter(Visitor* v) {  //visitor enters the hall
        pq.push(v);
        return true;
    }

    Visitor* Hall:: exit() {    //visitor's exit
        Visitor* v = pq.front();
        pq.pop();
        return v;
    }