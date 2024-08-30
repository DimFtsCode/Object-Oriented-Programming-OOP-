
#ifndef PARENTNODE_H
#define	PARENTNODE_H
#include "parent.h"

class ParentNode {
public:
    Parent* parent;
    ParentNode** nextParentNode;

    ParentNode(Parent* parent);
    ~ParentNode();
};

#endif	/* PARENTNODE_H */

