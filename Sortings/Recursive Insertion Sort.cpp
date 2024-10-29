class solution
{
public:
    void insert(int arr[], int i, int n)
    {
        // code here
        if (i == n)
        {
            return;
        }
        else
        {
            for (int j = i; j > 0; j--)
            {
                if (arr[j] < arr[j - 1])
                {
                    int temp = arr[j - 1];
                    arr[j - 1] = arr[j];
                    arr[j] = temp;
                }
            }
            insert(arr, i + 1, n);
        }
    }

public:
    // Function to sort the array using insertion sort algorithm.
    void insertionSort(int arr[], int n)
    {
        // code here
        insert(arr, 0, n);
    }
};