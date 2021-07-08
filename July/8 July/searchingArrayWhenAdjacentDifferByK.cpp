#include <bits/stdc++.h>
using namespace std;

// A step array is an array of integers where each element has a difference of at most k with its neighbor. 
// Given a key x, we need to find the index value of x if multiple-element exist to 
// return the first occurrence of the key.

// The idea is to start comparing from the leftmost element and find the difference between 
// the current array element and x. Let this difference be ‘diff’. From the given property of the array, 
// we always know that x must be at least ‘diff/k’ away, so instead of searching one by one, 
// we jump ‘diff/k’. 

int search(int arr[], int n, int x, int k)
{
    // Traverse the given array starting from
    // leftmost element
    int i = 0;
    while (i < n)
    {
        // If x is found at index i
        if (arr[i] == x)
            return i;
 
        // Jump the difference between current
        // array element and x divided by k
        // We use max here to make sure that i
        // moves at-least one step ahead.
        i = i + max(1, abs(arr[i]-x)/k);
    }
    return -1;
}