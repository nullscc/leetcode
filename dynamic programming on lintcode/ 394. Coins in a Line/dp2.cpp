class Solution {
public:
    /**
     * @param n: An integer
     * @return: A boolean which equals to true if the first player will win
     */
    bool firstWillWin(int n) {
        if(!n) return false;
        if(n<=2) return true;
        // write your code here
        bool ppre = false;
        bool pre = true;
        bool cur;
        for(int i=2; i<=n; i++) {
            cur = !ppre || !pre;
            ppre = pre;
            pre = cur;
        }
        return cur;
    }
};