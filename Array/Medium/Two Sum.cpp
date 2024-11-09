// Better Approch

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> eleMap;
        for (int i = 0; i < nums.size(); i++)
        {
            int rem = target - nums[i];
            if (eleMap.find(rem) != eleMap.end())
            {
                return {eleMap[rem], i};
            }
            eleMap[nums[i]] = i;
        }
        return {-1, -1};
    }
};