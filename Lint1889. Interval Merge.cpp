
//!!! sol1, from ch9, O(n), O(n)
// A2 = 'ab'  B1 = 'aba' carefull!!!
class Solution {
public:

    bool MergeJudge(string &interval_A, string &interval_B) {
        string A1, A2, B1, B2;
        int nA = interval_A.size(), nB = interval_B.size();
        
        // int i = find(interval_A.begin(), interval_A.end(), ',') - interval_A.begin();
        int i = interval_A.find(',');
        
        A1 = interval_A.substr(1, i-1);
        A2 = interval_A.substr(i+1, nA - i - 2);
        
        i = interval_B.find(',');
        B1 = interval_B.substr(1, i-1);
        B2 = interval_B.substr(i+1, nB - i - 2);

        char a1 = interval_A[0], a2=interval_A.back();
        char b1 = interval_B[0], b2 = interval_B.back();
        
        if(A1 > B1){
            swap(A1, B1);
            swap(A2, B2);
            swap(a1, b1);
            swap(a2, b2);
        }

        if(A2 > B1) return true;
        else if(A2 == B1){
            if(a2 == ')' && b1 == '(') return false;
            else return true;
        }
        else{
            A2.push_back('a');
            if(A2 == B1 && a2 == ']' && b1 == '[') return true;
            
        }
        return false;
    }
};
