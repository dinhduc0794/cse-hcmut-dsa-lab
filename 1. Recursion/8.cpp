#include<iostream>
#include<string.h>

using namespace std;

int myArrayToInt(char *str, int n) 
{ 
    /*  
     * STUDENT ANSWER
     */ 
    if (n == 0) return 0;
    else{
        int last = str[n-1] - '0';
        int tmp = myArrayToInt(str, n-1);
        return 10*tmp + last;
    }
}

int main(){
    char str[] = "2020";
    printf("%d", myArrayToInt(str, 4)); 
    return 0;
}