
#ifndef BADVISITOR_H
#define	BADVISITOR_H

#include "visitor.h"


class BadVisitor : public Visitor {
public:
    BadVisitor(int id, int officeNo);
    virtual ~BadVisitor();
    virtual void influence(Visitor* visitor);
    virtual void get_positive_influence();
    virtual void get_negative_influence();
    
private:

};

#endif	

