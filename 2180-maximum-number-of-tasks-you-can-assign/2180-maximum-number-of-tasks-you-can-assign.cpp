#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    bool canAssign(int k, vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        multiset<int> workerSet(workers.end() - k, workers.end());  // k strongest workers

        for (int i = k - 1; i >= 0; --i) {  // hardest k tasks
            int task = tasks[i];

            // Find a worker who can do it without pill
            auto it = workerSet.lower_bound(task);
            if (it != workerSet.end()) {
                workerSet.erase(it);
            } else {
                // Try to use a pill
                if (pills == 0) return false;

                // Find a worker who can do it with pill
                it = workerSet.lower_bound(task - strength);
                if (it == workerSet.end()) return false;

                workerSet.erase(it);
                pills--;
            }
        }
        return true;
    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int left = 0, right = min((int)tasks.size(), (int)workers.size()), answer = 0;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (canAssign(mid, tasks, workers, pills, strength)) {
                answer = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return answer;
    }
};
