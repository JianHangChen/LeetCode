// sol2.1, !!!! O(n)m O(1), add "," to string

class Solution{
public:
  bool isValidSerialization(string preorder){
    preorder += ",";

    int slot = 1;

    for(int i = 0; i < preorder.size(); i++){
      if(preorder[i] == ','){
        slot--;
        if(slot < 0) return false;
        if(preorder[i-1] != '#') slot += 2;
      }
    }
    return slot == 0;
  }
};



// sol2, ! O(n)m O(1), slot, from sol1

class Solution{
public:
  bool isValidSerialization(string preorder){
    int slot = 1;

    for(int i = 0; i < preorder.size(); i++){
      slot--;
      if(slot < 0) return false;  
      if(isdigit(preorder[i])){
        slot += 2;
        while(i < preorder.size() && isdigit(preorder[i])) i++;
      }
      else{
        i++;
      }
    }
    return slot == 0;
  }
};


// sol1.1, my, !!!, use istringstream, O(n) O(n)

class Solution{
public:
   bool isValidSerialization(string preorder){
    istringstream in(preorder);
    vector<string> v;
    string t = "";
    while(getline(in, t, ',')) v.push_back(t);

    stack<int> s;
    for(int i = 0; i < v.size(); i++){
      string t = v[i];
      if(!s.empty()){
        if(s.top() == 0) s.top()++;
        else s.pop();
      }
      else{
        if(i != 0) return false;
      }

      if(t != "#") s.push(0);
    }
    return s.empty();
   }
};


// sol1, my O(n) O(n)
class Solution{
public:
  bool isValidSerialization(string preorder){
    int n = preorder.size();
    stack<int> s;

    int j;
    for(int i = 0; i < n; i = j+1){
      j = i;
      while(isdigit(preorder[j]) || preorder[j] == '#') j++;

      if(!s.empty() ){
         if(s.top() == 0){
          s.top()++;
         }
         else{
          s.pop();
         }
      }
      else{
        if(i != 0) return false;
      }

      if(preorder[i] != '#'){
        s.push(0); // carefull, use s.push(0), don't use stack.push()
      }
    }

    return s.empty();
  }
};
