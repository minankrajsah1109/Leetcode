class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();

        int k = -1; // "1111111" (all bits set : nothing misplaced yet)

        for(int i = 0; i < n; i++){
            if(nums[i] != i){  // this number has to move
                k = (k & nums[i]); // keep only the bits it shares
            }
        }
        return k == -1? 0 : k;
    }
};