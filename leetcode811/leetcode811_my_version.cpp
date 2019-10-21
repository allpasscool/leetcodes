class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> domain_count; 
        
        for (auto& s: cpdomains) {
            auto p = getCP(s);
            int count = p.first, pos = p.second;
            
            string domain = s.substr(pos + 1);
            // cout << domain << endl;
            // count all domains, including sub-domains
            while (domain != "") {
                domain_count[domain] += count;
                
                // find next sub-domain
                // int i = 0;
                // for (; i < domain.length(); ++i) {
                //     if (domain[i] == '.')
                //         break;
                // }
                int i = domain.find('.');
                
                // cout << i << endl;
                // if (i == domain.length())
                //     domain = "";
                if (i == -1)
                    domain = "";
                else
                    domain = domain.substr(i + 1);
                
                // cout << domain << endl;
            }
        }
        
        vector<string> output;
        
        for (auto& p: domain_count) {
            string cp_domain = to_string(p.second) + " " + p.first;
            output.push_back(cp_domain);
        }
        
        return output;
    }
    
private:
    pair<int, int> getCP(string& s) {
        int i = 0;
        
        for (; i < s.length(); ++i) {
            if (s[i] == ' ')
                break;
        }
        
        return {stoi(s.substr(0, i)), i};
    }
};

// Runtime: 16 ms, faster than 90.09% of C++ online submissions for Subdomain Visit Count.
// Memory Usage: 13.1 MB, less than 86.67% of C++ online submissions for Subdomain Visit Count.
// time complexity: O(nm), n is # of string, and m is the most subdomain of a domain
// space complexity: O(nm)