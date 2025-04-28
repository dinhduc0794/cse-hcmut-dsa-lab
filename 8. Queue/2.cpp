/*
Given an array of integers.
Your task is to implement a function with following prototype:
int sumOfMaxSubarray(vector<int>& nums, int k);
The function returns the sum of the maximum value of every consecutive subarray of nums with fixed length k.

Note:
- The iostream, vector, queue and deque libraries have been included and namespace std is being used. No other libraries are allowed.
- You can write helper functions and classes.
*/

#include<bits/stdc++.h>

using namespace std;

int sumOfMaxSubarray(std::vector<int>& nums, int k) {
    int n = nums.size();
    
    if (n == 0 || k > n || k<0) {
        return 0;
    }
    
    int result = 0;
    int maxInWindow = nums[0];
    int check=0;
    // Calculate the maximum value in the first subarray of size k
    for (int i = 1; i < k; i++) {
        if (nums[i] > maxInWindow) {
            maxInWindow = nums[i];
            check=i;
        }
    }
    
    result += maxInWindow;
    
    // Iterate through the rest of the array and maintain the maximum value in the sliding window
    for (int i = k; i < n; i++) {
        if (nums[i] > maxInWindow) {
            maxInWindow = nums[i];
            check=i;
        }else{
            if(i-check>=k){
                maxInWindow=nums.at(i-k+1);
                check=i-k+1;
                for(int j=i-k+1;j<=i;j++){
                    if (nums[j] > maxInWindow) {
                        maxInWindow = nums[j];
                        check=j;
                    }
                }
            } 
        }
        result += maxInWindow;
    }
    
    return result;
}

int main(){
    vector<int> nums {1, 2, 4, 3, 6};
    int k = 3;
    cout << sumOfMaxSubarray(nums, k);
    return 0;
}