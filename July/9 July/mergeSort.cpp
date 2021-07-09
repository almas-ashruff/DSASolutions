// Sort an array using merge sort algorithm.

// RECURSIVE SOLUTION

vector<int> mergeSortedArrays(vector<int> leftHalf, vector<int> rightHalf);
vector<int> mergeSort(vector<int> array) {
  if(array.size() == 1) {
		return array;
	}
	int middleIndex = array.size() / 2;
	vector<int> leftHalf(array.begin(), array.begin() + middleIndex);
	vector<int> rightHalf(array.begin() + middleIndex, array.end());
	return mergeSortedArrays(mergeSort(leftHalf), mergeSort(rightHalf));
}

vector<int> mergeSortedArrays(vector<int> leftHalf, vector<int> rightHalf) {
	vector<int> sortedArray(leftHalf.size() + rightHalf.size(), 0);
	
	int sortedIdx = 0;
	int leftIdx = 0;
	int rightIdx = 0;
	
	while(leftIdx < leftHalf.size() && rightIdx < rightHalf.size()) {
		if(leftHalf[leftIdx] <= rightHalf[rightIdx]) {
			sortedArray[sortedIdx] = leftHalf[leftIdx];
			leftIdx++;
		} else {
			sortedArray[sortedIdx] = rightHalf[rightIdx];
			rightIdx++;
		}
		sortedIdx++;
	}
	
	while(leftIdx < leftHalf.size()) {
		sortedArray[sortedIdx] = leftHalf[leftIdx];
		leftIdx++;
		sortedIdx++;
	}
	
	while(rightIdx < rightHalf.size()) {
		sortedArray[sortedIdx] = rightHalf[rightIdx];
		rightIdx++;
		sortedIdx++;
	}
	return sortedArray;
}


// ITERATIVE - IN PLACE SOLUTION

#include <vector>
using namespace std;

void mergeSortHelper(vector<int> *minArray, int startIdx, int endIdx, vector<int> *auxiliaryArray);
void doMerge(vector<int> *mainArray, int startIdx, int middleIdx, int endIdx, vector<int> *auxiliaryArray);

vector<int> mergeSort(vector<int> array) {
  if(array.size() <= 1) {
		return array;
	}
	vector<int> auxiliaryArray = array;
	mergeSortHelper(&array, 0, array.size() - 1, &auxiliaryArray);
	return array;
}

void mergeSortHelper(vector<int> *mainArray, int startIdx, int endIdx, vector<int> *auxiliaryArray) {
	if(startIdx == endIdx) {
		return;
	}
	int middleIdx = (startIdx + endIdx) / 2;
	mergeSortHelper(auxiliaryArray, startIdx, middleIdx, mainArray);
	mergeSortHelper(auxiliaryArray, middleIdx + 1, endIdx, mainArray);
	doMerge(mainArray, startIdx, middleIdx, endIdx, auxiliaryArray);
}

void doMerge(vector<int> *mainArray, int startIdx, int middleIdx, int endIdx, vector<int> *auxiliaryArray) {
	int sortIdx = startIdx;
	int leftIdx = startIdx;
	int rightIdx = middleIdx + 1;
	
	while(leftIdx <= middleIdx && rightIdx <= endIdx) {
		if(auxiliaryArray -> at(leftIdx) <= auxiliaryArray->at(rightIdx)) {
			mainArray->at(sortIdx) = auxiliaryArray->at(leftIdx);
			leftIdx++;
			sortIdx++;
		} else {
			mainArray->at(sortIdx) = auxiliaryArray->at(rightIdx);
			rightIdx++;
			sortIdx++;
		}
	}
		
	while(leftIdx <= middleIdx) {
		mainArray->at(sortIdx) = auxiliaryArray->at(leftIdx);
		leftIdx++;
		sortIdx++;
	}
		
	while(rightIdx <= endIdx) {
		mainArray-> at(sortIdx) = auxiliaryArray->at(rightIdx);
		rightIdx++;
		sortIdx++;
	}
}