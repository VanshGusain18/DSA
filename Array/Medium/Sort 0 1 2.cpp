// Better Approch

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int zero = 0, one = 0, two = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                zero++;
            }
            else if (nums[i] == 1)
            {
                one++;
            }
            else
            {
                two++;
            }
        }
        for (int i = 0; i < zero; i++)
        {
            nums[i] = 0;
        }
        for (int i = zero; i < one + zero; i++)
        {
            nums[i] = 1;
        }
        for (int i = one + zero; i < nums.size(); i++)
        {
            nums[i] = 2;
        }
    }
};

// Optimal Approch (Dutch National flag algorithm)

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int low = 0, mid = 0, high = nums.size() - 1;
        while (mid <= high)
        {
            if (nums[mid] == 0)
            {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};