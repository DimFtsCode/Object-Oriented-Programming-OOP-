#ifndef PARENTQUEUE_H
#define	PARENTQUEUE_H
#include "parent.h"
#include "parentnode.h"

class ParentQueue {
public:
    ParentNode* tail;
    ParentNode** firstParent;
    int teach_num;

    ParentQueue(int teach_count);
    
    ~ParentQueue() ;

    void enqueue(Parent* parent) ;
    
    Parent* dequeue(int teacher_id) ;
};

#endif	/* PARENTQUEUE_H */

