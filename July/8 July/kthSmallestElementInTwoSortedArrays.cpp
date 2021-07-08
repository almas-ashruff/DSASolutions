#include <bits/stdc++.h>
using namespace std;

// Given two sorted arrays arr1 and arr2 of size M and N respectively and an element K. 
// The task is to find the element that would be at the k’th position of the final sorted array.

// https://www.youtube.com/watch?v=nv7F4PiLUzo 

// Variant of binary search

int kthElement(int arr1[], int arr2[], int n, int m, int k)
{
    // n -> size of array1
    // m -> size of array 2
    // k -> the element to be found
    if(n > m) {
        return kthElement(arr2, arr1, m, n, k);
        // if second array is smaller, run this function for smaller array
    }
    int low = max(0, k - m);
    int high = min(k, n);
    
    while(low <= high) {
        int cut1 = (low + high) / 2;
        int cut2 = k - cut1;
        
        int left1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1];
        int left2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];
        
        int right1 = cut1 == n ? INT_MAX : arr1[cut1];
        int right2 = cut2 == m ? INT_MAX : arr2[cut2];
        
        if(left1 <= right2 && left2 <= right1) {
            return max(left1, left2);
        } else if(left1 > right2) {
            high = cut1 - 1;
        } else {
            low = cut1 + 1;
        }
    }
    return 1;
}