#include<iostream>
#include<vector>

using namespace std;

// int equalSumIndex(vector<int>& nums) {
//     // STUDENT ANSWER
//     for (int i = 0; i < nums.size(); i++){
//         int leftsum = 0, rightsum = 0;
//         for (int j = 0; j < i; j++){
//             leftsum += nums[j];
//         }
//         for (int k = i+1; k < nums.size(); k++){
//             rightsum += nums[k];
//         }
//         if (leftsum == rightsum){
//             return i;
//         }
//     }
//     return -1;
// }

// toi uu o(n)
int equalSumIndex(vector<int>& nums){
    int sum = 0;
    int leftsum = 0;
    for (int x : nums){
        sum += x;
    }
    for (int i = 0; i < nums.size(); i++){
        sum -= nums[i];
        if (leftsum == sum){
            return i;
        }
        leftsum += nums[i];
    }
    return -1;
}

int main(){
    vector<int> nums {3, 5, 2, 7, 6, 4};
    cout << equalSumIndex(nums);    
}