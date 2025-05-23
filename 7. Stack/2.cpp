/*
You are keeping score for a basketball game with some new rules. The game consists of several rounds, where the scores of past rounds may affect future rounds' scores.

At the beginning of the game, you start with an empty record. You are given a list of strings ops, where ops[i] is the operation you must apply to the record, with the following rules:

A non-negative integer x (from 0 to 9) - record a new score of x
'+' - Record a new score that is the sum of the previous two scores. It is guaranteed there will always be two previous scores.
'D' - Record a new score that is double the previous score. It is guaranteed there will always be a previous score.
'C' - Invalidate the previous score, removing it from the record. It is guaranteed there will always be a previous score.
Finally, return the sum of all scores in the record.

For example:

ops = "52CD+"

'5' - add to the record. Record now is [5]
'2' - add to the record. Record now is [5,2]
'C' - invalid the previous score (2). Record now is [5]
'D' - Record new score that is double of previous score (5*2). Record now is [5,10]
'+' - Record a new score that is the sum of the previous two scores. Record now is [5,10,15]
Return the sum: 5+10+15 = 30
*/

#include<bits/stdc++.h>

using namespace std;

int baseballScore(string ops){
/*TODO*/
    stack<int> st;
    for (char &x : ops){
        if (x == 'C'){
            if (!st.empty()){
                st.pop();
            }
        }
        else if (x == 'D'){
            if (!st.empty()){
                st.push(st.top()*2);
            }
        }
        else if (x == '+'){
            int fi = st.top();
            st.pop();
            int sc = st.top();
            st.push(fi);
            st.push(fi + sc);
        }
        else{
            st.push(x - '0');
        }
    }
    int sum = 0;
    while (!st.empty()){
        sum += st.top();
        st.pop();
    }
    return sum;
}

int main(){
    cout << baseballScore("52CD+");
    return 0;
}