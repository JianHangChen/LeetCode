// !!! sol1.1, my, O(nlogk), O(k), use array<int,3> to reduce time, faster than vector
// similar to amazon oa
double diff(double x, double y){
    return (x + 1) / (y + 1) - x / y;
}

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        vector<array<double, 3> > triple;
        double total = 0;
        for(auto& c:classes){
            double x = c[0], y = c[1];
            total += x / y;
            triple.push_back( {diff(x, y), x, y });
        }     
        
        priority_queue<array<double,3>> pq(triple.begin(), triple.end());
        while(extraStudents){
            auto a = pq.top(); pq.pop();
            total += a[0];
            double x = a[1] + 1, y = a[2] + 1;
            pq.push({diff(x, y), x, y }); 
            extraStudents--;
        }
        int n = classes.size();
        return total/n;
    }
};


// sol1, my, O( (n+k)logk ), O(k)
// k classes, n extrastudent
// similar to amazon oa
// double diff(double x, double y){
//     return (x + 1) / (y + 1) - x / y;
// }

// class Solution {
// public:
//     double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        
//         vector<pair<double,  array<int, 2> >> triple;
                    
//         double total = 0;

//         for(auto& c:classes){
//             total += (double)c[0] / c[1];
//             triple.push_back( {diff(c[0], c[1]), {c[0], c[1]}});
//             // pq.push({diff(c[0], c[1]), {c[0], c[1]}});
//         }     
        
        
//         priority_queue<pair<double, array<int, 2>>> pq(triple.begin(), triple.end());

        

        
//         while(extraStudents){
//             auto a = pq.top(); pq.pop();
//             total += a.first;
//             int x = a.second[0] + 1, y = a.second[1] + 1;
//             pq.push({diff(x, y), {x, y}}); 
//             extraStudents--;
//         }
//         int n = classes.size();
//         return total/n;
//     }
// };


// sol1, my, O(klogn), O(n), tle
// classes n, students k
// similar to amazon oa
// double diff(vector<int>& a){
//     double x = a[0], y = a[1];
//     return (x + 1) / (y + 1) - x / y;
    
// }

// struct CMP{
//     bool operator()(vector<int>& a, vector<int>& b){
//         return diff(a) < diff(b);
//     }    
// };

// class Solution {
// public:
//     double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
//         priority_queue<vector<int>, vector<vector<int>>,  CMP> pq;
//         for(auto& c:classes){
//             pq.push(c);
//         }
        
//         while(extraStudents){
//             auto a = pq.top(); pq.pop();
//             pq.push({a[0]+1, a[1]+1});           
//             extraStudents--;
//         }
//         double res = 0;
//         int n = classes.size();
//         while(!pq.empty()){
//             auto a = pq.top(); pq.pop();
//             res += (double)a[0] / a[1];
//         }
//         return res/n;
//     }
// };
