// Given a binary matrix of M X N of integers,
// you need to return only unique rows of binary array
#include <bits/stdc++.h>
using namespace std;
#define ROW 4
#define COL 5

class BST
{
    int data;
    BST *left, *right;

public:
    // Default constructor.
    BST();

    // Parameterized constructor.
    BST(int);

    // Insert function.
    BST *Insert(BST *, int);

    // Inorder traversal.
    void Inorder(BST *);
};

//convert array to decimal
int convert(int arr[])
{
    int sum = 0;

    for (int i = 0; i < COL; i++)
    {
        sum += pow(2, i) * arr[i];
    }
    return sum;
}

//print the column represented as integers
void print(int p)
{
    for (int i = 0; i < COL; i++)
    {
        cout << p % 2 << " ";
        p /= 2;
    }
    cout << endl;
}

// Default Constructor definition.
BST ::BST() : data(0), left(NULL), right(NULL) {}

// Parameterized Constructor definition.
BST ::BST(int value)
{
    data = value;
    left = right = NULL;
}

// Insert function definition.
BST *BST ::Insert(BST *root, int value)
{
    if (!root)
    {
        // Insert the first node, if root is NULL.
        return new BST(value);
    }

    //if the value is present
    if (value == root->data)
        return root;

    // Insert data.
    if (value > root->data)
    {
        // Insert right node data, if the 'value'
        // to be inserted is greater than 'root' node data.

        // Process right nodes.
        root->right = Insert(root->right, value);
    }
    else
    {
        // Insert left node data, if the 'value'
        // to be inserted is greater than 'root' node data.

        // Process left nodes.
        root->left = Insert(root->left, value);
    }

    // Return 'root' node, after insertion.
    return root;
}

// Inorder traversal function.
// This gives data in sorted order.
void BST ::Inorder(BST *root)
{
    if (!root)
    {
        return;
    }
    Inorder(root->left);
    print(root->data);
    Inorder(root->right);
}

// The main function that prints
// all unique rows in a given matrix.
void findUniqueRows(int M[ROW][COL])
{

    BST b, *root = NULL;

    //Traverse through the matrix
    for (int i = 0; i < ROW; i++)
    {
        //insert the row into BST
        root = b.Insert(root, convert(M[i]));
    }

    //print
    b.Inorder(root);
}

// Driver Code
int main()
{
    int M[ROW][COL] = {{0, 1, 0, 0, 1},
                                        {1, 0, 1, 1, 0},
                                        {0, 1, 0, 0, 1},
                                        {1, 0, 1, 0, 0}};

    findUniqueRows(M);

    cout << endl;
    system("pause");
    return 0;
}
