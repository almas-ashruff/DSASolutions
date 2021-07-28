// Given an input stream of N integers. The task is to insert these numbers into a new stream and 
// find the median of the stream formed by each insertion of X to the new stream.

// https://practice.geeksforgeeks.org/problems/find-median-in-a-stream-1587115620/1#

// https://www.youtube.com/watch?v=dshWERdcAdg

priority_queue<int> smaller; // max heap
priority_queue<int, vector<int>, greater<int>> larger; //min heap
// stores the smaller and the larger half of the numbers 

// insert the numbers in the heap such that 
// the sizes of the two heaps at max differ by one
void insertHeap(int &x)
{
    int smallSize = smaller.size();
    int largeSize = larger.size();
    
    if(smaller.empty()) { // when smaller is empty, push to smaller
        smaller.push(x);
        
    } else if(smallSize == largeSize) { // if the sizes are equal
        if(x < larger.top()) { 
        // if x is smaller than the smallest value in larger heap
            smaller.push(x);
            
        } else { 
        // if x is bigger than the smallest value in the larger heap
            int temp = larger.top();
            larger.pop();
            larger.push(x);
            smaller.push(temp);
            // pop from larger heap and put it in smaller heap. push x in larger heap
            
        }
    } else {
        // if smaller is larger in size
        if(!larger.empty() && x >= larger.top()) {
        // if larger is not empty, and x is greater than 
        // the smallest element in larger, push into larger
            larger.push(x);
        } else {
            if(x > smaller.top()) {
                larger.push(x);
            } else {
                int temp = smaller.top();
                smaller.pop();
                smaller.push(x);
                larger.push(temp);
                
            }
        }
    }
}

//Function to return Median.
double getMedian()
{
    if(smaller.size() > larger.size()) {
        return double(smaller.top());
    }
    
    return (double(smaller.top()) + double(larger.top())) / 2;
}