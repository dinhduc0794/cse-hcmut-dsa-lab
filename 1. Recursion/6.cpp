/*
String s contains lowercase letters, digits, "(" and ")", satisfying the following rules:

- Two digits cannot be adjacent.

- Two "(" cannot be adjacent.

- One "(" and one ")" cannot be adjacent.

- After any digit, there must be "(".

- The quantities of "(" and ")" are equal.

Change string s until new string t created, t contains only lowercase letters. These are changing rules:

- Sub-strings with form "n(p)", can change to "pp...p" (n times p), where n is a digit and p is a string.

- If p still contains "(", ")" or digits, continue to implement the above changing method.  

Request: Implement function 

expand(string s);
Where s is a string with the above form; return the result is a string containing only lowercase letters.

Example:

- String "2(ab3(cde)x)" changes into "abcdecdecdexabcdecdecdex".

- String "2(x0Có)3(z)" changes into "xxzzz".

Note: In this exercise, libraries iostream, string and using namespace std; have been used. You can add other functions for your answer, but you are not allowed to add other libraries.
*/

#include<bits/stdc++.h>

using namespace std;

int findEnd(string s, int start, int count) {
    int end = start;
    if (count == 0) return end;
    end++;
    if (s[end] == '(') count++;
    if (s[end] == ')') count--;
    return findEnd(s, end, count);
}

string repeat(string s, int n){    
    if (n == 0) {
        return "";
    }
    else {
        return s + repeat(s, n - 1);
    }
}

string expand(string s, int i = 0){
    if (i == (int)s.length()){
        return "";
    }
    else{
        if (isalpha(s[i])) {
            return s[i] + expand(s, i + 1);
        }
        else if (isdigit(s[i])){
            int n = s[i] - '0';     //chuyen tu char thanh int 
            i++; 
            int start = i + 1;
            int count = 1;      
            int end = findEnd(s, start, count);
            string sub = s.substr(start, end - start);
            string expanded = expand(sub);
            return repeat(expanded, n) + expand(s, end + 1);
        }
    }
    return "";
}

int main(){
    cout << expand("2(ab3(cde)x)") << "\n";
    return 0;
}