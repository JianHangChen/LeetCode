// sol1, my O(N), O(26)

// "leetcode"
// "codeleet"

// "ee" appear in str2,  it's not possible to change ee to od and t



// a..z
// z..a
// if change a->z, there is two z in str1
// when we change char in str1, should be careful if c1->c1',  c1' also appear in str1

// if there are 26 map, this will happen


// for total alphabet = 3
// abc
// aba
// c->a is enough

// abc
// cba
// fail
// a->c, no space for c->a


// ac
// ca
// ok
// a->b, bc then c->a, ba then b->c: ca



// a..z
// z..z
// if change a->z, this time is safe because z already match in str1 and str2

class Solution {
public:
    bool canConvert(string str1, string str2) {
        if(str1 == str2) return true;
        unordered_map<char, char> m1, m2;
        for(int i = 0; i < str1.size(); i++){
            if(m1.count(str1[i]) > 0){
                if(m1[str1[i]] != str2[i]) return false;
            }
            else{
                m1[str1[i]] = str2[i];
            }
            m2[str2[i]] = str1[i];
        }
        if(m1.size() == 26 && m2.size() == 26) return false;
        return true;
        
    }
};


