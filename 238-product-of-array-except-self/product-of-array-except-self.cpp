#include <vector>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        int n = nums.size();
        int pre = 1;
        int suff = 1;
        std::vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            arr[i] = pre;
            pre *= nums[i];
        }

        for (int i = n - 1; i >= 0; i--) {
            arr[i] *= suff;
            suff *= nums[i];
        }

        return arr;
    }
};