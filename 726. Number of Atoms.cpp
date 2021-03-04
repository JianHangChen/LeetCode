// !!! sol1.1, from gy similar to sol1, no need for last
// O(n^2), O(n)
class Solution {
public:
    int i, n;
    string countOfAtoms(string formula) {
        map<string, int> m;
        string res;
        i = 0; n = formula.size();
        auto um = count_range(formula);
        for(auto& item:um){
            m[item.first] = item.second;
        }
        for(auto& item:m){
            if(item.second == 1) res += (item.first);
            else res += (item.first) + to_string(item.second);
        }
        
        return res;
    }
    unordered_map<string, int> count_range(string& formula){
        unordered_map<string, int> m;

        while(i < n){
            if(isalpha(formula[i])){
                string key;
                key.push_back(formula[i++]);
                while(i < n && islower(formula[i])){
                    key.push_back(formula[i]);
                    i++;
                }
                int count = 0;
                if(i < n && isdigit(formula[i])){
                    while(i < n && isdigit(formula[i])){
                        count = count * 10 + (formula[i++] - '0');                   
                    }
                }
                else{
                    count = 1;
                }
                m[key] += count;
            }
            else if(formula[i] == '('){
                i++;
                auto um = count_range(formula); 
                for(auto& item:um){
                    m[item.first] += item.second ;
                }
            }
            else{ // i == ")"
                i++;
                int count = 0;
                if(i < n && isdigit(formula[i])){
                    while(i < n && isdigit(formula[i])){
                        count = count * 10 + (formula[i] - '0');
                        i++;
                    }
                }
                else{
                    count = 1;
                }
                for(auto& item:m){
                    m[item.first] = count * item.second ;
                }
                return m;
            }
        }
        return m;
    }
};

// my, sol1, recursion, O(n^2), O(n)

// "K4(ON(SO3)2)2"
// class Solution {
// public:
//     string countOfAtoms(string formula) {
//         map<string, int> m;
//         string res;
//         auto um = count_range(formula, 0, formula.size() - 1);
//         for(auto& item:um){
//             m[item.first] = item.second;
//         }
//         for(auto& item:m){
//             if(item.second == 1) res += (item.first);
//             else res += (item.first) + to_string(item.second);
//         }
        
//         return res;
//     }
//     unordered_map<string, int> count_range(string& formula, int start, int end){
//         unordered_map<string, int> m;
//         int i = start;
//         while(i <= end){
//             if(isalpha(formula[i])){
//                 string key;
//                 key.push_back(formula[i++]);
//                 while(i <= end && formula[i] >= 'a' && formula[i] <= 'z'){
//                     key.push_back(formula[i]);
//                     i++;
//                 }
//                 int count = 0;
//                 if(i <= end && isdigit(formula[i])){
//                     while(i <= end && isdigit(formula[i])){
//                         count = count * 10 + (formula[i++] - '0');                    
//                     }
//                 }
//                 else{
//                     count = 1;
//                 }
//                 m[key] += count;
//             }
//             else{ // i == "()"
//                 int balance = 1; //
//                 int left = ++i;
//                 while( i <= end){
//                     if(formula[i] == '(') balance++;
//                     if(formula[i] == ')') balance--;
//                     i++;
//                     if(balance == 0) break;
//                 }
//                 int right = i-2;
//                 int count = 0;
//                 auto um = count_range(formula, left, right);
                
//                 if(i <= end && isdigit(formula[i])){
//                     while(i <= end && isdigit(formula[i])){
//                         count = count * 10 + (formula[i] - '0');
//                         i++;
//                     }
//                 }
//                 else{
//                     count = 1;
//                 }
//                 for(auto& item:um){
//                     m[item.first] += count * item.second ;
//                 }
                
//             }
//         }
//         return m;
//     }
// };
