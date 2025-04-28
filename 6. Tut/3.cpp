#include<bits/stdc++.h>
using namespace std;

void reverseQueue(queue<int> & q) {
     stack<int> st;
    while (!q.empty()) {
        st.push(q.front());
        q.pop();
    }
    while (!st.empty()) {
        q.push(nganXep.top());
        st.pop();
    }
}