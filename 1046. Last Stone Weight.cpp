// //!!! sol1, my, priority queue, O(nlogn), O(n)
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        for(int stone:stones) q.push(stone);
        
        while(!q.empty()){
            int largest = q.top(); q.pop();
            if(q.empty()) return largest;
            int second = q.top(); q.pop();
            if(largest != second){
                q.push(largest - second);
            }
        }
        
        return 0;
    }
};


//! sol2, from sol4, bucket sort, O()
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int largestWeight = 0, currentWeight;
        for(auto stone:stones){
            largestWeight = max(largestWeight, stone);
        }
        currentWeight = largestWeight;
        vector<int> bucket(largestWeight+1, 0);
        for(auto stone:stones){
            bucket[stone]++;
        }
        largestWeight = 0;
        while(currentWeight > 0){
            if(bucket[currentWeight] == 0){
                currentWeight--;
            }
            else{ // bucket[currentWeihgt] > 0
                if(largestWeight == 0){
                    bucket[currentWeight] %= 2;
                    if(bucket[currentWeight] == 0) continue;
                    largestWeight = currentWeight;
                    bucket[currentWeight] = 0;
                }
                else{
                    bucket[currentWeight]--;
                    int diff = largestWeight - currentWeight;
                    if(diff > currentWeight){
                        largestWeight = diff;
                    }
                    else{
                        largestWeight = 0;
                        bucket[diff]++;
                    }
                }
            }
        }
        
        return largestWeight;
    }
};
