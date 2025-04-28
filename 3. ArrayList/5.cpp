#include<iostream>
#include<algorithm>

using namespace std;

int buyCar(int* nums, int length, int k) {
    sort(nums, nums + length);
    int cnt = 0;
    for (int i = 0; i < length; i++){
        k -= nums[i];
        if (k < 0) break;
        cnt++;
    }
    return cnt;
}



int main(){
    int nums[] = {90,30,40,90,20};
    int length = sizeof(nums)/sizeof(nums[0]);
    cout << buyCar(nums, length, 90) << "\n";
    return 0;
}
