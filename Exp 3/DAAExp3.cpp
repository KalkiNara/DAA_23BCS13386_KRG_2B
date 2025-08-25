class Solution {
  public:
    vector<vector<int>> countFreq(vector<int>& arr) {
        unordered_map<int, int> freq;  
        
        
        for (int num : arr) {
            freq[num]++;
        }
        
       
        vector<vector<int>> result;
        for (auto &it : freq) {
            result.push_back({it.first, it.second});
        }
        
     
        sort(result.begin(), result.end());
        
        return result;
    }
};
