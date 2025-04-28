/*
void interleaveQueue(queue<int>& q) {
    int n = q.size();
    int a[n];
    for (int i = 0; i < n; i++){
        a[i] = q.front();
        q.pop();
    }
    a[n] = '\0';
    for (int i = 0; i < n/2; i++){
        q.push(a[i]);
        q.push(a[i+n/2]);
    }
}
*/

#include<bits/stdc++.h>

using namespace std;

void interleaveQueue(queue<int>& q) {
    int n = q.size();
    int a[n];
    for (int i = 0; i < n; i++){
        a[i] = q.front();
        q.pop();
    }
    a[n] = '\0';
    for (int i = 0; i < n/2; i++){
        q.push(a[i]);
        q.push(a[i+n/2]);
    }
}