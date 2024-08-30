#ifndef HALL_H
#define	HALL_H

#include "visitor.h"
#include "receptionist.h"
#include <queue>


class Hall {
private:
  std::  queue<Visitor*> pq;
public:
    Hall(); 
    ~Hall();

    bool enter(Visitor* v);

    Visitor* exit();
};

#endif	/* HALL_H */

