#ifndef VISITOR_H
#define	VISITOR_H

#define DIFF_LIMIT 10

class Visitor {
protected:
    int id;
    int priority;
    int officeNo;
    bool jobdone;
    int patience;
    int anger;

public:
    Visitor(int id, int officeNo);
    virtual ~Visitor();

    int getId() ;

    int getPriority() ;

    int getOfficeNo();

    bool getJobDone();

    void setJobDone() ;

    void setPriority(int newvalue) ;

    virtual void enter() ;

    virtual void exit() ;
    
    virtual void influence(Visitor* visitor);
    virtual void get_positive_influence();
    virtual void get_negative_influence();
    
    int getPatience();
    int getAnger();
};


#endif	

