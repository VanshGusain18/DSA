// Better Approch

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        map<int, int> countMap;
        for (int i = 0; i < nums.size(); i++)
        {
            countMap[nums[i]]++;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (countMap[nums[i]] > nums.size() / 2)
            {
                return nums[i];
            }
        }
        return -1;
    }
};

// Optimal Approch (Moore’s Voting Algorithm)

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        int ele, cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (cnt == 0)
            {
                ele = nums[i];
            }
            if (nums[i] == ele)
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
        }
        cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (ele == nums[i])
                cnt++;
            if (cnt > n / 2)
                return nums[i];
        }
        return -1;
    }
};