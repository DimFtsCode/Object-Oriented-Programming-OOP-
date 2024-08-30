#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "parent.h"
#include "parentnode.h"
#include "parentqueue.h"
#include "school.h"

using namespace std;



School::School(int K, int L, int N) : K(K),L(L), N(N) {     //scholl instractor
        cout << "a school has been created " << endl;
    }
    
    School:: ~School() {                                //school distractor
        cout << "a school has been destroyed " << endl;
    }
    
    void School:: loop() {      //scool's operation
        int id;
        ParentQueue pq(N);
        
        for (id=1;id<=L;id++) {                 
            Parent* p = new Parent(id, N);
            if (!p->meetdone()) {
                pq.enqueue(p);
            } else {
                delete p;
            }
        }
        
        while (id < K) {
            for (int n=0;n<N;n++) {
                Parent* p = pq.dequeue(n);
                if (p != NULL) {
                    p->meetTeacher(n);
                    if (!p->meetdone())  {
                        pq.enqueue(p);
                    } else {
                        delete p;
                    }
                }
            }
            
            if (K != id) {
                int q = 1 + rand()%(K-id);
                for (int i=0;i<q;i++) {
                    Parent* p = new Parent(id, N);
                    pq.enqueue(p);
                    id++;
                }
            }
        }
    };
