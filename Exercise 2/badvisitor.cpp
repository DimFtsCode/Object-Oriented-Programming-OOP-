
#include "visitor.h"
#include "badvisitor.h"

BadVisitor::BadVisitor(int id, int officeNo) : Visitor(id, officeNo) {  //construct bad visitor
}

BadVisitor::~BadVisitor() {     //distruct bad visitor
    
}

void BadVisitor::influence(Visitor* visitor) {      //influence  for visitor
    visitor->get_negative_influence();
}


void BadVisitor::get_positive_influence() {         //gets positive influence
    if (anger - patience < DIFF_LIMIT) {
        patience++;
    }
}
void BadVisitor::get_negative_influence() {         //gets negative influence
    if (patience - anger < DIFF_LIMIT) {
        anger++;
        anger++;
    }
}
