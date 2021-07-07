#include <bits/stdc++.h>
using namespace std;

// Given a sorted array arr containing n elements with possibly duplicate elements, 
// the task is to find indexes of first and last occurrences of an element x in the given array.

// https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1#

// USES MODIFICATION OF BINARY SEARCH

vector<int> find(int arr[], int n , int ele )
{
    int low = 0, high = n - 1;
    int first = -1, last = -1;
    // finding first occurence
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == ele) {
            first = mid;
            high = mid - 1;
        }
        else if (ele < arr[mid]) {
            high = mid-1;
        }
        else if (ele > arr[mid]) {
            low = mid+1;
        }
    }
    // checking for last occurence
    low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) /2;
        if (arr[mid] == ele) {
            last = mid;
            low = mid+1;
        }
        else if (arr[mid] > ele) {
            high = mid-1;
        }
        else if (arr[mid] < ele) {
            low = mid+1;
        }
    }
    vector <int> Result {first,last};
    return Result;
}