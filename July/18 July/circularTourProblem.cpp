// Suppose there is a circle. There are N petrol pumps on that circle. You will be given two sets of data.
// 1. The amount of petrol that every petrol pump has.
// 2. Distance from that petrol pump to the next petrol pump.
// Find a starting point where the truck can start to get through the complete circle without exhausting its petrol in between.
// Note :  Assume for 1 litre petrol, the truck can go 1 unit of distance.

// https://practice.geeksforgeeks.org/problems/circular-tour/1

// SIMILAR TO -
// https://www.algoexpert.io/questions/Valid%20Starting%20City

// GFG SOLUTION - 

int tour(petrolPump p[],int n)
{
   int start = 0;
   int cap = 0;
   int deficit = 0;
   
   for(int i = 0; i < n; i++) {
       cap += p[i].petrol - p[i].distance;
       if(cap < 0) {
           start = i + 1;
           deficit += cap;
           cap = 0;
       }
   }
   
   if(deficit + cap >= 0) {
       return start;
   }
   return -1;
}

// AlgoExpert Solution - 

// Basically, find the city for which the value is negative, or the least
int validStartingCity(vector<int> distances, vector<int> fuel, int mpg) {
  int numberOfCities = distances.size();
	int milesRemaining = 0;
	
	int indexOfStartingCityCandidate = 0;
	int milesRemainingAtStartingCityCandidate = 0;
	
	for(int cityIdx = 1; cityIdx < numberOfCities; cityIdx++){
		int distanceFromPreviousCity = distances[cityIdx - 1];
		int fuelFromPreviousCity = fuel[cityIdx - 1];
		milesRemaining = milesRemaining + fuelFromPreviousCity * mpg - distanceFromPreviousCity;
		
		if(milesRemaining < milesRemainingAtStartingCityCandidate){
			milesRemainingAtStartingCityCandidate = milesRemaining;
			indexOfStartingCityCandidate = cityIdx;
		}
	}
	return indexOfStartingCityCandidate;
}



