
//!!! sol2.1, selection sort, revised from sol2, O(n), O(n)
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        sort(0, points.size() - 1, K, points);
        vector<vector<int>> res(points.begin(), points.begin()+K);
        return res;
    }
    
    void sort(int start, int end, int K, vector<vector<int>>& points){
        if(start >= end) return;
        int pivot = start + rand() % (end - start + 1);
        swap(points[start], points[pivot]);
        int i = start + 1, j =end;
        
        while(i <= j){
            if(dist(points[start]) < dist(points[i]) && dist(points[start]) > dist(points[j]) ){
                swap(points[i++], points[j--]);
            }
            else if(dist(points[start]) >= dist(points[i])){
                i++;
            }
            else{
                j--;
            }
        }
        swap(points[start], points[j]);
        int left_len = j - start + 1;
        if(left_len == K) return;
        else if(left_len > K) sort(start, j - 1, K, points);
        else sort(j+1, end, K - left_len, points);   
    }
    
    int dist(vector<int>& point){
        return pow(point[0], 2) + pow(point[1], 2);
    }
    
};

// sol2, slection sort, O(n), O(n)
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> res;
        int n = points.size();
        select(res, points, 0, n - 1, K);
        return res;
    }
    
    void select(vector<vector<int>>& res, vector<vector<int>>& points, int start, int end, int K){
        if(start > end) return;
        
        int pivot = start + rand() % (end - start + 1);        
        
        swap(points[start], points[pivot]);

        int i = start + 1, j = end;
        while(i <= j){
            if(dist(points[start]) < dist(points[i]) && dist(points[start]) > dist(points[j])){
                swap(points[i++], points[j--]);
            }
            else if(dist(points[start]) >= dist(points[i])){
                i++;
            }
            else{
                j--;
            }
        }
        swap(points[start], points[j]);
        if(j - start + 1 > K){
            select(res, points, start, j - 1, K);
        }
        else{
            res.insert(res.end(), points.begin() + start, points.begin() + j + 1);
            select(res, points, j + 1, end, K - (j - start + 1));
        }
    }
    int dist(vector<int>& point){
        return point[0] * point[0] + point[1] * point[1];
    }
};

my sol1, map, O(nlogn), O(n)
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        map<int, vector<vector<int>> > m;
        for(auto& point:points){
            m[(pow(point[0], 2) + pow(point[1], 2))].push_back(point);
        }
        int count = 0;
        
        vector<vector<int>> res;
        
        for(auto& ele:m){
            if(count <= K){
                res.insert(res.end(), ele.second.begin(), ele.second.end());        
                count += ele.second.size();
                if(count == K) return res;
            }            
        }
        return {};
    }
};
