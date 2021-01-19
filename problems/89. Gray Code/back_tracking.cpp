class Solution {
public:
    vector<int> ans;
    vector<bool>visited;
    
    int turn(int cur, int k) {
        /*
        int one_or_zero = (cur >> (k-1)) % 2;
        if(one_or_zero) {
            return cur & (~(1<<(k-1)));
        } else {
            return cur | (1<<(k-1));
        }
        */
        return cur ^= (0x1 << (k-1));
    }

    bool back_tracking(int n, int cur) {
        int tmp;
        bool flag = false; // 代表有没有找到
        
        // 依次尝试翻转第i位
        for(int i=1; i<=n; i++) {
            tmp = turn(cur, i);
            if(!visited[tmp]) {
                visited[tmp] = true;
                flag = true;
                if(back_tracking(n, tmp)) {
                    ans.emplace_back(tmp);
                    return true;
                }
            }
        }
        // 函数的返回值true代表递归应该结束了
        if(!flag) return true;
        return false;
    }

    vector<int> grayCode(int n) {
        int max_num = (1<<n)-1;
        visited.resize(max_num+1);
        visited[0] = true;
        ans.emplace_back(0);
        back_tracking(n, 0);
        return ans;
    }
};