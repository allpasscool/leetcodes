class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (sx < tx && sy < ty)
            if (tx < ty)
                ty %= tx;
            else
                tx %= ty;

        if (sx == tx)
            return sy <= ty && (ty - sy) % sx == 0;
        else if (sy == ty) //sy==ty
            return sx <= tx && (tx - sx) % sy == 0;
        return false;
    }
};
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Reaching Points.
// Memory Usage: 8 MB, less than 100.00% of C++ online submissions for Reaching Points.
// time complexity: O(log max(tx, ty))
// space complexity: O(1)