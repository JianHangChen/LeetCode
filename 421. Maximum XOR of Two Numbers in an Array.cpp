

//!!! sol3, trie
//https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/discuss/91052/C%2B%2B-Trie-69ms-beats-85

class TrieNode {
public:
	TrieNode* next[2];
	
	TrieNode(){next[0] = NULL; next[1] = NULL;}
};

class Solution {
public:
	TrieNode* buildTrie(vector<int>& nums){
		TrieNode* root = new TrieNode;

		for(auto num:nums){
			TrieNode* cur = root;
			for(int i = 31; i >= 0; i--){
				int bit = (num >> i) & 1;
				if(cur->next[bit] == NULL){
					cur->next[bit] = new TrieNode;
				}
				cur = cur->next[bit];
			}
		}
		return root;
	}

	int findMax(int num, TrieNode* root){
		int m = 0;
		TrieNode* curNode = root;
		for(int i = 31; i >= 0; i--){
			int bit = (num >> i) & 1;
			int opposite_bit = 1 - bit;
			if(curNode->next[opposite_bit]){
				m = m | (1 << i);
				curNode = curNode->next[opposite_bit];
			}
			else{
				curNode = curNode->next[bit];
			}
		}
		return m;
	}

    int findMaximumXOR(vector<int>& nums) {
    	TrieNode* root;
    	root = buildTrie(nums);
    	int res = 0;
    	for(auto num:nums){
    		res = max(res, findMax(num, root));
    	}
    	return res;
	}
};


// xor property
// a^b = c
// a^c = b
// b^(a^b) = a

// sol2, O(32n)
//https://kingsfish.github.io/2017/12/15/Leetcode-421-Maximum-XOR-of-Two-Numbers-in-an-Array/

// class Solution {
// public:
//     int findMaximumXOR(vector<int>& nums) {
//         int res = 0;
//         int mask = 0;
//         for(int i = 31; i >= 0; i--){
//             mask = mask | (1 << i);
//             unordered_set<int> s;
//             for(auto num:nums){
//                 s.insert(num&mask);
//             }
//             int temp = res | (1<<i);
//             for(auto ele:s){
//                 if( s.count(temp ^ ele)> 0 ){
//                     res = temp;
//                     break;
//                 }
//             }
//         }
//         return res;
//     }
// };



//sol1, my brute force, O(n^2), TLE

// class Solution {
// public:
//     int findMaximumXOR(vector<int>& nums) {
//         int n = nums.size();
//         int res = 0;
//         for(int i = 0; i < n; i++){
//           for(int j = i+1; j < n; j++){
//             res = max(res, nums[i] ^ nums[j]);
//           }
//         }
//         return res;
//     }
// };
