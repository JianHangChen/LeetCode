// sol2, stack, O(n), O(n)

class Solution{
public:
    vector<int> exclusiveTime(int n, vector<string>& logs){
        vector<int> res(n, 0);
        stack<int> s;
        int id, timestamp;
        string temp, status;

        int time;
        
        for(int i = 0; i < logs.size(); i++){
            string log = logs[i];
            istringstream stream(log);
            getline(stream,temp, ':'); id = stoi(temp);
            getline(stream,temp, ':'); status = temp;
            getline(stream,temp, ':'); timestamp = stoi(temp);            
            
            if(status == "start"){
                if(!s.empty())
                    res[s.top()] += timestamp - time;
                time = timestamp;
                s.push(id);
            }
            else{
                timestamp++; //!!!
                res[s.top()] +=  timestamp - time;
                s.pop();
                time = timestamp;
            }
        }
        return res;
    }
};





// sol1, very slow stack, from sol1, O(t_max), O(n);
// class Solution {
// public:
//     vector<int> exclusiveTime(int n, vector<string>& logs) {
//         vector<int> res(n, 0);
//         stack<int> s;
        
//         string log = logs[0];
//         istringstream streams(log);            
//         string temp, status;
//         int id, timestamp;

//         getline(streams, temp, ':'); id = stoi(temp);
//         getline(streams, temp, ':'); status = temp;
//         getline(streams, temp, ':'); timestamp = stoi(temp);
        
//         int time = timestamp;
//         s.push(id);
        
//         for(int i = 1; i < logs.size(); i++){
//             istringstream streams(logs[i]);
//             getline(streams, temp, ':'); id = stoi(temp);
//             getline(streams, temp, ':'); status = temp;
//             getline(streams, temp, ':'); timestamp = stoi(temp);
        
//             while(time < timestamp){
//                 res[s.top()]++;
//                 time++;
//             }
            
//             if(status == "start"){
//                 s.push(id);
//             }
//             else{
//                 res[s.top()]++;
//                 time++;
//                 s.pop();
//             }            
//         }
//         return res;
//     }
// };
