Given an array A[] of size N and a positive integer K, 
find the first negative integer for each and every window(contiguous subarray) of size K.

// https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1#

vector<long long> printFirstNegativeInteger(long long int a[], long long int n, long long int k) {
    queue<int> q;
    int i = 0; int j = 0;
    vector<long long> ans;
    
    while(j < n) {
        if(a[j] < 0) {
            q.push(a[j]); // push all -ve numbers in the queue
        }
        if(j - i + 1 < k) {
            j++;
        } else if(j - i + 1 < k) {
            j++; //moving pointer j to window size k
        } else if (j - i + 1 == k) {
            if(q.size() == 0) { // if q is empty, push 0
                ans.push_back(0);
            } else {
                ans.push_back(q.front()); // else push element from the front of the queue;
            }
        
            if(a[i] < 0) {
                q.pop(); // first element is negative, pop
            }
            i++;
            j++;
       }
    }
    return ans;
}