#include <vector>

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        int i = 0;
        int j = 0;
        std::vector<int> arr(m + n);
        int id = 0;
        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) {
                arr[id++] = nums1[i++];
            } else {
                arr[id++] = nums2[j++];
            }
        }
        while (j < n) {
            arr[id++] = nums2[j++];
        }
        while (i < m) {
            arr[id++] = nums1[i++];
        }
        for (int k = 0; k < m + n; k++) {
            nums1[k] = arr[k];
        }
    }
};