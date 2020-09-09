class SOL{
public:
    vector<string> align(vector<vector<string>>& lines, vector<string>& aligns, int width){
        vector<string> res; // each string of res is a line with [width]
        for(int i = 0; i < lines.size(); i++){
            helpler(lines[i], aligns[i], width, res);
        }
        return res;
    }
    void helpler(vector<string>& line, string direction, int width, vector<string>& res){
        string l;
        for(int i = 0; i < line.size(); i++){
            string word = line[i];
            if(l.size() + 1 + word.size() <= width){
                if(l.size() == 0) l = word;
                else l = l + " " + word;
            }
            else{
                string space(width - l.size(), ' ');
                
                if(direction  == "LEFT"){
                    l = l + space; 
                }
                else{
                    l = space + l;
                }
                res.push_back(l);
                l = "";
                i--;
            }
        }
        if(l != ""){
            string space(width - l.size(), ' ');    
            if(direction  == "LEFT"){
                l = l + space; 
            }
            else{
                l = space + l;
            }
            res.push_back(l);
        }
    }
    
    
};

int main() {
    SOL sol;
    string a = "apple";
    vector<string> line(2, a);
    vector<vector<string>> lines(8, line);
    lines[0] = {"Given", "an", "array", "of", "words", "and", "a", "width",  "maxWidth"};
    vector<string> aligns(8, "LEFT");
    aligns[0] = "RIGHT";
    aligns[3] = "RIGHT";
    
    vector<string> res = sol.align(lines, aligns, 13);
    for(auto& s:res){
        cout << s << endl;
    }
    return -1;
}
