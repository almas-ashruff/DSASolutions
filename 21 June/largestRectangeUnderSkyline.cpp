#include <bits/stdc++.h>
using namespace std;

// https://www.algoexpert.io/questions/Largest%20Rectangle%20Under%20Skyline

// Solution 1 O(n^2) time

// Go both direction from a building, considering its height as the height of the rectangle
// Find the max right and max left you can go. Find the area. Update max area.


int largestRectangleUnderSkyline(vector<int> buildings) {
  int maxArea = 0;
	
	for(int pillarIdx = 0; pillarIdx < buildings.size(); pillarIdx++) {
		int currentHeight = buildings[pillarIdx];
		
		int furthestLeft = pillarIdx, furthestRight = pillarIdx;
		
		while(furthestLeft > 0 && buildings[furthestLeft - 1] >= currentHeight) {
			furthestLeft--;
		}
		
		while(furthestRight < buildings.size() - 1 && buildings[furthestRight + 1] >= currentHeight) {
			furthestRight++;
		}
		
		int areaWithCurrentBuilding = (furthestRight - furthestLeft + 1) * currentHeight;
		
		maxArea = max(areaWithCurrentBuilding, maxArea);
	} 
	return maxArea;
}


// Solution 2 - O(n) time

