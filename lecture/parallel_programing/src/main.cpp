#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include <random>
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>



void generate_random(double*, int, std::mt19937&);
 int loc(int i, int j, int n)
{
	return ( (n * i) + j);
}
void printMatrix(double *a, int n)
{
	for(int i = 0; i < n ; i++)
	{
		for(int j = 0; j < n; j++)
			printf("%f\t",a[loc(i,j,n)]);
		printf("\n");
	}		
}
void reset(double* C, int n){
    for(int i = 0; i < n ; i++)
	{
		for(int j = 0; j < n; j++)
			C[loc(i,j,n)]=0;
	}
}

void matmul(double *A, double *B, double *C, int n)
{
	#pragma omp parallel for collapse(2)
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			C[loc(i,j,n)] = 0.0;
	
	#pragma omp parallel for collapse(2)
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			for(int k = 0; k < n; k++)
				C[loc(i,j,n)]+= A[loc(i,k,n)] * B[loc(k,j,n)];
				
}

void matmul_serial(double *A, double *B, double *C, int n)
{
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			C[loc(i,j,n)] = 0.0;
	
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			for(int k = 0; k < n; k++)
				C[loc(i,j,n)]+= A[loc(i,k,n)] * B[loc(k,j,n)];
				
}

int main(){
    omp_set_num_threads(2);
    int n = 3;
    #pragma omp parallel
    {
    std::cout<<n<<std::endl;
    }
    
    double* A = new double[n*n];
    double* B = new double[n*n];
    double* CP = new double[n*n];
    double* CS = new double[n*n];
    std::mt19937 gen(std::time(0));
    generate_random(A,n, gen);
    generate_random(B,n, gen);
     std::ofstream MyExcelFile;
    MyExcelFile.open("../data/parallel_mult.csv", std::ios::app);

    for(int i = 1; i<=6; i++){
        omp_set_num_threads(omp_get_max_threads()*2);
        reset(CP,n);
    auto startParallel = std::chrono::high_resolution_clock::now();
    matmul(A,B,CP,n);
    auto endParallel = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> durationParallel = endParallel - startParallel;
    std::cout<<"The time it takes for parallel is "<< durationParallel.count()<<" with "<< omp_get_max_threads()<<" threads"<<std::endl;
    MyExcelFile << omp_get_max_threads()<<", "<< n<<", "<< durationParallel.count() << std::endl;
    }
    MyExcelFile.close();
     MyExcelFile.open("../data/serial_mult.csv", std::ios::app);
     auto start_series = std::chrono::high_resolution_clock::now();
    matmul_serial(A,B,CS,n);
    auto endSeries = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> durationSeries = endSeries - start_series;
     std::cout<<"The time it takes for serial is "<< durationSeries.count()<<std::endl;
     MyExcelFile << n<<", "<< durationSeries.count() << std::endl;
     MyExcelFile.close();
    
    

    printMatrix(A,n);
    std::cout<<std::endl;
    printMatrix(B,n);
    std::cout<<std::endl;
    printMatrix(CP,n);
    std::cout<<std::endl;
    printMatrix(CS,n);
    std::cout<<std::endl;


    delete[] A;
    delete[] B;
    delete[] CP;
    delete[] CS;

    
    
    return 0;
}

void generate_random(double* T, int n, std::mt19937& gen){
        

    // Generate a random integer between a specified range
    int minValue = 1;  // Minimum value (inclusive)
    int maxValue = 100; // Maximum value (inclusive)

    std::uniform_int_distribution<int> dist(minValue, maxValue);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            T[loc(i, j, n)] = dist(gen);
        }
    }
}
