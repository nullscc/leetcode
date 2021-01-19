class Solution {
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    bool can(int i, int j, vector<vector<bool>>& visit, int m, int n) {
        // 1. 看有没有越界
        // 2. 看有没有访问过
        if(i<0 || i>m-1 || j<0 || j>n-1) return false;
        return !visit[i][j];
    }
    pair<int, int> get_next(int i, int j, int di) {
        return {i+dx[di], j+dy[di]};
    }

    bool dfs(vector<vector<char>>& board, const string &word, vector<vector<bool>>& visit, int m, int n, int deep) {
        if(deep == word.size()-1 && board[m][n]==word[deep]) return true;
        
        pair<int, int> next;
        for(int di=0; di<4; di++) {
            next = get_next(m, n, di);
            if(can(next.first, next.second, visit, board.size(), board[0].size()) \
            && word[deep]==board[m][n]) {
                visit[m][n] = true;

                bool ret = dfs(board, word, visit, next.first, next.second, deep+1);
                if(ret) return ret;

                visit[m][n] = false;
            }
        }
        
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size(), n=board[0].size();

        vector<vector<bool>>visit(m, vector<bool>(n, false));
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                visit[i][j] = true;
                bool ret = dfs(board, word, visit, i, j, 0);
                if(ret) return true;
                visit[i][j] = false;
            }
        }
        return false;
    }
};