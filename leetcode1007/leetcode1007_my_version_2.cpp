class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        vector<int> count_A(7, 0);
        vector<int> count_B(7, 0);
        vector<int> A_no_switch(7); // if goal num is i, there are A_no_switch[i] don't need to switch
        vector<int> A_and_B(7); // for A[i] == B[i]
        int goal_num = 0;
        
        if (A[0] == B[0]) {
            ++count_A[A[0]];
            ++A_and_B[A[0]];
        }
        else {
            ++count_A[A[0]];
            ++count_B[B[0]];
            ++A_no_switch[A[0]];
        }
        
        
        // find goal_num
        for (int i = 1; i < A.size(); ++i) {
            if (A[i] == B[i]) {
                ++count_A[A[i]];
                ++A_and_B[A[i]];
            }
            else {
                ++count_A[A[i]];
                ++count_B[B[i]];
                ++A_no_switch[A[i]];
            }
            
            // check if there is at least one goal num
            if (count_A[A[i]] + count_B[A[i]] != i + 1
               && count_A[B[i]] + count_B[B[i]] != i + 1)
                return -1;
        }
        
        // find goal_num
        for (int i = 1; i <= 6; ++i) {
            if (count_A[i] + count_B[i] == A.size())
                goal_num = i;
        }
        
        return min(A_no_switch[goal_num], (int) A.size() - A_no_switch[goal_num] - A_and_B[goal_num]);
    }
};


// Runtime: 120 ms, faster than 81.00% of C++ online submissions for Minimum Domino Rotations For Equal Row.
// Memory Usage: 19.2 MB, less than 83.33% of C++ online submissions for Minimum Domino Rotations For Equal Row.
// time complexity: O(n)
// space complexity: O(1)