
#include <vector>
using namespace std;

// find the median till each position in a given array. Return the array of the medians.

// Solved using two heaps of equal sizes.
// One heap is the max heap of all smaller numbers and one heap is the min heap of all greater numbers.

class MinHeap {
public:
  vector<int> heap;

  MinHeap(vector<int> array) { heap = buildHeap(array); }

  vector<int> buildHeap(vector<int> array) {
    int firstParentIdx = (array.size() - 2) / 2;
		for(int currentIdx = firstParentIdx; currentIdx >= 0; currentIdx--){
			siftDown(currentIdx, array.size() - 1, array);
		}
		return array;
  }

  void siftDown(int currentIdx, int endIdx, vector<int> &heap) {
    int childOneIdx = currentIdx * 2 + 1;
		while(childOneIdx <= endIdx){
			int childTwoIdx = currentIdx * 2 + 2 <= endIdx ? currentIdx * 2 + 2 : -1;
			int idxToSwap;
			if(childTwoIdx != -1 && heap[childTwoIdx] < heap[childOneIdx]){
				idxToSwap = childTwoIdx;
			} else {
				idxToSwap = childOneIdx;
			}
			if(heap[idxToSwap] < heap[currentIdx]){
				swap(currentIdx, idxToSwap, heap);
				currentIdx = idxToSwap;
				childOneIdx = currentIdx * 2 + 1;
			} else {
				return;
			}
		}
  }
	
	bool isEmpty() { return heap.size() == 0; }
	
  void siftUp(int currentIdx, vector<int> &heap) {
    int parentIdx = (currentIdx - 1) / 2;
		while(currentIdx > 0 && heap[currentIdx] < heap[parentIdx]){
			swap(currentIdx, parentIdx, heap);
			currentIdx = parentIdx;
			parentIdx = (currentIdx - 1) / 2;
		}
  }

  int peek() {
    return heap[0];
  }

  int remove() {
    swap(0, heap.size() - 1, heap);
		int valueToRemove = heap.back();
		heap.pop_back();
		siftDown(0, heap.size() - 1, heap);
		return valueToRemove;
  }

  void insert(int value) {
    heap.push_back(value);
		siftUp(heap.size() - 1, heap);
  }
	
	void swap(int i, int j, vector<int> &heap) {
		int temp = heap[j];
		heap[j] = heap[i];
		heap[i] = temp;
	}
};

	


vector<int> sortKSortedArray(vector<int> array, int k) {
  vector<int> minHeapInputArray(array.begin(), array.begin() + min(k + 1, (int) array.size()));
	auto minHeapWithKElements = new MinHeap(minHeapInputArray);
	
	int nextIndexToInsertElement = 0;
	
	for(int idx = k + 1; idx < array.size(); idx++) {
		auto minElement = minHeapWithKElements -> remove();
		array[nextIndexToInsertElement] = minElement;
		nextIndexToInsertElement++;
		
		auto currentElement = array[idx];
		minHeapWithKElements -> insert(currentElement);
	}
	
	while(!minHeapWithKElements -> isEmpty()) {
		auto minElement = minHeapWithKElements -> remove();
		array[nextIndexToInsertElement] = minElement;
		nextIndexToInsertElement++;
	}
	
	return array;

}
