static void swap(T* a, T* b){
    T tmp = *a;
    *a = *b;
    *b = tmp;
}

static T* Partition(T* start, T* end) {
    T pivot = *start;
    T i = 0;
    T j = end - start;

    do {
        do {
            i++;
        } while (start[i] < pivot);
        
        do {
            j--;
        } while (start[j] > pivot);
        
        swap(&start[i] , &start[j]);
        
    } while (i < j);
    
    swap(&start[i], &start[j]);
    swap(start, &start[j]);
    return &start[j];
}

static void QuickSort(T* start, T* end) {
    // TODO
     if (start < end) {
        T* k = Partition(start, end);

        cout << (k - start) << " ";

        QuickSort(start, k);
        QuickSort(k + 1, end);
    }
    
}