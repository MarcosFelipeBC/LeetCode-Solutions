class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = (int)nums.size();
        for (int i=n-1; i>=0; i--){
            int j = i;
            if(nums[j] != 0) continue ;
            while (j+1 < n && nums[j+1] != 0){
                swap(nums[j+1], nums[j]);
                j++;
            }
        }
    }
};