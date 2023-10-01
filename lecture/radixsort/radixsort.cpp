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
int getMax(vector<long long>& arr, int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

// A function to do counting sort of arr[]
// according to the digit
// represented by exp.
void countSort(vector<long long>& arr, int n, int exp)
{

    // Output array
    vector<long long> output(n);
    int i;
    vector<int> count(10);

    // Store count of occurrences
    // in count[]
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that count[i]
    // now contains actual position
    // of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[],
    // so that arr[] now contains sorted
    // numbers according to current digit
    arr=output;
}

// The main function to that sorts arr[]
// of size n using Radix Sort
void radixsort(vector<long long>& arr, int n)
{

    // Find the maximum number to
    // know number of digits
    int m = getMax(arr, n);

    // Do counting sort for every digit.
    // Note that instead of passing digit
    // number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

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
    radixsort(arr, arr.size());
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    ofstream MyExcelFile;
    MyExcelFile.open("decimal.csv", std::ios::app);

   // MyExcelFile << "Number of Digits, Sample Size, Time" << endl;
    MyExcelFile << number_of_digits<<", "<< sample_size<<", "<< duration.count() << endl;
    MyExcelFile.close();

    print(arr, arr.size());
    //cout<<"Execution Time: "<< duration.count()<< " s"<< endl;
    return 0;
}