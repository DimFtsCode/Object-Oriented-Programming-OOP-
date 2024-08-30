#ifndef SCHOOL_H
#define	SCHOOL_H
#include "parent.h"
#include "parentnode.h"
#include "parentqueue.h"

class School {
public:
    int K, L, N;
    
    School(int K, int L, int N);
    
    ~School();
    
    void loop() ;
};

#endif	/* SCHOOL_H */

