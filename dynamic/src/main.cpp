    // Recursion
#include <iostream>
#include <vector>
#include<ctime>
#include <cmath>
#include <fstream>
#include <string>
#include <chrono>

int helper(std::vector<int>& nums, int start, int highest_so_far);

int lengthOfLIS_recursive(std::vector<int>& nums);

int lengthOfLIS_dp(std::vector<int>& nums);


int helper(std::vector<int>& nums, int start, int highest_so_far){

        if(start == nums.size() - 1){
            if(highest_so_far == -1)
            return 1;
            return nums[nums.size() - 1]> nums[highest_so_far];
        }
        
        if(highest_so_far == -1 || nums[start]> nums[highest_so_far]){
            return std::max(1 + helper(nums, start+1, start), helper(nums, start+1, highest_so_far));
        }
        return helper(nums, start+1, highest_so_far);
    }


    int lengthOfLIS_recursive(std::vector<int>& nums) {
        int n = nums.size();
        if(nums.size()== 0)
        return 0;
        if(nums.size() == 1)
        return 1;
        return helper(nums, 0, -1);
    }
    
    



       int lengthOfLIS_dp(std::vector<int>& nums) {
        std::vector<std::vector<int>> longest(nums.size(), std::vector<int>(nums.size(), 0));// columns = j + 1
       if(nums.size() == 0 || nums.size() == 1)
       return nums.size();
        int n = nums.size();
        for(int i = 0 ; i < n ; i ++){
            if(i == 0)
            longest[n-1][i]=1;
            else
            longest[n-1][i]= nums[n-1]> nums[i-1];
        }
        for(int j = n - 2; j >=0 ; j--){
            for(int i = 0; i<=j; i ++){
                if( i == 0 || nums[j]> nums[i-1])
                longest[j][i] = std::max(longest[j + 1][i],1 + longest[j+1][j+1]);
                else
                longest[j][i]= longest[j+1][i];
            }
        }
        int m = 0;
        for(int i = 0; i < n; i++){
            if(longest[i][0]>m){
                m = longest[i][0];
            }
        }

        return m;
    }
    

int main(int argc, char **argv){
    int sample_size=10; // default values
    if(argc ==2){
        sample_size=atoi(argv[1]);
    }
    std::vector<int> nums;
    srand(time(0));
    for(int i = 0 ; i < sample_size; i ++){
         nums.push_back(rand()%(int)((sample_size%10 == 0)? sample_size: 1000));
    }
   /* for(int i = 0 ; i < sample_size; i ++){
        std::cout<<nums[i] << " ";
    }*/
    auto start = std::chrono::high_resolution_clock::now();
    int max = lengthOfLIS_recursive(nums);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
     start = std::chrono::high_resolution_clock::now();
    int max2 = lengthOfLIS_dp(nums);
     end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration2 = end - start;
    std::ofstream MyExcelFile;
    MyExcelFile.open("../data/data.csv", std::ios::app);

    //MyExcelFile << "Size, Recursion Time, DP time, matches" << std::endl;
    MyExcelFile << sample_size<<", "<< duration.count() <<", "<< duration2.count()<<", " << ((max==max2)?1:0 )<< std::endl;
    MyExcelFile.close();



}