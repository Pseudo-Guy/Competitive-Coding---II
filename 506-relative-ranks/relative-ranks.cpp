#include <vector>
#include <string>
#include <queue>

class Solution {
public:
    std::vector<std::string> findRelativeRanks(std::vector<int>& score) {
        int n = score.size();
        std::vector<std::string> result(n);
        
        // Max-heap storing pair<score, original_index>
        std::priority_queue<std::pair<int, int>> pq;
        for (int i = 0; i < n; ++i) {
            pq.push({score[i], i});
        }
        
        int rank = 1;
        while (!pq.empty()) {
            int original_idx = pq.top().second;
            pq.pop();
            
            if (rank == 1) {
                result[original_idx] = "Gold Medal";
            } else if (rank == 2) {
                result[original_idx] = "Silver Medal";
            } else if (rank == 3) {
                result[original_idx] = "Bronze Medal";
            } else {
                result[original_idx] = std::to_string(rank);
            }
            rank++;
        }
        
        return result;
    }
};