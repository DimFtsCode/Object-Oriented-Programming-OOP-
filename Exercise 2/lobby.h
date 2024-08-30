#ifndef ZEROFLOOR_H
#define	ZEROFLOOR_H

#include <queue>
#include "visitor.h"
#include "lobby.h"
#include "hall.h"
#include "office.h"
#include "groundfloor.h"

using namespace std;

class Lobby : public Groundfloor {
protected:    
    Receptionist receptionist;

public:
    Lobby(int capacity);
    virtual  ~Lobby();
    
    virtual bool enter(Visitor * v); 
    virtual Visitor* exit();
};

#endif	

