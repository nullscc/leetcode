/*
    这个方法用的回溯法的思想，用这个思想可以解决问题的，就是会超时
    本代码本身是错误的代码，因为它回溯的时候need_del的状态乱了，主要原因是因为是need_del删除增加操作在某些特定的测试用例上是错误的，比如下面的测试用例：
    ababacb
    3
    
    执行过程如下(0 6:c 表示执行到recursion(s, 0, 6, 3)时need_del集合中的内容)：
    0 6:c
    左下沉 add:a
    1 6:a c 
    左下沉 add:b
    2 6:a b c 
    左下沉 add:a
    3 6:a b c 
    左下沉 add:b
    4 6:a b c 
    左上浮 del:b
    3 6:a c 

    回到3 6这个状态以后，need_del和之前的内容完全不同了(之前是a b c，恢复状态以后变成了a c)
*/

class Solution {
public:
    set<int> need_del;
    vector<int> happened_num;
    int increase_start[2] = {1, 0};
    int increase_end[2] = {0, -1};
    
    int ans = -1;

    void need_del_op(int tmp, bool del) {
        char c = tmp+'a';
        if(del) {
            need_del.erase(tmp);
        } else {
            need_del.insert(tmp);
        }
    }
    void recursion(string &s, int start, int end, int k) {
        if(!need_del.size()) {
            ans = max(end-start+1, ans);
            return;
        }
        if(start == end) return;
        if( end-start+1 <= need_del.size()) return;

        int ret = -1;
        int start_end[2] = {start, end};
        start_end[0] = start;
        start_end[1] = end;
        for(int i=0; i<2; i++) {
            int tmp = s[start_end[i]]-'a';
            
            set<int> before_need_del = need_del;
            happened_num[tmp]--;
            int before_num = happened_num[tmp];
            if(happened_num[tmp]<k && happened_num[tmp]>0) need_del_op(tmp, false);
            if(happened_num[tmp] == 0) need_del_op(tmp, true);
            recursion(s, start+increase_start[i], end+increase_end[i], k);
            if(happened_num[tmp] == 0) need_del_op(tmp, false);
            if(happened_num[tmp]<k && happened_num[tmp]>0) need_del_op(tmp, true);
            happened_num[tmp]++;
            
        }
    }

    int longestSubstring(string s, int k) {
        happened_num.resize(26);
        for(char ch: s) {
            int tmp = ch-'a';
            happened_num[tmp]++;
            if(happened_num[tmp] < k) need_del.insert(tmp);
            else need_del.erase(tmp);
        }
        recursion(s, 0, s.size()-1, k);
        return max(ans, 0);
    }
};