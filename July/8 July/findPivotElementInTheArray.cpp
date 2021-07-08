#include <bits/stdc++.h>
using namespace std;

// https://www.pepcoding.com/resources/online-java-foundation/time-and-space-complexity/pivot-sorted-rotated-array-official/ojquestion

// Suppose we have a sorted array, and now we rotate it N times, find the pivot element. 
// The pivot element would be the smallest element.

// Solution - 
// if mid element less than high element (normal case), pivot element is on the left of mid element.
// if mid element greater than low element (abnormal case), pivot element is on the right of mid element.
// when low == mid, return.


int findPivot(int[] arr) {
    int high = arr.length - 1;
    int low  = 0;
    while (low < high) {
        int mid  = (high + low) / 2;
        if (arr[mid] < arr[high]) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return arr[low];
}