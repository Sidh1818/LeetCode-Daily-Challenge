class Solution {
public:
    string winningPlayer(int x, int y) {
        int r = y/4;
        int turn = min(x,r);
        if(turn%2!=0)
            return "Alice";
        return "Bob";
    }
};