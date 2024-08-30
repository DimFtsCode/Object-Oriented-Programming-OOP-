#ifndef FLOOR_H
#define	FLOOR_H
#include <queue>
#include "visitor.h"
#include "receptionist.h"
#include "hall.h"
#include "office.h"
#include "groundfloor.h"
#include "lobby.h"

using namespace std;

class Floor : public Groundfloor {
protected:
    Office** offices;
    Hall lobby;

public:
    Floor(int floor_number, int capacity, int offices_count, int office_capacity); 
    virtual ~Floor();
   
    virtual bool enter(Visitor* v);
    virtual Visitor* exit();
};

#endif	


