/*
Given an array nums[] of size N having distinct elements, the task is to find the next greater element for each element of the array
Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
If there does not exist a next greater of a element, the next greater element for it is -1

Note: iostream, stack and vector are already included

Constraints:
1 <= nums.length <= 10^5
0 <= nums[i] <= 10^9

Example 1:
Input:
nums = {15, 2, 4, 10}
Output:
{-1, 4, 10, -1}

Example 2:
Input:
nums = {1, 4, 6, 9, 6}
Output:
{4, 6, 9, -1, -1}
*/

#include<bits/stdc++.h>

using namespace std;

// iostream, stack and vector are included

vector<int> nextGreater(vector<int>& arr) {
    vector<int> res(arr.size());
    for (int &x : res) x = -1;
    stack<int> s; 
    for (int i = 0; i < arr.size(); i++){
        while (!s.empty() && arr[i] > arr[s.top()]){
            res[s.top()] = arr[i]; 
            s.pop();
        }
        s.push(i); 
    }

    return res;
}

int main(){
    int N;
    cin >> N;
    vector<int> nums(N);
    for(int i = 0; i < N; i++) cin >> nums[i];
    vector<int> greaterNums = nextGreater(nums);
    for(int i : greaterNums) 
        cout << i << ' ';
    cout << '\n';   
    return 0;
}