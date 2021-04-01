/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

//!!! sol1, from sol1, O(mn), O(mn) # hashset to track all path
class Solution {
public:
    unordered_set<string> s;
    void cleanRoom(Robot& robot) {
        dfs(robot, 0, 0, 0);
    }
    vector<vector<int>> dirs = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}  }; // up,  right, down, left
    string encoding(int a, int b){
        return to_string(a) + "," + to_string(b);
    }
    void dfs(Robot& robot, int a, int b, int d){
        s.insert(encoding(a, b));
        robot.clean();        
        for(int i = 0; i < 4; i++){
            int newd = (d + i) % 4;
            int x = a + dirs[newd][0], y = b + dirs[newd][1];
            if(s.count(encoding(x, y)) == 0 && robot.move()){
                dfs(robot, x, y, newd );
                goback(robot);
            }
            robot.turnRight();
        }
    }
    void goback(Robot& robot){
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();
    }
};
