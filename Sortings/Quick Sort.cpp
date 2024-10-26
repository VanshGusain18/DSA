class Solution
{
public:
    // Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        // code here
        if (low >= high)
        {
            return;
        }
        else
        {
            int pindex = partition(arr, low, high);
            quickSort(arr, low, pindex - 1);
            quickSort(arr, pindex + 1, high);
        }
    }

public:
    int partition(int arr[], int low, int high)
    {
        // Your code here
        int pivot = arr[low];
        int i = low;
        int j = high;
        while (i < j)
        {
            while (arr[i] <= pivot && i <= high)
            {
                i++;
            }
            while (arr[j] > pivot && j >= low)
            {
                j--;
            }
            if (i < j)
                swap(arr[i], arr[j]);
        }
        swap(arr[low], arr[j]);
        return j;
    }
};