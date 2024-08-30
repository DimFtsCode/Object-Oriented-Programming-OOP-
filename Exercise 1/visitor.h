#ifndef VISITOR_H
#define	VISITOR_H


class Visitor {
private:
    int id;
    int priority;
    int officeNo;
    bool jobdone;

public:
    Visitor(int id, int officeNo);
    ~Visitor();

    int getId() ;

    int getPriority() ;

    int getOfficeNo();

    bool getJobDone();

    void setJobDone() ;

    void setPriority(int newvalue) ;

    void enter() ;

    void exit() ;
};

#endif	/* VISITOR_H */
