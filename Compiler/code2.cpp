#include <iostream>
int count_no_digits(int n){
    int count = 0;
    while(n>0){
        n/=10;
        count++;
    }
    return count;
}
int main(){
    int a = 783;
    std::cout<<count_no_digits(a);
    return 0;
}
