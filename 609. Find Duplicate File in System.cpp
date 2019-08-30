// O(mn), O(mn)
class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> ans;
        
        unordered_map<string, vector<string>> s;
        
        for(auto path:paths){
            istringstream in(path);
            string rootname = "", file_content = "";
            getline(in, rootname, ' ');
            while(getline(in, file_content, ' ')){ //!!! usage of getline                
                size_t pos = file_content.find_last_of('('); //find_last_of
                string content = file_content.substr(pos + 1, file_content.size() - pos - 2);
                string dir = rootname + "/" + file_content.substr(0, pos);
                
                s[content].push_back(dir);
            }            
        }
        
        for(auto files:s){
            if( files.second.size() > 1) ans.push_back(files.second);
        }
        
        return ans;
    }
};
