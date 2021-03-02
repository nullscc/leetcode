class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) return intersect(nums2, nums1);
        vector<int> ans;
        map<int, int> m;
        for(int i=0; i<nums1.size(); i++) {
            m[nums1[i]]++;
        }
        for(int i=0; i<nums2.size(); i++) {
            if(m.count(nums2[i]) && m[nums2[i]]) {
                ans.push_back(nums2[i]);
                m[nums2[i]]--;
            }
        }
        return ans;
    }
};