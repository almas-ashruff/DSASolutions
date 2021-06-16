#include <bits/stdc++.h>
using namespace std;

// Given an array of size n and a range [a, b]. 
// The task is to partition the array around the range such that array is divided into three parts.
// 1) All elements smaller than a come first.
// 2) All elements in range a to b come next.
// 3) All elements greater than b appear in the end.
// The individual elements of three sets can appear in any order. 
// You are required to return the modified array.

// https://practice.geeksforgeeks.org/problems/three-way-partitioning/1#

// Same as three number sort.
// https://www.algoexpert.io/questions/Three%20Number%20Sort

void threeWayPartition(vector<int>& array,int a, int b)
{
    int firstIdx = 0, secondIdx = 0, thirdIdx = array.size() - 1;
    while(secondIdx <= thirdIdx) {
        int value = array[secondIdx];
        
        if(value < a) {
            swap(array[firstIdx], array[secondIdx]);
            firstIdx++;
            secondIdx++;
        } else if(value > b) {
            swap(array[secondIdx], array[thirdIdx]);
            thirdIdx--;
        } else {
            secondIdx++;
        }
    }
}