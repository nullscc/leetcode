class Solution {
public:
    // 按题中的图示，1可以走到4，这个很重要...
    // 所以每步共有16个方向可以走
    vector<vector<bool>>visited;
    int ans=0;
    // 方向依次是 上、右上、右、右下、下、左下、左、左上、
    // 右上(与水平线60度，比如7直接到2)、右上(与水平线30度，比如7直接走到6)、....
    int dx[16] = {-1, -1, 0, 1, 1, 1, 0, -1, -2, -1, 1, 2, 2, 1, -1, -2};
    int dy[16] = {0, 1, 1, 1, 0, -1, -1, -1, 1, 2, 2, 1, -1, -2, -2, -1};

    bool can(int x, int y) {
        if(x<2 || x>4 || y<2 || y>4) return false;
        
        return !visited[x][y];
    }

    pair<int, int>get_next(int x, int y, int di) {
        x += dx[di];
        y += dy[di];
        while(visited[x][y]) {
            x += dx[di];
            y += dy[di];
        }
        return {x, y};
    }

    void back_tracking(int len, int start_x, int start_y) {
        if(len==0) {
            ans++;
            return;
        }
        for(int di=0; di<16; di++) {
            auto next = get_next(start_x, start_y, di);
            if(!can(next.first, next.second)) {
                continue;
            }
            
            visited[next.first][next.second] = true;
            back_tracking(len-1, next.first, next.second);
            visited[next.first][next.second] = false;
        }
    }

    int numberOfPatterns(int m, int n) {
        visited.resize(7, vector<bool>(7, false));
        for(int len=m; len<=n; len++) {
            for(int i=2; i<5; i++) {
                for(int j=2; j<5; j++) {
                    visited[i][j] = true;
                    back_tracking(len-1, i, j);
                    visited[i][j] = false;
                }
            }
        }
        return ans;
    }
};