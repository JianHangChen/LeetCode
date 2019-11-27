// !! sol3, map+set, the same as sol2, but less code
// from https://leetcode.com/problems/dinner-plate-stacks/discuss/366331/C%2B%2BPython-Two-Solutions
class DinnerPlates{
private:
  int CAPACITY;
  map<int, vector<int>> plates;
  set<int> has_space;
public:
  DinnerPlates(int capacity){
    CAPACITY = capacity;
  }
  void push(int val){
    if(has_space.empty()) has_space.insert(plates.size());
    int idx = *(has_space.begin());
    plates[idx].push_back(val);
    if(plates[idx].size() == CAPACITY) has_space.erase(idx); 
  }
  int pop(){
    if(plates.empty()) return -1;
    return popAtStack( (plates.rbegin())->first );
  }
  int popAtStack(int index){
    if(plates.count(index) == 0 || plates[index].empty()) return -1;
    if(plates[index].size() == CAPACITY) has_space.insert(index);
    int val = plates[index].back(); plates[index].pop_back();
    if(plates[index].empty()) plates.erase(index);
    return val;
  }
};

// !! sol2, my, two set , O(log(MAX_IDX)) O(N)
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
        if(has_space.empty()){
          plates.push_back({});
          has_space.insert(plates.size() - 1);
        }
        for(auto v:has_space){
          if(plates[v].empty()) has_val.insert(v); 
          plates[v].push_back(val);
          if(plates[v].size() == CAPACITY) has_space.erase(v); //O(log(MAX_IDX))          
          return;
        }

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
// class DinnerPlates {
// private:
//     vector<vector<int>> plates;
//     int CAPACITY;
// public:
//     DinnerPlates(int capacity) {  // O(MAX_IDX)
//         CAPACITY = capacity;
//     }
    
//     void push(int val) {
//         for(int i = 0; i < plates.size(); i++){ // O(MAX_IDX)!!!!
//           if(plates[i].size() < CAPACITY){
//             plates[i].push_back(val);
//             return;
//           }
//         }
//         plates.push_back({val});
//     }
    
//     int pop() {
//         for(int i = plates.size() - 1; i >= 0; i--){ // O(MAX_IDX)!!!!
//           if(plates[i].size() > 0){
//             int val = plates[i].back(); plates[i].pop_back();
//             return val;
//           }
//         }
//         return -1;
//     }
    
//     int popAtStack(int index) {
        
//         if(index < plates.size() && index >= 0 && plates[index].size() > 0){
//           int val = plates[index].back(); plates[index].pop_back();
//           return val;
//         }
//         return -1;
//     }
// };
