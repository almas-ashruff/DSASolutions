#include <bits/stdc++.h>
using namespace std;

// WATCH - https://www.youtube.com/watch?v=wSOfYesTBRk  https://www.youtube.com/watch?v=SiE1XFhYoaA
// variant of binary search

int aggressiveCows(vector<int> a, int c) {
    sort(a, a + n);
    int low = 0, high = n - 1, mid, best = 0;
    while(low <= high) {
    	mid = (low + high) / 2;
    	int count = 1, left  = 0;
    	for(int i = 1; i < n; i++) {
    		if(a[i] - a[left] >= mid) {
    			left = i; count++;
    		}
    	} 
    	if(count >= c) {
    		best = mid;
    		low = mid + 1;
    	} else {
    		high = mid - 1;
    	}
    }
    return best;
}