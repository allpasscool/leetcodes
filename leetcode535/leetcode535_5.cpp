class Solution {
public:
    string chars =
        "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::unordered_map<string, string> url_map;
    string key = getRand();
    
    string getRand() {
        string sub_string = "";
        
        for (int i = 0; i < 6; i++) {
            sub_string += to_string(chars[rand() % 63]);
        }
        
        return sub_string;
    }

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        while (url_map.find(key) != url_map.end()) {
            key = getRand();
        }
        url_map[key] = longUrl;
        
        return "http://tinyurl.com/" + key;
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

// Runtime: 8 ms, faster than 48.72% of C++ online submissions for Encode and Decode TinyURL.
// Memory Usage: 9.4 MB, less than 38.10% of C++ online submissions for Encode and Decode TinyURL.
// time complexity: O(1)
// space complexity: O(n) n is #of input

// Performance Analysis

// The number of URLs that can be encoded is quite large in this case, nearly of the order (10+26*2)^6.

// The length of the encoded URLs is fixed to 6 units, which is a significant reduction for very large URLs.

// The performance of this scheme is quite good, due to a very less probability of repeated same codes generated.

// We can increase the number of encodings possible as well, by increasing the length of the encoded strings. Thus, there exists a tradeoff between the length of the code and the number of encodings possible.

// Predicting the encoding isn't possible in this scheme since random numbers are used.