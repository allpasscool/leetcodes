class Solution {
public:
    std::unordered_map<int, string> url_map;
    int key = rand();

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        while (url_map.find(key) != url_map.end()) {
            key = rand();
        }
        
        url_map[key] = longUrl;
        return "http://tinyurl.com/" + to_string(key);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string sub_string = shortUrl.substr(19, shortUrl.length() - 19);
        int num = std::stoi(sub_string);
        
        return url_map[num];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

// Runtime: 8 ms, faster than 48.72% of C++ online submissions for Encode and Decode TinyURL.
// Memory Usage: 9.2 MB, less than 66.67% of C++ online submissions for Encode and Decode TinyURL.
// time complexity: O(1)
// space complexity: O(n) , n is #of input

// **Performance Analysis**
// The number of URLs that can be encoded is limited by the range of int.

// The average length of the codes generated is independent of the longURL's length, since a random integer is used.

// The length of the URL isn't necessarily shorter than the incoming longURL. It is only dependent on the relative order in which the URLs are encoded.

// Since a random number is used for coding, again, as in the previous case, the number of collisions could increase with the increasing number of input strings, leading to performance degradation.

// Determining the encoded URL isn't possible in this scheme, since we make use of random numbers.