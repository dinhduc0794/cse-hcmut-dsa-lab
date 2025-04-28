#include<iostream>

using namespace std;

void printPattern(int n) 
{
    /*  
     * STUDENT ANSWER
     */
    if(n > 0){
        cout << n << " ";
        printPattern(n - 5);
        cout << " " << n;
    }
    if(n <= 0) cout << n;
}

int main(){
    printPattern(14);
}