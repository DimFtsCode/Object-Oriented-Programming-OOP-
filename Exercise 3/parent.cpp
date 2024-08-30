#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "parent.h"

using namespace std;

    Parent::Parent(int id, int teacher_num) : id(id), teacher_num(teacher_num) {      //parent instractor
        cout << "A parent came with id: "<<id<<endl;
        program = new int[teacher_num];
        for (int i = 0; i < teacher_num; i++) {
            program[i] = (unsigned) (rand() % 2);              //random plan of parent
        }
        cout << "His program is:  ";
        for (int i = 0; i < teacher_num; i++) {
            cout << program[i];
        }
        cout<<endl;        

    }

    Parent::~Parent() {     //parent's distraction
        cout << "Parent " << id << ": leaves the school " << endl;
        delete [] program;
    }
    
    bool Parent:: meetdone() {      //checks if parent's meetings has finished
        int count = 0;
        for (int i = 0; i < teacher_num; i++) {
            count += program[i];
        }
        return count == 0;
    }

    void Parent:: meetTeacher(int teacher_id) {     //checks if a parent has meet a teacher
        program[teacher_id] = 0;
    }

