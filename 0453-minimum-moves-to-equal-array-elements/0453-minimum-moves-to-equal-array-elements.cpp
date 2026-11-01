class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();

        int sum = accumulate(begin(nums), end(nums), 0);
        int min_ele = *min_element(nums.begin(), nums.end());

        return sum - n*min_ele;
    }
};