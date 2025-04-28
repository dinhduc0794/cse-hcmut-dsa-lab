#include<bits/stdc++.h>

using namespace std;

static void sortSegment(T* start, T* end, int segment_idx, int cur_segment_total) {
    for (int i = segment_idx + cur_segment_total; i < end - start; i += cur_segment_total) {
        T key = start[i];
        int j = i - cur_segment_total;
        while (j >= 0 && start[j] > key) {
            start[j + cur_segment_total] = start[j];
            j -= cur_segment_total;
        }
        start[j + cur_segment_total] = key;
    }
}


static void ShellSort(T* start, T* end, int* num_segment_list, int num_phases) {
    for (int phase = num_phases - 1; phase >= 0; phase--) {
        int cur_segment_total = num_segment_list[phase];
        for (int segment_idx = 0; segment_idx < cur_segment_total; segment_idx++)
        {
            sortSegment(start, end, segment_idx, cur_segment_total);
        }
        cout << cur_segment_total << " segments: ";
        printArray(start, end);
    }
}