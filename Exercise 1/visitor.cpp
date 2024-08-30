
#include <iostream>
#include "visitor.h"

using namespace std;

Visitor::Visitor(int id, int officeNo) : id(id), priority(0), officeNo(officeNo), jobdone(false) {
    cout << "A Visitor has been constructed with id,office: (" << id << "," << officeNo << ")" << endl;
}

Visitor::~Visitor() {
    cout << "A Visitor has been destroyed with (" << id << "," << officeNo << ")" << endl;
}

int Visitor::getId() { // accessor
    return id;
}

int Visitor::getPriority() {
    return priority;
}

int Visitor::getOfficeNo() {
    return officeNo;
}

bool Visitor::getJobDone() {
    return true;
}

void Visitor::setJobDone() {
    jobdone = true;
}

void Visitor::setPriority(int newvalue) {
    priority = newvalue;
}

void Visitor::enter() {

}

void exit() {

}
