#include <list>
#include "testobject.h"
class List {
private:
    std::list<testobject> list_;
public:
    void insert(testobject test);
    void remove(int index);
    void print();
};
