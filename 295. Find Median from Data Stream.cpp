

//!!! sol2, min max heap from ch9, O(nlogn), O(n)
// can also be used for dynamic maintain kth element
class MedianFinder {
public:
    priority_queue<int> max_pq;
    priority_queue<int, vector<int>, greater<int>> min_pq;
    /** initialize your data structure here. */
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(max_pq.empty() || num <= max_pq.top()) max_pq.push(num);
        else min_pq.push(num);
        
        if(max_pq.size() > min_pq.size() + 1){
            min_pq.push(max_pq.top());
            max_pq.pop();
        }
        else if(max_pq.size() < min_pq.size()){
            max_pq.push(min_pq.top());
            min_pq.pop();
        }
    }
    
    double findMedian() {
        if(max_pq.size() == min_pq.size()) return double(max_pq.top() + min_pq.top()) / 2.0;
        return max_pq.top();
    }
};



// !sol1, min max multiset from ch9, O(nlogn), O(n)
// can also be used for dynamic maintain kth element
class MedianFinder {
public:
    multiset<int> min_set;
    multiset<int, greater<int>> max_set;

    /** initialize your data structure here. */
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(max_set.size() == 0 || num <= *max_set.begin()) max_set.insert(num);
        else min_set.insert(num);
        
        if(max_set.size() > min_set.size() + 1){
            min_set.insert(*max_set.begin());
            max_set.erase(max_set.begin());
        } 
        else if(max_set.size() < min_set.size()){
            max_set.insert(*min_set.begin());
            min_set.erase(min_set.begin());
        }
    }
    
    double findMedian() {
        if(max_set.size() == min_set.size()) return double(*max_set.begin() + *min_set.begin()) / 2.0;
        return *max_set.begin();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
