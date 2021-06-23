#include <bits/stdc++.h>
using namespace std;

// Given an array of n positive integers and a number k. 
// Find the minimum number of swaps required to bring all the numbers less than or equal to k together.

// https://practice.geeksforgeeks.org/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together4847/1#

// Solution - 
// https://www.youtube.com/watch?v=iDmJaMRhAcY&t=4s

// Sliding window technique. The minimum number of bad elements in the window is the number of swaps needed.

int minSwap(int *arr, int n, int k) {
    int i, good = 0,bad = 0, ans, j;
    for(i = 0;i < n; i++)
    {
        if(arr[i] <= k) {
            good++; //signifies how many elements <= k
        }
    }
    if(good == 1 || good == n) {
        return 0;
    }
    for(i = 0; i < good; i++)
    {
        if(arr[i] > k) {
            bad++; //signifies number of elements >k and so only those many elements have to be swapped
        }
    }

    ans = bad;
    j = i - 1;
    i = 0;
    while(j < n - 1)//because when j=n-2 it enters the loop and then j++ happens and j=n-1 take place.
    {             //do try this for arr=[10,12,1,20,1] & k=1 you will understand use of 
                   // j<n-1 over j<n
        if(arr[i] > k) {
            bad--;
        }
        
        i++; 
        j++;
        if(arr[j] > k) {
            bad++;
        }
        ans = min(ans, bad); 
    }
    return ans;
}