#include <vector>
#include "testobject.h"
class List {
private:
    std::vector<testobject> list_;
public:
    void insert(testobject test);
    void remove(int index);
    void print();
};
