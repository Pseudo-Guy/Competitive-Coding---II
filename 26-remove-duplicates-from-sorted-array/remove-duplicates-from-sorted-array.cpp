#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.empty()) return 0;
        int off = 0;
        int unique = 1;
        int cm = 1;
        while (cm < nums.size()) {
            if (nums[cm] == nums[cm - 1]) {
                cm++;
                continue;
            }
            nums[++off] = nums[cm];
            unique++;
            cm++;
        }
        return unique;
    }
};