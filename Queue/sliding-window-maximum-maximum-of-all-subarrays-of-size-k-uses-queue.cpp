// CPP program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to find max
void find_max(queue<int> q)
{
    int max = 0;
    while (!q.empty())
    {
        if (q.front() > max)
            max = q.front();
        q.pop();
    }

    cout << max << " ";
    return;
}

// Function to find max of windows
void window_max(int arr[], int size,
                int window_s)
{
    queue<int> q;

    cout << "\nMaximun in each window : ";

    for (int i = 0; i < size; i++)
    {

        // For first window
        if (i < window_s)
        {
            q.push(arr[i]);
        }

        // For middle window
        else
        {
            find_max(q);
            q.pop();
            q.push(arr[i]);
        }
    }

    // for last window
    find_max(q);

    return;
}

// Driver Code
int main()
{
    int arr[] = {1, 2, 3, 1, 4, 5, 2, 3, 6};

    // Size of array
    int size = 9;
    int window_s = 3;

    // Function Call
    window_max(arr, size, window_s);

    cout << endl;
    system("pause");
    return 0;
}
