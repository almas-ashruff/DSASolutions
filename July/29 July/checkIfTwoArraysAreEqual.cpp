// Given two arrays A and B of equal size N, the task is to find 
// if given arrays are equal or not. Two arrays are said to be equal 
// if both of them contain same set of elements, arrangements (or permutation) 
// of elements may be different though.

// https://practice.geeksforgeeks.org/problems/check-if-two-arrays-are-equal-or-not3847/1/?company[]=Goldman%20Sachs&company[]=Goldman%20Sachs&problemStatus=unsolved&difficulty[]=-1&page=1&query=company[]Goldman%20SachsproblemStatusunsolveddifficulty[]-1page1company[]Goldman%20Sachs#

bool check(vector<ll> A, vector<ll> B, int N) {
    unordered_map<long long, int> map;
    
    for(int i = 0; i < N; i++) {
        map[A[i]]++;
        map[B[i]]--;
    }
    
    for(auto val : map) {
        if(val.second != 0) {
            return false;
        }
    }
    
    return true;
}