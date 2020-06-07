// !!! sol1, from gy1
// O(n^2), O(n) sort and insert, preserve order information when adding smaller element

struct CMP{
  bool operator()(vector<int>& a, vector<int>& b) const{
    return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
  }
} cmp;

class Solution{
public:

  // static bool cmp(vector<int>& a, vector<int>& b){
  //   return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
  // };

  vector<vector<int>> reconstructQueue(vector<vector<int>>& people){
    vector<vector<int>> res;
    sort(people.begin(), people.end(), cmp);


    for(auto person:people){
      res.insert(res.begin() + person[1], person);
    }
    return res;
  }

};


// ! sol2, from gy3
// the same but inline erase, O(nlogn), O(1)

struct CMP{
  bool operator()(vector<int>& a, vector<int>& b) const{
    return a[0] > b[0] || a[0] == b[0] && a[1] < b[1];
  }
} cmp;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
      
      sort(people.begin(), people.end(), cmp);

      int n = people.size();
      for(int i = 0; i < n; i++){
        auto tmp = people[i];
        if(tmp[1] != i){
          people.erase(people.begin() + i); 
          people.insert(people.begin() + tmp[1], tmp);// always insert to existing element or the last element.
        }
      }
      return people;
    }
};
