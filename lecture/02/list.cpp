#include "list.h"

#include <iostream>

void List::insert(testobject test) {
    //list_.insert(std::upper_bound( list_.begin(), list_.end(), number), number);
    // auto it = list_.begin();
    // while (it != list_.end() && (*it < number)) {
    //     ++it;
    // }
     list_.insert(list_.begin(), test);
    //list_.push_back(test);
}

void List::remove(int index) {
    auto it = list_.begin();
    
    while(index-- > 0) {
        ++it;
    }

    list_.erase(it);
}

void List::print() {

    for( testobject num : list_) {
        //std::cout << num.a[0] << " ";
    }
    std::cout << std::endl;
}