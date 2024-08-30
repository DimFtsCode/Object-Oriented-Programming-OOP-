#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "parentnode.h"


    ParentNode::ParentNode(Parent* parent) : parent(parent) {       //parents node instraction 
        nextParentNode = new ParentNode*[parent->teacher_num];
        for (int i = 0; i < parent->teacher_num; i++) {
            nextParentNode[i] = NULL;
        }
    }

    ParentNode::~ParentNode() {     //parentnode distraction
        delete [] nextParentNode;
    }
