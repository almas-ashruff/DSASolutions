// Given two n-ary trees. Check if they are mirror images of each other or not. 
// You are also given e denoting the number of edges in both trees, and two arrays, 
// A[] and B[]. Each array has 2*e space separated values u,v denoting an edge 
// from u to v for the both trees.

// https://practice.geeksforgeeks.org/problems/check-mirror-in-n-ary-tree1528/1#

// https://www.geeksforgeeks.org/check-mirror-n-ary-tree/


int checkMirrorTree(int n, int e, int A[], int B[]) {
    vector<int> a[n + 1];
    vector<int> b[n + 1];
    
    for(int i = 0; i < 2 * e; i += 2) {
        a[A[i]].push_back(A[i + 1]);
        b[B[i]].push_back(B[i + 1]);
    }
    
    for(int i = 1; i <= n; i++) {
        reverse(b[i].begin(), b[i].end());
    }
    
    for(int i = 1; i <= n; i++) {
        if(a[i] != b[i]) {
            return false;
        }
    }
    return true;
}
