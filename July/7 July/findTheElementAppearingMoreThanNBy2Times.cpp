#include <bits/stdc++.h>
using namespace std;


// Given an array A of N elements. Find the majority element in the array. 
// A majority element in an array A of size N is an element that appears more than N/2 times in the array.

// https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1#
// https://www.youtube.com/watch?v=AoX3BPWNnoE

// Watch the video for concept

 int majorityElement(int a[], int size)
    {
        // Boyer-Moore voting algorithm
        int count = 0;
        int candidate;
        for(int i = 0; i < size; i++) {
            int num = a[i];
            
            if(count == 0) {
                candidate = num;
                // will not reach 0 at the end for the majority element
            }
            
            if(candidate == num) {
                count++;
            } else {
                count--;
            }
        }
        // sets the candidate for majority appearance
        
        
        count = 0;
        for(int i = 0; i < size; i++){
            if(a[i] == candidate) {
                count++;
            } 
        }
        // checks if the majority candidate actually appears more than n / 2 times.

        if(count > size / 2) {
            return candidate;
        } 
        return -1;
    }