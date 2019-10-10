//!!!! sol1, from gy, O(n)
class Solution {
public:
    string removeKdigits(string num, int k) {
      int n = num.size(), remain = n - k;
      string res = "";

      for(char digit:num){
        while(k > 0 && res.size() > 0 && res.back() > digit){
          res.pop_back();
          k--;
        }
        res.push_back(digit);
      }

      res.resize(remain); //carefull of using n - k, k changes after k--
      // while(k > 0){
      //   res.pop_back();
      //   k--;
      // }

      while(res.size() > 0 && res.front() == '0') res.erase(res.begin());

      return res.empty() ? "0" : res;
    }
};



// sol2, from gy2
// class Solution {
// public:
//     string removeKdigits(string num, int k) {
//       string res = "";
//       for(char c:num){
//         while(k > 0 && !res.empty() && res.back() > c){
//           res.pop_back();
//           k--;
//         }

//         if(res.empty() && c == '0'){
//           continue; // no need for k-- because we don't remove '0' in fact
//         }

//         res.push_back(c);
//       }
//       // cannot use resize here such as case 10 1, we left res = "". don't resize to 1
//       //res.resize(remain);

//       while(!res.empty() && k > 0){ 
//         res.pop_back();
//         k--;
//       }

//       return res.empty() ? "0" : res;
//     }
// };
