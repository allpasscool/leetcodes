class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        vector<int> count_A(7, 0);
        vector<int> count_B(7, 0);
        int goal_num = 0;
        if (A[0] == B[0]) {
            ++count_A[A[0]];
        }
        else {
            ++count_A[A[0]];
            ++count_B[B[0]];
        }
        
        // find goal_num
        bool has_candidate = false;
        for (int i = 1; i < A.size(); ++i) {
            has_candidate = false;
            if (A[i] == B[i]) {
                ++count_A[A[i]];
            }
            else {
                ++count_A[A[i]];
                ++count_B[B[i]];
            }
            
            // find which num is our last goal num
            for (int j = 1; j <= 6; ++j) {
                // might find our goal num
                if (count_A[j] + count_B[j] == i + 1) {
                    has_candidate = true;
                    break;
                }
            }
            
            if (!has_candidate)
                return -1;
        }
        
        // find goal_num
        for (int i = 1; i <= 6; ++i) {
            if (count_A[i] + count_B[i] == A.size())
                goal_num = i;
        }

        int goal_in_A = 0;
        int switch_to_A = 0;
        
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] == goal_num && B[i] != goal_num)
                ++goal_in_A;
            else if (B[i] == goal_num && A[i] != goal_num) 
                ++switch_to_A;
        }
        
        return min(goal_in_A, switch_to_A);
    }
};


// Runtime: 128 ms, faster than 38.16% of C++ online submissions for Minimum Domino Rotations For Equal Row.
// Memory Usage: 19.1 MB, less than 83.33% of C++ online submissions for Minimum Domino Rotations For Equal Row.
// time complexity: O(n)
// space complexity: O(1)