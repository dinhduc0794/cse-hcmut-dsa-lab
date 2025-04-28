#include <vector>
struct ElementFrequency {
    int element;
    int frequency;
    int originalIndex;
};

bool compareFrequency(const ElementFrequency &a, const ElementFrequency &b) {
    if (a.frequency == b.frequency) {
        return a.originalIndex < b.originalIndex;
    }
    return a.frequency > b.frequency;
}

void sortByFrequency(int arr[], int n) {
    vector<ElementFrequency> freqArr;

    for (int i = 0; i < n; i++) {
        bool found = false;
        for (auto &element : freqArr) {
            if (element.element == arr[i]) {
                element.frequency++;
                found = true;
                break;
            }
        }
        if (!found) {
            freqArr.push_back({arr[i], 1, i});
        }
    }

    sort(freqArr.begin(), freqArr.end(), compareFrequency);

    int index = 0;
    for (auto &element : freqArr) {
        for (int i = 0; i < element.frequency; i++) {
            arr[index++] = element.element;
        }
    }
}