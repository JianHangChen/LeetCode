// my, same as sol2, O(nlgon), O(1)
class Solution {
public:
    struct CMP{
        bool operator()(vector<int> const& a, vector<int> const& b){
            return a[1] > b[1];
        }        
    } cmp;
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        int units = 0;
        for(int i = 0; i < boxTypes.size(); i++){
            if(boxTypes[i][0] >= truckSize){
                units += truckSize * boxTypes[i][1];
                break;
            }
            else{
                units += boxTypes[i][0] * boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            }
        }
        return units;        
    }
};
