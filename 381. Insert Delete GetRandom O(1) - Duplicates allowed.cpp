// //!!! sol2, gy use unordered_set for storing idx in v

class RandomizedCollection {
private:
    unordered_map<int, unordered_set<int> > m;
    vector<int> v;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        int not_exist = (m.count(val) == 0 || m[val].size() == 0);

        v.push_back(val);
        m[val].insert(v.size() - 1);

        return not_exist;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(m.count(val) == 0 || m[val].size() == 0) return false;
        
        if(val == v.back()){
            m[val].erase(v.size() - 1);
            v.pop_back();
        }
        else{
            int idx = *m[val].begin(); // idx in v for current val
            int idx_back = v.size() - 1;
            int back_val = v.back();   
            
            m[val].erase(idx);
            v[idx] = back_val; // swap for v.back
            m[back_val].erase(idx_back);
            m[back_val].insert(idx);
            v.pop_back();
        }
                
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        int l = v.size();
        int r = random() % l;
        return v[r];
    }
};






// sol1, my, use extra count for the same value index

// [{1,1}  {1, 2} 2]
//  \      \    \
//  m[1] m[1][2] m[2]
class RandomizedCollection {
private:
    unordered_map<int, unordered_map<int, int>> m;
    vector<vector<int>> v;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        int not_exist = (m.count(val) == 0 || m[val].size() == 0);
        int count_val = m[val].size();
        v.push_back({val, count_val + 1}); // count_val + 1 -th element in m[val]
        m[val][count_val + 1] = v.size() - 1;

        return not_exist;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(m.count(val) == 0 || m[val].size() == 0) return false;
        int count_val = m[val].size();
        
        int idx = m[val][count_val]; // idx in v for current val
        v[idx] = v.back(); // swap for v.back
        m[v[idx][0]][v[idx][1]] = idx; // move v.back map to idx

        v.pop_back();
        
        m[val].erase(count_val);
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        int l = v.size();
        int r = random() % l;
        return v[r][0];
    }
};
