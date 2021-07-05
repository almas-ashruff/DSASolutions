#include <vector>
using namespace std;

// https://www.algoexpert.io/questions/Disk%20Stacking
// Given an array containing arrays of size 3, that represent the dimensions of disks, 
// stack disks in an order such that any of the dimensions of the top disk is always smaller than the bottom disk with the goal of maximizing height.

// Solution -

// Sort the disks in order of their heights.
// Solve using dynamic programming - 
// Iterate through the heightwise sorted arrays
// Make an array of maximum possible height using the current disk as the base disk.
// At every step, compare the other two dimensions of the previous all disks with current disk. Also check if the height is strictly less, and not equal.
// Then, if the conditions are satisfied, get the maximum height possible for that other disk and add it to the current disk's height and store it in the DP.
// Check for next position. Also, keep track of the last disk whose height was added.

bool areValidDimensions(vector<int> o, vector<int> c);
vector<vector<int>> buildSequence(vector<vector<int>> array, vector<int> sequences, int currentIdx);


vector<vector<int>> diskStacking(vector<vector<int>> disks) {
  sort(disks.begin(), disks.end(), [](vector<int> &a, vector<int> &b) {
		return a[2] < b[2];
	});
	
	vector<int> heights;
	for(int i = 0; i < disks.size(); i++) {
		heights.push_back(disks[i][2]);
	}
	vector<int> sequences;
	
	for(int i = 0; i < disks.size(); i++) {
		sequences.push_back(-1);
	}
	
	int maxHeightIdx = 0;
	for(int i = 1; i < disks.size(); i++) {
		vector<int> currentDisk = disks[i];
		for(int j = 0; j < i; j++) {
			vector<int> otherDisk = disks[j];
			if(areValidDimensions(otherDisk, currentDisk)) {
				if(heights[i] <= currentDisk[2] + heights[j]) {
					heights[i] = currentDisk[2] + heights[j];
					sequences[i] = j;
				}
			}
		}
		if (heights[i] >= heights[maxHeightIdx]) {
			maxHeightIdx = i;
		}
	}
	return buildSequence(disks, sequences, maxHeightIdx);
}

bool areValidDimensions(vector<int> o, vector<int> c) {
	return o[0] < c[0] && o[1] < c[1] && o[2] < c[2];
}

vector<vector<int>> buildSequence(vector<vector<int>> array, vector<int> sequences, int currentIdx) {
	vector<vector<int>> sequence;
	
	while(currentIdx != -1) {
		sequence.insert(sequence.begin(), array[currentIdx]);
		currentIdx = sequences[currentIdx];
	}
	return sequence;
}