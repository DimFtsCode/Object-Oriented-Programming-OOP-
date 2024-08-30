#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "parent.h"
#include "parentnode.h"
#include "parentqueue.h"

using namespace std;

    ParentQueue::ParentQueue(int teach_num) : teach_num(teach_num) {      //parent queue instractor
        firstParent = new ParentNode*[teach_num];
        for (int i = 0; i < teach_num; i++) {
            firstParent[i] = NULL;
        }
    }

    ParentQueue::~ParentQueue() {       //parent queue distractor
        delete [] firstParent;
    }

    void ParentQueue::enqueue(Parent* parent) { //put a parent in queue
        ParentNode* newNode = new ParentNode(parent);

        if (tail == NULL) {            
            for (int i = 0; i < teach_num; i++) {
                if (parent->program[i] == 1) {
                    firstParent[i] = newNode;
                }
            }
            tail = newNode;
            cout << "Parent " << parent->id << " was enqueued as the only parent. ";
        } else {
            for (int i = 0; i < teach_num; i++) {
                if (parent->program[i] == 1) {
                    newNode->nextParentNode[i] = firstParent[i];
                    firstParent[i] = newNode;
                }
            }
            tail = newNode;
            cout << "Parent " << parent->id << " was enqueued. ";
        }
        
        for (int i = 0; i < parent->teacher_num; i++) {
            cout << parent->program[i];
        }
        cout << endl;
    }

    Parent* ParentQueue::dequeue(int teacher_id) {      // dequeues a parent
        ParentNode* previousToLast;
        ParentNode* last;
        
        if (tail == NULL || firstParent[teacher_id] == NULL) {
            cout << "No parent for teacher " << teacher_id << endl;
            return NULL;
        }
        
        last = firstParent[teacher_id];
        while (last->nextParentNode[teacher_id] != NULL) {
            last = last->nextParentNode[teacher_id];
        }
        
        Parent* p = last->parent;

        for (int i = 0; i < teach_num; i++) {
            previousToLast = firstParent[i];

            while (previousToLast->parent->program[i] == 1 &&
                    previousToLast->nextParentNode[i] != NULL &&
                    previousToLast->nextParentNode[i] != last) {
                previousToLast = previousToLast->nextParentNode[i];
            }
            
                if (previousToLast->nextParentNode[i] == NULL) {
                if (previousToLast == last) {
                    firstParent[i] =NULL;
                }
                continue;
            } else {
                previousToLast->nextParentNode[i] = previousToLast->nextParentNode[i]->nextParentNode[i];
            }
        }

        cout << "Parent " << p->id << " was dequeued for teacher " << teacher_id << " ";
        for (int i = 0; i < p->teacher_num; i++) {
            cout << p->program[i];
        }
        cout << endl;
        return p;
    };
