#include<bits/stdc++.h>

using namespace std;

// bool consecutiveOnes(vector<int>& nums) {
//     // STUDENT ANSWER
//     if (nums.size() == 0) return 1;
//     int check = 0;
//     int start = -100, end;
//     for (int i = 0; i < nums.size()-1; i++){
//         if (nums[i] == 1){
//             start = i;
//             break;
//         }
//     }
//     if (start == -100) return 1;
//     for (int i = nums.size()-1; i >= 0; i--){
//         if (nums[i] == 1){
//             end = i;
//             break;
//         }
//     }
//     for (int i = start; i <= end; i++){
//         if (nums[i] != 1) return 0;
//     }
//     return 1;
// }



bool consecutiveOnes(vector<int>&  nums){
    int start = -100, end;
    if (nums.size() == 0) return 1;
    for (int i = 0; i < nums.size()-1; i++){
        if (nums[i] == 1){
            start = i;
            break;
        }
    }
    if (start == -100) return 1;
    for (int i = nums.size()-1; i >= 0; i--){
        if (nums[i] == 1){
            end = i;
            break;
        }
    }
    for (int i = start; i <= end; i++){
        if (nums[i] != 1) return 0;
    }
    return 1;
}


int main(){
    vector<int> nums {0, 1, 1, 1, 9, 8};
    cout << consecutiveOnes(nums);
    return 0;
}