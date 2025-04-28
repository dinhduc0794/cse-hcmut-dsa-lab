#include<bits/stdc++.h>

using namespace std;

vector<int> updateArrayPerRange(vector<int>& nums, vector<vector<int>>& operations) {
    // STUDENT ANSWER
    for (auto &vect : operations){
        int l = vect[0];
        int r = vect[1];
        int val = vect[2];
        for (int i = l; i <= r; i++){
            nums[i] += val;
        }
    }
    return nums;
}

int main(){
    vector<int> nums {13, 0, 6, 9, 14, 16};
    vector<vector<int>> operations {{5, 5, 16}, {3, 4, 0}, {0, 2, 8}};
    // printVector(updateArrayPerRange(nums, operations));
    return 0;
}