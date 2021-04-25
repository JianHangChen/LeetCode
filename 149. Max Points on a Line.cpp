// !!! sol2.3, O(n^2), O(n) 
// 1. gcd + add duplication
// 2. for different combination of lines for each node, no set needed
// 3. use  string unordered set
// http://zxi.mytechroad.com/blog/geometry/leetcode-149-max-points-on-a-line/
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size(), res = 1;
        for(int i = 0; i < n; i++){
            int x1 = points[i][0], y1 = points[i][1];
            int duplicate = 1;
            unordered_map<string, int> count;
            int maxcount = 0;
            for(int j = i+1; j < n; j++){
                int x2 = points[j][0], y2 = points[j][1];
                if(x1 == x2 && y1 == y2) duplicate++;
                else{
                    int dx = x1 - x2, dy = y1 - y2;
                    // get slope
                    int g = gcd(dx, dy);
                    string key = to_string(dx/g) + "#" + to_string(dy/g);
                    //这两种特殊情况其实可以通过gcd就处理了，所有的(0, dy)都会自动map到(0, 1)   
                    maxcount = max(maxcount, ++count[key]);
                }               
            }
            res = max(res, maxcount + duplicate);
        }
        return res;
    }
    int gcd(int a, int b){
        while(b != 0){
            int c = a % b;
            a = b;
            b = c;
        }
        return a;
    }
};

// !!! sol2.2, O(n^2), O(n) 
// 1. gcd + add duplication
// 2. for different combination of lines for each node, no set needed
// 3. use  string unordered set
// http://zxi.mytechroad.com/blog/geometry/leetcode-149-max-points-on-a-line/
// class Solution {
// public:
//     int maxPoints(vector<vector<int>>& points) {
//         int n = points.size(), res = 1;
//         for(int i = 0; i < n; i++){
//             int x1 = points[i][0], y1 = points[i][1];
//             int duplicate = 1;
//             unordered_map<string, int> count;
//             int maxcount = 0;
//             for(int j = i+1; j < n; j++){
//                 int x2 = points[j][0], y2 = points[j][1];
//                 if(x1 == x2 && y1 == y2) duplicate++;
//                 else{
//                     int dx = x1 - x2, dy = y1 - y2;
//                     // get slope
//                     string key;
//                     if(dx == 0){
//                         key = "0#"; //这两种特殊情况其实可以通过gcd就处理了，所有的(0, dy)都会自动map到(0, 1)   
//                     }
//                     else if(dy == 0){
//                         key = "#0";
//                     }
//                     else{
//                         int g = gcd(dx, dy);
//                         key = to_string(dx/g) + "#" + to_string(dy/g);      
//                     }
//                     maxcount = max(maxcount, ++count[key]);
//                 }               
//             }
//             res = max(res, maxcount + duplicate);
//         }
//         return res;
//     }
//     int gcd(int a, int b){
//         while(b != 0){
//             int c = a % b;
//             a = b;
//             b = c;
//         }
//         return a;
//     }
// };

// sol2.1, O(n^2), O(n) 
// add duplication
// for different combination of lines for each node, no set needed
// class Solution {
// public:
//     int maxPoints(vector<vector<int>>& points) {
        
//         int n = points.size();
//         // y = kx + b
//         // if(x1 == x2) x = x1;
        
//         // k = (y1-y2) / (x1-x2) 
//         // b = y - kx
//         double k, b;
//         int res = 1;
//         for(int i = 0; i < n; i++){
//             int x1 = points[i][0], y1 = points[i][1];
//             map<vector<double>, int> countLine; 
            
//             int duplicate = 1; // for duplicate
//             int maxpoint = 0; // no duplicate, other points with the same k b
//             for(int j = i + 1; j < n; j++){
//                 int x2 = points[j][0], y2 = points[j][1];
                
//                 if(x1 == x2 && y1 == y2){
//                     duplicate++;
//                 }
//                 else{
//                     if(x1 == x2){
//                         k = INT_MAX;
//                         b = x1;
//                     }
//                     else{
//                         k = ((double)y1-y2) / (x1-x2);
//                         b = y1 - k * x1;
//                     }   
//                     maxpoint = max(maxpoint, ++countLine[{k, b}]);                                    
//                 }
//             }
//             res = max(res, maxpoint + duplicate ); // 这个逻辑应该挪到最后这里，而不是在countLine那里，比如说duplicate点出现在最后   
//         }
        

//         return res;        
//     }
// };


// sol2, O(n^2), O(n) for different combination of lines for each node
// class Solution {
// public:
//     int maxPoints(vector<vector<int>>& points) {
        
//         int n = points.size();
//         // y = kx + b
//         // if(x1 == x2) x = x1;
        
//         // k = (y1-y2) / (x1-x2) 
//         // b = y - kx
//         double k, b;
//         int res = 1;
//         for(int i = 0; i < n; i++){
//             int x1 = points[i][0], y1 = points[i][1];
//             map<vector<double>, int> countLine; 
//             for(int j = i + 1; j < n; j++){
//                 int x2 = points[j][0], y2 = points[j][1];
//                 if(x1 == x2){
//                     k = INT_MAX;
//                     b = x1;
//                 }
//                 else{
//                     k = ((double)y1-y2) / (x1-x2);
//                     b = y1 - k * x1;
//                 }
                
//                 countLine[{k, b}]++;                
                
//                 res = max(res, countLine[{k, b}] + 1 );
//             }
            
//         }
        

//         return res;        
//     }
// };

//my sol1,  O(n^2), O(n^2)
// use a set to remove duplicate for the same k, b, very bad
// class Solution {
// public:
//     int maxPoints(vector<vector<int>>& points) {
//         map<vector<double>, set<vector<int>>> countLine; 
//         int n = points.size();
//         // y = kx + b
//         // if(x1 == x2) x = x1;
        
//         // k = (y1-y2) / (x1-x2) 
//         // b = y - kx
//         double k, b;
//         int res = 1;
//         for(int i = 0; i < n; i++){
//             int x1 = points[i][0], y1 = points[i][1];
//             for(int j = i + 1; j < n; j++){
//                 int x2 = points[j][0], y2 = points[j][1];
//                 if(x1 == x2){
//                     k = INT_MAX;
//                     b = x1;
//                 }
//                 else{
//                     k = ((double)y1-y2) / (x1-x2);
//                     b = y1 - k * x1;
//                 }
//                 countLine[{k, b}].insert({x1, y1});
//                 countLine[{k, b}].insert({x2, y2});
//                 res = max(res, (int)countLine[{k, b}].size());
//             }
            
//         }
        

//         return res;        
//     }
// };
