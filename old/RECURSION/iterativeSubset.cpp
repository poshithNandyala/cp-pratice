// C++ implementation
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> outer = {{}};
        for(int num : nums){
            int n = outer.size();
            for(int i = 0; i < n; i++){
                vector<int> internal = outer[i];
                internal.push_back(num);
                outer.push_back(internal);
            }
        }
        return outer;
    }
};