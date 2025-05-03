
using namespace std;

class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int rotations = min(check(tops, bottoms, tops[0]), 
                            check(tops, bottoms, bottoms[0]));
        return rotations == INT_MAX ? -1 : rotations;
    }

private:
    // Check how many rotations are needed to make all values equal to target
    int check(const vector<int>& tops, const vector<int>& bottoms, int target) {
        int rotateTop = 0, rotateBottom = 0;
        for (int i = 0; i < tops.size(); ++i) {
            if (tops[i] != target && bottoms[i] != target) {
                return INT_MAX; // Not possible
            } else if (tops[i] != target) {
                ++rotateTop; // Need to rotate to bring target to top
            } else if (bottoms[i] != target) {
                ++rotateBottom; // Need to rotate to bring target to bottom
            }
        }
        return min(rotateTop, rotateBottom);
    }
};
