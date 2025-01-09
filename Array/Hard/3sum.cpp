// Brute Approch

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        set<vector<int>> st;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (nums[i] + nums[j] + nums[k] == 0)
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
        vector<vector<int>> result(st.begin(), st.end());
        return result;
    }
};

// Better Approch

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        set<vector<int>> st;
        for (int i = 0; i < n; i++)
        {
            set<int> hashset;
            for (int j = i + 1; j < n; j++)
            {
                int diff = -(nums[i] + nums[j]);
                if (hashset.find(diff) != hashset.end())
                {
                    vector<int> temp = {nums[i], nums[j], diff};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashset.insert(nums[j]);
            }
        }
        vector<vector<int>> result(st.begin(), st.end());
        return result;
    }
};

// Optimal Approch

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0;
        vector<vector<int>> result;
        while (i < n)
        {
            if (i != 0 && nums[i] == nums[i - 1])
            {
                i++;
                continue;
            }
            int j = i + 1;
            int k = n - 1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0)
                {
                    j++;
                }
                else if (sum > 0)
                {
                    k--;
                }
                else
                {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    result.push_back(temp);
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j - 1])
                    {
                        j++;
                    }
                    while (j < k && nums[k] == nums[k + 1])
                    {
                        k--;
                    }
                }
            }
            i++;
        }
        return result;
    }
};