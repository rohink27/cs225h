#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include <random>
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <vector>

void prefix_sum_serial(std::vector<int>& a){

    for(int i = 1; i< a.size(); i++){
        a[i]+=a[i-1];
    }
}

void prefix_sum_parallel_2threads(std::vector<int>& a){
    #pragma omp parallel for
    for(int i = 0; i< a.size()-1; i++)
        a[i+1]+=a[i];
}
    
    

    
    
 void prefix_sum_parallel_4threads(std::vector<int>& a){  
    #pragma omp parallel
    for(int i =(omp_get_thread_num()==0)?0:((omp_get_thread_num())*(a.size()-1)/omp_get_max_threads()) + 1; i< (omp_get_thread_num()+1)*(a.size()-1)/omp_get_max_threads(); i++)
    a[i+1]+=a[i];
    


    std::vector<int> linear(omp_get_max_threads());
  
    linear[0]=0;
    for(int i = 1; i< linear.size(); i++){
        linear[i]= a[i*(a.size()-1)/omp_get_max_threads()];
        linear[i]+=linear[i-1];

    }

    #pragma omp parallel
    for(int i =(omp_get_thread_num()==0)?0:((omp_get_thread_num())*(a.size()-1)/omp_get_max_threads()) + 1; i<= (omp_get_thread_num()+1)*(a.size()-1)/omp_get_max_threads(); i++)
    a[i]+=linear[omp_get_thread_num()];
    
    
    


}

void print_vector(std::vector<int>& a){
    for(int i = 0; i< a.size(); i++){
        std::cout<<a[i]<<" ";
    }
    std::cout<<std::endl;
}

void generate_random(std::vector<int>& a, std::mt19937& gen){
        

    // Generate a random integer between a specified range
    int minValue = 1;  // Minimum value (inclusive)
    int maxValue = 100; // Maximum value (inclusive)

    std::uniform_int_distribution<int> dist(minValue, maxValue);

    for (int i = 0; i < a.size(); i++) {
         a[i]= dist(gen);
        
    }
}




/*void matmul(double *A, double *B, double *C, int n)
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
				
}*/

int main(){
    omp_set_num_threads(2);
    int n = 100000000;
  
    std::cout<<n<<std::endl;
    
    std::vector<int> a(n);
    

    std::mt19937 gen(std::time(0));
    generate_random(a, gen);
    std::vector<int> b = a;
     std::vector<int> c = a;
    //print_vector(a);
    std::ofstream MyExcelFile;
    MyExcelFile.open("../data/prefix_2thread.csv", std::ios::app);

    auto startParallel = std::chrono::high_resolution_clock::now();
    prefix_sum_parallel_2threads(a);
    auto endParallel = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> durationParallel = endParallel - startParallel;
    MyExcelFile<<n<<","<<durationParallel.count()<<std::endl;
    MyExcelFile.close();
    std::cout<<"The time it takes for parallel is "<< durationParallel.count()<<" with "<< omp_get_max_threads()<<" threads"<<std::endl;

     omp_set_num_threads(4);
MyExcelFile.open("../data/prefix_4thread.csv", std::ios::app);
     startParallel = std::chrono::high_resolution_clock::now();
    prefix_sum_parallel_4threads(c);
     endParallel = std::chrono::high_resolution_clock::now();
    durationParallel = endParallel - startParallel;
    MyExcelFile<<n<<","<<durationParallel.count()<<std::endl;
    MyExcelFile.close();
    std::cout<<"The time it takes for parallel is "<< durationParallel.count()<<" with "<< omp_get_max_threads()<<" threads"<<std::endl;

    
    
MyExcelFile.open("../data/prefix_serial.csv", std::ios::app);
    startParallel = std::chrono::high_resolution_clock::now();
    prefix_sum_serial(b);
   endParallel = std::chrono::high_resolution_clock::now();
    durationParallel = endParallel - startParallel;
    MyExcelFile<<n<<","<<durationParallel.count()<<std::endl;
    MyExcelFile.close();
    std::cout<<"The time it takes for serial is "<< durationParallel.count()<<std::endl;
    
   /*/ print_vector(a);
    print_vector(c);
   print_vector(b);*/



    
    
    return 0;
}



