#include <iostream>
#include <vector>
#include<ctime>
#include <cmath>
#include <fstream>
#include <string>
using namespace std;


// code modified from https://www.geeksforgeeks.org/radix-sort/


// A utility function to get maximum
// value in arr[]

// A utility function to print an array
void print(vector<long long>& arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout<<endl;
}

// Driver Code
int main(int argc, char **argv)
{
    vector<long long> arr;
    srand(time(0));
    int sample_size=10; // default values
    int number_of_digits = 2; // default values
    if(argc == 3) {
        sample_size=atoi(argv[1]);
        number_of_digits=atoi(argv[2]);// every input is an array of characters
        if(number_of_digits>20)
        number_of_digits = 20;
    }
    if(argc ==2){
        sample_size=atoi(argv[1]);
    }
    
    for(int i = 0 ; i<sample_size; i++){
        arr.push_back(rand()%(long long)pow(10, number_of_digits));
    }
    print(arr, arr.size());
        

    // Function Call
    auto start = std::chrono::high_resolution_clock::now();
    std::sort(arr.begin(), arr.end());
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    ofstream MyExcelFile;
    MyExcelFile.open("data/standard.csv", std::ios::app);

    //MyExcelFile << "Number of Digits, Sample Size, Time" << endl;
    MyExcelFile << number_of_digits<<", "<< sample_size<<", "<< duration.count() << endl;
    MyExcelFile.close();

    print(arr, arr.size());
    //cout<<"Execution Time: "<< duration.count()<< " s"<< endl;
    return 0;
}