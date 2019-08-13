class Solution {
public:
    map<int, string> url_map;
    int i = 0;

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        url_map[i] = longUrl;
        string short_url = "http://tinyurl.com/" + std::to_string(i);
        i++;
        return short_url;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string num_str = shortUrl.substr(19, shortUrl.length() - 19);
        int num = std::stoi(num_str);
        
        return url_map[num];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
// Runtime: 4 ms, faster than 88.52% of C++ online submissions for Encode and Decode TinyURL.
// Memory Usage: 9.3 MB, less than 61.90% of C++ online submissions for Encode and Decode TinyURL.
// time complexity: O(1)
// space complexity: O(n), n is #of input

// Performance Analysis

// The range of URLs that can be decoded is limited by the range of int.

// If excessively large number of URLs have to be encoded, after the range of int is exceeded, integer overflow could lead to overwriting the previous URLs' encodings, leading to the performance degradation.

// The length of the URL isn't necessarily shorter than the incoming longURL. It is only dependent on the relative order in which the URLs are encoded.

// One problem with this method is that it is very easy to predict the next code generated, since the pattern can be detected by generating a few encoded URLs.