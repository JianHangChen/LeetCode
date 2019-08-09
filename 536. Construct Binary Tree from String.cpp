

// sol1, !!!recursively, from grandyang sol1
class Solution {
public:
    TreeNode * str2tree(const string& s) {
        if(s.empty()) return NULL;
        int found = s.find('(');
        int val;
        if(found == string::npos) val = stoi(s);
        else val = stoi(s.substr(0, found));
        TreeNode* root = new TreeNode(val);

        int start = found;
        int cnt = 0;
        for(int i = start; i < s.size(); i++){
          if(s[i] == '(') cnt++;
          else if(s[i] == ')') cnt--;
          if(cnt==0){
            if(start == found){
              root->left = str2tree(s.substr(start + 1, i - start - 1));
              start = i + 1;
            }
            else{
              root->right = str2tree(s.substr(start + 1, i - start - 1));
            }
          }

        }
        return root;
    }
};


// sol2, iteratively, stack

class Solution {
public:
    TreeNode * str2tree(const string& s) {
      stack<TreeNode*> st;

      TreeNode* root;
      int i = 0;
      while(i < s.size()){
        if(s[i] >= '0' && s[i] <= '9' || s[i] == '-'){
          int j = i;

          while(i < s.size() && s[i] >= '0' && s[i] <= '9' || s[i] == '-') i++;

          TreeNode* cur = new TreeNode(stoi( s.substr(j, i - j)));
          if(!st.empty()){
            TreeNode* t = st.top();
            if(t->left) t->right =  cur;
            else t->left = cur;
          }
          st.push(cur);
        }
        else{
          if(s[i] == ')'){
            st.pop();
          }
          i++;
        }
      }
      return st.top();
    }
};




