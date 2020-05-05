

!!! sol2.1, two stage reverse, use reverse function, from gy2, O(n), O(1)
class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverse(s.begin(), s.end());
        int start = 0, end;
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' '){
                reverse(s.begin()+start, s.begin() + i);
                start = i + 1;
            }
        }
        
        reverse(s.begin() + start, s.end());
    }
};

sol2, two stage reverse, own reverse function, from gy1,  O(n), O(1)
class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverse(0, s.size(), s);
        int start = 0, end;
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' '){
                reverse(start, i, s);
                start = i + 1;
            }
        }
        
        reverse(start, s.size(), s);
    }
    
    void reverse(int i, int j, vector<char>& s){
        j = j - 1;
        while(i < j){
            swap(s[i++], s[j--]);
        }
    }
};

sol1, my, using extra space, O(n), O(n)
class Solution {
public:
    void reverseWords(vector<char>& s) {
        stack<string> st;
        for(int i = 0; i < s.size(); i++){
            string cur;
            while(i < s.size() && s[i] != ' '){
                cur.push_back(s[i]);
                i++;
            }
            st.push(cur);
        }
        
        for(int i = 0; i < s.size(); i++){
            string cur = st.top(); st.pop();
            for(int j = 0; j < cur.size(); j++){
                s[i++] = cur[j];
            }
            if(i < s.size()) s[i] = ' ';
        }
        
    }
};
