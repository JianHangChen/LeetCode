// sol2 bfs + reverse dfs, O(mN), O(mN) by ch9,linghu, TLE
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
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
                            q.push(new_string);
                            pre[new_string].insert(cur_string);
                            visited_cur_level.insert(new_string);
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
            res.push_back(path);
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




// sol1.1, my, O(mN), O(mN^2),   N is the length of wordList, m is the maximum word length
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
