#include "goodvisitor.h"
#include <iostream>

using namespace std;

GoodVisitor::GoodVisitor(int id, int officeNo) : Visitor(id, officeNo) {
}   //construct good visitor

GoodVisitor::~GoodVisitor() {   //distruct good visitor
}


void GoodVisitor::influence(Visitor* visitor)  {
    visitor->get_positive_influence();
}

void GoodVisitor::get_positive_influence() {    //when a good visitor has a positive influence
    if (anger - patience < DIFF_LIMIT) {
        patience++;
        patience++;
    }
}
void GoodVisitor::get_negative_influence() {        //when a good visitor has a negative influence
    cout << "You wont get me upset!!" << endl;
    if (patience - anger < DIFF_LIMIT) {
        anger++;
    }
}