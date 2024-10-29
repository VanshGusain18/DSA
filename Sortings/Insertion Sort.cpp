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

class solution2
{
public:
    void insert(int arr[], int i)
    {
        // code here
        for (int j = i; j > 0; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                int temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
            }
            else
                break;
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