

// sol1, my
// employee number O(N), relationship O(M), department O(K)

// O(N + M + K), O(N + M + K)

class Solution {
public:

    unordered_map<int, string> id2department;
    unordered_map<string, int> department2count;
    unordered_map<string, unordered_set<int>> department2with_other_friend_id;
    
    vector<string> departmentStatistics(vector<string> &employees, vector<string> &friendships) {
        for(auto& employee:employees){
            auto pos = employee.find(",");

            int id = stoi( employee.substr(0,pos) );
            pos = employee.find_last_of(" ");
            string department = employee.substr(pos + 1);
            
            
            id2department[id] = department;
            department2count[department]++;
        }
        

        for(string& friendship:friendships){
            auto pos = friendship.find(",");
            int id1 = stoi(friendship.substr(0, pos ));
            int id2 = stoi(friendship.substr(pos+2));
            
            if(id2department[id1] != id2department[id2]){
                
                department2with_other_friend_id[id2department[id1]].insert(id1);
                department2with_other_friend_id[id2department[id2]].insert(id2);
            }
        }
        
        vector<string> ans;
        for(auto& item:department2count){
            int total_count = item.second;
            string department_name = item.first;
            int count_with_other_friend = department2with_other_friend_id[department_name].size();
            
            ans.push_back(department_name + ": " + to_string(count_with_other_friend) + " of " +  to_string(total_count)  );
        }
        
        return ans;
    }
};
