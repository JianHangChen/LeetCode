// my, sol1, using sort, carefull about using of friend bool operator
class Solution {
public:
    class Object{
    public:
        string id;
        string content;
        int idx;
        Object(const string& i, const string& c,const int index): id(i), content(c), idx(index){
        }
        friend bool operator < (const Object& a, const Object& b){
            if(a.content.size() == 0) return true;
            if(b.content.size() == 0) return false;

            if( isdigit(a.content[0]) && isdigit(b.content[0])) return a.idx < b.idx;
            if(isdigit(a.content[0]) && isalpha(b.content[0])) return false;
            if(isdigit(b.content[0]) && isalpha(a.content[0])) return true;
            
            if(isalpha(b.content[0]) && isalpha(a.content[0])){
                if(a.content == b.content) return a.id < b.id;
                return a.content < b.content;
            }
            return true;           
        }
        
    };

    vector<string> logSort(vector<string> &logs) {
        
        vector<Object> v;
        for(int i = 0; i < logs.size(); i++){
            auto p = logs[i].find(" ");
            string content = logs[i].substr(p + 1);
            string id = logs[i].substr(0, p);
            
            v.push_back(Object(id, content, i));
        }
        
        sort(v.begin(), v.end());
        
        vector<string> res;
        for(auto& obj:v) res.push_back(obj.id + " " + obj.content);
        return res;
    }
};

