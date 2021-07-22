// A celebrity is a person who is known to all but does not know anyone at a party. 
// If you go to a party of N people, find if there is a celebrity in the party or not.
// A square NxN matrix M[][] is used to represent people at the party such that 
// if an element of row i and column j  is set to 1 it means ith person knows jth person. 
// Here M[i][i] will always be 0.
// Note: Follow 0 based indexing.

// https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1#

// https://www.youtube.com/watch?v=CiiXBvrX-5A

int celebrity(vector<vector<int> >& arr, int n) 
{
    stack<int> st;
    
    for(int i = 0; i < n; i++) {
        st.push(i); // push all people in the stack
    }
    
    while(st.size() > 1) { 
    // take out two people and check if they are a potential celeb. 
    // Only max one celeb can exist in a test case

        int first = st.top();
        st.pop();
        int second = st.top();
        st.pop();
        
        if(arr[first][second] == 1) {
            st.push(second);
        } else {
            st.push(first);
        }
    }

    // at the end we are left with one potential for celeb
    
    int potential = st.top();

    // check if the potential person is actually a celeb
    for(int i = 0; i < n; i++) {
        if(i != potential) {
            if(arr[i][potential] == 0 || arr[potential][i] == 1) {
                return -1;
            }
        }
    }
    return potential;
}