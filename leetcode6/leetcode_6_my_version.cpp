class Solution {
public:
    string convert(string s, int numRows) {
        std::vector<string> Zig_Zag(numRows);
        
        int one_cycle;
        if(numRows > 1){
            one_cycle = 2 * numRows - 2;
        }
        else if(numRows == 1){
            one_cycle = 1;
        }
        else{
            return "";
        }
        
        for(int i = 0; i < s.size(); i++){
            
            int row_loc = i % one_cycle;
            
            if(row_loc < numRows){
                Zig_Zag[row_loc] += s[i];
            }
            else{
                Zig_Zag[numRows - 1 - (row_loc % numRows + 1)] += s[i];
            }
        }
        
        string output;
        
        for(int i = 0; i < numRows; i++){
            output += Zig_Zag[i];
        }
        
        return output;
    }
};

// Runtime: 20 ms, faster than 37.44% of C++ online submissions for ZigZag Conversion.
// Memory Usage: 12.8 MB, less than 25.46% of C++ online submissions for ZigZag Conversion.
//time complexity: O(n)
//space complexity: O()


class Solution {
public:
    string convert(string s, int numRows) {
        std::vector<string> Zig_Zag(numRows);
        
        int one_cycle;
        if(numRows > 1){
            one_cycle = 2 * numRows - 2;
        }
        else if(numRows == 1){
            // one_cycle = 1;
            return s;
        }
        else{
            return "";
        }
        
        for(int i = 0; i < s.size(); i++){
            
            int row_loc = i % one_cycle;
            
            if(row_loc < numRows){
                Zig_Zag[row_loc] += s[i];
            }
            else{
                Zig_Zag[numRows - 1 - (row_loc % numRows + 1)] += s[i];
            }
        }
        
        string output;
        
        for(int i = 0; i < numRows; i++){
            output += Zig_Zag[i];
        }
        
        return output;
    }
};
// Runtime: 12 ms, faster than 84.84% of C++ online submissions for ZigZag Conversion.
// Memory Usage: 12.7 MB, less than 30.56% of C++ online submissions for ZigZag Conversion.