class Solution {
public:
    vector<vector<int>> dirs = { {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int getMinDistance(vector<vector<int>> &mazeMap) {
        int m = mazeMap.size(); if(m == 0) return 0; 
        int n = mazeMap[0].size(); if(n == 0) return 0;
        
        vector<vector<int>> cost(m, vector<int> (n, INT_MAX));
        
        int dest_x, dest_y;
        queue<vector<int>> q;
        unordered_map<int, vector<vector<int>> > hole;
        unordered_set<int> visited_hole;
        
        for(int i = 0; i < m ;i++){
            for(int j = 0; j < n; j++){
                if(mazeMap[i][j] == -3){
                    cost[i][j] = 0;
                    q.push({i, j});
                }
                else if(mazeMap[i][j] == -2){
                    dest_x = i;
                    dest_y = j;
                }
                else if(mazeMap[i][j] > 0){
                    hole[mazeMap[i][j]].push_back({i, j});
                }
            }
        }
        
        int step = 0;
        while(!q.empty()){
            int t = q.size();

            step++;
            
            for(int k = 0; k < t; k++){
                int i  = q.front()[0], j = q.front()[1]; q.pop();
                for(auto& dir:dirs){
                    int x = i + dir[0], y = j + dir[1];
                    if(x >= 0 && x < m && y >= 0 && y < n && mazeMap[x][y] != -1){
                        if(step < cost[x][y]){
                            if(x == dest_x && y == dest_y) return step;
                            cost[x][y]= step;
                            q.push({x,y});
                        }
                        
                    }
                }
                if( visited_hole.count(mazeMap[i][j]) > 0) continue;
                visited_hole.insert(mazeMap[i][j]);
                for(auto& v:hole[mazeMap[i][j]]){
                    int x = v[0], y = v[1];
                    if(step < cost[x][y]){
                        if(x == dest_x && y == dest_y) return step;
                        cost[x][y]= step;
                        q.push({x,y});
                    }
                    
                }
            }
        }
        return -1;
        
    }
};



// class Solution {
//   public:
//     //TP[i] 表示第i种传送门的各个点的下标
//     vector<pair<int, int> > TP[55];
//     //vis 标记点有没有访问过
//     vector<vector<int> > vis;
//     // distance 标记起点到各个点的距离
//     vector<vector<int> > distance;
//     // 标记这种传送门有没有使用过
//     int visTP[55];
//     // 起点xy坐标 终点xy坐标
//     int beginx, beginy, endx, endy;
//     int getMinDistance( vector<vector<int> > &mazeMap) {


//         int m = mazeMap.size(); if(m == 0) return 0; 
//         int n = mazeMap[0].size(); if(n == 0) return 0;

//         // 初始化数组，并找出起点终点
//         vector<int>tmp;
//         for(int i = 0; i < m; i++) {
//             tmp.push_back(0);
//         }
//         for(int i = 0; i < n; i++) {

//             for(int j = 0; j < m; j++) {
//                 if(mazeMap[i][j] == -2) {
//                     beginx = i;
//                     beginy = j;
//                 }
//                 if(mazeMap[i][j] == -3) {
//                     endx = i;
//                     endy = j;
//                 }
//                 if(mazeMap[i][j] > 0) {
//                     pair<int, int> pi = make_pair(i, j);
//                     TP[mazeMap[i][j]].push_back(pi);
//                     visTP[mazeMap[i][j]] = 0;
//                 }
//             }
//             vis.push_back(tmp);
//             distance.push_back(tmp);
//         }
//         // bfs的队列
//         queue<pair<int, int> >q;
//         //压入起点
//         pair<int, int> beginPi = make_pair(beginx, beginy);
//         q.push(beginPi);
//         vis[beginx][beginy] = 1;
//         //四个行走的方向
//         int zx[] = {0, 0, -1, 1};
//         int zy[] = {1, -1, 0, 0};
//         while(!q.empty()) {

//             pair<int, int> now = q.front();
//             q.pop();
//             int x = now.first;
//             int y = now.second;
//             int cost = distance[x][y];
//             int idx = mazeMap[x][y];
//             //到达了终点
//             if(x == endx && y == endy) {
//                 return distance[x][y];
//             }

//             for(int k = 0; k < 4; k++) {
//                 int nx = x + zx[k];
//                 int ny = y + zy[k];
//                 //判断非法条件
//                 if(nx < 0 || nx >= n || ny < 0 || ny >= m || mazeMap[nx][ny] == -1 || vis[nx][ny]) {
//                     continue;
//                 }
//                 //找到了终点
//                 if(mazeMap[nx][ny] == -3) {
//                     return cost + 1;
//                 }
//                 //压入新节点
//                 vis[nx][ny] = 1;
//                 distance[nx][ny] = cost + 1;
//                 pair<int, int> newPoint = make_pair(nx, ny);
//                 q.push(newPoint);
//             }
//             //这个点是传送门
//             if(idx > 0) {
//                 //这个传送门已经用过了
//                 if(visTP[idx]) {
//                     continue;
//                 } else {
//                     for(int i = 0; i < TP[idx].size(); i++) {

//                         //压入这种传送门的其他点
//                         int nx = TP[idx][i].first;
//                         int ny = TP[idx][i].second;
//                         if(vis[nx][ny]) {
//                             continue;
//                         }
//                         vis[nx][ny] = 1;
//                         distance[nx][ny] = cost + 1;
//                         q.push(TP[idx][i]);
//                     }
//                     visTP[idx] = 1;
//                 }
//             }
//         }
//         return -1;
//     }
// };

// [[0,0,0,2,6,0,10,4,9,0],
// [-1,0,0,0,-1,0,0,0,3,2],
// [-1,0,0,8,0,0,0,0,0,0],
// [0,7,0,0,5,0,0,-1,4,5],
// [0,0,2,0,0,10,3,1,0,0],
// [3,0,-1,0,9,1,0,0,0,8],
// [-1,0,9,0,0,0,0,0,0,4],
// [0,10,3,7,0,10,2,0,0,0],
// [0,0,3,0,-3,-1,0,-2,0,-1],
// [0,3,0,1,0,-1,0,5,0,6]]



// [[1,0,-1,1],
// [-2,0,1,-3],
// [2,2,0,0]]
