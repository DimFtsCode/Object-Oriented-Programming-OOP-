
#ifndef GOODVISITOR_H
#define	GOODVISITOR_H

#include "visitor.h"

class GoodVisitor :public Visitor{
public:
    GoodVisitor(int id, int officeNo);
    virtual ~GoodVisitor();
    
    virtual void influence(Visitor* visitor);
    virtual void get_positive_influence();
    virtual void get_negative_influence();
private:

};

#endif	

