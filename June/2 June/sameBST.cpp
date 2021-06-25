#include <bits/stdc++.h>
using namespace std;

// ALGOEXPERT HARD QUESTION

// https://www.algoexpert.io/questions/Same%20BSTs

// Check if the size of the two arrays is the same, and if the root node is matching.
// For both arrays, for every node, find out the nodes coming after it in the array with a smaller value, 
// and the nodes coming after it with a larger or equal value. Store them in two arrays.
// For every root value in those smaller and the largerOrEqual arrays, check if the above checks are true. Recursively.

vector<int> getSmaller(vector<int> array);
vector<int> getBiggerOrEqual(vector<int> array);

bool sameBsts(vector<int> arrayOne, vector<int> arrayTwo){
    if(arrayOne.size() != arrayTwo.size()){
        // check if the size of the two arrays is the same
        return false;
    }
    if(!arrayOne.size() && !arrayTwo.size()){
        // check if both arrays are empty
        return true;
    }
    if(arrayOne[0] != arrayTwo[0]){
        // check if the root node is same or not
        return false;
    }

    // the below arrays store the elements - smaller than the current root element, 
    // and larger or equal than the current root node for the array elements after the array.

    vector<int> leftOne = getSmaller(arrayOne);
    vector<int> leftTwo = getSmaller(arrayTwo);
    vector<int> rightOne = getBiggerOrEqual(arrayOne);
    vector<int> rightTwo = getBiggerOrEqual(arrayTwo);

    // check if the two small arrays and two large arrays have the same elements
    return sameBsts(leftOne, leftTwo) && sameBsts(rightOne, rightTwo);
}

vector<int> getSmaller(vector<int> array) {
    
    // returns the array elements after the current root node that are smaller than the current element
    vector<int> smaller = {};
    for(int i = 1; i < array.size(); i++){
        if(array[i] < array[0]){
            smaller.push_back(array[i]);
        }
    }
    return smaller;

}

vector<int> getBiggerOrEqual(vector<int> array){
    // returns the array elements after the current root node that are greater or equal than the current element
    vector<int> biggerOrEqual =  {};
    for(int i = 1; i < array.size(); i++){
        if(array[i] >= array[0]){
            biggerOrEqual.push_back(array[i]);
        }
    }
    return biggerOrEqual;
}