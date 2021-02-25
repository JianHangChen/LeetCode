// sol1, my, O(m), O(1)
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = flowerbed.size();
        for(int i = 0; i < m; i++){
            if(flowerbed[i] == 1) continue;
            else{ // 0
                bool before = true, after = true;
                if(i > 0 && flowerbed[i-1] == 1) before = false; // no before
                if(i < m - 1 && flowerbed[i+1] == 1) after = false;
                
                if(before && after){
                    flowerbed[i] = 1;
                    n--;
                }
            }
        }
        return  n <= 0;
    }
};
