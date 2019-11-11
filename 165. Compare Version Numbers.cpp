
//!!! sol2, pure sstream from gy3
#include <sstream>
#include <iostream>

class Solution {
public:
    int compareVersion(string version1, string version2) {
        char dot = '.';
        istringstream v1(version1 + dot), v2(version2 + dot);
        while(v1.good() || v2.good()){ //istringstrea.good()
            int d1 = 0, d2 = 0;
            if(v1.good()) v1 >> d1 >> dot;   // if you want to use this format, dot should be a char
            if(v2.good()) v2 >> d2 >> dot;
            if(d1 > d2) return 1;
            else if(d1 < d2) return -1;
        }
        return 0;
    }
};


#include <sstream>
#include <iostream>

class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<string> v1, v2;
        istringstream f(version1);    // istringstream(not isstring)
        string s;
        while(getline(f, s, '.')){     // getline(f, s, '.')
            v1.push_back(s);
        }
        istringstream f2(version2);
        while(getline(f2, s, '.')){
            v2.push_back(s);
        }
        int l1 = v1.size(), l2 = v2.size(), l = max(l1, l2);
        int c1 = 0, c2 = 0;
        for(int i = 0; i < l; i++){
            if(i < l1) c1 = stoi(v1[i]);
            else c1 = 0;
            if(i < l2) c2 = stoi(v2[i]);
            else c2 = 0;

            if(c1 > c2) return 1;
            if(c1 < c2) return -1;
        }
        return 0;
    }
};
