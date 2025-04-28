static void merge(T* left, T* middle, T* right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    T* L = new T[n1];
    T* R = new T[n2];

    for (int i = 0; i < n1; i++)
        L[i] = left[i];
    for (int j = 0; j < n2; j++)
        R[j] = middle[j + 1];

    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            left[k] = L[i];
            i++;
        } else {
            left[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        left[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        left[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;

    Sorting::printArray(left, right);
}

static void mergeSort(T* start, T* end) {
    if (start < end) {
        T* middle = start + (end - start) / 2;

        mergeSort(start, middle);
        mergeSort(middle + 1, end);

        merge(start, middle, end);
    }
}