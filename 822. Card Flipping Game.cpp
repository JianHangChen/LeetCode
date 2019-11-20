

// !!! sol2, from sol, O(n), O(n)
class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
    	unordered_set<int> repeat; int n = fronts.size();
    	for(int i = 0; i < n; i++){
    		if( fronts[i] == backs[i]) repeat.insert(fronts[i]);
    	}
    	int res = INT_MAX;
    	for(int i = 0; i < n; i++){
    		if(fronts[i] < res && repeat.count( fronts[i] ) ==  0 ) res = fronts[i];
    		if(backs[i] < res && repeat.count(backs[i]) == 0) res = backs[i];
    	}
    	return res == INT_MAX ? 0 : res;
    }
};

[2,1]
[1,2]
// my, sol1, wrong!
class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        int res = INT_MAX;
        unordered_map<int, int> m_front;
        for(int i = 0; i < fronts.size(); i++){
        	m_front[fronts[i]] ++;
        }
        for(int i = 0; i < fronts.size(); i++){
        	if(backs[i] == fronts[i]) continue;
        	if( backs[i] < res ){
        		if(m_front.count(backs[i]) == 0 || m_front[backs[i]] == 0) res = backs[i];
        	}
        	if( fronts[i] < res){
        		swap(fronts[i], backs[i]);
        		m_front[fronts[i]]++;
        		m_front[backs[i]]--;
        		if(m_front.count(backs[i]) == 0 || m_front[backs[i]] == 0) res = backs[i];	
        	}
        }
        return res == INT_MAX ? 0 : res;
    }
};

