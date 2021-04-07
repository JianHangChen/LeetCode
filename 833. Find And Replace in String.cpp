// !!!!! sol3, O(n+L), O(n+L)
class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        unordered_map<int, int> stringIdxToOpIdx;
        for(int i = 0; i < indexes.size(); i++){
            if(sources[i] == S.substr(indexes[i], sources[i].size())) stringIdxToOpIdx[indexes[i]] = i;
        }
        int i = 0;
        string res = "";
        while(i < S.size()){
            if(stringIdxToOpIdx.count(i) > 0){
                res += targets[stringIdxToOpIdx[i]];
                i += sources[stringIdxToOpIdx[i]].size();
            }
            else{
                res += S[i++];
            }
        }
        return res;
    }
};

// !!! sol2, O(qlogq, nq), O(n), from gy1
// use a pair of index for sort, (don't do quicksort all the time, it's very time consuming to write it)
// n is the length of S, l is the total length of replacement string
// q is the total operation

class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        // indexes is not sorted
        int n = S.size(), q = indexes.size();
        vector<vector<int>> idxs;
        for(int i = 0; i < q; i++){
            idxs.push_back({indexes[i], i});
        }
        sort(idxs.rbegin(), idxs.rend()); // reverse sort, can also use a tree map
        // sort(idxs.begin(), idxs.end(), greater<vector<int>>() );
        
        for(int i = 0; i < q; i++){
            int idx = idxs[i][0], idx_source = idxs[i][1];
            string source = sources[idx_source];
            string target = targets[idx_source];
            if(S.substr(idx, source.size()) == source){
                S = S.substr(0, idx) + target + S.substr(idx + source.size());
            }
        }
        return S;

    }
};
// sol1, my, use a new string, practice quicksort, O(qlogq + n + L), O(n)
// n is the length of S, l is the total length of replacement string
// q is the total operation
class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        string ans = "";
        int prev = 0;
        int n = S.size();
        
        quicksort(indexes, sources, targets, 0, indexes.size() - 1);
        
        
        int i = 0, j = 0; 
        while(i < S.size()){
            if(j >= indexes.size() || i != indexes[j]){
                ans += S[i++];
            }
            else{
                if(S.substr(i, sources[j].size()) == sources[j]){
                    i += sources[j].size();
                    ans += targets[j++];
                }
                else{
                    ans += S.substr(i, sources[j].size());
                    i += sources[j++].size();
                }
            }
            
        }
        return ans;
    }
    void quicksort(vector<int>& indexes, vector<string>& sources, vector<string>& targets, int start, int end){
        if(start >= end) return;
        int n = indexes.size();
        
        int pivot = partition(indexes, sources, targets, start, end);
        quicksort(indexes, sources, targets, start, pivot - 1);
        quicksort(indexes, sources, targets, pivot+1, end);
        
    }
    void allswap(int i, int j, vector<int>& indexes, vector<string>& sources, vector<string>& targets){
        swap(indexes[i], indexes[j]);
        swap(sources[i], sources[j]);
        swap(targets[i], targets[j]);
    }
    int partition(vector<int>& indexes, vector<string>& sources, vector<string>& targets, int start, int end){
        int tmp = start + rand() % (end - start + 1);
        allswap(start, tmp, indexes, sources, targets);
        int val  = indexes[start];
        int i = start + 1, j = end;
        while(i <= j){
            if(indexes[i] > val && indexes[j] <= val){
                allswap(i++, j--, indexes, sources, targets);
            }
            else if(indexes[i] <= val){
                i++;
            }
            else{
                j--;
            }
        }
        allswap(start, j, indexes, sources, targets);
        return j;
    }
    
};


