//!!! sol1.1, recursively, from gy1, similar to sol1, but more elegant with returning number as result

class Solution{
public:
	int sumNumbers(TreeNode* root){
		return sumNumbers(root, 0);
	}
	int sumNumbers(TreeNode* root, int val){
		if(!root) return 0;
		val = val * 10 + root->val;
		if(!root->left && !root->right) return val;
		return sumNumbers(root->left, val) + sumNumbers(root->right, val);
	}	
};

// sol1, my recursively
class Solution {
private:
	int res = 0;
public:
    int sumNumbers(TreeNode* root) {
    	sumNumbers(root, 0);
    	return res;
    }

    void sumNumbers(TreeNode* root, int val){
    	if(!root) return;
    	val = val * 10 + root->val;

    	if(!root->left && !root->right){
    		res += val;
    		return;
		}

    	
    	if(root->left) sumNumbers(root->left, val);
    	if(root->right) sumNumbers(root->right, val);
    }
};



// sol2, iteratively, from gy2
class Solution{
public:
	int sumNumbers(TreeNode* root){
		int res  = 0;
		int val = 0;
		stack<pair<TreeNode*, int>> s; //!!! pair not pairs
		if(root) s.push({root, val});
		
		while(!s.empty()){
			root = s.top().first; val = s.top().second; s.pop(); //pair.first
			val = val * 10 + root->val;
			if(!root->left && !root->right) res += val;
			else{
				if(root->left) s.push({root->left, val});
				if(root->right) s.push({root->right, val});//pair format when push
			}
		}
		return res;
	}

};


