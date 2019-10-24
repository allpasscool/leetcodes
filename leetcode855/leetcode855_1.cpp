class ExamRoom {
public:
    ExamRoom(int N) {
        this->N = N;
    }
    
    int seat() {
        if (seats.empty()) {
            seats.push_back(0);
            hash_map[0] = seats.begin();
            return 0;
        }
        
        int last = -1, dist, val; // val is output, the seat index
        list<int>::iterator pos;
        
        for (auto it = seats.begin(); it != seats.end(); ++it) {
            if (last == -1) {
                dist = *it;
                pos = it;
                val = 0;
            }
            else if ((*it - last) / 2 > dist) {
                dist = ((*it - last) / 2);
                pos = it;
                val = (*it + last) / 2;
            }
            
            last = *it;
        }
        
        if ((N - 1) - seats.back() > dist) {
            pos = seats.end();
            val = N - 1;
        }
        
        hash_map[val] = seats.insert(pos, val);
        
        return val;
    }
    
    void leave(int p) {
        seats.erase(hash_map[p]);
    }
private:
    int N;
    list<int> seats;
    unordered_map<int, list<int>::iterator> hash_map;
};


// Runtime: 36 ms, faster than 57.91% of C++ online submissions for Exam Room.
// Memory Usage: 14.4 MB, less than 5.88% of C++ online submissions for Exam Room.
// time complexity: seat O(N) leave O(1)
// space complexity: O(N)
// https://leetcode.com/problems/exam-room/discuss/139862/C%2B%2BJavaPython-Straight-Forward

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */

// class ExamRoom {
//     int N;
//     list<int> seats;
//     unordered_map<int, list<int>::iterator> hash_map;
// public:
//     ExamRoom(int N) {
//         this->N = N;
//     }
    
//     int seat() {
//         if (seats.empty())
//             return seats.push_back(0), hash_map[0] = seats.begin(), 0;
//         int last = -1, dist, val;
//         list<int>::iterator pos;
//         for (auto it = seats.begin(); it != seats.end(); ++it) {
//             if (last == -1)
//                 dist = *it, pos = it, val = 0;
//             else if ((*it - last) / 2 > dist)
//                 dist = (*it - last) / 2, pos = it, val = (*it + last) / 2;
//             last = *it;
//         }
//         if (N - 1 - seats.back() > dist)
//             pos = seats.end(), val = N - 1;
//         return hash_map[val] = seats.insert(pos, val), val;
//     }
    
//     void leave(int p) {
//         seats.erase(hash_map[p]);
//     }
// };