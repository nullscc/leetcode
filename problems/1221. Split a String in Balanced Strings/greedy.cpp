class Solution {
public:
    int balancedStringSplit(string s) {
        /*
        由题意s必为平衡字符串
        所以以下算法中每个balance=0的点都是分割点，这样就是最大的
        */
        int balance=0, count=0;
        for(auto &c: s) {
            if(c=='L') balance++;
            else balance--;
            
            if(balance==0) count++;
        }
        return count;
    }
};