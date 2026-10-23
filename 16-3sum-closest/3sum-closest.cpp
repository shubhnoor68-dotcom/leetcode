class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int PreSum = 0;
        int sum = nums[0] + nums[1] + nums[2];

        for(int i = 0; i < n - 2; i++) {
            int j = i + 1;
            int k = n - 1;

            while(j < k) {
                PreSum = nums[i] + nums[j] + nums[k];
                int diff1 = abs(target - PreSum);
                int diff2 = abs(target - sum);

                if(diff1 < diff2) {
                    sum = PreSum;
                }

                if(PreSum < target) {
                    j++;
                }
                else if(PreSum > target) {
                    k--;
                }
                else {
                    return target;
                }
            }
        }
        return sum;
    }
};