
// sol1, my, sort and two pointer, O(nlogn), O(1)
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int i = 0, j = people.size() - 1;
        int res = 0;
        while(i <= j){
            if(i == j){
                res++; break;
            }
            if(people[i] + people[j] <= limit){
                res++; i++; j--;
            }
            else{
                j--;
                res++;
            }
        }
        return res;
    }
};
