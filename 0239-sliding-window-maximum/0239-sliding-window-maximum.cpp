class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // Using deque
        int n = nums.size();
        if(k == 1) return nums;
        deque<int> dq; // decreasing order of element index
        vector<int> ans; // i should be min k-1
        for(int i = 0; i < n; i++){
            while(dq.size() > 0 && nums[i] > nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
            int j = i-k+1; // start of the window
            while(dq.front() < j) dq.pop_front();
            if(i >= k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};