#ifndef OFFICE_H
#define	OFFICE_H
#include "visitor.h"
#include "receptionist.h"
#include "hall.h"
#include <queue>

class Office {
private:
    int office_no;
    int capacity;
    std::  queue<Visitor*> pq;
public:
    Office(int office_no, int capacity);
    ~Office();

    int getCapacity();
    int getPeople();
    bool thereisRoom();
    void enter(Visitor* v);
    Visitor* exit();
};

#endif	/* NEWFILE_H */

