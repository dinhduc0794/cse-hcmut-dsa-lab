#include<iostream>

using namespace std;

string reverseWord(string s) {
    int sz = s.size();
    if (sz == 1) return s;
    else {
        return s[sz - 1] + reverseWord(s.substr(0, sz - 1));
    }
}

string res = "";
string temp = "";

string reverseSentence(string s) {
    // if (s == "") return "";
    if (s.size() == 0) {
        if (!temp.empty()) {
            res += " ";
            res += reverseWord(temp);
            temp = "";
        }
        if(res != "") res = res.substr(1, res.size()-1);
        string tmp = res;
        res = "";
        return tmp;
    }

    temp += s[s.size() - 1];
    if (s[s.size() - 1] == ' ') {
        res += reverseWord(temp);
        temp = "";
    }
    return reverseSentence(s.substr(0, s.size() - 1));
}
int main(){
    cout << reverseSentence("data structure and algorithm is scary");
    cout << endl;
    cout << reverseSentence("khum biet");
}