class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == ""){
            return 0;
        }
        if(haystack == ""){
            return -1;
        }
        int i=0, j=0;
        int l1 = haystack.size();
        int l2 = needle.size();
        while(i<=l1-l2) {   // 这里换成 i<l1就直接超时了
            int p = i;
            j = 0;
            while(haystack[i] == needle[j] && j<l2 && i<l1) {
                i++, j++;
            }
            if(j == l2){
                return p;
            }
 
            i = p+1;
        }
        return -1;
    }
};