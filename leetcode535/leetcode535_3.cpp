class Solution {
public:
    std::unordered_map<string, string> url_map;
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        std::hash<string> hasher;
        string hash_key = to_string(hasher(longUrl));
        url_map[hash_key] = longUrl;
        
        return "http://tinyurl.com/" + hash_key;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string sub_string = shortUrl.substr(19, shortUrl.length() - 19);
        
        return url_map[sub_string];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
// Runtime: 4 ms, faster than 88.36% of C++ online submissions for Encode and Decode TinyURL.
// Memory Usage: 9.4 MB, less than 42.86% of C++ online submissions for Encode and Decode TinyURL.
// time complexity: O(1)
// space complexity: O(n) n is #of input url

// Performance Analysis

// The number of URLs that can be encoded is limited by the range of int, since hashCode uses integer calculations.

// The average length of the encoded URL isn't directly related to the incoming longURL length.

// The hashCode() doesn't generate unique codes for different string. This property of getting the same code for two different inputs is called collision. Thus, as the number of encoded URLs increases, the probability of collisions increases, which leads to failure.

// Thus, it isn't necessary that the collisions start occuring only after a certain number of strings have been encoded, but they could occur way before the limit is even near to the int. This is similar to birthday paradox i.e. the probability of two people having the same birthday is nearly 50% if we consider only 23 people and 99.9% with just 70 people.

// Predicting the encoded URL isn't easy in this scheme.