// C++ program to reverse a string without using stack
#include <bits/stdc++.h>
using namespace std;

// A utility function to swap two characters
void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

// A stack based function to reverse a string
void reverse(char str[])
{
    // get size of string
    int n = strlen(str), i;

    for (i = 0; i < n / 2; i++)
        swap(&str[i], &str[n - i - 1]);
}

// Driver program to test above functions
int main()
{
    char str[] = "abc";

    reverse(str);
    cout << "Reversed string is " << str;

    cout << endl;
    system("pause");
    return 0;
}
