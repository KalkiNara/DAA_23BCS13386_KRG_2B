class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int, int> mp;  
        mp[0] = 1;  // prefix sum = 0 exists once

        int prefix = 0;
        int count = 0;

        for (int x : nums) {
            prefix += x;

            if (mp.find(prefix - k) != mp.end()) {
                count += mp[prefix - k];
            }

            mp[prefix]++;
        }

        return count;
    }
};
