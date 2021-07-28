// Given two binary max heaps as arrays, merge the given heaps to form a new max heap.

// https://practice.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1


void heapify(vector<int> &arr, int i){
    int n = arr.size();
    
    int largestIdx = i;
    int leftChildIdx = (i * 2) + 1;
    int rightChildIdx = (i * 2) + 2;

    if(leftChildIdx < n && arr[largestIdx] < arr[leftChildIdx]) {
        largestIdx = leftChildIdx;
    }
    
    if(rightChildIdx < n && arr[largestIdx] < arr[rightChildIdx]) {
        largestIdx = rightChildIdx;
    }
    
    if(largestIdx != i) {
        swap(arr[i], arr[largestIdx]);
        
        // heapify the affected subtree
        heapify(arr, largestIdx);
    }
}


vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
    for(int i = 0; i < m; i++) {
        a.push_back(b[i]);
    }
    
    int size = a.size();
    
    // merge the two arrays and heapify all the parent nodes
    for(int i = (size - 1) / 2; i >= 0; i--) {
        heapify(a, i);
    }
    
    return a;
}