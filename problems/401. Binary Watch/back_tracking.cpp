class Solution {
public:
    // 两种不同的方法算10进制数字n中二进制表示中1的个数
    int count1_2(int n) {
        int count = 0;
        while (n != 0) {
            n = n & (n - 1);
            count++;
        }
        return count;
    }

    int count1(int n) {
        int count = 0;
        while(n != 0) {
            if(n%2 == 1) {
                count++;
            }
            n = n>>1;
        }
        return count;
    }

    vector<string> readBinaryWatch(int num) {
        vector<string> ans;
        char s[6];
        for(int i=0; i<12; i++) {
            for(int j=0; j<60; j++) {
                if((count1(i)+count1(j))==num) {
                    sprintf(s, "%d:%02d", i, j);
                    ans.emplace_back(s);
                    // ans.push_back(to_string(i)+(j>9?":"+to_string(j):":0"+to_string(j)));
                }
            }
        }
        return ans;
    }
};