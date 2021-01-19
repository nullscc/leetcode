class Solution {
public:
    unsigned long int get_key(unsigned long int x, unsigned long int y) {        
        return x*100000+y;
    }
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        int x = 0, y = 0, di = 0;

        set<unsigned long int> obstacle_set;
        for (vector<int> obstacle: obstacles) {
            obstacle_set.insert(get_key(obstacle[0], obstacle[1]));
        }
        int ans = 0;
        // 时间复杂度为 commands.size() + obstacles.size()
        for (int cmd: commands) {
            if (cmd == -2)
                di = (di + 3) % 4;
            else if (cmd == -1)
                di = (di + 1) % 4;
            else {
                for (int k = 0; k < cmd; ++k) {
                    int nx = x + dx[di];
                    int ny = y + dy[di];
                    
                    if (obstacle_set.find(get_key(nx, ny)) == obstacle_set.end()) {
                        x = nx;
                        y = ny;
                        ans = max(ans, x*x + y*y);
                    } else {
                        // 这个else可以不要，也是正确的，因为x, y一直没变，按照一步一步走的方法，只要碰到障碍物了就一直会卡在这里
                        break;
                    }
                }
            }
        }

        return ans;
    }
};