#include "testobject.h"
testobject::testobject(){
    for(int i=0;i<100000;i++)
    a[i]=rand()%100; 
}

