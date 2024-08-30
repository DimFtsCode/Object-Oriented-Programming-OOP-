#ifndef PARENT_H
#define	PARENT_H

class Parent {
public:
    int id;
    int teacher_num;
    int* program;

    Parent(int id, int teacher_count);
    ~Parent();
    
    bool meetdone(); 

    void meetTeacher(int teacher_id);
};

#endif	/* PARENT_H */

