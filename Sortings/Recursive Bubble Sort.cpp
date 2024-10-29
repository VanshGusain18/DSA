class solution
{
public:
    // Function to sort the array using bubble sort algorithm.
    void bubbleSort(int arr[], int n)
    {
        // Your code here
        if (n == 1)
        {
            return;
        }
        else
        {
            for (int i = 0; i < n - 1; i++)
            {
                if (arr[i] > arr[i + 1])
                    swap(arr[i], arr[i + 1]);
            }
            n--;
            bubbleSort(arr, n);
        }
    }
};