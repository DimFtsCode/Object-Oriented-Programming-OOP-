#ifndef HALL_H
#define	HALL_H
#include <queue>
#include "visitor.h"
#include "receptionist.h"

using namespace std;

class Hall {
private:
    queue<Visitor*> PriorityQueue;
public:
    Hall(); 
    ~Hall(); 

    bool enter(Visitor* v);

    Visitor* exit();
};

#endif	

