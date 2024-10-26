class solution
{
public:
    void insert(int arr[], int i)
    {
        // code here
        while (i > 0 && arr[i - 1] > arr[i])
        {
            int temp = arr[i - 1];
            arr[i - 1] = arr[i];
            arr[i] = temp;
            i--;
        }
    }

public:
    // Function to sort the array using insertion sort algorithm.
    void insertionSort(int arr[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            insert(arr, i);
        }
        // code here
    }
};