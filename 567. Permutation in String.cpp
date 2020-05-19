//!!! sol2, from sol6, O(n1 + n2 - n1), O(1)
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        if(n2 < n1) return false;
        vector<int> v1(26,0), v2 = v1;
        for(int i = 0; i < n1; i++){
            v1[s1[i] - 'a']++;
            v2[s2[i] - 'a']++;
        }
        int count = 0;
        for(int i = 0; i < 26; i++){
            if(v1[i] == v2[i]) count++;
        }
        
        for(int i = 0; i + n1 < n2; i++){
            int left = s2[i] - 'a', right = s2[i + n1] - 'a'; // left is i, right is new element
            if(count == 26) return true;
            
            v2[left]--;
            if(v1[left] == v2[left]) count++;
            else if(v1[left] - 1 == v2[left]) count--;
            
            v2[right]++;
            if(v1[right] == v2[right]) count++;
            else if(v1[right] + 1 == v2[right]) count--;
        }
        return count == 26;      
    }
};

!! my sol1, same as sol5, O(n1+26(n2-n1)) , O(1)
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size()) return false;
        int n1 = s1.size(), n2 = s2.size();
        vector<int> v1(26, 0), v2 = v1;
        for(int i = 0; i < n1; i++){
            v1[s1[i] - 'a']++;
            v2[s2[i] - 'a']++;
        }
        for(int i = 0; i + n1 <= n2; i++){
            if(i != 0){
                v2[s2[i-1] - 'a']--;
                v2[s2[i+n1-1] - 'a']++;
            }
            int j; 
            for(j = 0; j < 26; j++){
                if(v1[j] > v2[j]) break;
            }
            if(j == 26) return true;
        }
        return false;
    }
};
