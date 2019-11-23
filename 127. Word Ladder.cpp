
// // !!!! sol2 bi-diectionary bfs, O(mN), O(mN), N is the length of wordList, m is the maximum word length
// https://leetcode.com/problems/word-ladder/discuss/40707/C%2B%2B-BFS

class Solution{
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList){
        int l = beginWord.size(), res = 1;
        unordered_set<string> words(wordList.begin(), wordList.end()), visited_head({beginWord}), visited_tail({endWord});
        if(words.count(endWord) == 0) return 0;
        queue<string> q_head({beginWord}), q_tail({endWord});
        
        while(!q_head.empty()){
            for(int k = q_head.size(); k > 0; k--){
                string cur = q_head.front(); q_head.pop();
                if(visited_tail.count(cur) > 0) return res;
                for(int i = 0 ; i < l; i++){
                    string new_string = cur;
                    for(char c = 'a'; c <= 'z'; c++){
                        new_string[i] = c;
                        if(words.count(new_string) > 0 && visited_head.count(new_string) == 0){
                            visited_head.insert(new_string);
                            q_head.push(new_string);
                        }
                    }
                }
            }
            if(q_head.size() > q_tail.size() || q_head.empty()){
                swap(q_head, q_tail);
                swap(visited_head, visited_tail);
            }
            res++;
        }
        return 0;
    }     
};


//!!!!! sol1.1, gy2, bfs  cleverer, no need to use visited set
// O(mN), O(mN), N is the length of wordList, m is the maximum word length
// class Solution { 
// public:
//     int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
//         unordered_set<string> s(wordList.begin(), wordList.end());
//         if(s.count(endWord) == 0) return 0; //!! increase speed
//         queue<string> q({beginWord});
//         int l  = beginWord.size();
//         int level = 1;
//         while(!q.empty()){            
//             for(int k = q.size(); k > 0; k--){
//                 string cur = q.front(); q.pop(); 
//                 if(cur == endWord) return level;
//                 for(int i = 0; i < l; i++){
//                     string new_string = cur;
//                     for(char c = 'a'; c <= 'z'; c++){
//                         if(c == cur[i]) continue;
//                         new_string[i] = c;
//                         if(s.count(new_string) > 0){
//                             q.push(new_string);
//                             s.erase(new_string);
//                         }
//                     }
//                 }
//             }
//             level++;
//         }
//         return 0;
//     }
// };




// sol1, gy2 hint, my dfs, O(mN), O(mN), N is the length of wordList, m is the maximum word length
// class Solution {
    
// public:
//     int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
//         unordered_set<string> s(wordList.begin(), wordList.end());
//         unordered_set<string> visited({beginWord});
//         if(s.count(endWord) == 0) return 0; //!! increase speed
        
//         queue<string> q({beginWord});
        
//         int level = 1;
//         int l  = beginWord.size();
        
//         string cur;
//         while(!q.empty()){            
//             for(int k = q.size(); k > 0; k--){
//                 cur = q.front(); q.pop(); 
//                 if(cur == endWord) return level;

//                 for(int i = 0; i < l; i++){
//                     string new_string = cur;
//                     for(int j = 0; j < 26; j++){
//                         char c = 'a' + j; if(c == cur[i]) continue;
//                         new_string[i] = c;
//                         if(s.count(new_string) > 0 && visited.count(new_string) == 0){
//                             q.push(new_string);
//                             visited.insert(new_string); // here position of visited is very important. you should add to the visited set to avoid adding the same item to the queue again and again. Don't put the addvisited when you pop queue
//                         }
//                     }
//                 }
//             }
//             level++;
//         }
        
//         return 0;
//     }
    
// };
