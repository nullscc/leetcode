class Solution {
public:
    int numberOfMatches(int n) {
        int m=0;
        int pair_num;
        while(n>1) {
            if(n%2 == 1) {
                pair_num = (n-1)/2;
                n = pair_num + 1;
            } else {
                pair_num = n/2;
                n = pair_num;
            }
            m = m + pair_num;
        }
        return m;
    }
};