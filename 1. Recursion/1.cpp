#include<bits/stdc++.h>

using namespace std;

int i = 0;

void printArray(int n)
{
    /*  
     * STUDENT ANSWER
     */
    if (i == n) cout << i;
    else{
        cout << i << ", ";
        i++;
        printArray(n);
    } 
}

int main(){
    int n = 5;
    printArray(n);
}


/*
Solution:
if (n==0) cout << n;
else{
    printArray(n-1);
    cout << ", " << n; 
}
*/