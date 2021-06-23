#include <bits/stdc++.h>
using namespace std;

// Given three arrays sorted in increasing order. 
// Find the elements that are common in all three arrays.

// https://practice.geeksforgeeks.org/problems/common-elements1132/1#


vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3){
    vector<int> answer;
    int i = 0, j = 0, k = 0;
    while(i < n1 && j < n2 && k < n3) {

        if(A[i] == B[j] && B[j] == C[k]) {
            // when equal
            answer.push_back(A[i]);
            i++;
            // increase only one index value
        } 
        if(i < n1) {
            if(A[i] <= B[j] && A[i] <= C[k]) {
                i++; 
                // A[i] is smallest
                while(i < n1 && A[i] == A[i - 1]) {
                    i++;
                    // duplicate values in array
                }
            } else if(B[j] <= A[i] && B[j] <= C[k]) {
                j++;
                // B[j] is smallest
                while(j < n2 && B[j] == B[j - 1]) {
                    j++;
                    // duplicate value
                }
            } else if(C[k] <= A[i] && C[k] <= B[j]) {
                k++;
                // C[k] is smallest
                while(k < n3 && C[k] == C[k - 1]) {
                    k++;
                    // duplicate value
                }
            }
        }
    }
    return answer;
}