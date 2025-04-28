#include<bits/stdc++.h>

using namespace std;

// iostream, vector and queue are included
// You can write helper methods

long long nthNiceNumber(int n) {
    if (n == 1) 
        return 2;

    queue<long long> q;
    q.push(2);
    long long niceNum;
    n--; // Số đẹp đầu tiên đã bao gồm số 2

    while (n > 0) {
        niceNum = q.front();
        q.pop();

        // Thêm các số đẹp bằng cách thêm 2 và 5 vào cuối số đẹp hiện tại
        q.push(niceNum * 10 + 2);
        q.push(niceNum * 10 + 5);

        n--;
    }

    return niceNum;
}


