

template <class T>
void Sorting<T>::selectionSort(T *start, T *end) {
     if (start == end || start == nullptr || end == nullptr) {
        // Nothing to sort or invalid range
        return;
    }

    int size = end - start;

    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < size; j++) {
            if (start[j] < start[minIndex]) {
                minIndex = j;
            }
        }

        T temp = start[i];
        start[i] = start[minIndex];
        start[minIndex] = temp;

        printArray(start, end);
    }
}