#include <vector>
#include <algorithm>

class Solution {
public:
    void backtrack(int start, int target, std::vector<int>& candidates, std::vector<int>& current, std::vector<std::vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            if (candidates[i] > target) {
                break;
            }

            current.push_back(candidates[i]);
            backtrack(i, target - candidates[i], candidates, current, result);
            current.pop_back();
        }
    }

    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        
        std::sort(candidates.begin(), candidates.end());
        backtrack(0, target, candidates, current, result);
        
        return result;
    }
};