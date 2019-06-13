class Solution {
public:
    // sol1
    //recap:
    //1. add brackets for (h << 6) operation, it has lower priority
    // 2. the usage of bitset:   (bitset<10> (13) ).count()
    // 3. usage of: to_string(13), stoi("sample")
    
    
    vector<string> readBinaryWatch(int num) {
        vector<string> ans;
        for(int h = 0; h < 12; h++){
            for(int m = 0; m < 60; m++){
                if( bitset<10>((h << 6) + m).count() == num){
                    ans.push_back( to_string(h) + ((m < 10) ? ":0" : ":")  + to_string(m) );
                }
            }
        }
        return ans;
    }
    
    
    //sol2,
    vector<string> readBinaryWatch(int num) {
        vector<int> hours = {1,2,4,8}, minutes = {1,2,4,8,16,32};
        vector<int> hs, ms;
        vector<string> ans;
        for(int i = 0; i <= num; i++){
            hs = generate(hours, i);
            ms = generate(minutes, num - i);
            
            for(auto h:hs){
                if(h > 11) continue;
                for(auto m:ms){
                    if(m > 59) continue;
                    ans.push_back(to_string(h) + ((m < 10) ? ":0":":") + to_string(m));
                }
            }
        }
        return ans;
    }
    
    vector<int> generate(const vector<int> picks, int count){
        vector<int> res;
        helpler(picks, count, 0, 0, res);
        return res;
    }
    void helpler(const vector<int>& picks, int count, int start, int output, vector<int>& res){
        if(count == 0){
            res.push_back(output);
        }
        else{
            for(int i = start; i < picks.size(); i++){
                helpler(picks, count - 1, i + 1, output + picks[i], res);            
            }
        }
        return;
    }
};
