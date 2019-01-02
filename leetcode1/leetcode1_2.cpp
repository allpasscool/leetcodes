class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        vector<int> answer (2);
        std::unordered_map<int, int> hash_map;
        for(vector<int>::size_type i = 0;
                                  i < size;
                                  i++){
            int complement = target - nums[i];
            if(hash_map.count(complement) > 0 
               && hash_map.find(complement)->second != i){
                answer[1] = i;
                answer[0] = hash_map[complement];
                return answer;
            }
            hash_map[nums[i]] = i;
        }
    }
};