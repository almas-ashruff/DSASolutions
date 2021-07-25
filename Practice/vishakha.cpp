
int KadanesAlgo(vector<int> array){

    if(array.size() == 0){
        return -1;
    }

    int maxSumTillNow = array[0], maxSumSoFar = array[0];
    for(int i = 1; i < array.size(); i++){
        int num = array[i];
        maxSumTillNow = max(num, maxSumTillNow + num);
        maxSumSoFar = max(maxSumSoFar, maxSumTillNow);
    }
    return maxSumSoFar;
}


int jumps(vector<int> array) {
    vector<int> jumps(array.size(), INT_MAX);
    jumps[0] = 0;

    for(int i = 1; i < array.size(); i++) {
        for(int j = 0; j < i; j++) {
            if(array[j] > i - j) {
                jumps[i] = min(jumps[i], jumps[j] + 1);
            }
        }
    }
    return jumps[array.size() - 1];
}

int jumps(vector<int> array) {
    int jumps = 0;
    int maxReach = array[0];
    int steps = maxReach;

    for(int i = 1; i < array.size(); i++) {
        maxReach = max(maxReach, i + array[i]);
        steps--;
        if(steps == 0) {
            jumps++;
            steps = maxReach - i;
        }
    }
    return jumps + 1;
}