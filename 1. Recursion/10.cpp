#include<iostream>

using namespace std;

/*
int cntOpen = 0;
int cntClose = 0;

int mininumBracketAdd(string s){
    int size = s.size();
    if (size == 0) return cntOpen + cntClose;
    if (s[size-1] == '('){
        cntOpen++;
        if (cntClose > 0){
            cntOpen--;
            cntClose--;
        }
    }
    if (s[size-1] == ')'){
        cntClose++;
        
    }
    return mininumBracketAdd(s.substr(0, s.size()-1));
}

bai nay dc 0.9 diem, can toi uu bang phep truyen tham chieu vi gọi string 1 lần là hàm đệ quy phải tạo 1 dữ liệu string mới Rồi copy cái string truyền vào gây tốn bộ nhớ   
*/

int tempFunc(const char* &c, int cntOpen = 0, int cntClose = 0){
    if (*c == '\0') 
        return cntOpen + cntClose;
    if (*c == '('){
        cntOpen++;
    } 
    else if (*c == ')'){
        if (cntOpen > 0){
            cntOpen--;
        } 
        else{
            cntClose++;
        }
    }
    c++; 
    return tempFunc(c, cntOpen, cntClose);
}

int mininumBracketAdd(string s) {
    const char *c = &s[0]; 
    return tempFunc(c);
}

int main(){
    cout << mininumBracketAdd(")))((");
    return 0;
}