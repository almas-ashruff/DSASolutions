// Given K sorted lists of integers of size N each, find the smallest range 
// that includes at least one element from each of the K lists. 
// If more than one such range's are found, find the first such range found.

// https://practice.geeksforgeeks.org/problems/find-smallest-range-containing-elements-from-k-lists/1

pair<int,int> findSmallestRange(int arr[][N], int n, int k) {
      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
      
      int maxVal = INT_MIN;
      int minRange = INT_MAX;
      int start;
      
      for(int i = 0; i < k; i++) {
          pq.push(make_pair(arr[i][0], i));
          maxVal = max(maxVal, arr[i][0]);
      }
      
      int a[k] = {0};
      
      while(1) {
          pair<int, int> p = pq.top();
          pq.pop();
          
          int minVal = p.first;
          
          int range = maxVal - minVal;
          
          if(range < minRange) {
              start = minVal;
              minRange = range;
          }
          
          a[p.second]++;
          
          if(a[p.second] == n) {
              break;
          }
          
          pq.push(make_pair(arr[p.second][a[p.second]], p.second));
          maxVal = max(maxVal, arr[p.second][a[p.second]]);
      }
      
      return make_pair(start, minRange + start);
}