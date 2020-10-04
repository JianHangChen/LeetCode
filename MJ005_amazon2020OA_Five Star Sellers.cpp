
/*
 !! so1
 O(n + klogn), O(n)
 n is the number of products, k is the total five star operation needed 
 k ~= 9900n
 that's because: each product five <= 100, total <= 100
 in worst case five = 0, total = 100, threshold  = 99
 so we need operation k: (0+k)/(100+k) >= 0.99
 so k >= 9900 for each product in worst case
 
 correct me if I am wrong
*/

double diff(vector<double> a, int n){
    return ((a[0]+1)/(a[1]+1) - a[0] / a[1]) / n;
}
int fiveStarReviews(vector<vector<int>> productRatings, int ratingsThreshold){
    double rating = 0;
    int n = productRatings.size();
    vector<vector<double>> tmp; 
    for(auto& ratings:productRatings){
        double five_star = ratings[0], total = ratings[1];
        rating += five_star / total / n;
        tmp.push_back({diff({five_star, total}, n), five_star, total} );
    }
    priority_queue< vector<double> > pq(tmp.begin(), tmp.end());
    
    int count = 0;
    while(rating*100 < ratingsThreshold){
        vector<double> t = pq.top(); pq.pop();
        rating += t[0];
        count++; t[1]++; t[2]++;
        pq.push({diff({t[1], t[2]}, n) , t[1], t[2]});
    }
    return count;    
    
}

int main(){    
    vector<vector<vector<int>>> rts = {
        {{4,4}, {1,2}, {3,6}},
        {{4,4},{1,2},{3,6},{3,5},{2,7},{1,4}}
        
    };
    vector<int> ths = {
        77,
        90
    } ;
    vector<int> ans = {
        3,
        86
    };
    
    for(int i= 0; i < ths.size(); i++){
        vector<vector<int>> ratings = rts[i];
        int threshold = ths[i];
        cout << "answer: " << fiveStarReviews(ratings, threshold) << endl;
        cout << "ground truth: " << ans[i] << endl; 
    }    
}


