#include<vector>
string minDiffPairs(int* arr, int n) {
    if (n < 2) {
        return "";
    }

    sort(arr, arr + n);

    int minDiff = 9999999;
    for (int i = 1; i < n; ++i) {
        minDiff = min(minDiff, arr[i] - arr[i - 1]);
    }

    vector<pair<int, int>> result;
    for (int i = 1; i < n; ++i) {
        if (arr[i] - arr[i - 1] == minDiff) {
            result.push_back({arr[i - 1], arr[i]});
        }
    }

    string res;
    for (auto pair : result) {
        res += "(" + to_string(pair.first) + ", " + to_string(pair.second) + "), ";
    }
    
    int hac = res.size();
    return res.substr(0, hac - 2);
}