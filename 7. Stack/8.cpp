/*
Given string S representing a postfix expression, the task is to evaluate the expression and find the final value. Operators will only include the basic arithmetic operators like *, /, + and -.

Postfix expression: The expression of the form “a b operator” (ab+) i.e., when a pair of operands is followed by an operator.

For example: Given string S is  "2 3 1 * + 9 -". If the expression is converted into an infix expression, it will be 2 + (3 * 1) – 9 = 5 – 9 = -4.

Requirement: Write the function to evaluate the value of postfix expression.
*/
#include<bits/stdc++.h>

using namespace std;


int evaluatePostfix(string expr) {
    stack<int> st;
    int n = expr.size();
    for (int i = 0; i < n; i++){
        if (expr[i] == ' ') 
            continue;
        if (isdigit(expr[i])){
            if (expr[i+1] == ' ') 
            st.push(expr[i] - '0');
            else{
                int sum = 0;
                while(expr[i] != ' ' && i < n){
                    sum = sum * 10 + (expr[i] - '0');
                    i++;
                    if (expr[i] == ' ' || expr[i] == '\0') 
                        break; 
                }
                st.push(sum);
                i--;
            }
        }
        else{
            if (expr[i] == '+'){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(a+b);
            }
            else if (expr[i] == '-'){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b-a);
            }
            else if (expr[i] == '*'){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b*a);
            }
            else if (expr[i] == '/'){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b/a);
            }
        }
    }
    return st.top();
}