//!!! sol1.2, using priority queue
// O(nlogn), O(n)
// https://www.youtube.com/watch?v=o8emK4ehhq0
// 先从最基础的brute force，观察loop，思考如何优化
class Solution {
public:
    struct Worker{
        int quality;
        int wage;
        double ratio;
        Worker(int q, int w):quality(q), wage(w){
            ratio = double(w) / q;
        }
        bool operator <(Worker& worker) const{
            if(ratio == worker.ratio) return quality < worker.quality;
            return ratio < worker.ratio;
        }
        
    };
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        int n = quality.size();
        vector<Worker> workers;
        for(int i = 0; i < n; i++){
            workers.push_back( Worker(quality[i], wage[i]));            
        }
        sort(workers.begin(), workers.end()); // nlogn
        
        double res = DBL_MAX, sum = 0;
        priority_queue<int> pq;

        for(int i = 0; i < n; i++){ // O(n)
            pq.push(workers[i].quality); // O(logK)
            sum += workers[i].quality;
            if(pq.size() > K){
                sum -= pq.top();
                pq.pop();                
            }
            if(pq.size() == K){
                res = min(res, workers[i].ratio * sum);
            }
        }
            
        return res;
    }
};

// sol1.1, change from sol1 to speed up the process, we only sort quality once
// for each ratio, pick up the smallest K quality
// class Solution {
// public:
//     double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
//         int n = quality.size();
//         vector<vector<int>> v;
//         for(int i = 0; i < n; i++){
//             v.push_back({quality[i], wage[i]});            
//         }
//         sort(v.begin(), v.end()); // nlogn
        
//         double res = DBL_MAX;
//         for(int i = 0; i < n; i++){ // O(n)
//             double ratio = (double)v[i][1] / v[i][0];
            
//             vector<double> offers;
//             double sum = 0;
//             int count = 0;
//             for(int j  = 0; j < n; j++){ // O(n)->  O(k)
//                 if(ratio * (double)v[j][0] >= v[j][1]){
//                     sum += ratio * (double)v[j][0];
//                     count++;
//                     if(count == K){
//                         res = min(res, sum);
//                         break;
//                     }
//                 }
//             }
//         }
//         return res;
//     }
// };



// sol1, O(n^2logK), O(n)
// https://www.youtube.com/watch?v=o8emK4ehhq0
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        int n = quality.size();
        double res = DBL_MAX;
        for(int i = 0; i < n; i++){ // O(n)
            double ratio = (double)wage[i] / quality[i];
            
            vector<double> offers;
            for(int j  = 0; j < n; j++){ // O(n)
                if(ratio * quality[j] >= wage[j]) offers.push_back(ratio * quality[j]);
            }
            priority_queue<double> pq;
            double sum = 0;
            if(offers.size() < K) continue;
            for(int t = 0; t < offers.size(); t++){ // O(nlogK)
                sum += offers[t];
                pq.push(offers[t]);
                if(pq.size() > K){
                    sum -= pq.top();
                    pq.pop();
                }
                if(pq.size() == K) res = min(res, sum);
            }            
        }
        return res;
        
    }
};

// quality 10 20   5
// wage    70 50   30
// ratio   7  2.5  6

// totalwage
// = max(wage1/quality1, ... , wagek/qualityk) * (quality1 + quality2 + ... qualityk)
// = max(ratio1, ratio2, ..., ratiok) * (quality1 + quality2 + ... qualityk) 

// 5 30 6 -> 30
// 10 70 7-> 35 + 70 = 105
// 20 50 2.5-> 

// minimize the total wage sum
// the final ratio depend on the lowest wage/quality ratio in the group 
