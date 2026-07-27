#include <vector>
#include <algorithm>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector<int> merge = nums1;
        merge.insert(merge.end(), nums2.begin(), nums2.end());
        std::sort(merge.begin(), merge.end());

        int n = merge.size();
        if (n % 2 != 0) {
            return merge[n / 2];
        } else {
            return (merge[n / 2 - 1] + merge[n / 2]) / 2.0;
        }
    }
};