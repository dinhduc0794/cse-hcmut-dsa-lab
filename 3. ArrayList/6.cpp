#include<iostream>
#include<vector>

using namespace std;

// int longestSublist(vector<string>& words) {
//     // STUDENT ANSWER
//     int cnt[256] = {0};  
//     int maxCnt = 0; 
//     if (words.size() == 0) return 0;
//     for (int i = 1; i < words.size(); i++){
//         if (words[i][0] == words[i-1][0]){
//             cnt[words[i-1][0]] = 1;
//             cnt[words[i][0]]++;
//         }
//         else{
//             cnt[words[i-1][0]] = 0;
//         }
//         if (maxCnt < cnt[words[i][0]]) maxCnt = cnt[words[i][0]];
//     }
//     return maxCnt;
// }

int longestSublist(vector<string>& words){
    if (words.size() == 0) return 0;
    int cnt[256] = {0};
    int maxCnt = 0;
    int i = 0;
    while (i < words.size()){
        cnt[words[i][0]] = 1;
        int j = i + 1;
        while (j < words.size() && words[j][0] == words[i][0]){
            cnt[words[j][0]]++;
            j++;
        }
        if (maxCnt < cnt[words[i][0]]) maxCnt = cnt[words[i][0]];
        i = j;
    }
    return maxCnt;
}

int main(){
    vector<string> words {"faction", "fight", "and", "are", "attitude"};
    cout << longestSublist(words);
}

