// Brute Force Approch

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> list;
        for (int i = 0; i < n; i++)
        {
            if (list.size() == 0 || list[0] != nums[i])
            {
                int cnt = 0;
                for (int j = 0; j < n; j++)
                {
                    if (nums[i] == nums[j])
                    {
                        cnt++;
                    }
                }
                if (cnt > n / 3)
                {
                    list.push_back(nums[i]);
                }
                if (list.size() == 2)
                {
                    return list;
                }
            }
        }
        return list;
    }
};

// Better Approch

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> list;
        map<int, int> mpp;
        for (int i = 0; i < n; i++)
        {
            mpp[nums[i]]++;
            if (list.size() == 0 || list[0] != nums[i])
            {
                if (mpp[nums[i]] > n / 3)
                {
                    list.push_back(nums[i]);
                }
                if (list.size() == 2)
                {
                    return list;
                }
            }
        }
        return list;
    }
};

// Optimal Approch

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> list;
        int ele1, ele2, cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (cnt1 == 0 && nums[i] != ele2)
            {
                ele1 = nums[i];
                cnt1 = 1;
            }
            else if (cnt2 == 0 && nums[i] != ele1)
            {
                ele2 = nums[i];
                cnt2 = 1;
            }
            else if (nums[i] == ele1)
            {
                cnt1++;
            }
            else if (nums[i] == ele2)
            {
                cnt2++;
            }
            else
            {
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == ele1)
            {
                cnt1++;
            }
            else if (nums[i] == ele2)
            {
                cnt2++;
            }
        }
        if (cnt1 > n / 3)
        {
            list.push_back(ele1);
        }
        if (cnt2 > n / 3)
        {
            list.push_back(ele2);
        }
        return list;
    }
};