#include<iostream>
#include<string.h>

using namespace std;

bool isPalindrome(string str) 
{   
    int sz = str.size();
    if (sz == 1 || sz == 0) {
        return 1;
    }
    if (str[0] == ' '){
        return isPalindrome(str.substr(1));
    }
    if (str[sz - 1] == ' '){
        return isPalindrome(str.substr(0, sz-1));
    }
    if (str[0] != str[sz - 1]) {
        return 0;
    }
    return isPalindrome(str.substr(1, sz - 2));
}

int main(){
    cout << isPalindrome("do geese see god");   
    return 0;
}