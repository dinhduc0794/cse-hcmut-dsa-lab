/*
Given a string S of characters, a duplicate removal consists of choosing two adjacent and equal letters, and removing them.

We repeatedly make duplicate removals on S until we no longer can.

Return the final string after all such duplicate removals have been made.

Included libraries: vector, list, stack
*/

#include<bits/stdc++.h>

using namespace std;

string removeDuplicates(string S){
    /*TODO*/
    stack<char> st;
    for (char c : S){
        if (st.empty() || c != st.top()){
            st.push(c);
        }
        else st.pop();
    }
    string res;
    while(!st.empty()){
        res = st.top() + res;
        st.pop(); 
    }
    return res;
}

int main(){
    cout << removeDuplicates("abbaca");
    return 0;
}