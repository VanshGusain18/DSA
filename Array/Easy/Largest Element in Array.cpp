class solution
{
public:
    int largest(vector<int> &arr)
    {
        // code here
        int max = arr[0];
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] > max)
                max = arr[i];
        }
        return max;
    }
};