class ExamRoom {
public:
    ExamRoom(int N) {
        this->N = N;
    }
    
    int seat() {
        if (seats.empty()) {
            seats.insert(0);
            return 0;
        }
        
        int last = -1;
        int dist;
        int ans;
        // int pos;
        
        for (auto seat: seats) {
            if (last == -1) {
                dist = seat;
                // pos = seat;
                ans = 0;
            }
            else if ((seat - last) / 2 > dist) {
                dist = (seat - last) / 2;
                // pos = seat;
                ans = (seat + last) / 2;
            }
            
            last = seat;
        }
        
        if ((N - 1) - *seats.rbegin() > dist) {
            ans = N - 1;
        }
        
        seats.insert(ans);
        
        return ans;
    }
    
    void leave(int p) {
        seats.erase(seats.find(p));
    }
private:
    int N;
    set<int> seats;
};


// Runtime: 28 ms, faster than 94.60% of C++ online submissions for Exam Room.
// Memory Usage: 14 MB, less than 29.41% of C++ online submissions for Exam Room.
// time complexity: seat O(n) leave O(log n)
// space complexity: O(n)
// https://leetcode.com/problems/exam-room/discuss/139862/C%2B%2BJavaPython-Straight-Forward

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */

// int N;
// vector<int> L;
// ExamRoom(int n) {
//     N = n;
// }

// int seat() {
//     if (L.size() == 0) {
//         L.push_back(0);
//         return 0;
//     }
//     int d = max(L[0], N - 1 - L[L.size() - 1]);
//     for (int i = 0; i < L.size() - 1; ++i) d = max(d, (L[i + 1] - L[i]) / 2);
//     if (L[0] == d) {
//         L.insert(L.begin(), 0);
//         return 0;
//     }
//     for (int i = 0; i < L.size() - 1; ++i)
//         if ((L[i + 1] - L[i]) / 2 == d) {
//             L.insert(L.begin() + i + 1, (L[i + 1] + L[i]) / 2);
//             return L[i + 1];
//         }
//     L.push_back(N - 1);
//     return N - 1;
// }

// void leave(int p) {
//     for (int i = 0; i < L.size(); ++i) if (L[i] == p) L.erase(L.begin() + i);
// }