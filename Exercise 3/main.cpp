#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "parent.h"
#include "parentnode.h"
#include "parentqueue.h"
#include "school.h"

using namespace std;

int main(int argc, char** argv) {
    int K = 30;      //parents
    int L = 8;     //first parents
    int N = 3;     //teachers

    School school(K,L,N);
    
    school.loop();

    return 0;
}

 