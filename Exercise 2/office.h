#ifndef OFFICE_H
#define	OFFICE_H
#include <deque>
#include "visitor.h"
#include "receptionist.h"
#include "hall.h"
#include "groundfloor.h"


class Office {
private:
    deque<Visitor*> prioriotyQueue;
    int office_no;
    int capacity;
public:

    Office(int office_no, int capacity);
    ~Office();
        
    int getCapacity();
    int getPeople();
    bool thereisRoom(); 
    void enter(Visitor* v);
    Visitor* exit();
};

#endif	

