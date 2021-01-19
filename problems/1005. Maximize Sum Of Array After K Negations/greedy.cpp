class Solution {
public:
    // 思路：优先翻转负数(最小的负数优先翻转)，负数翻转完以后，则对绝对值最小的数进行重复翻转
    int largestSumAfterKNegations(vector<int>& A, int K) {
        int m=INT_MAX;  // 最小的正整数(包括0)
        vector<int> minus;  // 将负数存到这里
        int sum = 0;
        for(int a: A) {
            if(a<0) {
                minus.push_back(a);
            } else {
                if(a<m) m = a;
                sum = sum + a;
            }
        }
        sort(minus.begin(), minus.end());
        int k = K;
        if(k<=minus.size()) {
            for(int i=0; i<minus.size(); i++) {
                if(k>=i+1) {
                    sum = sum - minus[i];
                } else {
                    sum = sum + minus[i];
                }
            }
        } else {
            for(int i=0; i<minus.size(); i++) {
                sum = sum - minus[i];
            }
            
            if((k-minus.size())%2 == 1) {
                if(minus.size() && m>-minus[minus.size()-1]) sum = sum + 2*minus[minus.size()-1];
                else sum = sum - 2*m;
            }
            
        }
        return sum;
    }
};