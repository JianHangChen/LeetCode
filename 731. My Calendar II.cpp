
// sol1, !!! my, brute force same as sol1 O(N^2) , O(N)
class MyCalendarTwo {
    
vector< vector<int> > intervals;
vector< vector<int> > double_intervals;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        int count = 0;
        
        for(auto double_interval:double_intervals){
            int s = double_interval[0], e = double_interval[1];
            int small = max(s, start), big = min(end, e);
            if(small < big) return false;
        }
        for(auto interval:intervals){
            int s = interval[0], e = interval[1];
            
            int small = max(s, start);
            int big = min(end, e);
            if(small < big){
                double_intervals.push_back({small, big});
            }
        }
        
        intervals.push_back({start, end});
        return true;
    }
};


// sol2, count interval, blanced tree, from sol2, O(N^2), O(N)
class MyCalendarTwo{
private:
    map<int, int> m;
    
public:
    MyCalendarTwo(){
        
    }
    
    bool book(int start, int end){
        // if(m.count(start) == 0) m[start] = 0;
        m[start]++;
        // if(m.count(end) == 0) m[end] = 0;
        m[end]--;
        
        int count = 0;
        for(auto itr:m){
            count += itr.second;
            if(count >= 3){
                m[start]--;
                m[end]++;
                return false;
            }
        }
        return true;
    }
    
};


