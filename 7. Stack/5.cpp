/*
Given a string s containing just the characters '(', ')', '[', ']', '{', and '}'. Check if the input string is valid based on following rules:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
For example:

String "[]()" is a valid string, also "[()]".
String "[])" is not a valid string.
Your task is to implement the function
bool isValidParentheses (string s){
    
}
Note: The library stack of C++ is included.
*/

#include<bits/stdc++.h>

using namespace std;

bool isValidParentheses (string s){
    /*TODO*/
    stack<int> st;
    if (s[0] == ')' || s[0] == ']' || s[0] == '}') return 0;
    for (unsigned int i = 0; i < s.size(); i++){
        if (s[i] =='(' || s[i] == '[' || s[i] == '{'){
            st.push(s[i]);
        }
        else if (s[i] == ')'){
            if (st.top() == '('){
                st.pop();
            }
            else return 0;
        }
        else if (s[i] == ']'){
            if (st.top() == '['){
                st.pop();
            }
            else return 0;
        }
        else{
            if (st.top() == '{') st.pop();
            else return 0;
        }
    }
    return st.empty();
}

int main(){
    cout << isValidParentheses("[]()");
    cout << isValidParentheses("[]()");
    return 0;
}