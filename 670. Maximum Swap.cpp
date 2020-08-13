//!!! sol1.1, from sol1, O(n), O(n), last of digit 0, 1, 2,..., 9
class Solution {
public:
    int maximumSwap(int num) {
        string num_str = to_string(num); // !!! to_string
        int l = num_str.size();
        vector<int> last(10, -1);
        for(int i = 0; i < l; i++) last[num_str[i] - '0'] = i;
        
        for(int i = 0; i < l; i++){
            int digit = num_str[i] - '0';
            for(int d = 9; d > digit; d--){
                if(last[d] > i){
                    swap(num_str[i], num_str[last[d]]);
                    return stoi(num_str);
                }
            }
        }
        return num;
    }
};

// sol1, my, using array of max idx afterward, O(n), O(n)
// class Solution {
// public:
//     int maximumSwap(int num) {
//         int max_digit = num % 10;
//         int max_digit_idx = 0;
        
//         vector<int> num_array;
//         int i = 0;
//         while(num){
//             int digit = num % 10;
//             num_array.push_back(digit);
//             num /= 10;
//             i++;
//         }
//         reverse(num_array.begin(), num_array.end());
//         int l = num_array.size();
//         vector<int> max_idx(l, l - 1);
//         for(int i = l - 2; i >= 0; i--){
//             if(num_array[i] <= num_array[max_idx[i+1]]) max_idx[i] = max_idx[i+1];
//             else max_idx[i] = i;
//         }
        
//         for(int i = 0; i < l-1; i++){
//             if(num_array[i] != num_array[max_idx[i]]){
//                 swap(num_array[i], num_array[max_idx[i]]);
//                 break;
//             }
//         }
        
//         int res = 0;
//         for(int i = 0; i < l; i++){
//             res = res * 10 + num_array[i];
//         }
//         return res;
//     }

// };
