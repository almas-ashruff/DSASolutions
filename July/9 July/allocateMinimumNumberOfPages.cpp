#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1#
// https://www.youtube.com/watch?v=gYmWHvRHu-s


// You are given N number of books. Every ith book has Ai number of pages. 
// You have to allocate books to M number of students. 
// There can be many ways or permutations to do so. 
// In each permutation, one of the M students will be allocated the maximum number of pages. 
// Out of all these permutations, the task is to find that particular permutation 
// in which the maximum number of pages allocated to a student is minimum of those in 
// all the other permutations and print this minimum value. 

// Each book will be allocated to exactly one student. 
// Each student has to be allocated at least one book.

int findPages(int arr[], int size, int students) 
{
    if(size < students) {
        return -1;
    }
    
    int low = arr[0];
    int high = 0;
    
    for(int i = 0; i < size; i++) {
        int num = arr[i];
        high += num;
        low = min(low, num);
    }
    // low now stores the lowest number of pages and 
    // ... high stores the sum of all pages (which acts like our upper bound)
    
    int result = -1;
    // stores the answer

    // binary search
    while(low <= high) {
        int mid = (low + high) / 2;
        // mid stores the tentative minimum number of pages for which satisfies the conditions (the upper bound)

        if(isPossible(arr, students, mid, size)) {
            // checks if allocation is possible for the current upper bound
            result = mid;
            high = mid - 1;
        } else {
            // if not possible, low is updated
            low = mid + 1;
        }
    }
    return result;
}
    
    bool isPossible(int arr[], int students, int pagesAllowed, int size) {
        int count = 0;
        // counts the minimum number of students needed to distribute the given pages
        int sumAllocated = 0;
        // stores the sum allocated to the current student
        for(int i = 0; i < size; i++) {
            if(sumAllocated + arr[i] > pagesAllowed) {
                count++;
                sumAllocated = arr[i];
                if(sumAllocated > pagesAllowed) {
                    return false;
                }
            } else {
                sumAllocated += arr[i];
            }
        }
        if(count < students) {
            return true;
        } 
        return false;
    }