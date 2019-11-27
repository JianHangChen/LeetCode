// sol2, my, set , O(log(MAX_IDX)) O(N)
class DinnerPlates {
private:
    vector<vector<int>> plates;
    int CAPACITY;
    set<int> has_space;
    set<int, greater<int> > has_val;
public:
    DinnerPlates(int capacity) {
        CAPACITY = capacity;
    }
    
    void push(int val) { //O(log(MAX_IDX))
        for(auto v:has_space){
          if(plates[v].empty()) has_val.insert(v); 
          plates[v].push_back(val);
          if(plates[v].size() == CAPACITY) has_space.erase(v); //O(log(MAX_IDX))
          
          return;
        }
        plates.push_back({val});
        has_val.insert(plates.size() - 1);
        if(plates.back().size() < CAPACITY) has_space.insert(plates.size() - 1);

    }
    
    int pop() { //O(log(MAX_IDX))
        for(auto i:has_val){
          if(plates[i].size() == CAPACITY) has_space.insert(i); //O(log(MAX_IDX))
          int val = plates[i].back(); plates[i].pop_back();
          if(plates[i].size() == 0) has_val.erase(i);
          return val;
        }
        return -1;
    }
    
    int popAtStack(int index) { //O(log(MAX_IDX))
        
        if(index >= 0 && index < plates.size() && plates[index].size() > 0){ //O(log(MAX_IDX))
          if(plates[index].size() == CAPACITY) has_space.insert(index);
          int val = plates[index].back(); plates[index].pop_back();
          if(plates[index].size() == 0) has_val.erase(index);
          return val;
        }
        return -1;
    }
};


// sol1, my, TLE
class DinnerPlates {
private:
    vector<vector<int>> plates;
    int CAPACITY;
public:
    DinnerPlates(int capacity) {  // O(MAX_IDX)
        CAPACITY = capacity;
    }
    
    void push(int val) {
        for(int i = 0; i < plates.size(); i++){ // O(MAX_IDX)!!!!
          if(plates[i].size() < CAPACITY){
            plates[i].push_back(val);
            return;
          }
        }
        plates.push_back({val});
    }
    
    int pop() {
        for(int i = plates.size() - 1; i >= 0; i--){ // O(MAX_IDX)!!!!
          if(plates[i].size() > 0){
            int val = plates[i].back(); plates[i].pop_back();
            return val;
          }
        }
        return -1;
    }
    
    int popAtStack(int index) {
        
        if(index < plates.size() && index >= 0 && plates[index].size() > 0){
          int val = plates[index].back(); plates[index].pop_back();
          return val;
        }
        return -1;
    }
};
