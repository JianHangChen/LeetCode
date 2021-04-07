class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int x = coordinates[0] - 'a';
        int v = coordinates[1] - '1';
        return (x+v) % 2;
    }
};
