// sol2, treemap, faster
class Solution {
public:
  string shortestCompletingWord(string licensePlate, vector<string>& words){
    // vector<char> lowercase_license;
    vector<int> license_count(26,0);

    for(char c:licensePlate){
      if(c >= 'a' && c <= 'z' ){
        license_count[c-'a']++;
      }
      else if(c >= 'A' && c <= 'Z'){
        license_count[c-'A']++;
      }
    }

    map<int, vector<string>> m;
    for(auto word:words){
      m[word.size()].push_back(word);
    }



    for(auto& v_word:m){
      for(string& word:v_word.second){ //!!.second is the value of the map
        if(ismatch(license_count, word)){
          return word;
        }      
      }
    }
    return "";
  }

  bool ismatch(vector<int> & license_count, string &word){

    vector<int> word_count(26,0);
    for(char c:word){
      word_count[c-'a']++;
    }
    for(int i = 0; i < 26; i++){
      if(license_count[i] > word_count[i]){
        return false;
      }
    }
    return true;
  }
};




// sol1, 
class Solution {
public:
  string shortestCompletingWord(string licensePlate, vector<string>& words){
    // vector<char> lowercase_license;
    vector<int> license_count(26,0);

    for(char c:licensePlate){
      if(c >= 'a' && c <= 'z' ){
        license_count[c-'a']++;
      }
      else if(c >= 'A' && c <= 'Z'){
        license_count[c-'A']++;
      }
    }


    string ans;
    int ans_len = INT_MAX;

    for(auto word:words){
      if(match(license_count, word) < ans_len){
        ans = word;
        ans_len = ans.size();
      }
    }
    return ans;
  }

  int match(vector<int> & license_count, string &word){
    int l = word.size();

    vector<int> word_count(26,0);
    for(char c:word){
      word_count[c-'a']++;
    }
    for(int i = 0; i < 26; i++){
      if(license_count[i] > word_count[i]){
        return INT_MAX;
      }
    }
    return l;
  }
};
