// Building Heap from Array


// https://www.geeksforgeeks.org/building-heap-from-array/
// https://www.algoexpert.io/questions/Min%20Heap%20Construction


// MAX HEAP

void heapify(vector<int> &arr, int size, int rootIdx) {
    int largestIdx = rootIdx;
    int leftChildIdx = (2 * rootIdx) + 1;
    int rightChildIdx = (2 * rootIdx) + 2;

    if(leftChildIdx < size && arr[leftChildIdx] > arr[largestIdx]) {
        largestIdx = leftChildIdx;
    }

    if(rightChildIdx < size && arr[rightChildIdx] > arr[largestIdx]) {
        largestIdx = rightChildIdx;
    }

    if(largestIdx != rootIdx) {
        swap(arr[largestIdx], arr[rootIdx]);

        // Recursively heapify the affected sub-tree
        heapify(arr, size, largestIdx);
    }
}

void buildHeap(vector<int> &arr, int size) {
    int startIdx = (size / 2) - 1;

    // Perform reverse level order traversal from last non-leaf node and heapify each node
    for(int i = startIdx; i >= 0; i--) {
        heapify(arr, size, i);
    }
}