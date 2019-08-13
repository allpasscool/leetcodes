class Solution {
public:
    string chars = 
        "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::unordered_map<string, string> url_map;
    int count = 1;
    
    string getString() {
        int c = count;
        string substring;
        
        while (c > 0) {
            c--;
            substring += chars[c % 62];
            c /= 62;
        }
        
        return substring;
    }

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string key = getString();
        url_map[key] = longUrl;
        count++;
        return "http://tinyurl.com/" + key;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return url_map[shortUrl.substr(19, shortUrl.length() - 19)];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
// Runtime: 4 ms, faster than 88.36% of C++ online submissions for Encode and Decode TinyURL.
// Memory Usage: 9.4 MB, less than 61.90% of C++ online submissions for Encode and Decode TinyURL.
// time complexity: O(1)
// space complexity: O(n), n is #of input url

// Performance Analysis

// The number of URLs that can be encoded is, again, dependent on the range of int, since, the same countcount will be generated after overflow of integers.

// The length of the encoded URLs isn't necessarily short, but is to some extent dependent on the order in which the incoming \text{longURL}longURL's are encountered. For example, the codes generated will have the lengths in the following order: 1(62 times), 2(62 times) and so on.

// The performance is quite good, since the same code will be repeated only after the integer overflow limit, which is quite large.

// In this case also, the next code generated could be predicted by the use of some calculations.