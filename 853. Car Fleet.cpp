

// sol3, from gy2, using priority queue, O(nlogn), O(n)
class Solution{
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed){
        priority_queue<pair<int, double>> time;
        for(int i = 0; i < position.size(); i++) time.push({position[i], (double)(target - position[i])/speed[i]});
        int res = 0; double cur_time = 0;
        while(!time.empty()){ // priority queue is using pop and top
            auto item = time.top(); time.pop();
            if(item.second > cur_time){
                res++;
                cur_time = item.second;
           }
        }
        return res;
    }
};

// sol2, my, hint by gy1, using sort and unordered map, O(nlogn), O(n)

class Solution{
public:
     int carFleet(int target, vector<int>& position, vector<int>& speed){
        if(position.size() == 0) return 0;
        unordered_map<int, double> time;
        for(int i = 0; i < position.size(); i++) time[position[i]] = (double)(target - position[i]) / speed[i];
        sort(position.begin(), position.end(), greater<int> ());
        int res = 1, cur = 0, next = 0;
        while(cur < position.size() && next < position.size()){
            if( time[position[cur]] >= time[position[next]]) next++;
            else{
                res++;
                cur = next;
            }
        }

        return res;
     }
};


//!! sol1.3 from gy1, using tree map and greater O(nlogn) O(n)
class Solution{
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed){
        map<int, double, greater<int> > time;
        for(int i = 0; i < position.size(); i++){
            time[position[i]] =  (double)(target - position[i]) / speed[i];
        }
        double cur_time = 0; int res = 0;
        for(auto t:time){
            if(t.second > cur_time){
                res++;
                cur_time = t.second;
            }
        }
        return res;
    }
};



//!!!!! sol1.2 from gy1, using tree map trick, O(nlogn), O(n)
class Solution{
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed){
        map<int, double> time;
        for(int i = 0; i <  position.size(); i++){
            time[-position[i]] = (double)(target - position[i])/speed[i];
            cout << time[-position[i]] << endl;
        }
        double cur_time = 0; //!!!careful about the double to int conversion
        int res = 0;
        for(auto t:time){
            if(t.second > cur_time){
                cout << "t: "<< t.second << " cur time" << cur_time << endl;
                res++;
                cur_time = t.second;
            }
        }
        return res;
    }
};



// sol1.1, my hint by gy1, using tree map , O(nlogn), O(nlogn)
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        if(position.size() == 0) return 0;
        map<int, double> time;

        for(int i = 0; i < position.size(); i++){
            time[position[i]] = ((double)(target - position[i]))/speed[i];
            cout << "time" << time[position[i]] << endl;
        }
        vector<int> t_sort_position;
        for(auto t:time){
            t_sort_position.push_back(t.first);
        }
        int cur = position.size() - 1, next = cur, res = 1;
        while(cur >= 0 && next >= 0){
            int pos = t_sort_position[cur];
            int next_pos = t_sort_position[next];


            if(time[next_pos] <= time[pos]) next--;
            else{
                res++;
                cur = next;
            }



        }
        return res;
    }
};
