
// !!! sol4, from ch9 sol2, using map, O(n), O(k)

class Solution {
public:
    int majorityNumber(vector<int> &nums, int k) {
       if(k == 0|| nums.empty()) return -1;
       int n = nums.size();
       int s = n / k;
       unordered_map<int, int> m;
       for(int num:nums){
           if(m.count(num) > 0) m[num]++;
           else{
               if(m.size() < k){
                   m[num]++;
               }
               else{
                   vector<int> tmp;
                   for(auto& it:m){
                       it.second--; // the total decrease will  <= O(n)
                       if(it.second == 0) tmp.push_back(it.first);
                   }
                   for(int i:tmp) m.erase(i); // cannot delete the element when iterate in m
               }
           }
       }
       
       int res, max_count = 0;
       for(auto& it:m){
           if(it.second > max_count){
               max_count = it.second;
               res = it.first;
           }
       }
       return res;
        
    }
};



// my,sol3, O(n), O(n)

class Solution{
public:
    int majorityNumber(vector<int>& nums, int k){
        unordered_map<int, int> m;
        int n = nums.size();
        for(auto num:nums){
            m[num]++;
            if(m[num] > n/k) return num;
        }
        return -1;
    }
};



// sol2, two hash version, O(n), O(k)
// https://wdxtub.com/interview/14520595473216.html
class Solution{
public:
    int majorityNumber(vector<int>& nums, int k){
        int n = nums.size();
        unordered_map<int, int> m;

        for(auto num:nums){
            if(m.count(num) > 0){
                m[num]++;
            }
            else if(m.size() < k){
                m[num] = 1;
            }
            else{
                unordered_map<int, int> temp;
                for(auto ele:m){
                    if(ele.second > 1){
                        temp[ele.first] = ele.second - 1;
                    }
                }
                m = temp;
            }
        }
        int max_count = 0, res = 0;
        for(auto ele:m){
            if(ele.second > max_count){
                max_count = ele.second;
                res = ele.first;
            }
        }
        return res;
    }
};


// sol1, no hash version, hint form ch9, O(kn), O(k)
class Solution {
public:

    int majorityNumber(vector<int>& nums, int k){
        vector<int> majork(k), count = majork;
        int n = nums.size();
    
        for(int i = 0; i < nums.size(); i++){
            bool find = false, fill = false;
            for(int j = 0; j < k; j++){
                if(majork[j] == nums[i]){
                    count[j]++;
                    find = true;
                    break;
                }
            }
            if(!find){
                for(int j = 0; j < k; j++){
                    if(count[j] == 0){
                        majork[j] = nums[i];
                        count[j] = 1;
                        fill = true;
                        break;
                    }
                }

                if(!fill){
                    for(int j = 0; j < k; j++){
                        count[j]--;
                    }
                }
            }

        }
        unordered_map<int, int> recount;
        for(int j = 0; j < k; j++){
            recount[majork[j]] = 0;
        }
    
    
        for(int i = 0; i < nums.size(); i++){
            if(recount.count(nums[i]) > 0){
                recount[nums[i]]++;
                if(recount[nums[i]] > n / k) return nums[i];
            }
        }
        return -1;
    
    }
};
