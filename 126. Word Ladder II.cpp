
// !!!!! sol2.1 bfs + reverse dfs, O(mN), O(mN) by ch9,linghu
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        wordList.push_back(beginWord);
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        queue<string> q({beginWord});
        unordered_map<string, unordered_set<string>> pre;
        int word_size = beginWord.size();
        bool findShortest = false;
        while(!q.empty()){
            unordered_set<string> visited_cur_level;
            for(int k = q.size(); k > 0; k--){
                string cur_string = q.front(); q.pop();
                if(cur_string == endWord){ //findShortest
                    findShortest = true; break;
                }
                
                for(int i = 0; i < word_size; i++){
                    string new_string = cur_string;
                    for(char c = 'a'; c <= 'z'; c++){
                        new_string[i] = c;
                        
                        if(wordSet.count(new_string) > 0){
                            if(visited_cur_level.count(new_string) == 0){ // very carefull of how to insert to queue
                                q.push(new_string);
                                visited_cur_level.insert(new_string);
                            }
                            pre[new_string].insert(cur_string);
                        }
                    }
                }
            }
            if(findShortest) break;
            for(auto& v:visited_cur_level) wordSet.erase(v);  
        }
        vector<string> path({endWord});
        addRes(res, pre, beginWord, endWord, path);
        return res;
    }
    
    void addRes(vector<vector<string>>& res,  unordered_map<string, unordered_set<string>>& pre, string& beginWord, string cur, vector<string>& rpath){
        if(cur == beginWord){
            vector<string> path(rpath.rbegin(), rpath.rend());
            res.push_back(move(path));
        }
        else{
            for(auto& p:pre[cur]){
                rpath.push_back(p);
                addRes(res, pre, beginWord, p, rpath);
                rpath.pop_back();
            }            
        }
        return;
    }
};

// sol2.0 bfs + reverse dfs, O(mN), O(mN) by ch9,linghu
// 1. use index to compare
// 2. build neighbours set
class Solution {
public:
    bool ispair(string& s1, string& s2){
        if(s1.size() != s2.size()) return false;
        int diff = 0;
        for(int i = 0; i < s1.size(); i++){
            if(s1[i] != s2[i]) diff++;
            if(diff > 1) return false;
        }
        return diff == 1;
    }
    int n;
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;        
        
        unordered_map<int, unordered_set<int>> neighbors;

        wordList.push_back(beginWord);
        for(int i = 0; i < wordList.size(); i++){
            for(int j = i+1; j < wordList.size(); j++){
                if(ispair(wordList[i], wordList[j])){
                    neighbors[i].insert(j);
                    neighbors[j].insert(i);                        
                }
            }
        }
        n = wordList.size();
        
        unordered_set<int> wordSet;
        int end_idx;
        for(int i = 0; i < wordList.size(); i++){
            if(wordList[i] == endWord) end_idx = i;
            wordSet.insert(i);
        }
        queue<int> q({n-1});
        
        unordered_map<int, unordered_set<int>> pre;

        bool findShortest = false;
        while(!q.empty()){
            unordered_set<int> visited_cur_level;

            for(int k = q.size(); k > 0; k--){
                int cur = q.front(); q.pop();

                if(cur == end_idx){ //findShortest
                    findShortest = true; break;
                }
                
                for(auto nei:neighbors[cur]){
                    if(wordSet.count(nei) > 0){
                        if(visited_cur_level.count(nei) == 0) q.push(nei); // careful of how to add to bfs
                        
                        pre[nei].insert(cur);
                        visited_cur_level.insert(nei);
                    }
                }
            }
            if(findShortest) break;
            for(auto& v:visited_cur_level) wordSet.erase(v);  
        }
        vector<int> path({end_idx});
        addRes(res, pre, beginWord, end_idx, path, wordList);
        return res;
    }
    
    void addRes(vector<vector<string>>& res,  unordered_map<int, unordered_set<int>>& pre, string& beginWord, int cur, vector<int>& rpath, vector<string>& wordList){
        if(cur == n - 1){ // beginWord){
            vector<string> path;
            for(int i = rpath.size() - 1; i >= 0; i--){
                path.push_back(wordList[rpath[i]]);
                
            }

            res.push_back(move(path));
        }
        else{
            for(auto& p:pre[cur]){
                rpath.push_back(p);
                addRes(res, pre, beginWord, p, rpath, wordList);
                rpath.pop_back();
            }            
        }
        return;
    }
};



//!!! sol1.1, my, bfs with path O(mN), O(mN^2),   N is the length of wordList, m is the maximum word length
// "hit" "hib" ["hib"]
// class Solution {
// public:
//     vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
//         vector<vector<string>> res;
//         bool findShortest = false;
//         unordered_set<string> wordSet(wordList.begin(), wordList.end());
//         queue<vector<string>> q({{beginWord}});
//         int word_size = beginWord.size();
//         while(!q.empty()){
//             unordered_set<string> visited_cur_level;
//             for(int k = q.size(); k > 0; k--){
//                 vector<string> cur_path = q.front(); q.pop();
//                 string cur_string = cur_path.back();
//                 if(cur_string == endWord){
//                     findShortest = true;
//                     res.push_back(cur_path);
//                 }
                
//                 for(int i = 0; i < word_size && !findShortest; i++){
//                     string new_string = cur_string;
//                     for(char c = 'a'; c <= 'z'; c++){
//                         new_string[i] = c;
                        
//                         if(wordSet.count(new_string) > 0){
//                             vector<string> new_path(cur_path);
//                             new_path.push_back(new_string);
//                             q.push(new_path);
//                             visited_cur_level.insert(new_string);
//                         }
//                     }
//                 }
//             }
//             for(auto& v:visited_cur_level) wordSet.erase(v);  
//             if(findShortest) break;
//         }
//         return res;
//     }
// };



// sol1, my, O(mN), O(mN^2),   N is the length of wordList, m is the maximum word length
// "hit" "hib" ["hib"]
// class Solution {
// public:
//     vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
//         vector<vector<string>> res;
//         bool findShortest = false;
//         unordered_set<string> wordSet(wordList.begin(), wordList.end());
//         queue<vector<string>> q({{beginWord}});
//         int word_size = beginWord.size();
//         while(!q.empty()){
//             vector<string> visited_cur_level;
//             for(int k = q.size(); k > 0; k--){
//                 vector<string> cur_path = q.front(); q.pop();
//                 string cur_string = cur_path.back();
//                 if(cur_string == endWord){
//                     findShortest = true;
//                     res.push_back(cur_path);
//                 }
                
//                 for(int i = 0; i < word_size && !findShortest; i++){
//                     string new_string = cur_string;
                    
//                     for(char c = 'a'; c <= 'z'; c++){
//                         new_string[i] = c;
                        
//                         if(wordSet.count(new_string) > 0){
//                             vector<string> new_path(cur_path);
//                             new_path.push_back(new_string);
//                             q.push(new_path);
//                             visited_cur_level.push_back(new_string);
//                         }
//                     }
//                 }
//             }
//             for(auto& v:visited_cur_level) wordSet.erase(v);  
//             if(findShortest) break;
//         }
//         return res;
//     }
// };
