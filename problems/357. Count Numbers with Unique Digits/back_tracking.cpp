class Solution {
public:
    int ans=0;
    vector<bool>visited;    // 数组表示哪个数字被选了
    
    void back_tracking(int deep, int len) {
        if(len==0) {
            ans++;
            return;
        }
        
        for(int i=0; i<10; i++) {
            if(deep==0 && i==0 && len>1) continue;
            if(visited[i]) continue;
            visited[i] = true;
            back_tracking(deep+1, len-1);
            visited[i] = false;
        }
    }
    int countNumbersWithUniqueDigits(int n) {
        if(n==0) return 1;

        visited.resize(10);
        
        for(int len=1; len<=n; len++) {
            back_tracking(0, len);
        }
        return ans;
    }
};