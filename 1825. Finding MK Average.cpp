// sol1, 
// https://leetcode.com/problems/finding-mk-average/discuss/1152724/C%2B%2B-Balance-3-Multisets
class MKAverage {
public:
    vector<int> v;
    multiset<int> minset, midset, maxset;
    int m, k;
    long long sum = 0;
    int pos = 0;
    MKAverage(int m, int k): m(m), k(k) {
        // this->m = m;
        // this->k = k;
        v = vector<int> (m);
    }

    void Remove(int num){ // O(log(m))
        if(num <= *minset.rbegin()){
            minset.erase(minset.find(num));
        }
        else if(num <= *midset.rbegin()){
            sum -= num;
            midset.erase(midset.find(num));
        }
        else{
            maxset.erase(maxset.find(num));
        }
        if(minset.size() < k){
            sum -= *midset.begin();
            minset.insert(*midset.begin());
            midset.erase(midset.begin());
        }
        if(midset.size() < m - 2 * k){
            sum += *maxset.begin();
            midset.insert(*maxset.begin());
            maxset.erase(maxset.begin());
        }
        
    }
    void Add(int num){ // O(logm)
        minset.insert(num);
        if(minset.size() > k){
            sum += *minset.rbegin();
            midset.insert(*minset.rbegin());
            minset.erase(prev(minset.end()) );
        }
        if(midset.size() > m - 2 * k){
            sum -= *midset.rbegin();
            maxset.insert(*midset.rbegin());
            midset.erase(prev(midset.end()));
        }
        
    }
    
    void addElement(int num) {
        if(pos >= m){
            Remove(v[pos % m]);
        }
        v[pos++%m] = num;
        Add(num);
    }
    
    int calculateMKAverage() { // O(1)
        if(pos < m) return -1;
        return sum / (m-2*k);
    }
};
