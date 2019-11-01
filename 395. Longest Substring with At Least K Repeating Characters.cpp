

// !!!! sol2, divide and conquer, O(26n) = O(n), from 9 ch
// explain: https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/discuss/87749/Two-short-C%2B%2B-solutions-(3ms-and-6ms)

class Solution{
public:
    int longestSubstring(string s, int k){
        int n = s.size();
        return longestSubstring(s, k, 0, n - 1);
    }

    int longestSubstring(string& s, int k, int start, int end){
        if(start > end || end -start + 1 < k) return 0;
        int initial = start;

        unordered_map<char, int> m;
        for(int i = start; i <= end; i++) m[s[i]]++;
        int res = 0;

        for(int i = start; i <= end; i++){
            if(m[s[i]] < k){
                res =  max(res, longestSubstring(s, k, start, i - 1));  
                start = i + 1;
            }
        }

        if(start == initial) return (end-start+1);
        else{
            res =  max(res, longestSubstring(s, k, start, end));  
        }
        return res;

    }
};


// sol2.1, divide and conquer, divided by left and right, O(n^2) in worst case

class Solution{
public:
    int longestSubstring(string s, int k){
        return longestSubstring(s, k, 0, (int)s.size() - 1);
    }


    int longestSubstring(const string& s, int k, int start, int end){
        if(k > end - start + 1) return 0;
        else if(start == end){
            if(k <= 1) return 1;
        }

        int mid = start;
        unordered_map<char, int> m;
        for(int i = start; i <= end; i++){
            m[s[i]]++;
        }

        while(mid <= end && m[s[mid]] >= k){
            mid++;
        }

        if(mid > end) return end - start + 1; // !!! carefull about ending condition
        int left = longestSubstring(s, k, start, mid - 1);

        while(mid <= end && m[s[mid]] < k) mid++;

        int right = longestSubstring(s, k, mid, end);
        return max(left, right);
    }
};








// sol1, skipping pointer, from gy1, using mask, O(n^2) in worst case. O(n)in some case
class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        int i = 0;
        int res = 0;
        while(i + k <= n){
            int valid_j = i, mask = 0;
            vector<int> count(26,0);
            for(int j = i; j < n; j++){
                count[s[j] - 'a']++;
                if(count[s[j]-'a'] >= k){
                    mask &= ~(1 << (s[j] - 'a'));  // carefull, ~ is not !
                }else{
                    mask |= 1 << (s[j] - 'a');
                }
                if(mask == 0){
                    valid_j = j;
                    res = max(res, j - i + 1);
                }
            }
            i = valid_j + 1;
        }
        return res;
    }
};
