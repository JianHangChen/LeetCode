
// sol1, 
// O(elogn)-> O(e), O(n)
// https://leetcode-cn.com/problems/redundant-connection-ii/solution/rong-yu-lian-jie-ii-by-leetcode-solution/
// 这题比较难：
// https://www.cnblogs.com/grandyang/p/8445733.html
// 参考1： https://www.youtube.com/watch?v=lnmJT5b4NlM
// 参考2：https://leetcode-cn.com/problems/redundant-connection-ii/solution/xi-zhi-jie-du-yi-wen-rang-ni-zhen-zheng-du-dong-be/

class Solution {
public:
    unordered_map<int, int> parent;
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        vector<int> ans1, ans2;
        for(auto& e:edges){ // e[0]->e[1]
            if(parent.count(e[1]) > 0){ // parent[e[1]] has already exist!!!
                ans1 = {parent[e[1]], e[1]}; // potential answer1 is the previous pair of parent and e[1]
                ans2 = e;
                // let's try to delete e, to see if it works!
                e[0] = -1; e[1] = -1;
            }
            parent[e[1]] = e[0];
        }
        // reset the parent point to itself
        for(auto& e:edges){
            parent[e[0]] = e[0];
            parent[e[1]] = e[1];
        }
        // find if cycle exist
        for(auto& e:edges){
            if(e[0] == -1) continue; // the edge of answer2 has been deleted
            int p0 = find(e[0]), p1 = find(e[1]);
            if(p0 == p1 ){
            // find circle! two case: 1. we don't delete anything in previous forloop 2. we delete the e2 is not correct
                if(ans1.empty()) return e;
                else return ans1; // we delete answer2 in mistake
            }
            uni(e[0], e[1]);
        }
        return ans2;
        
    }
    int find(int a){
        if(parent[a] == a) return a;
        return parent[a] = find(parent[a]);
    }
    void uni(int a, int b){ // a->b
        parent[find(b)] = parent[find(a)];
    }
    
};

// 1->4, 5->4 invalid

// [[2,1],[3,1],[4,2],[1,4]]
// 4->2->1->back4
//    3->1
