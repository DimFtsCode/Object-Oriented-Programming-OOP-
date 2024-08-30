#ifndef RECEPTIONIST_H
#define	RECEPTIONIST_H 
#include "visitor.h"

class Receptionist {
private:
    int last_given_priority;
    
    
public:
    Receptionist(); 
    ~Receptionist();

    void assignPriority(Visitor* v);
};

#endif	/* RECEPTIONIST_H */

