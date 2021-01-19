/*
    这个与back_tracking.cpp相比做了两处剪枝:
        1. 在某个方向上走一个单位越界了就不尝试走两个单位了，见`for(int factor=1; factor<3; factor++)`
        2. 不固定死长度，固定死长度会损失计算量，因为较长长度的手势可以根据较短长度推演出来，对比numberOfPatterns函数中的for循环数量
    节省了约220ms的执行时间
*/
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

    void back_tracking(int len, int start_x, int start_y, int m, int n) {
        if(len > n)
            return;
        else if(len == n){
            ans++;
            return;
        }
        else if(len >= m)
            ans++;
        int x, y;
        for(int di=0; di<16; di++) {
            
            for(int factor=1; factor<3; factor++) {
                x = start_x + factor*dx[di];
                y = start_y + factor*dy[di];

                /* 
                    factor=1表示在某个方向上前进1个单位
                    factor=2表示在某个方向上前进2个单位
                如果在某个方向上前进1个单位会越界，前进2个单位必越界，所以没有必要尝试下去了
                */
                if(x<0 || x>2 || y<0 || y>2) break;

                // 这个内层for循环的目的只是为了在某个方向上走通，如果走一个单位能走通，没必要再尝试第二个单位了
                if(!visited[x][y]) {
                    visited[x][y] = true;
                    back_tracking(len+1, x, y, m, n);
                    visited[x][y] = false;
                    break;
                }
            }
        }
    }

    int numberOfPatterns(int m, int n) {
        visited.resize(3, vector<bool>(3, false));
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                visited[i][j] = true;
                back_tracking(1, i, j, m, n);
                visited[i][j] = false;
            }
        }
        return ans;
    }
};