class Solution {
public:
    vector<int>ans;
    /* 主要是临界条件判断:
        1. 遇到0的起始点，拆分宽度只能是1
        2. 判断整数范围外的数字
        3. 判断两数之和超出了整数范围外的数字
        4. 字符长度过长情况下，肯定超出了整数范围
    */
    bool back_tracking(string &S, int start) {
        if(start == S.size()) {
            if(ans.size()>=3) return true;
            return false;
        }
        int len = ans.size();
        long int tmp;
        long int prev_sum;
        for(int i=start; i<S.size(); i++) {
            if(i-start+1 > 10) break;
            tmp = stol(S.substr(start, i-start+1));
            if(tmp>2147483647) break;
            if(len>=2) prev_sum = (long int)ans[len-1]+(long int)ans[len-2];
            if(len<2 || tmp == prev_sum) {
                ans.emplace_back(tmp);
                if(back_tracking(S, i+1)) return true;
                ans.pop_back();
            }
            if(tmp==0) break;
        }
        return false;
    }
    vector<int> splitIntoFibonacci(string& S) {
        back_tracking(S, 0);
        return ans;
    }
};