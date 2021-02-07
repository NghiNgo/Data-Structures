// C++ code to print unique row in a
// given binary matrix
#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[][5], int row,
                int col)
{
    unordered_set<string> uset;

    for (int i = 0; i < row; i++)
    {
        string s = "";

        for (int j = 0; j < col; j++)
            s += to_string(arr[i][j]);

        if (uset.count(s) == 0)
        {
            uset.insert(s);
            cout << s << endl;
        }
    }
}

// Driver code
int main()
{
    int arr[][5] = {{0, 1, 0, 0, 1},
                            {1, 0, 1, 1, 0},
                            {0, 1, 0, 0, 1},
                            {1, 1, 1, 0, 0}};

    printArray(arr, 4, 5);

    cout << endl;
    system("pause");
    return 0;
}
